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
#include "cocos2d.h"
#include <jni.h>
#include "FMDefine.h"
using namespace cocos2d;
extern "C"
{

    void Java_com_fminutes_FMJNIHelper_nativecallfromjavatocpp(JNIEnv*  env, jobject thiz,jstring methodName,jstring ret)
	{

        FMLog("nativecallfromjavatocpp");
        
        jboolean isCopy = 0;
        const char* pszmethodName = env->GetStringUTFChars(methodName, &isCopy);
        CCMessageBox(pszmethodName, "call from java 1");
        if (isCopy) 
        {
            env->ReleaseStringUTFChars(methodName, pszmethodName);
        }
        isCopy = 0;
        const char* pszret = env->GetStringUTFChars(ret, &isCopy);
        CCMessageBox(pszret, "call from java 2");
        if (isCopy) 
        {
            env->ReleaseStringUTFChars(ret, pszret);
        }

        CCMessageBox(pszmethodName, pszret);
	}
    


}
