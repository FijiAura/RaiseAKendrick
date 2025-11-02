#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>
#include "../funcs.hpp"
using namespace geode::prelude;

namespace rooms {
    class roblox_stuff : public cocos2d::CCNode {
    public:
        cocos2d::CCLayer* parent = nullptr;

        void drake(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                std::vector<std::string> messages = {
                    "I will kill you Kendrick...",
                    "You will pay for what you have done...",
                    "I hate you Kendrick..."
                };
                std::string message = messages[rand() % messages.size()];
                FLAlertLayer::create("Drake", "<cr>" + message + "</c>", "OK")->show();
            }
        }

        void diddy(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                std::vector<std::string> messages = {
                    "*diddles you*",
                    "*gets oiled up*"
                };
                std::string message = messages[rand() % messages.size()];
                FLAlertLayer::create("Diddy", "<cr>" + message + "</c>", "OK")->show();
            }
        }

        void advy(CCObject*) {
            auto win = CCDirector::get()->getWinSize();
            if (parent) {
                std::vector<std::string> messages = {
                    "Activa cam"
                };
                std::string message = messages[rand() % messages.size()];
                FLAlertLayer::create("Tienes 14?", "<cr>" + message + "</c>", "OK")->show();
            }
        }
    };

    inline cocos2d::CCMenu* theroblox(cocos2d::CCLayer* parent = nullptr) {
        auto win = CCDirector::get()->getWinSize();
        auto things = new roblox_stuff();
        things->parent = parent;
        devlin::set_emotion(parent, "wth.gif"_spr, 3.0f, 0.3f, 0.2f);

        auto drakeSprite = CCSprite::create("drake.png"_spr);
        drakeSprite->setScale(2.5f);
        auto drake = CCMenuItemSpriteExtra::create(drakeSprite, nullptr, things, menu_selector(roblox_stuff::drake));
        drake->setPosition({win.width * 0.65f, win.height / 4.20f});
        drake->setID("drake"_spr);

        auto diddySprite = CCSprite::create("diddy.png"_spr);
        diddySprite->setScale(2.5f);
        auto diddy = CCMenuItemSpriteExtra::create(diddySprite, nullptr, things, menu_selector(roblox_stuff::diddy));
        diddy->setPosition({win.width - 120.f, win.height / 1.5f + 69.f});
        diddy->setID("diddy"_spr);

        auto advySprite = CCSprite::create("advy.png"_spr);
        advySprite->setScale(2.5f);
        auto advy = CCMenuItemSpriteExtra::create(advySprite, nullptr, things, menu_selector(roblox_stuff::advy));
        advy->setPosition({win.width / 12.f, win.height / 2.f});
        advy->setID("advy"_spr);

        auto menu = CCMenu::create();
        menu->setPosition({0, 0});
        menu->addChild(drake);
        menu->addChild(diddy);
        menu->addChild(advy);
        menu->setID("room-menu"_spr);
        return menu;
    }
}
