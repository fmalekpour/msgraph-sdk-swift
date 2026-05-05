//
// Copyright (c) Microsoft Corporation. All Rights Reserved. Licensed under the MIT License. See License in the project root for license information.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 This class can be used to get individual response dictionary or the whole response dictionary from a batch response data.
 */

@interface MSBatchResponseContent : NSObject

/*
 Creates and returns an instance of MSBatchResopnseContent
 @param batchResponseData NSData representation of response body received from API.
 @param options NSJSONReading options which will internally be used by NSJSONSerialization
 @param error If any error is encountered during the dictionary creation from batchResponseData, it will be assigned to this address.
 @return The MSBatchResponseContent object
 */
- (instancetype)initWithBatchResponseData:(NSData *)batchResponseData options:(NSJSONReadingOptions)options error:(NSError **)error;

/*
 Iterates through the batch response and returns the required response
 @param requestId The requestId of the request for which response is needed
 @return An NSDictionary object containing the requestId, response status, body and headers.
 */
- (nullable NSDictionary *)getResponseById:(NSString *)requestId;

/*
 Returns the whole Response dictionary created from the batchResponseData
 @return An NSDictionary object containing all the individual response dictionaries.
 */
- (NSDictionary *)getResponses;

@end

NS_ASSUME_NONNULL_END

