#ifndef HOTEL_H
#define HOTEL_H
#include "Chambre.h"
#include <string>
#include <vector>
namespace hotel {
	class Hotel {
	public:
		Hotel(std::string name, std::string ville, int idhotel, int maxnbchambres);

		std::string getNameHotel() const;
		int getIdHotel() const;
		std::string getVilleHotel() const;
		int getChambresDispo() const;

		void addChambre(gestion::Chambre &chambre);
		void setNameHotel(std::string name);
		void setVilleHotel(std::string ville);
		void setIdHotel(int id);

	private:
		std::string _name;
		int _idhotel;
		std::string _ville;
		int _dispo;
		std::vector<gestion::Chambre> _chambresliste ;
		int const _maxnbchambres ;
	};

}
#endif