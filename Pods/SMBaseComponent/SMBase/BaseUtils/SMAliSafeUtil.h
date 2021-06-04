//
//  SMAliSafeUtil.h
//  SMBase
//
//  Created by smwl on 2021/1/15.
//  Copyright © 2021 smwl. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMAliSafeUtil : NSObject

+(instancetype)shareInstance;

/// Init Ali SDK
-(void)aliInit;

/// get wToken String;
/// @param params params data send to AFN
/// @param isHTTPMethodsEncodingParametersInURI  AFN Deninition
-(NSString * __nullable)avmpSignWithParamsData:(id)params isHTTPMethodsEncodingParametersInURI:(BOOL)isHTTPMethodsEncodingParametersInURI;

@end

NS_ASSUME_NONNULL_END
