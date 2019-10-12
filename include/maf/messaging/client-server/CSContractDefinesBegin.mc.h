#ifndef CSCONTRACTDEFINESBEGIN_MC_H
#   define CSCONTRACTDEFINESBEGIN_MC_H
#   include <maf/messaging/client-server/CSTypes.h>
#   include <maf/messaging/client-server/ipc/IPCMessageTrait.h>
#endif // CSCONTRACTDEFINESBEGIN_MC_H

// The rest of this file must be putted outside include guard
// Make it to be use with multiple files
#	ifdef endfunc
#		pragma push_macro("endfunc")
#		define maf_restore_macro_endfunc
#	endif
#	ifdef function
#   error function is already defined
#		pragma push_macro("function")
#		define maf_restore_macro_function
#	endif
#	ifdef mc_maf_csc_function_params
#		pragma push_macro("mc_maf_csc_function_params")
#		define maf_restore_macro_mc_maf_csc_function_params
#	endif
#	ifdef mc_maf_csc_function_params_empty
#		pragma push_macro("mc_maf_csc_function_params_empty")
#		define maf_restore_macro_mc_maf_csc_function_params_empty
#	endif
#	ifdef has_request
#		pragma push_macro("has_request")
#		define maf_restore_macro_has_request
#	endif
#	ifdef request_noparams
#		pragma push_macro("request_noparams")
#		define maf_restore_macro_request_noparams
#	endif
#	ifdef has_result
#		pragma push_macro("has_result")
#		define maf_restore_macro_has_result
#	endif
#	ifdef result_noparams
#		pragma push_macro("result_noparams")
#		define maf_restore_macro_result_noparams
#	endif
#	ifdef has_update
#		pragma push_macro("has_update")
#		define maf_restore_macro_update
#	endif

#include <maf/utils/serialization/MafObjectBegin.mc.h>

#define function(FunctionName) \
struct FunctionName { \
    static constexpr maf::messaging::OpID ID() { \
        return __LINE__; \
    }

#define endfunc(...) \
};

#define has_request(...) mc_maf_csc_function_params(Request, __VA_ARGS__)
#define has_result(...) mc_maf_csc_function_params(Result, __VA_ARGS__)
#define has_update(...) mc_maf_csc_function_params(Update, __VA_ARGS__)

#define request_noparams() mc_maf_csc_function_params(Request, (bool, this_object_empty, true))
#define result_noparams() mc_maf_csc_function_params(Result, (bool, this_object_empty, true))

#define mc_maf_csc_function_params(Type, ...) \
Class(Type, maf::messaging::ipc::SerializableMessageContentBase) \
public: \
    maf::srz::ByteArray toBytes() override \
    { \
        maf::srz::BASerializer sr; \
        sr << *this; \
        return std::move(sr.mutableBytes()); \
    } \
    void fromBytes(const maf::srz::ByteArray& bytes) override { \
            maf::srz::BADeserializer ds(bytes); \
            ds >> *this; \
    } \
    static constexpr maf::messaging::OpID sOperationID() { \
        return ID(); \
    } \
    maf::messaging::OpID operationID() const override { \
        return sOperationID(); \
    } \
    properties(__VA_ARGS__) }; \
\
    template<typename ...Args> \
    static std::shared_ptr<Type> make##Type(Args&&... args) { \
        std::shared_ptr<Type> ptr{ new Type { std::forward<Args>(args)... } }; \
        return ptr; \
    }

#define mc_maf_csc_function_params_empty(Type) \
    struct Type { \
        static constexpr maf::messaging::OpID sOperationID() { \
            return ID(); \
        } \
    }; \
    template<typename ...Args> \
    static std::shared_ptr<Type> make##Type(Args&&... args) { \
        std::shared_ptr<Type> ptr{ new Type { std::forward<Args>(args)... } }; \
        return ptr; \
    }

