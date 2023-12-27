#include "lua_native_binding.hpp"
#include "natives.hpp"

namespace lua::native
{
	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_USE_SERVER_TRANSACTIONS()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_USE_SERVER_TRANSACTIONS();
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CATALOG_ITEM_IS_VALID(const char* name)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_CATALOG_ITEM_IS_VALID(name);
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CATALOG_ITEM_KEY_IS_VALID(Hash hash)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_CATALOG_ITEM_KEY_IS_VALID(hash);
		return retval;
	}

	static int LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_GET_PRICE(Hash itemHash, Hash categoryHash, bool p2)
	{
		auto retval = NETSHOPPING::NET_GAMESERVER_GET_PRICE(itemHash, categoryHash, p2);
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CATALOG_IS_VALID()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_CATALOG_IS_VALID();
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_IS_CATALOG_CURRENT()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_IS_CATALOG_CURRENT();
		return retval;
	}

	static Hash LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_GET_CATALOG_CLOUD_CRC()
	{
		auto retval = NETSHOPPING::NET_GAMESERVER_GET_CATALOG_CLOUD_CRC();
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_REFRESH_SERVER_CATALOG()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_REFRESH_SERVER_CATALOG();
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_RETRIEVE_CATALOG_REFRESH_STATUS(int state)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)NETSHOPPING::NET_GAMESERVER_RETRIEVE_CATALOG_REFRESH_STATUS(&state);
		std::get<1>(return_values) = state;

		return return_values;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_INIT_SESSION()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_INIT_SESSION();
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_RETRIEVE_INIT_SESSION_STATUS(int p0)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)NETSHOPPING::NET_GAMESERVER_RETRIEVE_INIT_SESSION_STATUS(&p0);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_START_SESSION(int charSlot)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_START_SESSION(charSlot);
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_START_SESSION_PENDING()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_START_SESSION_PENDING();
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_RETRIEVE_START_SESSION_STATUS(int p0)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)NETSHOPPING::NET_GAMESERVER_RETRIEVE_START_SESSION_STATUS(&p0);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static std::tuple<bool, int> LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_RETRIEVE_SESSION_ERROR_CODE(int p0)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)NETSHOPPING::NET_GAMESERVER_RETRIEVE_SESSION_ERROR_CODE(&p0);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_IS_SESSION_VALID(int charSlot)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_IS_SESSION_VALID(charSlot);
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CLEAR_SESSION(int p0)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_CLEAR_SESSION(p0);
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_SESSION_APPLY_RECEIVED_DATA(int charSlot)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_SESSION_APPLY_RECEIVED_DATA(charSlot);
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_IS_SESSION_REFRESH_PENDING()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_IS_SESSION_REFRESH_PENDING();
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_START_SESSION_RESTART(bool inventory, bool playerbalance)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_START_SESSION_RESTART(inventory, playerbalance);
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSACTION_IN_PROGRESS()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_TRANSACTION_IN_PROGRESS();
		return retval;
	}

	static std::tuple<bool, int, bool> LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_GET_SESSION_STATE_AND_STATUS(int p0, bool p1)
	{
		std::tuple<bool, int, bool> return_values;
		std::get<0>(return_values) = (bool)NETSHOPPING::NET_GAMESERVER_GET_SESSION_STATE_AND_STATUS(&p0, &p1);
		std::get<1>(return_values) = p0;
		std::get<2>(return_values) = p1;

		return return_values;
	}

	static std::tuple<bool, int> LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_START(int transactionId, Hash categoryHash, Hash actionHash, int flags)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)NETSHOPPING::NET_GAMESERVER_BASKET_START(&transactionId, categoryHash, actionHash, flags);
		std::get<1>(return_values) = transactionId;

		return return_values;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_END()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_BASKET_END();
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_IS_ACTIVE()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_BASKET_IS_ACTIVE();
		return retval;
	}

	static std::tuple<bool, Any> LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_ADD_ITEM(Any itemData, int quantity)
	{
		std::tuple<bool, Any> return_values;
		std::get<0>(return_values) = (bool)NETSHOPPING::NET_GAMESERVER_BASKET_ADD_ITEM(&itemData, quantity);
		std::get<1>(return_values) = itemData;

		return return_values;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_IS_FULL()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_BASKET_IS_FULL();
		return retval;
	}

	static std::tuple<bool, Any> LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_APPLY_SERVER_DATA(Any p0, Any p1)
	{
		std::tuple<bool, Any> return_values;
		std::get<0>(return_values) = (bool)NETSHOPPING::NET_GAMESERVER_BASKET_APPLY_SERVER_DATA(p0, &p1);
		std::get<1>(return_values) = p1;

		return return_values;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CHECKOUT_START(int transactionId)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_CHECKOUT_START(transactionId);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BEGIN_SERVICE(int transactionId, Hash categoryHash, Hash itemHash, Hash actionTypeHash, int value, int flags)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)NETSHOPPING::NET_GAMESERVER_BEGIN_SERVICE(&transactionId, categoryHash, itemHash, actionTypeHash, value, flags);
		std::get<1>(return_values) = transactionId;

		return return_values;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_END_SERVICE(int transactionId)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_END_SERVICE(transactionId);
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_DELETE_CHARACTER(int slot, bool transfer, Hash reason)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_DELETE_CHARACTER(slot, transfer, reason);
		return retval;
	}

	static int LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_DELETE_CHARACTER_GET_STATUS()
	{
		auto retval = NETSHOPPING::NET_GAMESERVER_DELETE_CHARACTER_GET_STATUS();
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_DELETE_SET_TELEMETRY_NONCE_SEED()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_DELETE_SET_TELEMETRY_NONCE_SEED();
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_BANK_TO_WALLET(int charSlot, int amount)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_TRANSFER_BANK_TO_WALLET(charSlot, amount);
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_WALLET_TO_BANK(int charSlot, int amount)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_TRANSFER_WALLET_TO_BANK(charSlot, amount);
		return retval;
	}

	static int LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_BANK_TO_WALLET_GET_STATUS()
	{
		auto retval = NETSHOPPING::NET_GAMESERVER_TRANSFER_BANK_TO_WALLET_GET_STATUS();
		return retval;
	}

	static int LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_WALLET_TO_BANK_GET_STATUS()
	{
		auto retval = NETSHOPPING::NET_GAMESERVER_TRANSFER_WALLET_TO_BANK_GET_STATUS();
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_CASH_SET_TELEMETRY_NONCE_SEED()
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_TRANSFER_CASH_SET_TELEMETRY_NONCE_SEED();
		return retval;
	}

	static bool LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_SET_TELEMETRY_NONCE_SEED(int p0)
	{
		auto retval = (bool)NETSHOPPING::NET_GAMESERVER_SET_TELEMETRY_NONCE_SEED(p0);
		return retval;
	}

	void init_native_binding_NETSHOPPING(sol::state& L)
	{
		auto NETSHOPPING = L["NETSHOPPING"].get_or_create<sol::table>();
		NETSHOPPING.set_function("NET_GAMESERVER_USE_SERVER_TRANSACTIONS", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_USE_SERVER_TRANSACTIONS);
		NETSHOPPING.set_function("NET_GAMESERVER_CATALOG_ITEM_IS_VALID", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CATALOG_ITEM_IS_VALID);
		NETSHOPPING.set_function("NET_GAMESERVER_CATALOG_ITEM_KEY_IS_VALID", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CATALOG_ITEM_KEY_IS_VALID);
		NETSHOPPING.set_function("NET_GAMESERVER_GET_PRICE", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_GET_PRICE);
		NETSHOPPING.set_function("NET_GAMESERVER_CATALOG_IS_VALID", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CATALOG_IS_VALID);
		NETSHOPPING.set_function("NET_GAMESERVER_IS_CATALOG_CURRENT", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_IS_CATALOG_CURRENT);
		NETSHOPPING.set_function("NET_GAMESERVER_GET_CATALOG_CLOUD_CRC", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_GET_CATALOG_CLOUD_CRC);
		NETSHOPPING.set_function("NET_GAMESERVER_REFRESH_SERVER_CATALOG", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_REFRESH_SERVER_CATALOG);
		NETSHOPPING.set_function("NET_GAMESERVER_RETRIEVE_CATALOG_REFRESH_STATUS", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_RETRIEVE_CATALOG_REFRESH_STATUS);
		NETSHOPPING.set_function("NET_GAMESERVER_INIT_SESSION", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_INIT_SESSION);
		NETSHOPPING.set_function("NET_GAMESERVER_RETRIEVE_INIT_SESSION_STATUS", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_RETRIEVE_INIT_SESSION_STATUS);
		NETSHOPPING.set_function("NET_GAMESERVER_START_SESSION", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_START_SESSION);
		NETSHOPPING.set_function("NET_GAMESERVER_START_SESSION_PENDING", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_START_SESSION_PENDING);
		NETSHOPPING.set_function("NET_GAMESERVER_RETRIEVE_START_SESSION_STATUS", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_RETRIEVE_START_SESSION_STATUS);
		NETSHOPPING.set_function("NET_GAMESERVER_RETRIEVE_SESSION_ERROR_CODE", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_RETRIEVE_SESSION_ERROR_CODE);
		NETSHOPPING.set_function("NET_GAMESERVER_IS_SESSION_VALID", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_IS_SESSION_VALID);
		NETSHOPPING.set_function("NET_GAMESERVER_CLEAR_SESSION", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CLEAR_SESSION);
		NETSHOPPING.set_function("NET_GAMESERVER_SESSION_APPLY_RECEIVED_DATA", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_SESSION_APPLY_RECEIVED_DATA);
		NETSHOPPING.set_function("NET_GAMESERVER_IS_SESSION_REFRESH_PENDING", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_IS_SESSION_REFRESH_PENDING);
		NETSHOPPING.set_function("NET_GAMESERVER_START_SESSION_RESTART", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_START_SESSION_RESTART);
		NETSHOPPING.set_function("NET_GAMESERVER_TRANSACTION_IN_PROGRESS", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSACTION_IN_PROGRESS);
		NETSHOPPING.set_function("NET_GAMESERVER_GET_SESSION_STATE_AND_STATUS", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_GET_SESSION_STATE_AND_STATUS);
		NETSHOPPING.set_function("NET_GAMESERVER_BASKET_START", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_START);
		NETSHOPPING.set_function("NET_GAMESERVER_BASKET_END", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_END);
		NETSHOPPING.set_function("NET_GAMESERVER_BASKET_IS_ACTIVE", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_IS_ACTIVE);
		NETSHOPPING.set_function("NET_GAMESERVER_BASKET_ADD_ITEM", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_ADD_ITEM);
		NETSHOPPING.set_function("NET_GAMESERVER_BASKET_IS_FULL", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_IS_FULL);
		NETSHOPPING.set_function("NET_GAMESERVER_BASKET_APPLY_SERVER_DATA", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BASKET_APPLY_SERVER_DATA);
		NETSHOPPING.set_function("NET_GAMESERVER_CHECKOUT_START", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_CHECKOUT_START);
		NETSHOPPING.set_function("NET_GAMESERVER_BEGIN_SERVICE", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_BEGIN_SERVICE);
		NETSHOPPING.set_function("NET_GAMESERVER_END_SERVICE", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_END_SERVICE);
		NETSHOPPING.set_function("NET_GAMESERVER_DELETE_CHARACTER", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_DELETE_CHARACTER);
		NETSHOPPING.set_function("NET_GAMESERVER_DELETE_CHARACTER_GET_STATUS", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_DELETE_CHARACTER_GET_STATUS);
		NETSHOPPING.set_function("NET_GAMESERVER_DELETE_SET_TELEMETRY_NONCE_SEED", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_DELETE_SET_TELEMETRY_NONCE_SEED);
		NETSHOPPING.set_function("NET_GAMESERVER_TRANSFER_BANK_TO_WALLET", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_BANK_TO_WALLET);
		NETSHOPPING.set_function("NET_GAMESERVER_TRANSFER_WALLET_TO_BANK", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_WALLET_TO_BANK);
		NETSHOPPING.set_function("NET_GAMESERVER_TRANSFER_BANK_TO_WALLET_GET_STATUS", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_BANK_TO_WALLET_GET_STATUS);
		NETSHOPPING.set_function("NET_GAMESERVER_TRANSFER_WALLET_TO_BANK_GET_STATUS", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_WALLET_TO_BANK_GET_STATUS);
		NETSHOPPING.set_function("NET_GAMESERVER_TRANSFER_CASH_SET_TELEMETRY_NONCE_SEED", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_TRANSFER_CASH_SET_TELEMETRY_NONCE_SEED);
		NETSHOPPING.set_function("NET_GAMESERVER_SET_TELEMETRY_NONCE_SEED", LUA_NATIVE_NETSHOPPING_NET_GAMESERVER_SET_TELEMETRY_NONCE_SEED);
	}
}
