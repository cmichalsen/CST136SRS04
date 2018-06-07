#pragma once
#include <string>
#include "Range.h"

namespace GPS
{
	template<int min, int max>
	class Angle
	{
		static_assert(min < max);

	private:
		using base_degree_type = int;
		using base_minute_type = unsigned;
		using base_second_type = unsigned;

	protected:
		using degree_type = Range<base_degree_type, min, max>;
		using minute_type = Range<base_minute_type, 0, 60>;
		using second_type = Range<base_second_type, 0, 60>;

	private:
		const degree_type degree_;
		const minute_type minute_;
		const second_type second_;

	public:

		Angle(const degree_type degree, const minute_type minute, const second_type second) noexcept
			:degree_(degree), minute_(minute), second_(second){}
		
		double getRadian() const noexcept
		{
			const auto degrees{ getDegrees() };
			const auto pi{ 3.14 };
			return (degrees * pi) / 180 ;
		}

		double getDegrees() const noexcept
		{
			const auto minutes{ minute_.getValue() };
			const auto seconds{ second_.getValue() };
			const auto degrees{ degree_.getValue() };
			const auto degreeSum{ degrees + (minutes / 60) + (seconds / 3600) };
			return degreeSum;
		}



	};

	class Latitude : public Angle<-89, 90>
	{
	private:
		double radian{ 0 };


	public:
		enum class Cardinal { S = -1, N = +1 };


		Latitude(const Cardinal cardinal, const degree_type degree, const minute_type minute,
		         const second_type second) noexcept;

		static int convertPolarity(Cardinal cardinal, degree_type degree) noexcept
		{
			return degree * static_cast<int>(cardinal);
		}
	};

	class Longitude : public Angle<-180, 180>
	{
	private:
		double radian{ 0 };

	public:
		enum class Cardinal { W = -1, E = +1 };

		Longitude(const Cardinal cardinal, const degree_type degree, const minute_type minute,
		          const second_type second) noexcept;

		static int convertPolarity(Cardinal cardinal, degree_type degree) noexcept
		{
			return degree * static_cast<int>(cardinal);
		}

		bool operator <(const Longitude* const longitude2) const noexcept
		{
			return this->getDegrees() < longitude2->getDegrees();
		}
	};

	class Location
	{
	private:
		const std::string name_;
		const Latitude latitude_;
		const Longitude longitude_;

	public:

		Location(const std::string name, const Latitude latitude, const Longitude longitude);


		Location& operator=(Location other) noexcept
		{

			//std::swap(*this, other);

			return *this;
		}

		double getDistance(const Location* const location2) const noexcept
		{
			const auto earthRadius{ 6378 }; // kilometers
			const auto lat1{ this->latitude_.getRadian() };
			const auto lat2{ location2->latitude_.getRadian() };
			const auto long1{ this->longitude_.getRadian() };
			const auto long2{ location2->longitude_.getRadian() };
			const auto sinLat{ sin((lat2 - lat1) / 2) };
			const auto sinLong{ sin((long2 - long1) / 2) };

			const auto haversine{ 2 * earthRadius * asin(sqrt(sinLat * sinLat + cos(lat1) * cos(lat2) * sinLong * sinLong)) };

			return haversine;
		}

		bool isMaxLong(const Location* const location2) const noexcept
		{
			return this->longitude_ < &location2->longitude_;
		}

	};
}
