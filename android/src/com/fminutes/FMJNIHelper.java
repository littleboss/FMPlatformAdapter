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



package com.fminutes;   
import java.lang.reflect.Method;

import com.fminutes.guituzaipao.FMJNIHelp;
public class FMJNIHelper {
	public static native void nativecallfromjavatocpp(String methodName,String ret);//from java to cpp
	
	
	public static void callFuncNameV(String className, String methodName) throws Exception {                                  
		System.out.println("callFuncNameV 2");
		System.out.println("className "+ className);
		System.out.println("methodNamexx " + methodName);


		if (className.equals("FMJNIHelp")) {
			if (methodName.equals("getUmengOnlineConfig")){
				// FMJNIHelp.getUmengOnlineConfig(args);
			}
		}
		
		//FMJNIHelper.nativecallfromjavatocpp(methodName,className);
		
		/*
		try {
            Class c = Class.forName(className);  // call from jni crash here !???  to do
            Method[] m=c.getMethods();
            for(int i=0;i<m.length;i++)
            {
            	System.out.println("callFuncNameV 2 method " + m[i].getName());
                if(m[i].getName().equals(methodName))
                {        
                        m[i].invoke(null);
                }
            }
        } 
        catch (Exception e) {
        	System.out.println("callFuncNameV exception");
            e.printStackTrace();
        }     
        */   
	}   
	
	
	public static String callFuncNameR(String className, String methodName,
			String args) {
		
		System.out.println("callFuncNameR 2");
		System.out.println("className "+ className);
		System.out.println("methodName " + methodName);
		System.out.println("args " + args);
		
		if (className.equals("FMJNIHelp")) {
			if (methodName.equals("getUmengOnlineConfig")){
				return FMJNIHelp.getUmengOnlineConfig(args);
			}
		}
		return null;
	}
	
	public static Object callFuncNameRObject(String className, String methodName,String args) throws Exception {                                  
		System.out.println("callFuncNameR ....xxx");
		if(className == null){
			System.out.println("className isnull");
		}else{
			System.out.println("className !null");
		}
		System.out.println("className "+ className.toString());
		System.out.println("methodName " + methodName.toString());
//		Class ownerClass = Class.forName(className);    // call from jni crash here !???  to do                           
//		Class[] argsClass = null;
//		if(args != null)
//		{
//			argsClass = new Class[1];                                
//
//			for (int i = 0, j = 1; i < j; i++) {                             
//				argsClass[i] = args.getClass();                                     
//			}                   
//		}else{
//			System.out.println("args null");
//		}
//
//		Method method = ownerClass.getMethod(methodName, argsClass);               
//		System.out.println("invoke");
//		return method.invoke(null, args);                                          
		return "to do";
	}   

	
	public static void callFuncNameV(String className, String methodName, String paramCode) throws Exception {                                  
		System.out.println("callFuncNameV 1");
		System.out.println("className "+ className);
		System.out.println("methodName " + methodName);
		FMJNIHelper.callFuncNameR(className, methodName, paramCode);
	}   
	

	
	

	public static Object invokeStaticMethod(String className, String methodName) throws Exception {                                  
		System.out.println("invokeStaticMethod 1");
		System.out.println("className "+ className);
		System.out.println("methodName " + methodName);
		
//		Object[] args = null;
//		Class ownerClass = Class.forName(className);              // call from jni crash here !???  to do                 
//		Class[] argsClass = new Class[args.length];                                
//    
//		for (int i = 0, j = args.length; i < j; i++) {                             
//			argsClass[i] = args[i].getClass();                                     
//		}                                                                          
//
//		Method method = ownerClass.getMethod(methodName, argsClass);               
//
//		return method.invoke(null, args);                                          
		return "to do";
	}   
	
	public static Object invokeStaticMethod(String className, String methodName,Object[] args) throws Exception {                                  
		System.out.println("invokeStaticMethod 2");
		System.out.println("className "+ className);
		System.out.println("methodName " + methodName);
//		Class ownerClass = Class.forName(className);         // call from jni crash here !???  to do                      
//		Class[] argsClass = new Class[args.length];                                
//
//		for (int i = 0, j = args.length; i < j; i++) {                             
//			argsClass[i] = args[i].getClass();                                     
//		}                                                                          
//
//		Method method = ownerClass.getMethod(methodName, argsClass);               
//
//		return method.invoke(null, args);                                          
		return "to do";
   
	}   
	
	
	public static Object invokeStaticMethod(String className, String methodName,String[] args) throws Exception {                                  
		System.out.println("invokeStaticMethod 3....xxx");
		if(className == null){
			System.out.println("isnull");
		}else{
			System.out.println("!null");
		}
		System.out.println("className "+ className.toString());
		System.out.println("methodName " + methodName.toString());
//		Class ownerClass = Class.forName(className);                 // call from jni crash here !???  to do              
//		Class[] argsClass = new Class[args.length];                                
//
//		for (int i = 0, j = args.length; i < j; i++) {                             
//			argsClass[i] = args[i].getClass();                                     
//		}                                                                          
//
//		Method method = ownerClass.getMethod(methodName, argsClass);               
//
//		return method.invoke(null, args);                                          
		return "to do";
	}   

}
