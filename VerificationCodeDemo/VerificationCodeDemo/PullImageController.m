//
//  PullImageController.m
//  VerificationCodeDemo
//
//  Created by dengtao on 2017/6/22.
//  Copyright © 2017年 JingXian. All rights reserved.
//

#import "PullImageController.h"

#define kWidth    self.view.frame.size.width
#define kHeight   self.view.frame.size.height

@interface PullImageController ()<UIScrollViewDelegate>

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UIImageView  *imageView;
@property (nonatomic, strong) UIButton     *button;
@property (nonatomic, assign) CGFloat       imageViewHeight;

@end

@implementation PullImageController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self.view addSubview:self.scrollView];
    [self.scrollView addSubview:self.imageView];
    [self.scrollView addSubview:self.button];
}


#pragma mark - Action
- (void)goBackAction{

    [self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - UIScrollViewDelegate

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    // 偏移量y的变化
    CGFloat dy = scrollView.contentOffset.y;
    NSLog(@"%f", dy);
    // 判断拉倒方向
//    if (dy < 0) {
        // 利用公式
        self.imageView.frame =CGRectMake(0, dy,kWidth, self.imageViewHeight - dy);
//    }
}

#pragma mark - Setter/Getter
- (UIScrollView *)scrollView{

    if (_scrollView == nil) {
        
        _scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, kWidth, kHeight)];
        _scrollView.backgroundColor = [UIColor grayColor];
        _scrollView.contentSize = CGSizeMake(0,kHeight + 1);
        _scrollView.delegate = self;
    }
    return _scrollView;
}

- (UIImageView *)imageView{

    if (_imageView == nil) {
        
        _imageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, kWidth, 310 * kWidth / 650)];
        _imageView.image = [UIImage imageNamed:@"2"];
        self.imageViewHeight = _imageView.frame.size.height;
    }
    return _imageView;
}


- (UIButton *)button{

    if (_button == nil) {
        
        _button = [[UIButton alloc] initWithFrame:CGRectMake(15, self.scrollView.frame.size.height - 60, kWidth - 30, 40)];
        _button.layer.cornerRadius = 8;
        _button.backgroundColor = [UIColor redColor];
        [_button setTitle:@"返回" forState:UIControlStateNormal];
        [_button addTarget:self action:@selector(goBackAction) forControlEvents:UIControlEventTouchUpInside];
        
    }
    return _button;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
