#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"

class GameOver : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();

    void update(float dt);

    void GoToPlayScene(Ref* pSender);
    void GoToHelloWorldScene(Ref* pSender);/
};

#endif //


