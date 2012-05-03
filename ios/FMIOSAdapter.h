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

#ifndef _FMIOSAdapter_h
#define _FMIOSAdapter_h


#include "FMDefine.h"
namespace   FM {

class FMIOSAdapter
{
public:
    /**
     *   get FMPlatFormAdapter version
     */
    virtual const char* getVersion();
    
    
    virtual std::string callFuncNameR(const char* methodName,const char* paramCode);
    virtual void callFuncNameV(const char* methodName,const char* paramCode);
    
    
    
    /**
     * callSynFunc 
     * return void*
     */
    virtual void* callSynFunc(const char* methodName,va_list args);
    
    /**
     * callASynFunc 
     * return void
     */
    virtual void callASynFunc(const char* methodName,const char* callBack,va_list args);
public:
    static FMIOSAdapter* getSingleton()
    {
        if(NULL==m_singleton)
        {
            return initSingleton();
        }
        return m_singleton;
    }
    ~FMIOSAdapter();
private:
    FMIOSAdapter();
private:
    static FMIOSAdapter* initSingleton();
    static FMIOSAdapter* m_singleton;        
};

}
#endif
