//
// Copyright (c) Microsoft Corporation. All Rights Reserved. Licensed under the MIT License. See License in the project root for license information.
//

#import <Foundation/Foundation.h>
#import "../../Protocols/MSGraphMiddleware.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Completion handler to be called from MSHttpProvider on download completion.
 */
typedef void (^MSRawDownloadCompletionHandler)(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error);

/**
 Completion handler to be called from MSHttpProvider on upload completion.
 */
typedef void (^MSRawUploadCompletionHandler)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error);

/**
 Completion handler to be called form MSHttpProvider on a data task completion.
 */
typedef void (^MSDataCompletionHandler)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error);

/**
 The `MSHttpProvider` protocol is meant to inject all network access from MSHTTPClient.
 */
@protocol MSHttpProvider <NSObject, MSGraphMiddleware>

/**
 Creates an NSURLSessionDataTask ready to be resumed.
 @param  request The request that should be sent.
 @param  completionHandler The completion handler to be called on completion. It may be nil.
 @return The NSURLSessionDataTask ready to be resumed.
 */
- (NSURLSessionDataTask *) dataTaskWithRequest:(NSURLRequest *)request
                             completionHandler:(nullable MSDataCompletionHandler)completionHandler;
/**
 Creates an NSURLSessionDataTask ready to be resumed.
 @param  request The request that should be sent.
 @param  progress A reference to an NSProgress object that will be updated when the download completes. It may be nil.
 @param  completionHandler The completion handler to be called on completion. It may be nil.
 @return The NSURLSessionDownloadTask ready to be resumed.
 */
- (NSURLSessionDownloadTask *) downloadTaskWithRequest:(NSURLRequest *)request
                                              progress:(NSProgress * __autoreleasing _Nullable * _Nullable)progress
                                     completionHandler:(nullable MSRawDownloadCompletionHandler)completionHandler;
/**
 Creates an NSURLSessionUploadTask ready to be resumed.
 @param  request The request that should be sent.
 @param  fileURL The file to upload.
 @param  progress A reference to an NSProgress to be updated as the upload completes. It may be nil.
 @param  completionHandler The completion handler to be called on completion. It may be nil.
 @return The NSURLSessionDownloadTask ready to be resumed.
 */
- (NSURLSessionUploadTask *) uploadTaskWithRequest:(NSURLRequest *)request
                                          fromFile:(NSURL *)fileURL
                                          progress:(NSProgress * __autoreleasing _Nullable * _Nullable)progress
                                 completionHandler:(nullable MSRawUploadCompletionHandler)completionHandler;
/**
 Creates an NSURLSessionUploadTask ready to be resumed.
 @param  request The request to be sent.
 @param  data The data to be uploaded.
 @param  progress A reference to an NSProgress to be updated as the upload completes. It may be nil.
 @param  completionHandler The completion handler to be called on completion. It may be nil.
 @return The NSURLSessionDownloadTask ready to be resumed.
 */
- (NSURLSessionUploadTask *)uploadTaskWithRequest:(NSURLRequest *)request
                                         fromData:(NSData *)data
                                         progress:(NSProgress * __autoreleasing _Nullable * _Nullable)progress
                                completionHandler:(nullable MSRawUploadCompletionHandler)completionHandler;

@end

NS_ASSUME_NONNULL_END
