#include "common.hpp"
#include "function_types.hpp"
#include "logger.hpp"
#include "gta/array.hpp"
#include "gta/player.hpp"
#include "gta/script_thread.hpp"
#include "gui.hpp"
#include "hooking.hpp"
#include "memory/module.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "renderer.hpp"
#include "script_mgr.hpp"

#include <MinHook.h>

namespace big
{
	hooking::hooking() :
		// Swapchain
		m_swapchain_hook(*g_pointers->m_swapchain, hooks::swapchain_num_funcs),

		// Script Hook
		m_run_script_threads_hook("SH", (void*)g_pointers->m_run_script_threads, (void*)&hooks::run_script_threads),

		// GTA Thead Start
		m_gta_thread_start_hook("GTS", (void*)g_pointers->m_gta_thread_start, (void*)&hooks::gta_thread_start),
		// GTA Thread Kill
		m_gta_thread_kill_hook("GTK", (void*)g_pointers->m_gta_thread_kill, (void*)&hooks::gta_thread_kill),

		// Network Player Mgr Init
		m_network_player_mgr_init_hook("NPMI", (void*)g_pointers->m_network_player_mgr_init, (void*)&hooks::network_player_mgr_init),
		// Network Player Mgr Shutdown
		m_network_player_mgr_shutdown_hook("NPMS", (void*)g_pointers->m_network_player_mgr_shutdown, (void*)&hooks::network_player_mgr_shutdown),

		// Network Group Override
		m_network_group_override("NGO", (void*)g_pointers->m_network_group_override, (void*)&hooks::network_group_override),

		// Net Array Handler
		m_net_array_handler_hook("NAH", (void*)g_pointers->m_net_array_handler, (void*)&hooks::net_array_handler),
		
		// Is DLC Present
		m_is_dlc_present_hook("IDP", (void*)g_pointers->m_is_dlc_present, (void*)&hooks::is_dlc_present),

		// Received Event
		m_received_event_hook("RE", (void*)g_pointers->m_received_event, (void*)&hooks::received_event),

		// Send NET Info to Lobby
		m_send_net_info_to_lobby("SNITL", (void*)g_pointers->m_send_net_info_to_lobby, (void*)&hooks::send_net_info_to_lobby),

		// Player Has Joined
		m_player_has_joined_hook("PHJ", (void*)g_pointers->m_player_has_joined, (void*)&hooks::player_join),
		// Player Has Left
		m_player_has_left_hook("PHL", (void*)g_pointers->m_player_has_left, (void*)&hooks::player_leave),
		// Receive Net Message
		m_receive_net_message_hook("RNM", (void*)g_pointers->m_receive_net_message, (void*)&hooks::receive_net_message),
		// Received clone sync
		m_received_clone_sync_hook("RCS", (void*)g_pointers->m_received_clone_sync, (void*)&hooks::received_clone_sync),
		//Get Network Event Data
		m_get_network_event_data_hook("GNED", (void*)g_pointers->m_get_network_event_data, (void*)&hooks::get_network_event_data)
	{
		m_swapchain_hook.hook(hooks::swapchain_present_index, (void*)&hooks::swapchain_present);
		m_swapchain_hook.hook(hooks::swapchain_resizebuffers_index, (void*)&hooks::swapchain_resizebuffers);

		g_hooking = this;
	}

	hooking::~hooking()
	{
		if (m_enabled)
			disable();

		g_hooking = nullptr;
	}

	void hooking::enable()
	{
		m_swapchain_hook.enable();
		m_og_wndproc = WNDPROC(SetWindowLongPtrW(g_pointers->m_hwnd, GWLP_WNDPROC, LONG_PTR(&hooks::wndproc)));

		m_run_script_threads_hook.enable();

		m_gta_thread_start_hook.enable();
		m_gta_thread_kill_hook.enable();

		m_network_group_override.enable();

		m_network_player_mgr_init_hook.enable();
		m_network_player_mgr_shutdown_hook.enable();

		m_net_array_handler_hook.enable();

		m_player_has_joined_hook.enable();
		m_player_has_left_hook.enable();

		m_received_event_hook.enable();

		m_send_net_info_to_lobby.enable();

		m_receive_net_message_hook.enable();
		m_get_network_event_data_hook.enable();

		m_received_clone_sync_hook.enable();

		m_enabled = true;
	}

	void hooking::disable()
	{
		m_enabled = false;

		m_received_clone_sync_hook.disable();

		m_get_network_event_data_hook.disable();
		m_receive_net_message_hook.disable();

		m_send_net_info_to_lobby.disable();

		m_received_event_hook.disable();

		m_player_has_joined_hook.disable();
		m_player_has_left_hook.disable();

		m_net_array_handler_hook.disable();

		m_network_player_mgr_init_hook.disable();
		m_network_player_mgr_shutdown_hook.disable();

		m_network_group_override.disable();

		m_gta_thread_kill_hook.disable();
		m_gta_thread_start_hook.disable();

		m_run_script_threads_hook.disable();

		SetWindowLongPtrW(g_pointers->m_hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(m_og_wndproc));
		m_swapchain_hook.disable();
	}

	minhook_keepalive::minhook_keepalive()
	{
		MH_Initialize();
	}

	minhook_keepalive::~minhook_keepalive()
	{
		MH_Uninitialize();
	}

	bool hooks::run_script_threads(std::uint32_t ops_to_execute)
	{
		if (g_running)
		{
			g_script_mgr.tick();
		}

		return g_hooking->m_run_script_threads_hook.get_original<functions::run_script_threads>()(ops_to_execute);
	}
}
