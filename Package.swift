// swift-tools-version:5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MSGraphClientSDK",
    platforms: [
        .iOS(.v16),
        .macOS(.v11),
    ],
    products: [
        .library(
            name: "MSGraphClientSDK",
            targets: ["MSGraphClientSDK"]
        ),
    ],
    dependencies: [
        .package(
            url: "https://github.com/AzureAD/microsoft-authentication-library-for-objc",
            "1.2.0"..<"3.0.0"
        ),
    ],
    targets: [
        .target(
            name: "MSGraphClientSDK",
            dependencies: [
                .product(name: "MSAL", package: "microsoft-authentication-library-for-objc"),
            ],
            path: "MSGraphClientSDK/MSGraphClientSDK",
            exclude: ["Info.plist"],
            publicHeadersPath: "include",
            cSettings: [
                .headerSearchPath("."),
                .headerSearchPath("Authentication"),
                .headerSearchPath("Authentication/MSAL"),
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
                .headerSearchPath("BaseModels"),
                .headerSearchPath("GeneratedModels"),
            ]
        ),
    ]
)
