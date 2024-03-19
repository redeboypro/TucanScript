#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <concepts>
#include "tucan_entity.h"

namespace tucan_script 
{
	template <typename T>
	concept numeric = std::integral<T> || std::floating_point<T>;

	class tucan_operable : public tucan_entity
	{
	private:
		std::vector<tucan_operable> m_arrayValues;
		std::string m_stringValue;
		long long m_intValue;
		double m_floatValue;
		bool m_boolValue;

	public:
		tucan_operable();
		tucan_operable(const TUCAN_TYPE& type);
		~tucan_operable();

		size_t length() const;

		const std::string& getStringValue() const;
		long long getIntValue() const;
		double getFloatValue() const;
		bool getBoolValue() const;

		bool isArray() const;
		bool isString() const;
		bool isInt() const;
		bool isFloat() const;
		bool isBoolean() const;

		void set(const std::string &rValue);
		void set(long long rValue);
		void set(double rValue);
		void set(bool rValue);
		void set(const tucan_operable& rValue);

		void add(const std::string& rValue);
		void add(numeric auto rValue);
		void add(const tucan_operable& rValue);

		void sub(numeric auto rValue);
		void sub(const tucan_operable& rValue);

		void mul(numeric auto rValue);
		void mul(const tucan_operable& rValue);

		void div(numeric auto rValue);
		void div(const tucan_operable& rValue);

		void rem(numeric auto rValue);
		void rem(const tucan_operable& rValue);

		void equal(const std::string& rValue);
		void equal(long long rValue);
		void equal(double rValue);
		void equal(bool rValue);
		void equal(const tucan_operable& rValue);

		void greater(numeric auto rValue);
		void greater(const tucan_operable& rValue);

		void less(numeric auto rValue);
		void less(const tucan_operable& rValue);

		void gEqual(numeric auto rValue);
		void gEqual(const tucan_operable& rValue);

		void lEqual(numeric auto rValue);
		void lEqual(const tucan_operable& rValue);

		void conjunction(bool rValue);
		void conjunction(const tucan_operable& rValue);

		void disjunction(bool rValue);
		void disjunction(const tucan_operable& rValue);

		tucan_operable& operator[](const size_t& index);
		void setElement(const size_t& index, const tucan_operable& value);

		std::string toString() const;
		long long toInt() const;
		double toFloat() const;
		bool toBoolean() const;

	protected:
		void set(
			const TUCAN_TYPE& type,
			const std::string& stringValue,
			const long long& intValue,
			const double& floatValue,
			const bool& boolValue,
			const std::vector<tucan_operable>& arrayValues);

		void set(
			const TUCAN_TYPE& type,
			const std::string& stringValue,
			const long long& intValue,
			const double& floatValue,
			const bool& boolValue);
	};
}
