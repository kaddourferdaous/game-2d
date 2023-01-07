
 


#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "cocos2d.h"
class gamescreen: public cocos2d::Layer
{

	
public:
	static cocos2d::Scene * createscene();
	virtual bool init();
	CREATE_FUNC(gamescreen);

	void GoTopausemenu(Ref*pSender);
	void GoTooverscene(Ref* pSender);
};
#endif