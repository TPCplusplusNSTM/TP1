#include "chambre.h"

namespace gestion {
	
	Chambre::Chambre(int id, genre type, int price) : _id(id), _type(type), _price(price) {};
	
	int Chambre::id() const {
		return _id;
	};

	genre Chambre::type() const {
		return _type;
	};

	int Chambre::price() const {
		return _price;
	};

	void Chambre::setId(int id) {
		_id = id;
	};

	void setType(genre type) { 
		_type = type;
	};

	void setPrice(int price) { 
		_price = price;
	};

};
