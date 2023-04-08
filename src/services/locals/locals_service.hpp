#pragma once

#include "gta/script_thread.hpp"
#include "file_manager/file.hpp"
#include "file_manager.hpp"
#include "script_local.hpp"
#include "gta_util.hpp"

namespace big
{

	struct local_offset
	{
		local_offset(int offset, int size = 0)
		{
			m_offset = offset;

			if (size)
				m_size = size;
		}

		int m_offset = 0;
		int m_size   = 0;
	};


	struct local
	{
		GtaThread* m_script_thread;
		std::string m_script_thread_name;
		int m_base_address;
		bool m_freeze = false;
		std::string m_name;
		std::vector<local_offset> m_offsets;
		int m_value;
		int m_freeze_value;
		int* m_internal_address;

		local(const char* script_thread_name, const char* name, const int base_address, const bool freeze, const int (*offsets)[2], int offset_count)
		{
			m_internal_id = ++m_instance_count;

			m_script_thread_name = script_thread_name;
			m_base_address       = base_address;
			m_freeze             = freeze;
			m_name               = std::string(name);
			m_value              = 0;

			for (int i = 0; i < offset_count; i++)
				m_offsets.push_back(local_offset(offsets[i][0], offsets[i][1]));

			fetch_local_pointer();
		}

		int get_id()
		{
			return m_internal_id;
		}

		int* fetch_local_pointer()
		{
			m_script_thread = gta_util::find_script_thread(rage::joaat(m_script_thread_name));
			
			if(m_script_thread){
				script_local actual_local = script_local(m_script_thread, m_base_address);

				for (auto offset : m_offsets)
				{
					if (offset.m_size > 0)
						actual_local.at(offset.m_offset, offset.m_size);
					else
						actual_local.at(offset.m_offset);
				}

				m_internal_address = actual_local.as<int*>();

				return m_internal_address;
			}
			return nullptr;
		}

	private:
		inline static int m_instance_count;
		int m_internal_id;
	};


	class locals_service
	{
	
	public:
		std::filesystem::path get_path();
		bool load();
		void save();

		static bool does_script_exist(std::string script);
		static bool is_script_thread_running(GtaThread* thread);

		std::vector<local> m_locals;
		bool m_running = false;
	};

	inline locals_service g_locals_service{};
}