#pragma
#include "../../Header/Powerups/Controllers/ShieldController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        using namespace Global;

        void ShieldController::ApplyPowerup()
        {
            ServiceLocator::GetInstance()->GetPlayerService()->EnableShield();

        }
        ShieldController::ShieldController(PowerupType type) : PowerupController(type) {}

        ShieldController::~ShieldController() {}

    }
}