#pragma once
#include "../../Header/Powerups/PoweupController.h"

namespace Powerup
{
    namespace Controller
    {
        class TrippleLaserController : public PowerupController
        {
        protected:
            void ApplyPowerup() override;

        public:
            TrippleLaserController(PowerupType type);
            virtual ~TrippleLaserController();

        };
    }
}
