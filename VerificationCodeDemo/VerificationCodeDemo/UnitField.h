//
//  UnitField.h
//  VerificationCodeDemo
//
//  Created by dengtao on 2017/6/22.
//  Copyright © 2017年 JingXian. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


#ifdef NSFoundationVersionNumber_iOS_9_x_Max

UIKIT_EXTERN NSNotificationName const UnitFieldDidBecomeFirstResponderNotification;
UIKIT_EXTERN NSNotificationName const UnitFieldDidBecomeFirstResponderNotification;
#else
UIKIT_EXTERN NSString *const UnitFieldDidBecomeFirstResponderNotification;
UIKIT_EXTERN NSString *const UnitFieldDidBecomeFirstResponderNotification;
#endif

@class UnitField;

@protocol UnitFieldDelegate <NSObject>

@optional

- (BOOL)unitField:(UnitField *)uniField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

@end

/**
 键盘样式
 
 - KeyboardTypeNumberPad: 纯数字键盘
 - KeyboardTypeASCIICapable: ASCII 字符键盘
 */
typedef NS_ENUM(NSUInteger, KeyboardType) {
    
    KeyboardTypeNumberPad,
    KeyboardTypeASCIICapable
};

IB_DESIGNABLE
@interface UnitField : UIControl

@property (nullable, nonatomic, weak) id<UnitFieldDelegate> delegate;

/**
 保留的用户输入的字符串
 */
@property (nullable, nonatomic, copy) NSString *text;//readonly

/**
 当需要密文输入时，可以设置该值为 YES，输入文字将被圆点替代
 如：
 ┌┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈┐
 ┆ • ┆ • ┆ • ┆ • ┆       secureTextEntry is YES.
 └┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈┘
 ┌┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈┐
 ┆ 1 ┆ 2 ┆ 3 ┆ 4 ┆       secureTextEntry is NO.
 └┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈┘
 默认值为 NO.
 */
@property (nonatomic, assign, getter=isSecureTextEntry) IBInspectable BOOL secureTextEntry;

#if TARGET_INTERFACE_BUILDER
/**
 允许输入的个数。
 目前 UnitField 允许的输入单元个数区间控制在 1 ~ 8 个。任何超过该范围内的赋值行为都将被忽略。
 */
@property (nonatomic, assign) IBInspectable NSUInteger inputUnitCount;
#else
@property (nonatomic, assign, readonly) NSUInteger inputUnitCount;
#endif

#if TARGET_INTERFACE_BUILDER
@property (nonatomic, assign) IBInspectable NSInteger defaultKeyboardType;
@property (nonatomic, assign) IBInspectable NSInteger defaultReturnKeyType;
#else
@property (nonatomic, assign) KeyboardType defaultKeyboardType;       // 默认为 KeyboardTypeNumberPad。
@property (nonatomic, assign) UIReturnKeyType defaultReturnKeyType;     // 默认为 UIReturnKeyDone。
#endif


/**
 每个 Unit 之间的距离，默认为 0
 ┌┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈┐
 ┆ 1 ┆ 2 ┆ 3 ┆ 4 ┆       unitSpace is 0.
 └┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈┘
 ┌┈┈┈┐┌┈┈┈┐┌┈┈┈┐┌┈┈┈┐
 ┆ 1 ┆┆ 2 ┆┆ 3 ┆┆ 4 ┆    unitSpace is 6
 └┈┈┈┘└┈┈┈┘└┈┈┈┘└┈┈┈┘
 */
@property (nonatomic, assign) IBInspectable CGFloat unitSpace;

/**
 设置边框圆角
 ╭┈┈┈╮╭┈┈┈╮╭┈┈┈╮╭┈┈┈╮
 ┆ 1 ┆┆ 2 ┆┆ 3 ┆┆ 4 ┆    unitSpace is 6, borderRadius is 4.
 ╰┈┈┈╯╰┈┈┈╯╰┈┈┈╯╰┈┈┈╯
 ╭┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈╮
 ┆ 1 ┆ 2 ┆ 3 ┆ 4 ┆       unitSpace is 0, borderRadius is 4.
 ╰┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈╯
 */
@property (nonatomic, assign) IBInspectable CGFloat borderRadius;

/**
 设置边框宽度，默认为 1。
 */
@property (nonatomic, assign) IBInspectable CGFloat borderWidth;

/**
 设置文本字体
 */
@property (nonatomic, strong) IBInspectable UIFont *textFont;

/**
 设置文本颜色，默认为黑色。
 */
@property (null_resettable, nonatomic, strong) IBInspectable UIColor *textColor;

@property (null_resettable, nonatomic, strong) IBInspectable UIColor *tintColor;

/**
 如果需要完成一个 unit 输入后显示地指定已完成的 unit 颜色，可以设置该属性。默认为 nil。
 注意：
 该属性仅在`unitSpace`属性值大于 2 时有效。在连续模式下，不适合颜色跟踪。可以考虑使用`cursorColor`替代
 */
@property (nullable, nonatomic, strong) IBInspectable UIColor *trackTintColor;

/**
 用于提示输入的焦点所在位置，设置该值后会产生一个光标闪烁动画，如果设置为空，则不生成光标动画。
 */
@property (nullable, nonatomic, strong) IBInspectable UIColor *cursorColor;

/**
 当输入完成后，是否需要自动取消第一响应者。默认为 NO。
 */
@property (nonatomic, assign) IBInspectable BOOL autoResignFirstResponderWhenInputFinished;

- (instancetype)initWithInputUnitCount:(NSUInteger)count;

@end


NS_ASSUME_NONNULL_END

