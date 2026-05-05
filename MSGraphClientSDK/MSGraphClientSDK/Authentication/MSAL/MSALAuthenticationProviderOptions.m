//
// Copyright (c) Microsoft Corporation. All Rights Reserved. Licensed under the MIT License. See License in the project root for license information.
//

#import "MSALAuthenticationProviderOptions.h"

@implementation MSALAuthenticationProviderOptions

@synthesize scopesArray;

- (instancetype)initWithScopes:(NSArray<NSString *> *)scopeArray
{
    self = [super init];
    if (self)
    {
        scopesArray = scopeArray ? [scopeArray copy] : [NSArray new];
    }
    return self;
}

@end
