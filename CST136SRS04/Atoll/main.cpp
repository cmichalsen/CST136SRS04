// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include "GPS.h"
#include <vector>
using namespace GPS;


void useVector(const std::array<GPS::Location, 12> container)
{
	std::vector <std::reference_wrapper<const GPS::Location>> southNorth;

	for (auto i = 0; i < 12; i++)
	{
		southNorth.push_back(container.at(i));
	}
	
	std::sort(southNorth.begin(), southNorth.end(), [](const Location& a, const Location& b) noexcept
	{
		return a.isMaxLong(&b);
	});


	std::vector <std::reference_wrapper<const GPS::Location>> westEast;

	for (auto i = 0; i < 12; i++)
	{
		westEast.push_back(container.at(i));
	}

	std::sort(westEast.begin(), westEast.end(), [](const Location& a, const Location& b) noexcept
	{
		return a.isMaxLat(&b);
	});


}

int main() noexcept
{

	std::array<GPS::Location, 12> island
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

	useVector(island);


GPS::Location test1 = GPS::Location{
	"Faichuk Islands",
	GPS::Latitude{ GPS::Latitude::Cardinal::N, 7, 21, 8 },
	GPS::Longitude{ GPS::Longitude::Cardinal::E, 151, 36, 30 }
};

GPS::Location test2 = GPS::Location{
	"Faichuk Islands",
	GPS::Latitude{ GPS::Latitude::Cardinal::N, 9, 21, 8 },
	GPS::Longitude{ GPS::Longitude::Cardinal::E, 161, 36, 30 }
};

//GPS::Location test3(test2);
//
//bool testthis = test1.isMaxLong(&test2);

//auto test = test1.getDistance(&test2);


return 0;
}

