//
//  SMBaseCommon.h
//  SMBase
//
//  Created by smwl on 2020/5/6.
//  Copyright © 2020 smwl. All rights reserved.
//

#ifndef SMBaseCommon_h
#define SMBaseCommon_h

//尺寸比例
#define SizePecent 0.34
#define DEVICES_IS_PRO_12_9 ([UIScreen mainScreen].bounds.size.width == 1024)
#define IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define CurrentHeight ([UIScreen mainScreen].bounds.size.height)
#define CurrentWidth ([UIScreen mainScreen].bounds.size.width)
#define KWIDTH (IPAD ? (CurrentWidth > CurrentHeight ? CurrentHeight : CurrentWidth)/750 : (CurrentWidth > CurrentHeight ? CurrentHeight : CurrentWidth)/375)
#define newKWIDTH (CurrentHeight>CurrentWidth ? CurrentWidth: CurrentHeight)/375
#define kBannerHeight 200*newKWIDTH
#define NavHeight     ([[UIApplication sharedApplication] statusBarFrame].size.height>20?88:64) // 适配iPhone x
#define BottomiPhoneMax     ([[UIApplication sharedApplication] statusBarFrame].size.height>20?24:0) // 适配iPhone x 多34
#define DCHeight [[UIApplication sharedApplication] statusBarFrame].size.height////电池高度

//是否是ipad。是iPad比例c乘以1.5倍，不是则直接按照屏幕比例是配
#define SMSIZEBILI (IPAD ? SizePecent*1.5 : SizePecent*newKWIDTH)
#define SMBili   1.77778

#define AutoWidthSize(str,zsize)   [str boundingRectWithSize:CGSizeMake(MAXFLOAT, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:zsize]} context:nil].size.width
#define kSearchbarHeight        53
#define kSlideHeight        180*SMSIZEBILI
// Include any system framework and library headers here that should be included in all compilation units.
// You will also need to set the Prefix Header build setting of one or more of your targets to reference this file.

#define iPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
#define iOS_11 @available(iOS 11.0,*)
#define UIColorFromRGB(rgbValue) \
[UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0x00FF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0x0000FF))/255.0 \
alpha:1.0]

#define newSizePecent 375/1080

///////1、导航栏
#define TabbarHeight     ([[UIApplication sharedApplication] statusBarFrame].size.height>20?73+6:49+6) // 适配iPhone x 底栏高度 83:49
#define NavHeight     ([[UIApplication sharedApplication] statusBarFrame].size.height>20?88:64) // 适配iPhone x
#define TopiPhoneMax     ([[UIApplication sharedApplication] statusBarFrame].size.height>20?24:0) // 适配iPhone x 多24
#define BottomiPhoneMax     ([[UIApplication sharedApplication] statusBarFrame].size.height>20?24:0) // 适配iPhone x 多34
#define SpaceToTop     ([[UIApplication sharedApplication] statusBarFrame].size.height>20?34:0) // 适配iPhone x 多34

//文本size
#define AutoHeightSize(str,with,zsize)   [str boundingRectWithSize:CGSizeMake(with, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:zsize]} context:nil].size.height

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////        宏定义       ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;
#define StringWithData(data) [[NSString alloc] initWithData:(data) encoding:NSUTF8StringEncoding]
#define DataWithString(str) [(str) dataUsingEncoding:NSUTF8StringEncoding]

/* debug和release设置 */
#ifdef DEBUG
#define NSLog(...) NSLog(__VA_ARGS__)
#else
#define NSLog(...)
#endif

#ifndef SMLog
#define SMLogF(FORMAT, ...) fprintf(stderr,"%s:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#ifdef DEBUG
#define SMLog(format, ...) SMLogF(format, ##__VA_ARGS__);
#else
#define SMLog(format, ...) while(0){}
#endif
#endif

#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
#define SM_MULTILINE_TEXTSIZE(text, font, maxSize, mode) [text length] > 0 ? [text \
boundingRectWithSize:maxSize options:(NSStringDrawingUsesLineFragmentOrigin) \
attributes:@{NSFontAttributeName:font} context:nil].size : CGSizeZero;
#else
#define SM_MULTILINE_TEXTSIZE(text, font, maxSize, mode) [text length] > 0 ? [text \
sizeWithFont:font constrainedToSize:maxSize lineBreakMode:mode] : CGSizeZero;
#endif

//延时宏
#define DELAYED(time, block) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), block)

//发送通知宏
#define POST_NOTIFICATION1(name)    [[NSNotificationCenter defaultCenter] postNotification:[NSNotification notificationWithName:name object:nil]];
#define POST_NOTIFICATION2(name, obj)    [[NSNotificationCenter defaultCenter] postNotification:[NSNotification notificationWithName:name object:obj]];
#define POST_NOTIFICATION3(name, userInfo)    [[NSNotificationCenter defaultCenter] postNotification:[NSNotification notificationWithName:name object:nil userInfo:userInfo]];
#define POST_NOTIFICATION4(name, obj, userInfo) [[NSNotificationCenter defaultCenter] postNotification:[NSNotification notificationWithName:name object:obj userInfo:userInfo]]

