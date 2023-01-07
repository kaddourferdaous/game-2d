#include "gameoverscene.h"
#include "hellowordscene.h"
#include "pausemenue.h"

USING_NS_CC;

scene* gameover::createscene()

    auto scene = Scene::create();
    auto layer = pausemenu::create();

  
    scene->addChild(layer);
    return scene;
}
bool gameover::init()
{

    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();





}
void GameOver::GoTopausemenu(cocos2d::Ref* pSender)
{
    auto scene = Playscene::createScene();

    Director::getInstance()->replaceScene(scene);
}
void GameOver::GoTohellowordscene(cocos2d::Ref* pSender)
{
    auto scene = helloword::createScene();

    Director::getInstance()->replaceScene(scene);
}

