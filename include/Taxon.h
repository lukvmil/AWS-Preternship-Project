#ifndef TAXON_H
#define TAXON_H

#include <string>
#include <iostream>

#include "../include/Vertex.h"

class Taxon: public Vertex {
private:
    std::string name;
    unsigned int parent;

public:
    Taxon(std::string name_in, unsigned int parent_id) : name(name_in), parent(parent_id) {}

    ~Taxon() {}

    std::string get_name() {
        return name;
    }

    unsigned int get_parent() {
        return parent;
    }

    friend std::ostream& operator<<(std::ostream& os, Taxon& t) {
        os << t.name;
        return os;
    }

};

#endif