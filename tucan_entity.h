#pragma once
#include <string>

namespace tucan_script 
{
	enum class TUCAN_TYPE
	{
		UNDEFINED = -2,
		NONE = -1,

		STRING = 0,
		INTEGER = 1,
		DOUBLE = 2,
		BOOLEAN = 3,

		LPAREN = 4,
		RPAREN = 5,

		EQUAL = 6,
		DOUBLE_EQUAl = 7,
		GEQUAL = 8,
		LEQUAL = 9,
		GREATER = 10,
		LESS = 11,
		PLUS_EQUAL = 12,
		MINUS_EQUAL = 13,
		MUL_EQUAL = 14,
		DIV_EQUAL = 15,
		PLUS = 18,
		MINUS = 19,
		PERCENT = 20,
		MUL = 21,
		DIV = 22,

		AND = 23,
		OR = 24,

		IF = 25,
		WHILE = 26,

		DEF = 27,
		IMP = 28,

		SEMICOLON = 29,
		COMMA = 30,

		LBLOCK = 31,
		RBLOCK = 32,

		BREAK = 33,
		RETURN = 34,
		CALL = 35,
		REF = 36,

		ARRAY = 37,

		FOR = 38,
		INSIDE = 39,

		CONTINUE = 40
	};

	class tucan_resetable
	{
	public:
		virtual void reset() = 0;
	};

	class tucan_entity
	{
	private:
		TUCAN_TYPE m_type;

	public:
		tucan_entity();
		tucan_entity(const TUCAN_TYPE& type);

		TUCAN_TYPE getType() const;

	protected:
		void setType(const TUCAN_TYPE& type);
	};

	class tucan_undefined : public tucan_entity
	{
	private:
		std::string m_content;

	public:
		tucan_undefined(const std::string& content);
		~tucan_undefined();
	};
}
