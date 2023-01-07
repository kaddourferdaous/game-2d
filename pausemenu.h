



#ifndef _pausemenu_SCENE_H_
#define _pausemenu_SCENE_H_
#include "cocos2d.h"



class Pausemenu : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();




    void Resume(Ref* pSender);
    void GoToHelloWodldScene(Ref* pSender);
    void Retry(Ref* pSender);
};

#endif // __PLAY_SCENE_H__
