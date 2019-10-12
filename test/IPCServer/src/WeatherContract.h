#pragma once

#define MAF_ENABLE_DUMP

#include <maf/messaging/client-server/CSTypes.h>
#include <maf/messaging/client-server/CSContractBegin.mc.h>
#include <maf/messaging/client-server/CSContractDefines.mc.h>

constexpr maf::messaging::Address::Port REQUESTS_PER_CLIENT = 100;
constexpr maf::messaging::Address::Port WEATHER_SERVER_PORT  = 0 ;

constexpr const char* const SERVER_ADDRESS = "nocpes.github.com";
constexpr const maf::messaging::ServiceID SID_WeatherService = 0;

result(WeatherStatus)
    enum StatusType{
        Rainy,
        Suny,
        Windy
    };
    properties
        (
            (StatusType, status),
            (std::string, sStatus),
            (std::vector<std::string>, extra_information),
			(int, index)
        )
tluser(WeatherStatus)

request(WeatherStatus)
    properties
(
    (int, place_id),
	(std::string, sid),
    (std::vector<std::string>, extra_information)
    )
tseuqer(WeatherStatus)


result(PolicyStatus)
        properties((int, compliant_status))
tluser(PolicyStatus)

result(NotificationMessageUpdate)
	properties((std::string, message, "nothing to show"))
tluser(NotificationMessageUpdate)

empty_result(ShutDownServerRequest)

#include <maf/messaging/client-server/CSContractEnd.mc.h>

