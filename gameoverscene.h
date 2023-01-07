

#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"

class PlayScene : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();


    void menuCloseCallback(cocos2d::Ref* pSender);


    CREATE_FUNC(PlayScene);

    cocos2d::Sprite* mySprite;

    void GoTopausescene(Ref* pSender);
    void GoTogameoverscene(Ref* pSender);


};

#endif
