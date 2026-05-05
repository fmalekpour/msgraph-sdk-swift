#!/usr/bin/env bash
#
# fix-model-imports.sh
#
# Rewrites cross-folder `#import "Foo.h"` statements in the model headers
# so they resolve through Swift Package Manager's publicHeadersPath when
# downstream consumers do Clang module dependency scanning.
#
# Specifically:
#   - In GeneratedModels/*.h: rewrite imports of BaseModels headers to
#     "../BaseModels/Foo.h".
#   - In BaseModels/MSCollection.h: rewrite "MSObject.h" to "MSObject.h"
#     (already a sibling, so left untouched) — handled implicitly.
#
# Idempotent: running it twice is a no-op because already-rewritten
# imports won't match the source pattern.
#
# Usage:  ./Scripts/fix-model-imports.sh
#
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
GEN_DIR="${REPO_ROOT}/MSGraphClientSDK/MSGraphClientSDK/GeneratedModels"

if [[ ! -d "${GEN_DIR}" ]]; then
    echo "ERROR: ${GEN_DIR} not found" >&2
    exit 1
fi

# BaseModels headers that GeneratedModels reference.
BASE_HEADERS=( MSObject MSDate MSDuration MSTimeOfDay )

count=0
for name in "${BASE_HEADERS[@]}"; do
    # macOS sed: -i '' for in-place edit with no backup.
    # Match exactly `#import "MSObject.h"` (anchored, no path) and replace.
    while IFS= read -r -d '' file; do
        sed -i '' -E "s|^#import \"${name}\.h\"$|#import \"../BaseModels/${name}.h\"|" "$file"
        count=$((count + 1))
    done < <(grep -lZE "^#import \"${name}\.h\"$" "${GEN_DIR}"/*.h 2>/dev/null || true)
done

echo "==> Patched ${count} import statement(s) across GeneratedModels/."
echo "    Review with: git diff -- MSGraphClientSDK/MSGraphClientSDK/GeneratedModels"
