//
//  ViewController.m
//  VerificationCodeDemo
//
//  Created by dengtao on 2017/6/22.
//  Copyright © 2017年 JingXian. All rights reserved.
//

#import "ViewController.h"
#import "UnitField.h"

@interface ViewController ()<UnitFieldDelegate>

@property (nonatomic, strong) UnitField   *smsCodeUnitField;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor groupTableViewBackgroundColor];
    [self.view addSubview:self.smsCodeUnitField];
}

- (UnitField *)smsCodeUnitField{

    if (_smsCodeUnitField == nil) {
        
        CGFloat width = self.view.frame.size.width;
        
        NSInteger count = 6;
        CGFloat space = 15;
        
        _smsCodeUnitField = [[UnitField alloc] initWithInputUnitCount:count];
        _smsCodeUnitField.frame = CGRectMake(space, 100, width - space * 2, 1);
        _smsCodeUnitField.textFont = [UIFont boldSystemFontOfSize:36];
        
        _smsCodeUnitField.textColor = [UIColor greenColor];
        _smsCodeUnitField.tintColor = [UIColor redColor];//未输入边框颜色
        _smsCodeUnitField.trackTintColor = [UIColor greenColor];//输入边框颜色
        _smsCodeUnitField.cursorColor = [UIColor purpleColor];//当前光标颜色
        _smsCodeUnitField.delegate = self;
        _smsCodeUnitField.unitSpace = space;//输入框间距
        _smsCodeUnitField.borderRadius = 4;
        [_smsCodeUnitField sizeToFit];
        [_smsCodeUnitField addTarget:self action:@selector(unitFieldEditingChanged:) forControlEvents:UIControlEventEditingChanged];
    }
    return _smsCodeUnitField;
}

#pragma mark - UnitField
- (BOOL)unitField:(UnitField *)uniField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
    NSString *text = [uniField.text stringByReplacingCharactersInRange:range withString:string];
    NSLog(@"输入内容：%@",text);
    return YES;
}

- (void)unitFieldEditingChanged:(UnitField *)sender {
    //四位验证码 输入完毕 验证验证码
    if (sender.text.length == 6) {
        //清空输入框
        NSLog(@"输入完成...%@",sender.text);
        [_smsCodeUnitField resignFirstResponder];
    }
}

- (void)unitFieldEditingDidBegin:(id)sender {
    NSLog(@"+++++++++++++++");
}

- (void)unitFieldEditingDidEnd:(id)sender {
    NSLog(@"-------------");
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
