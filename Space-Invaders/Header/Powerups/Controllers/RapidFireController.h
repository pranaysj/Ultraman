#pragma once
#include "../../Header/Powerups/PoweupController.h"

namespace Powerup
{
    namespace Controller
    {
        class RapidFireController : public PowerupController
        {
        protected:
            void ApplyPowerup() override;

        public:
            RapidFireController(PowerupType type);
            virtual ~RapidFireController();

        };
    }
}