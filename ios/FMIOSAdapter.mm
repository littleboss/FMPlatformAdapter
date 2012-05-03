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

#include "FMIOSAdapter.h"
#include "FMIOSBridge.h"

namespace   FM {
    
    FMIOSAdapter* FMIOSAdapter::m_singleton=NULL;
    static FMIOSBridge* s_FMIOSBridge = NULL;

    FMIOSAdapter* FMIOSAdapter::initSingleton()
    {
        if(NULL==m_singleton)
        {
            m_singleton = new FMIOSAdapter();
            s_FMIOSBridge = [[FMIOSBridge alloc] init];
        }
        return m_singleton;
    }
    
    
    FMIOSAdapter::FMIOSAdapter()
    {
        
    }
    
    const char* FMIOSAdapter::getVersion(){
        return "IOS 0.0.1";
    }
    
    /**
     * callSynFunc 
     * return void*
     */
    
    void* FMIOSAdapter::callSynFunc(const char* methodName,va_list args){
        return (void*)"ios to do";
    }
    
    /**
     * callASynFunc 
     * return void
     */
    
    void FMIOSAdapter::callASynFunc(const char* methodName,const char* callBack,va_list args){
//        [s_FMIOSBridge callFunc:[NSString stringWithUTF8String:methodName] paramCode:[NSString stringWithUTF8String:paramCode] callBack:[NSString stringWithUTF8String:callBack]];
    }
    

    
    FMIOSAdapter::~FMIOSAdapter()
    {
        FMLog("~FMIOSAdapter");
        [s_FMIOSBridge release];
    }
}
