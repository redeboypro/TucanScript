#pragma once
#include "tucan_const.h"
#include <unordered_map>

namespace tucan_script
{
    const char QUOTE_CHAR = '"';
    const char SHARP_CHAR = '#';

    static std::unordered_map<char, TUCAN_TYPE> single_token_map =
    {
        { '=', TUCAN_TYPE::EQUAL },
        { '*', TUCAN_TYPE::MUL },
        { '/', TUCAN_TYPE::DIV },
        { '%', TUCAN_TYPE::PERCENT },
        { '+', TUCAN_TYPE::PLUS },
        { '-', TUCAN_TYPE::MINUS },
        { '>', TUCAN_TYPE::GREATER },
        { '<', TUCAN_TYPE::LESS },
        { '(', TUCAN_TYPE::LPAREN },
        { ')', TUCAN_TYPE::RPAREN },
        { '{', TUCAN_TYPE::LBLOCK },
        { '}', TUCAN_TYPE::RBLOCK },
        { ';', TUCAN_TYPE::SEMICOLON },
        { ',', TUCAN_TYPE::COMMA },
        { '&', TUCAN_TYPE::REF }
    };

    static std::unordered_map<std::string, TUCAN_TYPE> reserved_token_map =
    {
        { "and", TUCAN_TYPE::AND },
        { "or", TUCAN_TYPE::AND },
        { "if", TUCAN_TYPE::AND },
        { "while", TUCAN_TYPE::AND },
        { "define", TUCAN_TYPE::AND },
        { "implement", TUCAN_TYPE::IMP },
        { "for", TUCAN_TYPE::FOR },
        { "in", TUCAN_TYPE::INSIDE },
        { "break", TUCAN_TYPE::BREAK },
        { "continue", TUCAN_TYPE::CONTINUE },
        { "return", TUCAN_TYPE::RETURN }
    };

    static bool isOperator(TUCAN_TYPE type);

    static bool isSingleCharToken(char src, TUCAN_TYPE& type);

    static bool isReservedToken(const std::string& src, TUCAN_TYPE& type);

    static std::vector<tucan_entity> tokenize(const std::string& src);

    static tucan_entity parseToken(const std::string& src);

    template<typename T>
    static bool h_tryGetValue(const std::unordered_map<T, TUCAN_TYPE>& map, const T& src, TUCAN_TYPE& type);

    static bool h_tryParseBool(const std::string& str, bool& value);
}

