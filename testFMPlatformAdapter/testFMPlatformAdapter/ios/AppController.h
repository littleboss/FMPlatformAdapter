//
//  testFMPlatformAdapterAppController.h
//  testFMPlatformAdapter
//
//  Created by longfei.zhu on 12-5-4.
//  Copyright Five Minutes Inc. 2012年. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController	*viewController;
}

@end

