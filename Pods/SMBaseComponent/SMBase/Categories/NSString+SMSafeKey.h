//
//  NSString+SMSafeKey.h
//  SMBase
//
//  Created by smwl on 2021/1/11.
//  Copyright © 2021 smwl. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (SMSafeKey)

-(NSData *)sksme;

-(NSString *)sksmd;

@end

NS_ASSUME_NONNULL_END
