//
//  AirPurificationController.h
//  AirPurification
//
//  Created by virgil on 15/8/31.
//  Copyright (c) 2015年 xpg. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IoTMainController.h"


#define DATA_CMD                        @"cmd"                  //命令
#define Data_Switch @"ON_OFF"
#define Data_Air_Volume @"Air_Volume"
#define Data_Cartridge_life @"Cartridge_life"
#define Data_PM2_5   @"PM2_5"
#define Data_humidity @"humidity"
#define Data_model @"model"
#define Data_temperature @"temperature"
#define Data_AQI @"AQI"


#define DebugAir  0

@protocol PredictScrollViewDelegate;

@interface AirPurificationController : UIViewController<XPGWifiDeviceDelegate,PredictScrollViewDelegate>

//用于切换设备
@property (nonatomic, strong) XPGWifiDevice *device;

//数据信息
@property (nonatomic, assign) NSInteger onTiming;       //开机定时
@property (nonatomic, assign) NSInteger airSensitivity; //空气灵敏度
@property (nonatomic, assign) NSInteger filterLife;     //滤网寿命

//写入数据接口
- (void)writeDataPoint:(IoTDeviceDataPoint)dataPoint value:(id)value;

- (id)initWithDevice:(XPGWifiDevice *)device;

//获取当前实例
+ (AirPurificationController *)currentController;

@end
