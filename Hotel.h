#ifndef HOTEL_H
#define HOTEL_H
#include <string>
namespace hotel {
	class Hotel{
	public:
		Hotel(std::string name, int idhotel);
	private:
		std::string _name;
		int _idhotel;
	};

}
#endif