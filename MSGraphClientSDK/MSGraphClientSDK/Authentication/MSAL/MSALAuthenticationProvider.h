//
// Copyright (c) Microsoft Corporation. All Rights Reserved. Licensed under the MIT License. See License in the project root for license information.
//

#import <Foundation/Foundation.h>
#import <MSAL/MSAL.h>
#import "../MSAuthenticationProvider.h"
#import "MSALAuthenticationProviderOptions.h"

NS_ASSUME_NONNULL_BEGIN

/*
 This class provides a concrete implementation of the MSAuthenticationProvider protocol defined in
 MSGraphClientSDK and handles authentication token fetching via MSAL.
 */
@interface MSALAuthenticationProvider : NSObject<MSAuthenticationProvider>

/*
 Creates and returns an instance of MSALAuthenticationProvider.
 @param publicClientApplication An MSALPublicClientApplication instance from MSAL.
 @param providerOptions An MSALAuthenticationProviderOptions instance containing required options.
 @return An instance of MSALAuthenticationProvider with the provided values.
 */
- (instancetype)initWithPublicClientApplication:(MSALPublicClientApplication *)publicClientApplication
                                     andOptions:(MSALAuthenticationProviderOptions *)providerOptions;

@end

NS_ASSUME_NONNULL_END
