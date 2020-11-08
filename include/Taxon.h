#ifndef TAXON_H
#define TAXON_H

#include <string>
#include <iostream>

#include "../include/Vertex.h"

class Taxon: public Vertex<int> {
private:
    std::string name;

public:
    Taxon(std::string name_in) : name(name_in) {}

    ~Taxon() {}

    friend std::ostream& operator<<(std::ostream& os, Taxon& t) {
        os << t.name;
        return os;
    }

};

#endif