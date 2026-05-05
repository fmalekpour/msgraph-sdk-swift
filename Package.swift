// swift-tools-version:5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MSGraphClientSDK",
    platforms: [
        .iOS(.v14),
        .macOS(.v11),
    ],
    products: [
        .library(
            name: "MSGraphClientSDK",
            targets: ["MSGraphClientSDK"]
        ),
        .library(
            name: "MSGraphMSALAuthProvider",
            targets: ["MSGraphMSALAuthProvider"]
        ),
    ],
    dependencies: [
        .package(
            url: "https://github.com/AzureAD/microsoft-authentication-library-for-objc",
            "1.2.0"...
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
        .target(
            name: "MSGraphMSALAuthProvider",
            dependencies: [
                "MSGraphClientSDK",
                .product(name: "MSAL", package: "microsoft-authentication-library-for-objc"),
            ],
            path: "MSGraphMSALAuthProvider",
            publicHeadersPath: "include",
            cSettings: [
                .headerSearchPath("."),
            ]
        ),
    ]
)
