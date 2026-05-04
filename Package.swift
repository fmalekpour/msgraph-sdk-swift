// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MSGraphClientSDK",
    platforms: [
        .iOS(.v9),
        .macOS(.v10_10),
    ],
    products: [
        .library(
            name: "MSGraphClientSDK",
            targets: ["MSGraphClientSDK"]
        ),
    ],
    targets: [
        .target(
            name: "MSGraphClientSDK",
            path: "MSGraphClientSDK/MSGraphClientSDK",
            exclude: ["Info.plist"],
            publicHeadersPath: "include",
            cSettings: [
                .headerSearchPath("."),
                .headerSearchPath("Authentication"),
                .headerSearchPath("Common"),
                .headerSearchPath("Common/Session Tasks"),
                .headerSearchPath("GraphContent/BatchContent"),
                .headerSearchPath("GraphTasks"),
                .headerSearchPath("HTTPClient"),
                .headerSearchPath("Middleware/Implementations/Authentication"),
                .headerSearchPath("Middleware/Implementations/HTTPProvider"),
                .headerSearchPath("Middleware/Implementations/RedirectHandler"),
                .headerSearchPath("Middleware/Implementations/RetryHandler"),
                .headerSearchPath("Middleware/Options"),
                .headerSearchPath("Middleware/Protocols"),
            ]
        ),
    ]
)
