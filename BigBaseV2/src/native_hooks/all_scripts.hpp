#pragma once
#include "native_hooks.hpp"
#include "natives.hpp"

namespace big
{
    namespace all_scripts
    {
        void IS_DLC_PRESENT(rage::scrNativeCallContext* src)
        {
            const auto hash = src->get_arg<rage::joaat_t>(0);
            
            bool return_value = false;
            switch (hash)
            {
            case 0x96F02EE6:
            {
                return_value = true;

                break;
            }
            default:
            {
                return_value = DLC::IS_DLC_PRESENT(hash);

                break;
            }
            }

            src->set_return_value(return_value);
        }
    }
}