#include "main_tabs.hpp"
#include "util/system.hpp"
#include "features.hpp"
#include "fiber_pool.hpp"


namespace big
{
	void tab_main::tab_settings()
	{
		if (ImGui::BeginTabItem("Settings"))
		{
			ImGui::Text("No settings to be modified as of now");
<<<<<<<<< Temporary merge branch 1
=========

			ImGui::Separator();
			ImGui::Checkbox("Always Jackpot in Slot Machines", &features::always_jackpot);

			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("After enabling this option you'll always win in any Slot Machine.");

			ImGui::Separator();

			if(ImGui::Button("Reset cooldown"))
			{
				g_fiber_pool->queue_job([] {

					// Variant #1: The most popular and maybe detected (?) variant, i prefer this one, it's straight and... less buggy, but, if you're scared of using it, use the other variants.

					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CASINO_CHIPS_WON_GD"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CASINO_CHIPS_WONTIM"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CASINO_CHIPS_PUR_GD"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CASINO_CHIPS_PURTIM"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CASINO_MEM_BONUS"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_0"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_1"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_2"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_3"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_4"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_5"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_6"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_7"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_8"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_GMBLNG_9"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_0"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_1"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_2"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_3"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_4"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_5"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_6"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_7"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_8"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_TIME_PLYING_9"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CASINO_BAN_TIME"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CASINO_GMBLNG_GD"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_CUR_GMBLNG_GD"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_CUR_GMBLNG_PX"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24_PX"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_TRHSLD"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24_1"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24_2"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24_3"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24_4"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24_5"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24_6"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24_7"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_GMBLNG_L24_8"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_CUR_GMBLNG_HR"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CAS_24H_GMBLNG_PX"), 0, TRUE);
					STATS::STAT_SET_INT(RAGE_JOAAT("MPPLY_CHIPS_COL_TIME"), 0, TRUE);
					});
			}
>>>>>>>>> Temporary merge branch 2

			ImGui::EndTabItem();
           
		}
	}
}