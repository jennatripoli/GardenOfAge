#include "EventStep.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

#include "Explosion.h"

Explosion::Explosion() {
    registerInterest(df::STEP_EVENT);

    if (setSprite("explosion") == 0) time_to_live = getAnimation().getSprite()->getFrameCount();
    else time_to_live = 0;

    setType("Explosion");
    setSolidness(df::SPECTRAL);
}

// handle event (return 0 if ignored, else return 1)
int Explosion::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::STEP_EVENT) {
        step();
        return 1;
    }

    return 0;  // event ignored
}

// count down until explosion is finished
void Explosion::step() {
    time_to_live--;
    if (time_to_live <= 0) WM.markForDelete(this);
}
