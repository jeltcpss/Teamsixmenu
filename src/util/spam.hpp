#pragma once
#include "file_manager/file.hpp"
#include "services/players/player_service.hpp"
#include "core/enums.hpp"

namespace
{
	static const char* spam_texts[] = {
	    "qq", //a chinese chat app
	    "QQ",
	    "WWW.",
	    "www.",
	    ".cn",
	    ".CN",
	    ".cc",
	    ".CC",
	    ".TOP",
	    ".COM",
	    ".top",
	    "\xE3\x80\x90", //left bracket in Chinese input method
	    "/Menu",
	    "Money/",
	    "Money\\\\",
	    "Money\\",
	    ".gg",
	    "--->",
	    "shopgta5",
	    "doit#",
	    "krutka#",
	    "<b>",
	    "P888",
	    "gtacash",
	    "\xE6\x89\xA3\xE6\x89\xA3", // no clue what this is
	    "\xE5\xBE\xAE\xE4\xBF\xA1", // "wechat" in Chinese
	    ".cc",
	    "<font s",
	    "sellix.io",
	    "ezcars",
	    "PLANO INICIAL", // "initial plan"
	    "REP +",
	    "20R$", // Brazil currency?
	    "l55.me",
	    "\xE5\xBA\x97",                         //"shop" in Chinese
	    "\xE9\x92\xB1",                         //"money" in Chinese
	    "\xE5\x88\xB7",                         //"make(money)" in Chinese
	    "\xE8\x90\x9D\xE8\x8E\x89",             // "cute girl" in Chinese
	    "\xE5\xA6\x88",                         // "mother" in Chinese
	    "\xE7\xBE\x8E\xE5\xA5\xB3",             // "sexy girl" in Chinese
	    "\xE5\xBC\xBA\xE5\xA5\xB8",             // "rape" in Chinese
	    "\xE8\x90\x9D",                         // "loli" in Chinese
	    "\xE6\x8C\x82",                         // "hack" in Chinese
	    "\xE5\x85\x83",                         // chinese dollar
	    "\xE9\x98\xB4\xE4\xBC\xA0\xE5\xAA\x92", // "Yin Media" in Chinese
	    "\xE7\xBD\x91\xE7\xBA\xA2",             // "internet celebrities" in Chinese
	    "TRUSTPILOT",
	    "cashlounge",
	    "Fast Delivery",
	    "yosativa",
	    "rich2day",
	    "LevelLifters",
	    ". com",
	    "$1,000,000,000",
	    "Instant Delivery",
	    "0 Ban Risk",
	    "Discord For Cheap Money",
	};
}

namespace big::spam
{
	inline SpamReason is_text_spam(const char* text, player_ptr player)
	{
		if (g.session.use_spam_timer)
		{
			if (player->last_message_time.has_value())
			{
				auto currentTime = std::chrono::steady_clock::now();
				auto diff = std::chrono::duration_cast<std::chrono::seconds>(currentTime - player->last_message_time.value());
				player->last_message_time.emplace(currentTime);

				if (strlen(text) > g.session.spam_length && diff.count() <= g.session.spam_timer)
					return SpamReason::TIMER_DETECTION;
			}
			else
			{
				player->last_message_time.emplace(std::chrono::steady_clock::now());
			}
		}
		for (auto e : spam_texts)
			if (strstr(text, e) != 0)
				return SpamReason::STATIC_DETECTION;

		return SpamReason::NOT_A_SPAMMER;
	}

	inline void log_chat(char* msg, player_ptr player, SpamReason spam_reason, bool is_team)
	{
		std::ofstream log(g_file_manager.get_project_file(spam_reason != SpamReason::NOT_A_SPAMMER ? "./spam.log" : "./chat.log").get_path(), std::ios::app);

		auto& data = *player->get_net_data();
		auto ip    = player->get_ip_address();

		auto now        = std::chrono::system_clock::now();
		auto ms         = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
		auto timer      = std::chrono::system_clock::to_time_t(now);
		auto local_time = *std::localtime(&timer);

		std::string spam_reason_str = "";

		switch (spam_reason)
		{
			case SpamReason::STATIC_DETECTION: spam_reason_str = "(Static Detection) "; break;
			case SpamReason::TIMER_DETECTION: spam_reason_str = "(Timer Detection) "; break;
		}

		log << spam_reason_str << "[" << std::put_time(&local_time, "%m/%d/%Y %I:%M:%S") << ":" << std::setfill('0') << std::setw(3) << ms.count() << " " << std::put_time(&local_time, "%p") << "] ";

		if (ip)
			log << player->get_name() << " (" << data.m_gamer_handle.m_rockstar_id << ") <" << (int)ip.value().m_field1 << "."
			    << (int)ip.value().m_field2 << "." << (int)ip.value().m_field3 << "." << (int)ip.value().m_field4 << "> " << ((is_team == true) ? "[TEAM]: " : "[ALL]: ") << msg << std::endl;
		else
			log << player->get_name() << " (" << data.m_gamer_handle.m_rockstar_id << ") <UNKNOWN> " << ((is_team == true) ? "[TEAM]: " : "[ALL]: ") << msg << std::endl;

		log.close();
	}
}
