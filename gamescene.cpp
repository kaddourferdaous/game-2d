#include "gamescene.h"
#include "pausemenu.h"
#include "hellowordcene.h"
#include "gameovercene.h"

USING_NS_CC;

Scene* pausemenu::createscene()
{
    return pm::create();
}




bool pausemenu::init()
{
    if (!scene::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();



    auto background = Sprite::create("bggame.jpg");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    background->setScaleY(5.0);
    background->setScaleX(5.0);
    this->addChild(background, -1);


    auto bg1 = Sprite::create("bg.jpg");
    bg1->setScaleY(4.0);
    bg1->setScaleX(4.0);
    bg1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    bg1->setPosition(Vec2::ZERO);

    auto bg2 = Sprite::create("bg.jpg");
    bg2->setScaleY(4.0);
    bg2->setScaleX(4.0);
    bg2->setPosition(Vec2(1000, 50));

    auto gbgup = Sprite::create("bg.jpg");
    bgup->setScaleY(2.0);
    bgup->setScaleX(2.0);
    bgup->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    bgup->setPosition(Vec2(500, 100));

    auto bgup2 = Sprite::create("bg.jpg");
bgup2->setScaleY(2.0);
bgup2->setScaleX(2.0);
bgup2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
bgup2->setPosition(Vec2(1000, 500));




    this->scheduleUpdate();

    auto pauseItem = MenuItemImage::create("cocos2d.jpg",
        "cocos2d.jpg",
        CC_CALLBACK_1(PlayScene::GoTopausemenu, this));

  
    pauseItem->setPosition(Point(pauseItem->getContentSize().width - (pauseItem->getContentSize().width / 4) + origin.x,
        visibleSize.height - pauseItem->getContentSize().height + (pauseItem->getContentSize().width / 4) + origin.y));
    
    auto menu = Menu::create(pauseItem, NULL);
    
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu);




    initWithPhysics();
    sceneworld = getPhysicsWorld();
    sceneworld->setGravity(Vec2(0, -40));
    sceneworld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);



    auto bg1Body = PhysicsBody::createBox(ground1->getContentSize(), PhysicsMaterial(0, 1, 0));
   bg1Body->setDynamic(false);
    bg1->setPhysicsBody(ground1Body);

    auto bg2Body = PhysicsBody::createBox(ground2->getContentSize(), PhysicsMaterial(0, 1, 0));

 bg2Body->setDynamic(false);
   bg2->setPhysicsBody(bgBody);

    auto gbg = PhysicsBody::createBox(ground2->getContentSize(), PhysicsMaterial(0, 1, 0));

    bgup->setDynamic(false);
    bgup->setPhysicsBody(bgupbd);

    auto bgup2bd = PhysicsBody::createBox(ground2->getContentSize(), PhysicsMaterial(0, 1, 0));

    bgup2bd->setDynamic(false);
    bgup2->setPhysicsBody(groundup2bd);

    auto obs1 = Sprite::create("bg2.png");
    obs1->setScaleX(2.5);
    obs1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    obs1->setPosition(Vec2(300, 10));
    auto obsbd = PhysicsBody::createBox(ground2->getContentSize(), PhysicsMaterial(0, 1, 0));

    obsbd->setCollisionBitmask(2);
    obsbd->setContactTestBitmask(true);
    obsbd->setDynamic(false);
    obs1->setPhysicsBody(obsbd);





    auto mySprite = Sprite::create("layer.png");
    mySprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto eventListener = EventListenerKeyboard::create();


    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

        bool leftkeypressed = false;
        bool rightkeypressed = false;

        Vec2 loc = event->getCurrentTarget()->getPosition();
        auto newPosition = loc + Vec2(0, 25);
        auto jumpHeight = 70;
        auto jumpDuration = 0.5f;
        auto jumpActionright = MoveTo::create(jumpDuration, loc + Vec2(25, jumpHeight));
        auto jumpActionleft = MoveTo::create(jumpDuration, loc + Vec2(-25, jumpHeight));

        auto downDuration = 0.5f;
        auto downActionright = MoveTo::create(downDuration, loc + Vec2(25, 0));
        auto downActionleft = MoveTo::create(downDuration, loc + Vec2(-25, 0));
        auto sequenceright = Sequence::create(jumpActionright, downActionright, NULL);
        auto sequenceleft = Sequence::create(jumpActionleft, downActionleft, NULL);
         switch (keyCode) {
                //controler les mouvements par les 'keywords'
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW: 
            case EventKeyboard::KeyCode::KEY_L:
              
                isLeftPressed = true;
                    this->schedule(SEL_SCHEDULE(&pm::moveleft), 0.01);
                
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_R:
              
                isRightPressed = true;
                    this->schedule(SEL_SCHEDULE(&pm::moveright), 0.01);
                 
                break;
            case EventKeyboard::KeyCode::KEY_SPACE:
            case EventKeyboard::KeyCode::KEY_S:
                if (isSpacePressed == false)
                {
                    this->schedule(SEL_SCHEDULE(&pm::movetop), 0.01);
                    isSpacePressed = true;
                    isPlayerOnGround = false;
                }
                
                   
                    
            
                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:

                isUpPressed = true;

                break;
                  
            } 
    };
    eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, layer);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(gamecene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);


    return true;
}





void playscene::update(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

}






void playscene::GoTopausemenu(cocos2d::Ref* pSender)
{
    CCLOG("GoTopausemenu");
    auto scene = pausemenu::createScene();

    Director::getInstance()->pushScene(scene);
}
void PlayScene::GoTogameoverscene(cocos2d::Ref* pSender)
{
    auto scene = gameover::createScene();

    Director::getInstance()->pushScene(scene);
}

bool PlayScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();

    
    if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
    {
        CCLOG("COLLISION HAS OCCURED");
        auto scene = gameover::createscene();

        Director::getInstance()->replacescene(scene);
        CCLOG("GOTOGAMEOVR");
    }

    return true;
}


