/****************************************************************************
 
 Copyright (c) 2012      longfei zhu,Five Minutes
 
 https://github.com/zhuthesea/FMAndroidAdapter
 
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

#include "FMAndroidAdapter.h"
#include "platform/android/jni/JniHelper.h"

#define kJniPacketName "com/fminutes/FMJNIHelper"
#define kJniClassName "FMJNIHelp" // java static class name



#include <android/log.h>
#include <jni.h>


#if 1
#define  LOG_TAG    "FMAndroidAdapter"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#else
#define  LOGD(...) 
#endif

namespace   FM {
    
    FMAndroidAdapter* FMAndroidAdapter::m_singleton=NULL;
    
    
    FMAndroidAdapter* FMAndroidAdapter::initSingleton()
    {
        if(NULL==m_singleton)
        {
            m_singleton=new FMAndroidAdapter();
            
        }
        return m_singleton;
    }
    
    
    FMAndroidAdapter::FMAndroidAdapter()
    {
        
    }
    
    const char* FMAndroidAdapter::getVersion(){
        return "Android 0.0.1";
    }
    
    
    
    std::string FMAndroidAdapter::callFuncNameR(const char* methodName,const char* paramCode){
        JniMethodInfo t;
        LOGD("callFuncNameR 1");
        if (paramCode != NULL) {
            if (JniHelper::getStaticMethodInfo(t, 
                                               kJniPacketName, 
                                               "callFuncNameR",
                                               "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;")) 
            {
                
                LOGD("callFuncNameR 2_1");
                
                jstring jclassName = t.env->NewStringUTF(kJniClassName);
                jstring jmethodName = t.env->NewStringUTF(methodName);
                jstring jparamCode = t.env->NewStringUTF(paramCode);
                jstring strrs = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID,jclassName,jmethodName,jparamCode);
                t.env->DeleteLocalRef(jclassName);
                t.env->DeleteLocalRef(jmethodName);
                t.env->DeleteLocalRef(jparamCode);
                t.env->DeleteLocalRef(t.classID);
                
                return JniHelper::jstring2string(strrs);
                
                
            }
        }else{
            if (JniHelper::getStaticMethodInfo(t, 
                                               kJniPacketName, 
                                               "callFuncNameR",
                                               "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;")) 
            {
                
                LOGD("callFuncNameR 2_2");
                
                jstring jclassName = t.env->NewStringUTF(kJniClassName);
                jstring jmethodName = t.env->NewStringUTF(methodName);
                jstring strrs = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID,jclassName,jmethodName);
                t.env->DeleteLocalRef(jclassName);
                t.env->DeleteLocalRef(jmethodName);
                t.env->DeleteLocalRef(t.classID);
                
                return JniHelper::jstring2string(strrs);
                
                
            }
        }

        LOGD("callFuncNameR 3");
        return "";
    }
    
    void FMAndroidAdapter::callFuncNameV(const char* methodName,const char* paramCode){
        JniMethodInfo t;
        LOGD("callFuncNameV 1");
        if (paramCode != NULL) {
            if (JniHelper::getStaticMethodInfo(t, 
                                               kJniPacketName, 
                                               "callFuncNameV",
                                               "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V")) 
            {
                
                LOGD("callFuncNameV 2_1");
                
                jstring jclassName = t.env->NewStringUTF(kJniClassName);
                jstring jmethodName = t.env->NewStringUTF(methodName);
                jstring jparamCode = t.env->NewStringUTF(paramCode);
                
                t.env->CallStaticVoidMethod(t.classID, t.methodID,jclassName,jmethodName,jparamCode);
                
                t.env->DeleteLocalRef(jclassName);
                t.env->DeleteLocalRef(jmethodName);
                t.env->DeleteLocalRef(jparamCode);
                t.env->DeleteLocalRef(t.classID);

                
                
                
            }
        }else{
            if (JniHelper::getStaticMethodInfo(t, 
                                               kJniPacketName, 
                                               "callFuncNameV",
                                               "(Ljava/lang/String;Ljava/lang/String;)V")) 
            {
                
                LOGD("callFuncNameV 2_2");
                
                jstring jclassName = t.env->NewStringUTF(kJniClassName);
                jstring jmethodName = t.env->NewStringUTF(methodName);
                t.env->CallStaticVoidMethod(t.classID, t.methodID,jclassName,jmethodName);
                t.env->DeleteLocalRef(jclassName);
                t.env->DeleteLocalRef(jmethodName);
                t.env->DeleteLocalRef(t.classID);

            }
        }
        
        LOGD("callFuncNameR 3");
    }
    

    
    /**
     * callSynFunc not imp yet
     * return void*
     */
    
    void* FMAndroidAdapter::callSynFunc(const char* methodName,va_list args){
        JniMethodInfo t;
         LOGD("callSynFunc 1");
        if (JniHelper::getStaticMethodInfo(t, 
                                           kJniPacketName, 
                                           methodName,
                                           "(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljava/lang/Object;"))
//        if (JniHelper::getStaticMethodInfo(t, 
//                                           kJniPacketName, 
//                                           methodName,
//                                           "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;"))

        
        {
            
            LOGD("callSynFunc 2");
            
            char* ret = 0;
            
           // jstring stringArg1 = t.env->NewStringUTF("test");
            jstring strrs = (jstring)t.env->CallStaticObjectMethodV(t.classID, t.methodID,args);
           // t.env->DeleteLocalRef(stringArg1);
            t.env->DeleteLocalRef(t.classID);

            ret = (char*)JniHelper::jstring2string(strrs).c_str();
            //FM::FMPlatFormAdapter::getSingleton()->callSynFunc("invokeStaticMethod","testClassName","testParams1","testParams2",NULL);
            LOGD("ret %s",ret);
            
        }
        LOGD("callSynFunc 3");
        return (void*)"test Android callSynFunc";
    }
    
    /**
     * callASynFunc 
     * return void
     */
    
    void FMAndroidAdapter::callASynFunc(const char* methodName,const char* callBack,va_list args){
    
    }
    
    
    FMAndroidAdapter::~FMAndroidAdapter()
    {
        FMLog("~FMAndroidAdapter"); 
    }
    
}
