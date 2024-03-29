#pragma once

#include <functional>
#include <chrono>

namespace maf {
namespace util {

class TimeMeasurement
{
public:
	TimeMeasurement() = default;
    TimeMeasurement(std::function<void(long long)> onReportCallback) :
        _onReportCallback(std::move(onReportCallback))
    {
        _startTime = std::chrono::system_clock::now();
    }
    ~TimeMeasurement()
    {
        if(_onReportCallback)
        {
            _onReportCallback(this->elapsedTime());
        }
    }

	long long elapsedTime() const 
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - _startTime).count();
	}
    std::function<void(long long)> _onReportCallback;
    std::chrono::system_clock::time_point _startTime;
};
}
}
