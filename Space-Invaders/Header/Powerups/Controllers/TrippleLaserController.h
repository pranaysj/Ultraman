#pragma once
#include "../../Header/Powerups/PoweupController.h"

namespace Powerup
{
    namespace Controller
    {
        class TrippleLaserController : public PowerupController
        {
        public:
            TrippleLaserController(PowerupType type);
            virtual ~TrippleLaserController();

            void OnCollected() override;
        };
    }
}
