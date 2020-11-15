#ifndef TAXON_H
#define TAXON_H

#include <string>
#include <iostream>

#include "../include/Vertex.h"

class Taxon: public Vertex {
private:
    std::string name;
    unsigned int parent;
    bool deleted;

    // std::vector<> ;

public:
    Taxon(std::string name_in, unsigned int parent_id) : name(name_in), parent(parent_id), deleted(false) {}

    ~Taxon() {}

    std::string get_name() {
        return name;
    }

    void set_parent(unsigned int id) {
        parent = id;
    }

    unsigned int get_parent() {
        return parent;
    }

    void del() {
        deleted = true;
    }

    bool alive() {
        return !deleted;
    }

    friend std::ostream& operator<<(std::ostream& os, Taxon& t) {
        os << t.name;
        return os;
    }

};

#endif