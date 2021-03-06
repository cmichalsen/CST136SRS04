#pragma once
template<typename T, T min, T max>
class Range // You should re-code and simplify your SRS01 RangeInt
{
private:
	using value_type = T;

	value_type value_;

public:
	Range(const value_type value) noexcept
		:value_(value)
	{
	}

	value_type operator *(const value_type value) const noexcept
	{
		return this->value_ * value;
	}

	double getValue() const noexcept
	{
		return value_;
	}
};
