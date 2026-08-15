#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
 // colix - maybe it wants 2?
 // haturz1 - yes it wants 2

bool isSettingEnabled(std::string setting) {
    return Mod::get()->getSettingValue<bool>(setting);
}

void banish(CCNode* victim) {
    victim->setVisible(false);
}

class $modify(LevelEditorLayer, EditorPauseLayer) { // colix - removed LevelEditorLayer for test // haturz1 - i think its a good reason to have LevelEditorLayer now
    bool init() {
        if (!EditorPauseLayer::init()) {
            return false
        }
        
        auto guidelinesMenu = this->getChildByID("guidelines-menu");
        
        if (!guidelinesMenu) return true;
        
        auto helpButton = guidelinesMenu->getChildByID("help-button");
        
        auto resumeMenu = this->getChildByID("resume-menu");
        
        if (!resumeMenu) return true;
        
        auto exitButton = resumeMenu->getChildByID("exit-button");
        
        if (isSettingEnabled("helpButtonOnly"))
            banish(helpButton);
        guidelinesMenu->updateLayout();
        return true;
        
        if (isSettingEnabled("exitButtonOnly"))
            banish(exitButton);
        resumeMenu->updateLayout();
        return true
    }
};
