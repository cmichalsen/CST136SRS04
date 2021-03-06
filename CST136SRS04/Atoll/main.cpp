// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include "GPS.h"
#include <vector>
#include <functional>
#include <numeric>
#include <forward_list>
#include <map>
using namespace GPS;

struct classcomp  // http://www.cplusplus.com/reference/map/map/map/
{
	bool operator() (const Location& lhs, const Location& rhs) const
	{
		return lhs.isMaxLat(&rhs);
	}
};


void useVectorSN(const std::array<GPS::Location, 12> const container)
{
	std::vector <std::reference_wrapper<const GPS::Location>> southNorth; // use the reference wrapper to wrap the object by storing a pointer to it. 
	std::vector <GPS::Location> nonReferenceVector;
	std::vector <double> sumDistances;

	for (auto i{ 0 }; i < container.size(); i++) 
	{
		southNorth.push_back(container.at(i));
	}

	std::sort(southNorth.begin(), southNorth.end(), [](const Location& a, const Location& b) noexcept
	{
		return a.isMaxLat(&b);
	});

	for (auto i{ 0 }; i < container.size(); i++)
	{
		nonReferenceVector.push_back(southNorth.at(i));
	
	}

	for (auto i{ 0 }; i < container.size()-1; i++)
	{
		sumDistances.push_back(nonReferenceVector[i].getDistance(&nonReferenceVector[i + 1]));

	}

	auto totalDistance{ std::accumulate(sumDistances.begin(),sumDistances.end(),0.0) };
}


void useVectorWE(const std::array<GPS::Location, 12> const container)
{

	std::vector <std::reference_wrapper<const GPS::Location>> westEast;
	std::vector <GPS::Location> nonReferenceVector;
	std::vector <double> sumDistances;

	for (auto i{ 0 }; i < 12; i++)
	{
		westEast.push_back(container.at(i));
	}

	std::sort(westEast.begin(), westEast.end(), [](const Location& a, const Location& b) noexcept
	{
		return a.isMaxLong(&b);
	});

	for (auto i{ 0 }; i < container.size(); i++)
	{
		nonReferenceVector.push_back(westEast.at(i));

	}

	for (auto i{ 0 }; i < container.size() - 1; i++)
	{
		sumDistances.push_back(nonReferenceVector[i].getDistance(&nonReferenceVector[i + 1]));

	}

	auto totalDistance{ std::accumulate(sumDistances.begin(),sumDistances.end(),0.0) };

}

void useForwardListSN(const std::array<GPS::Location, 12> const container)
{
	std::forward_list<std::reference_wrapper<const GPS::Location>> southNorth;
	std::vector <GPS::Location> nonReferenceVector;
	std::vector <double> sumDistances;
	
	for (auto i{ 0 }; i < 12; i++)
	{
		southNorth.push_front(container.at(i));
	}

	southNorth.sort([](const Location& a, const Location& b) noexcept
	{
		return a.isMaxLat(&b);  
	});

	for (auto i{ 0 }; i < container.size(); i++)
	{
		nonReferenceVector.push_back(southNorth.front()); // can only access first element in this container
		southNorth.pop_front(); // remove first element

	}

	for (auto i{ 0 }; i < container.size() - 1; i++)
	{
		sumDistances.push_back(nonReferenceVector[i].getDistance(&nonReferenceVector[i + 1]));

	}

	auto totalDistance{ std::accumulate(sumDistances.begin(),sumDistances.end(),0.0) };
}


void useForwardListWE(const std::array<GPS::Location, 12> const container)
{
	std::forward_list<std::reference_wrapper<const GPS::Location>> westEast;
	std::vector <GPS::Location> nonReferenceVector;
	std::vector <double> sumDistances;

	for (auto i{ 0 }; i < 12; i++)
	{
		westEast.push_front(container.at(i));
	}

	westEast.sort([](const Location& a, const Location& b) noexcept
	{
		return a.isMaxLong(&b);  
	});

	for (auto i{ 0 }; i < container.size(); i++)
	{
		nonReferenceVector.push_back(westEast.front()); // can only access first element in this container
		westEast.pop_front(); // remove first element

	}

	for (auto i{ 0 }; i < container.size() - 1; i++)
	{
		sumDistances.push_back(nonReferenceVector[i].getDistance(&nonReferenceVector[i + 1]));

	}

	auto totalDistance{ std::accumulate(sumDistances.begin(),sumDistances.end(),0.0) };
}

void useMapSN(const std::array<GPS::Location, 12> const container) // did not get this to work
{
	//std::map<std::reference_wrapper<const GPS::Location>, bool, classcomp> southNorth (container.begin(), container.end());
	std::vector <GPS::Location> nonReferenceVector;
	std::vector <double> sumDistances;

}

int main() noexcept
{
	const std::array<GPS::Location, 12> island
	{
		GPS::Location{
			"Faichuk Islands",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 7, 21, 8},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 151, 36, 30}
		},

		GPS::Location{
			"Hawaii",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 21, 18, 41},
			GPS::Longitude{GPS::Longitude::Cardinal::W, 157, 47, 47}
		},

		GPS::Location{
			"Mariana Islands",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 17, 0, 0},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 146, 0, 0}
		},

		GPS::Location{
			"Johnston Atoll",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 16, 44, 13},
			GPS::Longitude{GPS::Longitude::Cardinal::W, 169, 31, 26}
		},


		GPS::Location{
			"Kosrae",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 5, 19, 0},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 162, 59, 0}
		},

		GPS::Location{
			"Falalop",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 10, 1, 14},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 139, 47, 23}
		},

		GPS::Location{
			"Guam",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 13, 30, 0},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 144, 48, 0}
		},

		GPS::Location{
			"Pohnpei",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 6, 51, 0},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 158, 13, 0}
		},

		GPS::Location{
			"Marshall Islands",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 7, 7, 0},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 171, 4, 0}
		},

		GPS::Location{
			"Yap",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 9, 32, 0},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 138, 7, 0}
		},

		GPS::Location{
			"Wake Island",
			GPS::Latitude{GPS::Latitude::Cardinal::N, 19, 17, 43},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 166, 37, 52}
		},

		GPS::Location{
			"New Zealand",
			GPS::Latitude{GPS::Latitude::Cardinal::S, 41, 17, 0},
			GPS::Longitude{GPS::Longitude::Cardinal::E, 174, 27, 0}
		}


	};

	useVectorSN(island);
	useForwardListSN(island);

return 0;
}

