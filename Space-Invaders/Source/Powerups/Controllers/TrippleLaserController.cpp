#pragma
#include "../../Header/Powerups/Controllers/TrippleLaserController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        using namespace Global;

        void TrippleLaserController::ApplyPowerup()
        {
            ServiceLocator::GetInstance()->GetPlayerService()->EnableTrippleLaser();

        }

        TrippleLaserController::TrippleLaserController(PowerupType type) : PowerupController(type) {}

        TrippleLaserController::~TrippleLaserController() {}

    }
}