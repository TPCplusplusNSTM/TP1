#include "reservation.h"
#include "Date.h"

using date::Date;

namespace gestion {
    Reservation::Reservation(int idres, date::Date dbegin, date::Date dend, int idhot, int idroom, int idcli, double total) : _idres(idres), _dbegin(dbegin), _dend(dend), _idhot(idhot), _idroom(idroom), _idcli(idcli), _total(total) {}

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

    double Reservation::calc(double price_per_night, double remise) {
        int days = 0;
        date::Date dind = _dbegin;
        while (dind != _dend) {
            dind.nextDay();
            days++;
        }
        return price_per_night * days * (1 - remise / 100);
    }

}