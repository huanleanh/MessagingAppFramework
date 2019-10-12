#pragma once

#include "BasicMessages.h"
#include <maf/utils/serialization/TupleLikeObject.mc.h>

#define mc_dcl_msg_start(MessageName) mc_tpl_class_hasbase(MessageName, maf::messaging::MessageBase)
#define mc_dcl_msg_end Ssalc
#define mc_dcl_msg_props properties

#define mc_dcl_signal(SignalName) struct SignalName : public maf::messaging::MessageBase {\
}
