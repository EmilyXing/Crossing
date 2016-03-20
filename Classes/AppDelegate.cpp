#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    
    // singleton 每次get唯一实例 导演一个就够
    auto director = Director::getInstance();
    
    // 背景的布 OpenGL View 如果没有 create 如果有 get
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("Xing", Rect(0, 0, 960, 640));
        director->setOpenGLView(glview);
    }
    
    // get之后 设置分辨率 以及屏幕适配
    director->getOpenGLView()->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);


    // 显示debug数据 记得app发布时设置成false
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    // 每秒的帧数 -> 让画面动起来
    director->setAnimationInterval(1.0 / 60);
    
    // 相当于include资源文件的搜索路径
    FileUtils::getInstance()->addSearchPath("res");
    

    // create a scene. it's an autorelease object
    // 创建第一个scene  auto scene = MyClass::create();
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
