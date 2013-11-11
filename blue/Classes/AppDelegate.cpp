#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "CCBReader.h"
#include "scenes/scenes_manager.h"

USING_NS_CC;
using namespace CocosDenshion;
using namespace cocos2d::extension;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    pDirector->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA8888);
    
    CCSize designSize = CCSizeMake(480, 320);
    CCSize resourceSize = CCSizeMake(480, 320);
    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    
    std::vector<std::string> resDirOrders;
    
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
    if (platform == kTargetIphone || platform == kTargetIpad)
    {
        std::vector<std::string> searchPaths = CCFileUtils::sharedFileUtils()->getSearchPaths();
        searchPaths.insert(searchPaths.begin(), "ccb-ios");
        CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
        
        if (screenSize.height > 768)
        {
            resourceSize = CCSizeMake(2048, 1536);
            resDirOrders.push_back("resources-ipadhd");
        }
        else if (screenSize.height > 640)
        {
            resourceSize = CCSizeMake(1536, 768);
            resDirOrders.push_back("resources-ipad");
        }else if (screenSize.width > 480)
        {
            resourceSize = CCSizeMake(960, 640);
            resDirOrders.push_back("resources-iphonehd");
        }
        else
        {
            resDirOrders.push_back("resources-iphone");
        }
    }
    
    CCFileUtils::sharedFileUtils()->setSearchResolutionsOrder(resDirOrders);
    
    pDirector->setContentScaleFactor(resourceSize.width/designSize.width);
    
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionNoBorder);
    
    // Then add the scene to the stack. The director will run it when it automatically when the view is displayed.
    pDirector->runWithScene(loadMainMenu());
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
