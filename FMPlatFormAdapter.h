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

#ifndef _FMPlatFormAdapter_h_
#define _FMPlatFormAdapter_h_

#include "cocos2d.h"
#include "FMDefine.h"
USING_NS_CC;

namespace   FM {
    class FMPlatFormAdapter
    {
    public:
        
        
        /**
         *   get FMPlatFormAdapter version
         */
        virtual const char* getVersion();
        
        
        
        /**
         *@param methodName
         *@param paramCode
         *@return string
         */
        virtual std::string callFuncNameR(const char* methodName,const char* paramCode);
        virtual void callFuncNameV(const char* methodName,const char* paramCode);
        
        virtual std::string callProcNameR(const char* methodName);
        virtual void callProcNameV(const char* methodName);
        
        
        
        
        
        
        
        
        /**
         * callSynFunc not imp yet
         *@return void*
         */
        virtual void* callSynFunc(const char* methodName,const char* paramCodes,...);
        
        /**
         * callASynFunc not imp yet
         * return void
         */
        virtual void callASynFunc(const char* methodName,const char* callBack,const char* paramCodes,...);
        
    public:
        static FMPlatFormAdapter* getSingleton()
        {
            if(NULL==m_singleton)
            {
                return initSingleton();
            }
            return m_singleton;
        }
        ~FMPlatFormAdapter();
    private:
        FMPlatFormAdapter();
    private:
        static FMPlatFormAdapter* initSingleton();
        static FMPlatFormAdapter* m_singleton;        
    };
}//namespace   FM 

#endif
