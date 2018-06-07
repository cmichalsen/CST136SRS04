#include "stdafx.h"
#include "GPS.h"


GPS::Latitude::Latitude(const Cardinal cardinal, const degree_type degree, const minute_type minute,
                        const second_type second) noexcept: Angle(convertPolarity(cardinal, degree), minute, second),
                                                            radian(this->getRadian())
{
}

GPS::Longitude::Longitude(const Cardinal cardinal, const degree_type degree, const minute_type minute,
                          const second_type second) noexcept: Angle(convertPolarity(cardinal, degree), minute, second),
                                                              radian(this->getRadian())
{
}

GPS::Location::Location(const std::string name, const Latitude latitude, const Longitude longitude)
: name_(name), latitude_(latitude), longitude_(longitude)
{
}


