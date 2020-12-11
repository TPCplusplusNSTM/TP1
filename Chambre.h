#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>
namespace gestion {
    enum class genre { Single, Double, Suite, Twin };
    class Chambre {
    public:
        
        Chambre(int id, genre type, int price);
        int id() const;
        genre type() const;
        int price() const;
        void setId(int id);
        void setType(genre type);
        void setPrice(int price);
        std::string toStringChambre() const;
    private:
        int _id;
        genre _type;
        int _price;
    };
}


#endif