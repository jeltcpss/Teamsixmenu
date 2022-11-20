#pragma once
#include "native_hooks.hpp"
#include "natives.hpp"
#include "core/scr_globals.hpp"

namespace big
{
    namespace all_scripts
    {
        void IS_DLC_PRESENT(rage::scrNativeCallContext* src)
        {
            const auto hash = src->get_arg<rage::joaat_t>(0);
            
            bool return_value = DLC::IS_DLC_PRESENT(hash);
            if (hash == 0x96F02EE6)
                return_value = return_value || g->settings.dev_dlc;

            src->set_return_value(return_value);
        }

        void NETWORK_HAS_RECEIVED_HOST_BROADCAST_DATA(rage::scrNativeCallContext* src)
        {
            *scr_globals::gsbd.as<int*>() = 4;
            src->set_return_value<BOOL>(TRUE);
        }
    }
}