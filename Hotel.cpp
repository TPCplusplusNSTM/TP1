#include "Hotel.h"
#include <assert.h>
namespace hotel {
	Hotel::Hotel(std::string name, std::string ville, int idhotel, int maxnbchambres) : _name(name), _idhotel(idhotel), _ville(ville), _dispo(0), _maxnbchambres(maxnbchambres){}
	std::string Hotel::getNameHotel() const {
		return _name;
	}
	int Hotel::getIdHotel() const {
		return _idhotel;
	}
	std::string Hotel::getVilleHotel() const {
		return _ville;
	}
	int Hotel::getChambresDispo() const {
		return _dispo;
	}
	void Hotel::addChambre(gestion::Chambre &chambre) {
		_chambresliste.push_back(chambre);
	}
	void Hotel::setNameHotel(std::string name) {
		assert(name != "" && name != " ");
		_name = name;
	}
	void Hotel::setVilleHotel(std::string ville) {
		assert(ville != "" && ville != " ");
		_ville = ville;
	}
	void Hotel::setIdHotel(int id) {
		assert(id != 0);
		_idhotel = id;
	}
}
