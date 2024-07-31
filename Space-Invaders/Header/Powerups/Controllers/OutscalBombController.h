#pragma once
#include "../../Header/Powerups/PoweupController.h"

namespace Powerup
{
    namespace Controller
    {
        class OutscalBombController : public PowerupController
        {
        public:
            OutscalBombController(PowerupType type);
            virtual ~OutscalBombController();

            void ApplyPowerup() override;

            void OnCollected() override;
        };
    }
}