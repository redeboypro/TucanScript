#include "pch.h"
#include "tucan_entity.h"

namespace tucan_script 
{
	tucan_entity::tucan_entity() : m_type(TUCAN_TYPE::NONE) {}

	tucan_entity::tucan_entity(const TUCAN_TYPE& type) : m_type(type) {}

	TUCAN_TYPE tucan_entity::getType() const
	{
		return m_type;
	}

	void tucan_entity::setType(const TUCAN_TYPE& type)
	{
		m_type = type;
	}

	tucan_undefined::tucan_undefined(const std::string& content) : m_content(content) {}

	tucan_undefined::~tucan_undefined()
	{
		m_content = std::string();
	}
}