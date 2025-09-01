#pragma once
#include <chrono>
using namespace std;

namespace Time {
    class TimeService {
    private:
        chrono::time_point <chrono::steady_clock> previous_time;

        float deltaTime;

        void UpdateDeltatiem();
        float CalculateDeltaTime();
        void UpdatePreviousTime();


    public:
        void Initialize();
        void Update();

        float GetDeltaTime();
    };
}
