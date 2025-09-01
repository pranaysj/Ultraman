#include "../../Header/Time/TimeService.h"

namespace Time {

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

    void TimeService::UpdateDeltatiem() {
        deltaTime = CalculateDeltaTime();
        UpdatePreviousTime();
    }

    float TimeService::CalculateDeltaTime() {
        // Calculate time difference in microseconds between the current and previous frame.
        int delta = chrono::duration_cast<std::chrono::microseconds>(
            chrono::steady_clock::now() - previous_time).count();

        // To convert delta time from microseconds into seconds.
        return static_cast<float>(delta) / static_cast<float>(1000000);
    }

    // Update previous_time to the current time
    void TimeService::UpdatePreviousTime() {
        previous_time = chrono::steady_clock::now();
    }

}


