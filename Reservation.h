#ifndef RESERVATION_H
#define RESERVATION_H
#include "Date.h"
#include "hotel.h"
#include "client.h"


using date::Date;

namespace gestion {
    class Reservation
    {
    private:
        int _idres;
        date::Date _dbegin;
        date::Date _dend;
        int _idhot;
        int _idroom;
        int _idcli;
        double _total;
    public:
        Reservation(int idres, date::Date dbegin, date::Date dend, int idhot, int idroom, int idcli);
        int idres() const;
        date::Date dbegin() const;
        date::Date dend() const;
        int idhot() const;
        int idroom() const;
        int idcli() const;
        double total() const;
        void setDbegin(date::Date dbegin);
        void setDend(date::Date dend);
        void setIdroom(int idroom);
        void calc(double price_per_night, double remise);
        std::string reservation_to_string();
    };
}

#endif