//NSUserDefaults 实例化
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]


//统计代码执行时间
#define START NSDate *startTime = [NSDate date]
#define END SMLog(@"func=%s Time: %f", __func__, -[startTime timeIntervalSinceNow])
#define END2(desc)  SMLog(@"func=%s Time: %f(%@)", __func__, -[startTime timeIntervalSinceNow], desc)

#define NSLocalizedString_SM(key, nil)  [[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] objectForKey:@"appLanguage"]] ofType:@"lproj"]] localizedStringForKey:(key) value:nil table:@"Localizable"]

#define  faloatWindow        [UIApplication sharedApplication].keyWindow

//状态栏高度
#define FloatStatusBarHeight (iPhoneX ? 44.f : 20.f)


#define KISIphoneX (CGSizeEqualToSize(CGSizeMake(375.f, 812.f), [UIScreen mainScreen].bounds.size) \
|| CGSizeEqualToSize(CGSizeMake(812.f, 375.f), [UIScreen mainScreen].bounds.size)   \
|| CGSizeEqualToSize(CGSizeMake(896.f, 414.f), [UIScreen mainScreen].bounds.size)   \
|| CGSizeEqualToSize(CGSizeMake(414.f, 896.f), [UIScreen mainScreen].bounds.size))

#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IOS_11  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 11.f)
#define IS_IPHONE_X (IS_IOS_11 && IS_IPHONE && (MIN([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height) >= 375 && MAX([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height) >= 812))
#define SizeForIpad 0.5

#define MAIN(block) dispatch_async(dispatch_get_main_queue(), block)


//Network API Encode
#define BUY_ENCRYSTRING_HEX @"d8115fcc8bf6dcefa12321c4c1ae087b3a723b89a0da22de78b4b601fae436403794e92f0494fe7662bab9bb08081b70aa2b6848009af780544df08e4ef731dcd1d4af7e2ddfe90f1af446b5a5ffd764"
#define EncryptedString_HEX @"4668cd7b6717aa3dadf22aa3c924ba0e2943617dd9fb966b92077d9f1212500570020c0a6d7ebd9a8c0fc1b05bba5fb70f6941bb6683f777695fffed704d94957a2c52c322afef664642e82e3b5a9553"
#define HGAME_ENCRYSTRING_HEX @"86a810bf0463e9feae35999a3b58b147bb7610fb5bad1c768bf83850cbb2a6435632c7f24b65f80adeec678b1c3e9e7e91d670576fc5adb08674e28f8aed5b264cb91b143dd3bbc2750fb98a29b315af"
#define URL_ENCODECODE_HEX  @"6b2fb9d0c649914d3d8efc4a23b45fffdd7ce4a39aa4d5fc07921622349598b0893b98e0c0e95aa077e537457ad49511"
#define New_ENCRYSTRING_HEX @"00b5b7a9f3982ba03f2da2e866fe2a71c798258f28a7ff2e2e9e0d973e9036e5a4bdd4d8b99c6e740484f6ba3a9cad0d81c47c608fb975255ae931f827978e52fc2f01dbc0715a470bd1e3db4d1380ad"
#define USER_ENCRYSTRING_HEX @"8a358ce033d173e959ab20ad4844c4637fc5ea747817bb971a3d085a2f9b258e11b931f4c4cc44e0926bceae651a8196b07fbcc83236e7643528dca6f84a4cd2e24986ba0a3d46bbd33b196f479389fd"
#define PAY_ENCRYSTRING_HEX @"9b08ee40a276b9c32c135ef22ae9e2fe29e2193cf17496d29d47f8e19191d033560f43407cd580879875ad9be1a486bf289d70242cd3babf1484de32e3dc27827ae1f4e65f9b9ad2e9d77a11a3e73b59"
#define UPLOAD_ENCRYSTRING_HEX @"30ee443c5b71a6b4b4e92b96ee9c5ccc78eedc68feb0c3b70e565ae891eac4e636d0a908f4d49ebb79aec66896d03277f271bfc5fd62c8de33585dec71dae0aa1a976d104aad1474d2935f7494864d9d"
#define USER_SECRET_KEY_HEX                     @"68f1b6dece73117026cc6aedc4a44597ae42e2c767778752dc7a75bacf2a219bf65c77cf5aac77b162a98979c19f52fa"
#define CURRENCY_ENCRYSTRING_HEX   @"de0b4f07f0abe14d459a3bc0e6f194e3229c3c0175b80698b91371f10d95f339"
#define HEADER_INFORMATION_ENCRYSTRING_HEX   @"14dee16ed4fb816fbb73538cadb68a981f5017168c0eb11824030be81201a854a2e3d7ea649e9ca69cd98162032d336e88dbd1a8e99850bd1da337d3948dca68036ec263d459d00e1f59610f0bdbf1ba"

