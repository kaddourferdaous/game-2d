#include "pausemenu.h"
#include "hellowordscene.h"


USING_NS_CC;

Scene* pausemenu::createscene()
{

    auto scene = scene::create();

    auto layer = pausemenu::create();

    scene->addChild(layer);
    return scene;
}


bool pausemenu::init()
{

    if (!Layer::init())
    {
        return false;
    }

}
Size visibleSize = Director::getInstance()->getVisibleSize();
Point origin = Director::getInstance()->getVisibleOrigin();

void pausemenu::Resume(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}

void pausemenu::GoTohellowordscene(cocos2d::Ref* pSender)
{
    auto scene = helloword::createscene();

    Director::getInstance()->popscene();
    Director::getInstance()->replaceScene(scene);
}

void pausemenu::Retry(cocos2d::Ref* pSender)
{
    auto scene = pausemenu::createscene();

    Director::getInstance()->popScene();
    Director::getInstance()->replacescene(scene);
}

