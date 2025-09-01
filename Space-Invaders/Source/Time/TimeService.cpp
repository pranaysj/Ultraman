#include "../../Header/Time/TimeService.h"

namespace Time {
    void TimeService::UpdateDeltatiem() {
        deltaTime = CalculateDeltaTime();
        UpdatePreviousTime();
    }

    float TimeService::CalculateDeltaTime() {
        int delta = chrono::duration_cast<std::chrono::microseconds>(
            chrono::steady_clock::now() - previous_time).count();
        return static_cast<float>(delta) / static_cast<float>(1000000);
    }

    void TimeService::UpdatePreviousTime() {
        previous_time = chrono::steady_clock::now();
    }

    void TimeService::Initialize() {
        previous_time = chrono::steady_clock::now();
        deltaTime = 0;
    }

    void TimeService::Update() {
        UpdateDeltatiem();
    }

    float TimeService::GetDeltaTime() {
        return deltaTime;
    }
}


