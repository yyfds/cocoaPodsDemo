//
//  SMEditNicknameTextFieldBaseDelegate.h
//  SMBase
//
//  Created by smwl on 2021/4/7.
//  Copyright © 2021 smwl. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^textFieldDidChangeBlock)(UITextField * textField);

@interface SMEditNicknameTextFieldBaseDelegate : NSObject <UITextFieldDelegate>

/// init
/// @param maxLength 文本的限制最大长度
-(instancetype)initWithTextFieldMaxLength:(int)maxLength;

/// init
/// @param maxLength 文本的限制最大长度
/// @param shouldRegardChineseTwo 是否需要把中文汉字的长度当作2看待
-(instancetype)initWithTextFieldMaxLength:(int)maxLength shouldRegardChineseTwo:(BOOL)shouldRegardChineseTwo;

/// Toast提示的superView, 可选
@property (nonatomic, weak, nullable) UIView * toastSuperView;

/// 监听到文本变化的回调
@property (nonatomic, copy) textFieldDidChangeBlock textFieldDidChange;

@end

NS_ASSUME_NONNULL_END
