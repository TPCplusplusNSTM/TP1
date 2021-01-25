#ifndef RESERVATION_H
#define RESERVATION_H
#include "Date.h"
#include "Chambre.h"
#include "Client.h"
#include <vector>


using date::Date;

namespace gestion {
    class Reservation
    {
    public:
        Reservation(int idres, date::Date dbegin, date::Date dend, int idhot, int idroom, int idcli);
        Reservation() = default;

        int getIdRes() const;
        date::Date getDbegin() const;
        date::Date getDend() const;
        int getIdHotel() const;
        int getIdChambre() const;
        int getIdClient() const;
        double getTotal() const;

        void setDbegin(date::Date dbegin);
        void setDend(date::Date dend);
        void setIdroom(int idroom);
        void setIdclient(int idcli);
        void setIdhot(int idhot);
        void setIdres(int idres);

        void calc(double price_per_night, double remise);
        void setTotal(double total);

        std::string reservation_to_string();
        void enterDates();
        bool checkDates(Date a, Date b) const;
        int nbDates();    
    private:
        int _idres;
        date::Date _dbegin;
        date::Date _dend;
        int _idhot;
        int _idroom;
        int _idcli;
        double _total;
    };
    genre chooseTypeRoom();
    int enterIDReservation();
    std::ostream& operator<<(std::ostream& os, Reservation reservation);
}

#endif