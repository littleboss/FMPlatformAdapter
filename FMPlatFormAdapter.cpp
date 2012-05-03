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

#include "FMPlatFormAdapter.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    #include "FMIOSAdapter.h"
#endif  // CC_PLATFORM_IOS

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include "FMAndroidAdapter.h"
#endif  // CC_PLATFORM_ANDROID
namespace   FM {
    
    FMPlatFormAdapter* FMPlatFormAdapter::m_singleton=NULL;
    
    
    FMPlatFormAdapter* FMPlatFormAdapter::initSingleton()
    {
        if(NULL==m_singleton)
        {
            m_singleton=new FMPlatFormAdapter();
            
        }
        return m_singleton;
    }
    
    
    FMPlatFormAdapter::FMPlatFormAdapter()
    {
        
    }
    
    const char* FMPlatFormAdapter::getVersion(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        return FMIOSAdapter::getSingleton()->getVersion();
#endif  // CC_PLATFORM_IOS
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        return FMAndroidAdapter::getSingleton()->getVersion();
#endif  // CC_PLATFORM_ANDROID    
    }
    
    
    std::string FMPlatFormAdapter::callProcNameR(const char* methodName){
        return callFuncNameR(methodName,NULL);
    }
    
    void FMPlatFormAdapter::callProcNameV(const char* methodName){
        callFuncNameV(methodName,NULL);
    }
    
    
    std::string FMPlatFormAdapter::callFuncNameR(const char* methodName,const char* paramCode){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        return FMIOSAdapter::getSingleton()->callFuncNameR(methodName,paramCode);
#endif  // CC_PLATFORM_IOS
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        return FMAndroidAdapter::getSingleton()->getVersion();
#endif  // CC_PLATFORM_ANDROID 
    }
    
    void FMPlatFormAdapter::callFuncNameV(const char* methodName,const char* paramCode){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        
        FMIOSAdapter::getSingleton()->callFuncNameV(methodName,paramCode);
#endif  // CC_PLATFORM_IOS
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        
        FMAndroidAdapter::getSingleton()->callFuncNameV(methodName,paramCode);
#endif  // CC_PLATFORM_ANDROID 
        
    }

    /**
     * callSynFunc 
     * return void*
     */
    
    void* FMPlatFormAdapter::callSynFunc(const char* methodName,const char* paramCodes,...){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        va_list args;
		va_start(args,paramCodes);
        void* v = FMIOSAdapter::getSingleton()->callSynFunc(methodName,args);
        va_end(args);
        return v;
#endif  // CC_PLATFORM_IOS
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        va_list args;
		va_start(args,paramCodes);
        void* v = FMAndroidAdapter::getSingleton()->callSynFunc(methodName,args);
        va_end(args);
        return v;
#endif  // CC_PLATFORM_ANDROID 
    }
    
    /**
     * callASynFunc 
     * return void
     */
    
    void FMPlatFormAdapter::callASynFunc(const char* methodName,const char* callBack,const char* paramCodes,...){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        va_list args;
		va_start(args,paramCodes);
        FMIOSAdapter::getSingleton()->callASynFunc(methodName,callBack,args);
        va_end(args);
#endif  // CC_PLATFORM_IOS
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        va_list args;
		va_start(args,paramCodes);
        FMAndroidAdapter::getSingleton()->callASynFunc(methodName,callBack,args);
        va_end(args);
#endif  // CC_PLATFORM_ANDROID 
    }
    
    
    FMPlatFormAdapter::~FMPlatFormAdapter()
    {
        FMLog("~FMPlatFormAdapter");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        delete FMIOSAdapter::getSingleton();
#endif  // CC_PLATFORM_IOS
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        delete FMAndroidAdapter::getSingleton();
#endif  // CC_PLATFORM_ANDROID    
    }
    
    
    
    
}
