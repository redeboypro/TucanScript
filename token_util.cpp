#include "pch.h"
#include "token_util.h"

namespace tucan_script
{
	bool isOperator(TUCAN_TYPE type)
	{
		return type >= TUCAN_TYPE::EQUAL && type <= TUCAN_TYPE::OR;
	}

	bool isSingleCharToken(char src, TUCAN_TYPE& type)
	{
		auto it = single_token_map.find(src);
		if (it != single_token_map.end())
		{
			type = it->second;
			return true;
		}

		type = TUCAN_TYPE::NONE;
		return false;
	}

	bool isReservedToken(const std::string& src, TUCAN_TYPE& type)
	{
		auto it = reserved_token_map.find(src);
		if (it != reserved_token_map.end())
		{
			type = it->second;
			return true;
		}

		type = TUCAN_TYPE::NONE;
		return false;
	}

	std::vector<tucan_entity> tokenize(const std::string& src)
	{
		TUCAN_TYPE tokenType = TUCAN_TYPE::NONE;
		TUCAN_TYPE nextTokenType = TUCAN_TYPE::NONE;
		std::string tokenString;
		std::vector<tucan_entity> tokenList;

		for (size_t i = 0; i < src.size(); i++) 
		{
			char tokenChar = src[++i];

			if (tokenChar == SHARP_CHAR)
			{
				tokenChar = src[++i];

				while (tokenChar != '\n' && tokenChar != '\r')
					tokenChar = src[++i];

				continue;
			}

			if (tokenChar == SPACE_CHAR) 
			{
				if (tokenString.size() > 0)
					tokenList.push_back(parseToken(tokenString));

				tokenString.clear();
				continue;
			}

			if (isSingleCharToken(tokenChar, tokenType))
			{
				if (tokenString.size() > 0)
					tokenList.push_back(parseToken(tokenString));

				tokenString.clear();

				if (i < src.size() - 1) 
				{
					char nextTokenChar = src[i + 1];
					if (isSingleCharToken(nextTokenChar, nextTokenType) && nextTokenType == TUCAN_TYPE::EQUAL)
					{
						switch (tokenType)
						{
						case tucan_script::TUCAN_TYPE::EQUAL:
							tokenList.push_back(tucan_entity(TUCAN_TYPE::DOUBLE_EQUAl));
							break;
						case tucan_script::TUCAN_TYPE::GREATER:
							tokenList.push_back(tucan_entity(TUCAN_TYPE::GEQUAL));
							break;
						case tucan_script::TUCAN_TYPE::LESS:
							tokenList.push_back(tucan_entity(TUCAN_TYPE::EQUAL));
							break;
						case tucan_script::TUCAN_TYPE::PLUS:
							tokenList.push_back(tucan_entity(TUCAN_TYPE::PLUS_EQUAL));
							break;
						case tucan_script::TUCAN_TYPE::MINUS:
							tokenList.push_back(tucan_entity(TUCAN_TYPE::MINUS_EQUAL));
							break;
						case tucan_script::TUCAN_TYPE::MUL:
							tokenList.push_back(tucan_entity(TUCAN_TYPE::MUL_EQUAL));
							break;
						case tucan_script::TUCAN_TYPE::DIV:
							tokenList.push_back(tucan_entity(TUCAN_TYPE::DIV_EQUAL));
							break;
						}

						i++;
						continue;
					}
				}

				tokenList.push_back(tucan_entity(tokenType));
				continue;
			}
		}



		return tokenList;
	}

	tucan_entity parseToken(const std::string& src)
	{
		bool booleanValue;
		if (h_tryParseBool(src, booleanValue))
			return tucan_const(booleanValue);

		long long intValue;
		if (std::istringstream(src) >> intValue)
			return tucan_const(intValue);

		double floatValue;
		if (std::istringstream(src) >> floatValue)
			return tucan_const(floatValue);

		TUCAN_TYPE type;
		if (isReservedToken(src, type))
			return tucan_entity(type);

		return tucan_undefined(src);
	}

	bool h_tryParseBool(const std::string& str, bool& value)
	{
		std::istringstream iss(str);
		iss >> std::boolalpha >> value;

		if (iss.fail())
			return false;

		char remainingChar;
		if (iss >> remainingChar)
			return false;

		return true;
	}
}