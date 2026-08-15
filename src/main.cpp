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

class $modify(EditorPauseLayer) {
    bool init(LevelEditorLayer* layer) {
        if (!EditorPauseLayer::init(layer)) {
            return false;
        }
        
        auto guidelinesMenu = this->getChildByID("guidelines-menu");
        
        if (!guidelinesMenu) return true;
        
        auto helpButton = guidelinesMenu->getChildByID("help-button");
        auto resumeMenu = this->getChildByID("resume-menu");
        
        if (!resumeMenu) return true;
        
        auto exitButton = resumeMenu->getChildByID("exit-button");
        
        if (isSettingEnabled("help-button-only"))
            banish(helpButton);
        if (isSettingEnabled("exit-button-only"))
            banish(exitButton);
        guidelinesMenu->updateLayout();
        resumeMenu->updateLayout();
        return true;
    }
};
