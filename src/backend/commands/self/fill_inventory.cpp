#include "backend/command.hpp"
#include "natives.hpp"

namespace big
{
	class fill_inventory : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			STATS::STAT_SET_INT(rage::joaat(self::char_index + "NO_BOUGHT_YUM_SNACKS"), 30, true);
			STATS::STAT_SET_INT(rage::joaat(self::char_index + "NO_BOUGHT_HEALTH_SNACKS"), 15, true);
			STATS::STAT_SET_INT(rage::joaat(self::char_index + "NO_BOUGHT_EPIC_SNACKS"), 5, true);
			STATS::STAT_SET_INT(rage::joaat(self::char_index + "MP_CHAR_ARMOUR_1_COUNT"), 10, true);
			STATS::STAT_SET_INT(rage::joaat(self::char_index + "MP_CHAR_ARMOUR_2_COUNT"), 10, true);
			STATS::STAT_SET_INT(rage::joaat(self::char_index + "MP_CHAR_ARMOUR_3_COUNT"), 10, true);
			STATS::STAT_SET_INT(rage::joaat(self::char_index + "MP_CHAR_ARMOUR_4_COUNT"), 10, true);
			STATS::STAT_SET_INT(rage::joaat(self::char_index + "MP_CHAR_ARMOUR_5_COUNT"), 10, true);
		}
	};

	fill_inventory g_fill_inventory("fillsnacks", "FILL_INVENTORY", "FILL_INVENTORY_DESC", 0);
}