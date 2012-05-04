/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2009      Jason Booth
Copyright (c) 2009      Robert J Payne
Copyright (c) 2011      Zynga Inc.

http://www.cocos2d-x.org

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

#include "cocoa/CCNS.h"
#include "ccMacros.h"
#include "CCTextureCache.h"
#include "CCSpriteFrameCache.h"
#include "CCSpriteFrame.h"
#include "CCSprite.h"
#include "support/TransformUtils.h"
#include "CCFileUtils.h"
#include "CCString.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "cocos2d.h"
#include <jni.h>
#include <android/log.h>
#ifndef LOG_TAG
#define  LOG_TAG    "FMRainBow_Android"
#endif

//#if DEBUG
//#define //FMLog(format, ...)      CCLOG(format, ##__VA_ARGS__)
#define FMLog(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
//#else
//    #define //FMLog(...) 
//#endif
#endif
namespace   cocos2d {

static CCSpriteFrameCache *pSharedSpriteFrameCache = NULL;

CCSpriteFrameCache* CCSpriteFrameCache::sharedSpriteFrameCache(void)
{
	if (! pSharedSpriteFrameCache)
	{
		pSharedSpriteFrameCache = new CCSpriteFrameCache();
        pSharedSpriteFrameCache->init();
	}

	return pSharedSpriteFrameCache;
}

void CCSpriteFrameCache::purgeSharedSpriteFrameCache(void)
{
	CC_SAFE_RELEASE_NULL(pSharedSpriteFrameCache);
}

bool CCSpriteFrameCache::init(void)
{
	m_pSpriteFrames= new CCDictionary<std::string, CCSpriteFrame*>();
	m_pSpriteFramesAliases = new CCDictionary<std::string, CCString*>();
	return true;
}

CCSpriteFrameCache::~CCSpriteFrameCache(void)
{
	CC_SAFE_RELEASE(m_pSpriteFrames);
	CC_SAFE_RELEASE(m_pSpriteFramesAliases);
}

void CCSpriteFrameCache::addSpriteFramesWithDictionary(CCDictionary<std::string, CCObject*> *dictionary, CCTexture2D *pobTexture)
{
	/*
	Supported Zwoptex Formats:

	ZWTCoordinatesFormatOptionXMLLegacy = 0, // Flash Version
	ZWTCoordinatesFormatOptionXML1_0 = 1, // Desktop Version 0.0 - 0.4b
	ZWTCoordinatesFormatOptionXML1_1 = 2, // Desktop Version 1.0.0 - 1.0.1
	ZWTCoordinatesFormatOptionXML1_2 = 3, // Desktop Version 1.0.2+
	*/
    if (dictionary) {
        //FMLog("has dictionary");
    }else{
        //FMLog("not has dictionary");
    }
    
    //FMLog("addSpriteFramesWithDictionary 1fuck");
    
    std::string test_key = "";
	CCDictionary<std::string, CCObject*> *test_frameDict = NULL;
	while( (test_frameDict = (CCDictionary<std::string, CCObject*>*)dictionary->next(&test_key)) )
	{
        //FMLog("test_key %s",test_key.c_str());
    }
    
    
	CCDictionary<std::string, CCObject*> *metadataDict = (CCDictionary<std::string, CCObject*>*)dictionary->objectForKey(std::string("metadata"));
     //FMLog("addSpriteFramesWithDictionary 2fuck");
	CCDictionary<std::string, CCObject*> *framesDict = (CCDictionary<std::string, CCObject*>*)dictionary->objectForKey(std::string("frames"));
     //FMLog("addSpriteFramesWithDictionary 3fuck");
	int format = 0;
     //FMLog("addSpriteFramesWithDictionary 1_1");
	// get the format
	if(metadataDict != NULL) 
	{
		format = atoi(valueForKey("format", metadataDict));
	}
    //FMLog("addSpriteFramesWithDictionary 1_1 %d",format);
	// check the format
	CCAssert(format >=0 && format <= 3, "");

	framesDict->begin();
	std::string key = "";
	CCDictionary<std::string, CCObject*> *frameDict = NULL;
	while( (frameDict = (CCDictionary<std::string, CCObject*>*)framesDict->next(&key)) )
	{
		CCSpriteFrame *spriteFrame = m_pSpriteFrames->objectForKey(key);
		if (spriteFrame)
		{
			continue;
		}
		
		if(format == 0) 
		{
			float x = (float)atof(valueForKey("x", frameDict));
			float y = (float)atof(valueForKey("y", frameDict));
			float w = (float)atof(valueForKey("width", frameDict));
			float h = (float)atof(valueForKey("height", frameDict));
			float ox = (float)atof(valueForKey("offsetX", frameDict));
			float oy = (float)atof(valueForKey("offsetY", frameDict));
			int ow = atoi(valueForKey("originalWidth", frameDict));
			int oh = atoi(valueForKey("originalHeight", frameDict));
			// check ow/oh
			if(!ow || !oh)
			{
				CCLOG("cocos2d: WARNING: originalWidth/Height not found on the CCSpriteFrame. AnchorPoint won't work as expected. Regenrate the .plist");
			}
			// abs ow/oh
			ow = abs(ow);
			oh = abs(oh);
			// create frame
			spriteFrame = new CCSpriteFrame();
			spriteFrame->initWithTexture(pobTexture, 
				                        CCRectMake(x, y, w, h), 
										false,
                                        CCPointMake(ox, oy),
                                        CCSizeMake((float)ow, (float)oh)
										);
		} 
		else if(format == 1 || format == 2) 
		{
			CCRect frame = CCRectFromString(valueForKey("frame", frameDict));
			bool rotated = false;

			// rotation
			if (format == 2)
			{
				rotated = atoi(valueForKey("rotated", frameDict)) == 0 ? false : true;
			}
             //FMLog("addSpriteFramesWithDictionary 1_2 %d",format);
			CCPoint offset = CCPointFromString(valueForKey("offset", frameDict));
			CCSize sourceSize = CCSizeFromString(valueForKey("sourceSize", frameDict));

			// create frame
			spriteFrame = new CCSpriteFrame();
			spriteFrame->initWithTexture(pobTexture, 
				frame,
				rotated,
				offset,
				sourceSize
				);
            //FMLog("addSpriteFramesWithDictionary 1_3 %d",format);
		} else
		if (format == 3)
		{
			// get values
			CCSize spriteSize = CCSizeFromString(valueForKey("spriteSize", frameDict));
			CCPoint spriteOffset = CCPointFromString(valueForKey("spriteOffset", frameDict));
			CCSize spriteSourceSize = CCSizeFromString(valueForKey("spriteSourceSize", frameDict));
			CCRect textureRect = CCRectFromString(valueForKey("textureRect", frameDict));
            bool textureRotated = atoi(valueForKey("textureRotated", frameDict)) == 0 ? false : true;

			// get aliases
			CCMutableArray<CCString*> *aliases = (CCMutableArray<CCString*> *) (frameDict->objectForKey(std::string("aliases")));
            CCMutableArray<CCString*>::CCMutableArrayIterator iter;

            CCString * frameKey = new CCString(key.c_str());
            for (iter = aliases->begin(); iter != aliases->end(); ++iter)
            {
                std::string oneAlias = ((CCString*) (*iter))->m_sString;
                if (m_pSpriteFramesAliases->objectForKey(oneAlias))
                {
                    CCLOG("cocos2d: WARNING: an alias with name %s already exists", oneAlias.c_str());
                }

                m_pSpriteFramesAliases->setObject(frameKey, oneAlias);
            }
            frameKey->release();
            // create frame
            spriteFrame = new CCSpriteFrame();
            spriteFrame->initWithTexture(pobTexture,
                            CCRectMake(textureRect.origin.x, textureRect.origin.y, spriteSize.width, spriteSize.height),
                            textureRotated,
                            spriteOffset,
                            spriteSourceSize);
		}
         //FMLog("addSpriteFramesWithDictionary 2");
		// add sprite frame
		m_pSpriteFrames->setObject(spriteFrame, key);
		spriteFrame->release();
         //FMLog("addSpriteFramesWithDictionary 3");
	}
}

void CCSpriteFrameCache::addSpriteFramesWithFile(const char *pszPlist, CCTexture2D *pobTexture)
{
     //FMLog("addSpriteFramesWithFile 3 %s",pszPlist);
	const char *pszPath = CCFileUtils::fullPathFromRelativePath(pszPlist);
    //FMLog("addSpriteFramesWithFile 3_1 %s",pszPath);
	CCDictionary<std::string, CCObject*> *dict = CCFileUtils::dictionaryWithContentsOfFileThreadSafe(pszPath);
    //CCDictionary<std::string, CCObject*> *dict = CCFileUtils::dictionaryWithContentsOfFile(pszPath);
    if (dict) {
        //FMLog("addSpriteFramesWithFile OK");
    }else{
        //FMLog("addSpriteFramesWithFile not OK");
    }
     
	addSpriteFramesWithDictionary(dict, pobTexture);
     //FMLog("addSpriteFramesWithFile 5");
	dict->release();
     //FMLog("addSpriteFramesWithFile 6");
}

void CCSpriteFrameCache::addSpriteFramesWithFile(const char* plist, const char* textureFileName)
{
	CCAssert(textureFileName, "texture name should not be null");
	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(textureFileName);

	if (texture)
	{
        //FMLog("addSpriteFramesWithFile 1");
		addSpriteFramesWithFile(plist, texture);
	}
	else
	{
         //FMLog("addSpriteFramesWithFile 2");
		CCLOG("cocos2d: CCSpriteFrameCache: couldn't load texture file. File not found %s", textureFileName);
	}
}

void CCSpriteFrameCache::addSpriteFramesWithFile(const char *pszPlist)
{
	const char *pszPath = CCFileUtils::fullPathFromRelativePath(pszPlist);
	CCDictionary<std::string, CCObject*> *dict = CCFileUtils::dictionaryWithContentsOfFileThreadSafe(pszPath);
	
	string texturePath("");

	CCDictionary<std::string, CCObject*>* metadataDict = (CCDictionary<std::string, CCObject*>*)dict->objectForKey(string("metadata"));
    if (metadataDict)
	{
		// try to read  texture file name from meta data
		texturePath = string(valueForKey("textureFileName", metadataDict));
	}

	if (! texturePath.empty())
	{
		// build texture path relative to plist file
        texturePath = CCFileUtils::fullPathFromRelativeFile(texturePath.c_str(), pszPath);
	}
	else
	{
		// build texture path by replacing file extension
        texturePath = pszPath;

		// remove .xxx
		size_t startPos = texturePath.find_last_of("."); 
		texturePath = texturePath.erase(startPos);

		// append .png
		texturePath = texturePath.append(".png");

		CCLOG("cocos2d: CCSpriteFrameCache: Trying to use file %s as texture", texturePath.c_str());
	}

	CCTexture2D *pTexture = CCTextureCache::sharedTextureCache()->addImage(texturePath.c_str());

	if (pTexture)
	{
        addSpriteFramesWithDictionary(dict, pTexture);
	}
	else
	{
		CCLOG("cocos2d: CCSpriteFrameCache: Couldn't load texture");
	}

	dict->release();
}

void CCSpriteFrameCache::addSpriteFrame(CCSpriteFrame *pobFrame, const char *pszFrameName)
{
	m_pSpriteFrames->setObject(pobFrame, std::string(pszFrameName));
}

void CCSpriteFrameCache::removeSpriteFrames(void)
{
	m_pSpriteFrames->removeAllObjects();
	m_pSpriteFramesAliases->removeAllObjects();
}

void CCSpriteFrameCache::removeUnusedSpriteFrames(void)
{
	m_pSpriteFrames->begin();
	std::string key = "";
	CCSpriteFrame *spriteFrame = NULL;
	while( (spriteFrame = m_pSpriteFrames->next(&key)) )
	{
		if( spriteFrame->retainCount() == 1 ) 
		{
			CCLOG("cocos2d: CCSpriteFrameCache: removing unused frame: %s", key.c_str());
			m_pSpriteFrames->removeObjectForKey(key);
		}
	}
	m_pSpriteFrames->end();
}


void CCSpriteFrameCache::removeSpriteFrameByName(const char *pszName)
{
	// explicit nil handling
	if( ! pszName )
	{
		return;
	}

	// Is this an alias ?
	CCString *key = (CCString*)m_pSpriteFramesAliases->objectForKey(string(pszName));

	if (key)
	{
        m_pSpriteFrames->removeObjectForKey(key->m_sString);
		m_pSpriteFramesAliases->removeObjectForKey(key->m_sString);
	}
	else
	{
        m_pSpriteFrames->removeObjectForKey(std::string(pszName));
	}
}

void CCSpriteFrameCache::removeSpriteFramesFromFile(const char* plist)
{
	const char* path = CCFileUtils::fullPathFromRelativePath(plist);
	CCDictionary<std::string, CCObject*>* dict = CCFileUtils::dictionaryWithContentsOfFileThreadSafe(path);

	removeSpriteFramesFromDictionary((CCDictionary<std::string, CCSpriteFrame*>*)dict);

	dict->release();
}

void CCSpriteFrameCache::removeSpriteFramesFromDictionary(CCDictionary<std::string, CCSpriteFrame*> *dictionary)
{
	CCDictionary<std::string, CCObject*>* framesDict = (CCDictionary<std::string, CCObject*>*)dictionary->objectForKey(string("frames"));
	vector<string> keysToRemove;

	framesDict->begin();
	std::string key = "";
	CCDictionary<std::string, CCObject*> *frameDict = NULL;
	while( (frameDict = (CCDictionary<std::string, CCObject*>*)framesDict->next(&key)) )
	{
		if (m_pSpriteFrames->objectForKey(key))
		{
			keysToRemove.push_back(key);
		}
	}
	framesDict->end();

	vector<string>::iterator iter;
	for (iter = keysToRemove.begin(); iter != keysToRemove.end(); ++iter)
	{
		m_pSpriteFrames->removeObjectForKey(*iter);
	}
}

void CCSpriteFrameCache::removeSpriteFramesFromTexture(CCTexture2D* texture)
{
	vector<string> keysToRemove;

	m_pSpriteFrames->begin();
	std::string key = "";
	CCDictionary<std::string, CCObject*> *frameDict = NULL;
	while( (frameDict = (CCDictionary<std::string, CCObject*>*)m_pSpriteFrames->next(&key)) )
	{
		CCSpriteFrame *frame = m_pSpriteFrames->objectForKey(key);
		if (frame && (frame->getTexture() == texture))
		{
			keysToRemove.push_back(key);
		}
	}
	m_pSpriteFrames->end();

	vector<string>::iterator iter;
	for (iter = keysToRemove.begin(); iter != keysToRemove.end(); ++iter)
	{
		m_pSpriteFrames->removeObjectForKey(*iter);
	}
}

CCSpriteFrame* CCSpriteFrameCache::spriteFrameByName(const char *pszName)
{
	CCSpriteFrame *frame = m_pSpriteFrames->objectForKey(std::string(pszName));
	if (! frame)
	{
		// try alias dictionary
		CCString *key = (CCString*)m_pSpriteFramesAliases->objectForKey(string(pszName));  
		if (key)
		{
			frame = m_pSpriteFrames->objectForKey(key->m_sString);
			if (! frame)
			{
				CCLOG("cocos2d: CCSpriteFrameCahce: Frame '%s' not found", pszName);
			}
		}
	}
	return frame;
}

const char * CCSpriteFrameCache::valueForKey(const char *key, CCDictionary<std::string, CCObject*> *dict)
{
	if (dict)
	{
		CCString *pString = (CCString*)dict->objectForKey(std::string(key));
		return pString ? pString->m_sString.c_str() : "";
	}
	return "";
}
}//namespace   cocos2d 
