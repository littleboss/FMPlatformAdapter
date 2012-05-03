/****************************************************************************
 
 Copyright (c) 2012      longfei zhu,Five Minutes
 
 https://github.com/zhuthesea/FMPlatformAdapter
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#import "FMIOSBridge.h"


//static const int kMaxLogLen = 16*1024;


@implementation FMIOSBridge


-(const char*)callFuncNameR:(const char*) methodName paramCode:(const char*)paramCode{

    // to do
    return "to do";
    
}


-(void)callFuncNameV:(const char*) methodName paramCode:(const char*)paramCode{
    NSString* performaction = [NSString stringWithUTF8String:methodName];
    if (paramCode == NULL) {
        if ([performaction length] >0) {
            SEL sel=sel_registerName(methodName);
            if ([self respondsToSelector:sel]) {
                [self performSelector:sel];
            }  
        }else{
            NSLog(@"methodName null1");
            assert(false);
        }
    }else{
        if ([performaction length] >0) {
            SEL sel=sel_registerName([[NSString stringWithFormat:@"%@:",methodName] UTF8String]);
            if ([self respondsToSelector:sel]) {
                [self performSelector:sel withObject:[NSString stringWithUTF8String:paramCode]];
            }  
        }else{
            NSLog(@"methodName null2");
            assert(false);
        }
    }
}


-(const char*)getVersion{

    return [[NSString stringWithUTF8String:"v0.1"] UTF8String];
}


/**
 * callSynFunc 
 * return void*
 */

-(void*) callSynFunc:(const char*) methodName paramCodes:(va_list)paramCodes{
    return "to do";

}

/**
 * callASynFunc 
 * return void
 */
-(void) callASynFunc:(const char*) methodName callBack:(const char*)callBack paramCodes:(va_list)paramCodes{


}

@end
