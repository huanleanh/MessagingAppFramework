#pragma once

#define MAF_ENABLE_DUMP
#include <maf/utils/serialization/MafObjectBegin.mc.h>

namespace maf {
namespace messaging {

Class(Address)
    public:
        using Port = int32_t;
        using Name = std::string;
        static constexpr Port INVALID_PORT = -1;
        static const Name INVALID_NAME;
        static const Address INVALID_ADDRESS;
        bool valid() const { return (port() != INVALID_PORT) || (name() != INVALID_NAME);}

    properties
        (
            (Name, name, INVALID_NAME),
            (Port, port, INVALID_PORT)
        )

Ssalc(Address)

}// messaging
}// maf

#include <maf/utils/serialization/MafObjectEnd.mc.h>

