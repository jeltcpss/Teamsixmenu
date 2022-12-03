#pragma once
#include "memory/pattern.hpp"
#include "gta/joaat.hpp"

namespace big
{
	// a lightweight script function wrapper insipred by https://github.com/Parik27/V.Rainbomizer/blob/master/src/mission/missions_YscUtils.hh
	class script_function
	{
		rage::joaat_t m_script;
		const memory::pattern m_pattern;
		int32_t m_offset;
		int32_t m_ip;
		std::string m_name;

		static const std::optional<uint32_t> get_code_location_by_pattern(rage::scrProgram* program, const memory::pattern& pattern);
	public:
		script_function(const std::string& name, const rage::joaat_t script, const std::string& pattern, int32_t offset);
		void populate_ip();
		void call(rage::scrThread* thread, rage::scrProgram* program, std::initializer_list<std::uint64_t> args);
		void operator()(std::initializer_list<std::uint64_t> args);
	};

	namespace scr_functions
	{
		static inline script_function join_ceo("JC", RAGE_JOAAT("freemode"), "2D 04 1D 00 00 5D", 0);
		static inline script_function dance_loop("DL", RAGE_JOAAT("am_mp_nightclub"), "2D 00 14 00 00 4F ? ? 47 ? ? 5D ? ? ? 56", 0);
		static inline script_function init_nightclub_script("INS", RAGE_JOAAT("am_mp_nightclub"), "2D 00 11 00 00 4F", 0);
	}
}