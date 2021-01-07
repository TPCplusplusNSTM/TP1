#include "reservation.h"
#include "Date.h"

using date::Date;

namespace gestion {
    Reservation::Reservation(int idres, date::Date dbegin, date::Date dend, int idhot, int idroom, int idcli) : _idres(idres), _dbegin(dbegin), _dend(dend), _idhot(idhot), _idroom(idroom), _idcli(idcli), _total(0) {}

    int Reservation::idres() const {
        return _idres;
    }

    date::Date Reservation::dbegin() const {
        return _dbegin;
    }

    date::Date Reservation::dend() const {
        return _dend;
    }

    int Reservation::idhot() const {
        return _idhot;
    }

    int Reservation::idroom() const {
        return _idroom;
    }

    int Reservation::idcli() const {
        return _idcli;
    }

    double Reservation::total() const {
        return _total;
    }

    void Reservation::setDbegin(date::Date dbegin) {
        _dbegin = dbegin;
    }

    void Reservation::setDend(date::Date dend) {
        _dend = dend;
    }

    void Reservation::setIdroom(int idroom) {
        _idroom = idroom;
    }

    void Reservation::calc(double price_per_night, double remise) {
        int days = 0;
        date::Date dind = _dbegin;
        while (dind != _dend) {
            dind.nextDay();
            days++;
        };
        _total = price_per_night * days * (1 - remise / 100);
    }

    std::string Reservation::reservation_to_string() {
        return "idres = " + std::to_string(_idres) + ", dbegin = " + _dbegin.toString() + ", dend = " + _dend.toString() + ", idhot = " + std::to_string(_idhot) + ", idroom = " + std::to_string(_idroom) + ", idcli = " + std::to_string(_idcli) + ", total = " + std::to_string(_total);
    }

    genre chooseTypeRoom() {
        bool test = false;
        std::string type;
        genre typec = Single;
        while (test == false) {
            std::cout << "Entrez le type de chambre souhaite (Single, Double, Suite, Twin)" << std::endl;
            std::cin >> type;
            if (type.compare("Single") == 0) {
                typec = Single;
                test = true;
            }
            else if (type.compare("Double") == 0) {
                typec = Double;
                test = true;
            }
            else if (type.compare("Suite") == 0) {
                typec = Suite;
                test = true;
            }
            else if (type.compare("Twin") == 0) {
                typec = Twin;
                test = true;
            }
            else {
                std::cout << "Incorrecte : veuillez taper exactement le contenu entre parentheses" << std::endl;
            }
        }
        return typec;
    }
}