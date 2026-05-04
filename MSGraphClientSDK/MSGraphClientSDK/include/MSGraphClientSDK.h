//
// Copyright (c) Microsoft Corporation. All Rights Reserved. Licensed under the MIT License. See License in the project root for license information.
//
// This file is the umbrella header used by Swift Package Manager.
// It uses flat imports (no module-qualified paths) so that all header search
// paths configured in Package.swift can resolve them correctly.
//

#ifndef MSGraphClientSDK_h
#define MSGraphClientSDK_h

// Authentication
#import "MSAuthenticationProvider.h"
#import "MSAuthenticationProviderOptions.h"

// Middleware – Protocols
#import "MSGraphMiddleware.h"

// Middleware – Options
#import "MSMiddlewareOptions.h"
#import "MSAuthenticationHandlerOptions.h"
#import "MSRedirectHandlerOptions.h"
#import "MSRetryHandlerOptions.h"

// Middleware – Implementations
#import "MSAuthenticationHandler.h"
#import "MSRedirectHandler.h"
#import "MSRetryHandler.h"
#import "MSHttpProvider.h"
#import "MSURLSessionManager.h"
#import "MSURLSessionTaskDelegate.h"

// HTTP Client
#import "MSClientFactory.h"
#import "MSMiddlewareFactory.h"
#import "MSHTTPClient.h"

// Common
#import "MSConstants.h"
#import "MSErrorCodes.h"

// Session Tasks
#import "MSURLSessionTask.h"
#import "MSURLSessionDataTask.h"
#import "MSURLSessionDownloadTask.h"
#import "MSURLSessionUploadTask.h"

// Batch Content
#import "MSBatchRequestStep.h"
#import "MSBatchRequestContent.h"
#import "MSBatchResponseContent.h"

// Graph Tasks
#import "MSPageIterator.h"
#import "MSLargeFileUploadTask.h"
#import "MSGraphOneDriveLargeFileUploadTask.h"

#endif /* MSGraphClientSDK_h */
