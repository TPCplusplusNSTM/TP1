#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>
#include <iostream>
enum genre { Single, Double, Suite, Twin };

namespace gestion {
    class Chambre
    {
    public:
        Chambre(int id, genre type, double price);
        int id() const;
        genre type() const;
        double price() const;
        bool dispo() const;
        void setId(int id);
        void setType(genre type);
        void setPrice(double price);
        void setDispo(bool dispo);
        std::string type_to_string(genre type);
        std::string Chambre_to_string();
    private:
        int _id;
        genre _type;
        double _price;
        bool _dispo;
    };
    std::ostream& operator<<(std::ostream& os, Chambre chambre);
}

#endif
