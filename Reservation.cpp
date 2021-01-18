#include "reservation.h"

using date::Date;


namespace gestion {

//Reservation -------------------------------------------------------------------------------------------------
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
        std::cout << "Le prix du séjour sera de " << _total << " euros" << std::endl;
    }

    std::string Reservation::reservation_to_string() {
        return "idres = " + std::to_string(_idres) + ", dbegin = " + _dbegin.toString() + ", dend = " + _dend.toString() + ", idhot = " + std::to_string(_idhot) + ", idroom = " + std::to_string(_idroom) + ", idcli = " + std::to_string(_idcli) + ", total = " + std::to_string(_total);
    }

    void Reservation::enterDates()
    {
        Date a; Date b;
        int stockage;
        bool estConforme = false;
        while (not estConforme) {
            std::cout << "Entrer l'année de votre première date de réservation" << std::endl;
            std::cin >> stockage;
            a.setYear(stockage);
            std::cout << "Entrer le mois de votre première date de réservation" << std::endl;
            std::cin >> stockage;
            a.setMonth(stockage);
            std::cout << "Entrer le jour de votre première date de réservation" << std::endl;
            std::cin >> stockage;
            a.setDay(stockage);
            std::cout << "Entrer l'année de votre deuxième date de réservation" << std::endl;
            std::cin >> stockage;
            b.setYear(stockage);
            std::cout << "Entrer le mois de votre deuxième date de réservation" << std::endl;
            std::cin >> stockage;
            b.setMonth(stockage);
            std::cout << "Entrer le jour de votre deuxième date de réservation" << std::endl;
            std::cin >> stockage;
            b.setDay(stockage);
            if (a.checkDate() && b.checkDate() && a <= b) {
                estConforme = true;
            }
            else {
                std::cout << "Les dates ne sont pas conformes veuillez rentrer de nouveau les dates" << std::endl;
            }
        }
        _dbegin = a;
        _dend = b;
        Reservation r;
        r.setDbegin(a);
        r.setDend(b);
        std::cout << "Votre réservation comporte " << r.nbDates() << "nuits" << std::endl;
    }

    int Reservation::nbDates() {
        if (_dbegin.checkDate() && _dend.checkDate() && _dbegin <= _dend) {
            int days = 0;
            date::Date dind = _dbegin;
            while (dind != _dend) {
                dind.nextDay();
                days++;
            };
            return days;
        }
        else {
            std::cout << "Les dates ne sont pas conformes" << std::endl;
        }
    }


//free fonction -----------------------------------------------------------------------------------------------

    std::ostream& operator<<(std::ostream& os, Reservation reservation) {
        os << reservation.reservation_to_string() << std::endl;
        return os;
    }

    genre chooseTypeRoom() {
        bool test = false;
        std::string type;
        genre typec = Single;
        while (test == false) {     // On compare les chaînes de caractères entrées par l'utilisateur
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
                std::cout << "Incorrect : veuillez entrer exactement le contenu entre parentheses" << std::endl;
            }
        }
        return typec;
    }
}
