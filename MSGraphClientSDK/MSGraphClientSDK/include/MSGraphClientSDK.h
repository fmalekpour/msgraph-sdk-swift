//
// Copyright (c) Microsoft Corporation. All Rights Reserved. Licensed under the MIT License. See License in the project root for license information.
//
// This file is the umbrella header used by Swift Package Manager.
// All imports use paths relative to this file (which lives in include/) so that
// Clang can resolve them through the publicHeadersPath without needing extra
// header search paths on the consumer side.
//

#ifndef MSGraphClientSDK_h
#define MSGraphClientSDK_h

// Authentication
#import "../Authentication/MSAuthenticationProvider.h"
#import "../Authentication/MSAuthenticationProviderOptions.h"
#import "../Authentication/MSAL/MSALAuthenticationProvider.h"
#import "../Authentication/MSAL/MSALAuthenticationProviderOptions.h"

// Middleware – Protocols
#import "../Middleware/Protocols/MSGraphMiddleware.h"

// Middleware – Options
#import "../Middleware/Options/MSMiddlewareOptions.h"
#import "../Middleware/Options/MSAuthenticationHandlerOptions.h"
#import "../Middleware/Options/MSRedirectHandlerOptions.h"
#import "../Middleware/Options/MSRetryHandlerOptions.h"

// Middleware – Implementations
#import "../Middleware/Implementations/Authentication/MSAuthenticationHandler.h"
#import "../Middleware/Implementations/RedirectHandler/MSRedirectHandler.h"
#import "../Middleware/Implementations/RetryHandler/MSRetryHandler.h"
#import "../Middleware/Implementations/HTTPProvider/MSHttpProvider.h"
#import "../Middleware/Implementations/HTTPProvider/MSURLSessionManager.h"
#import "../Middleware/Implementations/HTTPProvider/MSURLSessionTaskDelegate.h"

// HTTP Client
#import "../HTTPClient/MSClientFactory.h"
#import "../HTTPClient/MSMiddlewareFactory.h"
#import "../HTTPClient/MSHTTPClient.h"

// Common
#import "../Common/MSConstants.h"
#import "../Common/MSErrorCodes.h"

// Session Tasks
#import "../Common/Session Tasks/MSURLSessionTask.h"
#import "../Common/Session Tasks/MSURLSessionDataTask.h"
#import "../Common/Session Tasks/MSURLSessionDownloadTask.h"
#import "../Common/Session Tasks/MSURLSessionUploadTask.h"

// Batch Content
#import "../GraphContent/BatchContent/MSBatchRequestStep.h"
#import "../GraphContent/BatchContent/MSBatchRequestContent.h"
#import "../GraphContent/BatchContent/MSBatchResponseContent.h"

// Graph Tasks
#import "../GraphTasks/MSPageIterator.h"
#import "../GraphTasks/MSLargeFileUploadTask.h"
#import "../GraphTasks/MSGraphOneDriveLargeFileUploadTask.h"

#endif /* MSGraphClientSDK_h */