#define BUY_ENCRYSTRING [BUY_ENCRYSTRING_HEX sksmd]   //buy.x7sy.com 加密串
#define EncryptedString [EncryptedString_HEX sksmd]   //hgame.x7sy.com 加密串
#define HGAME_ENCRYSTRING [HGAME_ENCRYSTRING_HEX sksmd]   //hgame.x7sy.com 新加密串
#define URL_ENCODECODE  [URL_ENCODECODE_HEX sksmd]  //market.x7sy.com 加密串
#define New_ENCRYSTRING [New_ENCRYSTRING_HEX sksmd]   //market.x7sy.com 新 加密串
#define USER_ENCRYSTRING [USER_ENCRYSTRING_HEX sksmd]   //用户中心新加密串
#define PAY_ENCRYSTRING [PAY_ENCRYSTRING_HEX sksmd]   //支付加密
#define UPLOAD_ENCRYSTRING [UPLOAD_ENCRYSTRING_HEX sksmd]  //上传图片加密串
#define USER_SECRET_KEY [USER_SECRET_KEY_HEX sksmd]  //用户数据加密字符串，4.1账号互通
#define CURRENCY_ENCRYSTRING [CURRENCY_ENCRYSTRING_HEX sksmd]  //2019 12.5//通用加密串（后台说通用的 ?）
#define HEADER_INFORMATION_ENCRYSTRING [HEADER_INFORMATION_ENCRYSTRING_HEX sksmd]  //2020 03.16//头信息新增的key的加密串

#define auth_string  @"auth_string"


/**
    SMParseSymbols.py Auto Create File
    Time : 20210107143723
    Source_file : SMBaseSymbols.yaml
*/

#define SMUtils SMAdZu2tVkDOLSD7OM
#define SMConfig SMdKAHVsKyFjT39pBr
#define sdk7GameParamsNewRandomNumEncode1 smz1uI07PvcE7qrKYQ
#define sdk7GameParamsNewRandomNumEncode smB471seId5dKvLTmz
#define sdk7GameParamsEncodeXOR1 sm3UZ5Ib1YkPw3RJVe
#define sdk7GameParamsEncodeXOR smzFUnBFLNx7IpCA2Q
#define smNewheaderInfotmation smAYWbZeiysPsi2hLQ
#define XORHexEncode smmeImuR4WdsNOxUAW
#define XORHexDecode smeO6q84tO4wUCi1HG
#define isPassWordComplexWithPwd smQqnzWGRoYL1RswXq
#define getNowTimeTimestamp smjsaf38Pd5WehTwK1
#define paramsRandomNumEncodeWithXOR1 smZPVksC4kWGkf0jwI
#define paramsRandomNumEncodeWithXOR sm0AsYYBBjNyqT9TAJ
#define generateUserAgent smkLCU47M4h9u0dD0s
#define make_encode smsx7CXAOlVaHOJKum
#define isOrderedAscendingWithExpireTime smR0ZvhMWcwHZpmIge
#define pIdfaIsForApp smFEHWqlTImiNEYDIm
#define idfaStrForSDK smeaK5btR6iKkyrg9Y
#define uuidStrForSDK smSvrLhXC6NWt2YJ02
#define paramsEncode1 smEAw0KakWpVc03smk
#define paramsEncode smEtUyMK8IKsRzYCyl
#define paramsNewEncode1 smmq4kKaKpyIiBSTQe
#define paramsNewEncode smZ3fxImRJA9R5N2b6
#define paramsNewRandomNumEncode1 smiDROJuAuE5xufl2f
#define paramsPayEncode1 smnEsYZhCaQINIzvz9
#define userParameterEncode1 smR1OcflPPAPcOkrly
#define paramsAddParameterEncode1 smirGhOwc3QPPSMPRV
#define roleTradeParameterEncode1 sm2r3VFg89XTe45ZlZ
#define roleTradeParameterEncode smVj7g7o7nlxy194El
#define userParameterEncode smi6eQEmZohcNkjOyo
#define paramsAddParameterEncode smCcrcolOldqbbJ2e3
#define generateTradeNO smaQI4KuENy25tqDdB
#define paramMid smQZSEAEMIGPafTQV7
#define XORHexDigest smcdjkvsHaAR2b4bS2
#define getUserUDID smoEp7PVgWY4p7Fqt0
#define setUserUDID smK0jpJ47eenwGBMgl
#define getIsEnterpriseSign smPjMJ2hgN0TJ8KbzM
#define setIsEnterpriseSign smG8SQCr9rCtW6LPWM

/**
END
*/

/**
    SMParseSymbols.py Auto Create File
    Time : 20210115152330
    Source_file : ./SMBaseSymbols.yaml
*/

#define SMAliSafeUtil SMx0N9sRkWyYFMs4pM
#define avmpSignWithParamsData smbUUBlW0WVGsCaaut

/**
END
*/

#endif /* SMBaseCommon_h */
