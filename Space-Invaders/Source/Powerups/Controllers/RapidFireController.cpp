#pragma
#include "../../Header/Powerups/Controllers/RapidFireController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        using namespace Global;

        void RapidFireController::ApplyPowerup()
        {
            ServiceLocator::GetInstance()->GetPlayerService()->EnableRapidFire();
        }

        RapidFireController::RapidFireController(PowerupType type) : PowerupController(type) {}

        RapidFireController::~RapidFireController() {}

    }
}