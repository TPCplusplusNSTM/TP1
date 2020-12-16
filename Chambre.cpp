#include "Chambre.h"

namespace gestion {

    Chambre::Chambre(int id, genre type, double price) : _id(id), _type(type), _price(price) {}

    int Chambre::id() const {
        return _id;
    }

    genre Chambre::type() const {
        return _type;
    }

    double Chambre::price() const {
        return _price;
    }

    void Chambre::setId(int id) {
        _id = id;
    }

    void Chambre::setType(genre type) { _type = type; }

    void Chambre::setPrice(double price) { _price = price; }

    std::string Chambre::type_to_string(genre type) {
        if (type == 0) {
            return "Single";
        }
        else {
            if (type == 1) {
                return "Double";
            }
            else {
                if (type == 2) {
                    return "Suite";
                }
                else {
                    return "Twin";
                }
            }
        }
    }

    std::string Chambre::Chambre_to_string() {
        return "id = " + std::to_string(_id) + ", type = " + type_to_string(_type) + ", prix = " + std::to_string(_price);
    }

    std::ostream& operator<<(std::ostream& os, Chambre chambre) {
        os << chambre.Chambre_to_string() << std::endl;
        return os;
    }
}

