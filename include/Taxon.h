#ifndef TAXON_H
#define TAXON_H

#include <string>
#include <iostream>

#include "Vertex.h"
#include "File.h"

#define uint unsigned int

class Taxon: public Vertex {
private:
    std::string name;
    uint id;
    uint parent;
    bool deleted;

    // edges to files
    std::vector<uint> f_edges;

public:
    Taxon(std::string name_in, uint parent_id) : name(name_in), id(), parent(parent_id), deleted(false), f_edges() {}

    ~Taxon() {}

    std::string get_name() {
        return name;
    }

    void set_id(uint id_in) {
        id = id_in;
    }

    uint get_id() {
        return id;
    }

    void set_parent(uint id_in) {
        parent = id_in;
    }

    uint get_parent() {
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


    // file edge handling, identical to edge functions in Vertex.h
    void add_f_edge(uint f_dest) {
        for (uint i = 0; i < f_edges.size(); i++) {
            if (f_edges[i] == f_dest) {
                std::cout << "Error: Could not add. File edge to " << f_dest << " already exists." << std::endl;
                return;
            }
        }
        f_edges.push_back(f_dest);
    }

    void del_f_edge(uint f_dest) {
        // linear search to find and erase edge to requested destination
        for (uint i = 0; i < f_edges.size(); i++) {
            if (f_edges[i] == f_dest) {
                f_edges.erase(f_edges.begin() + i);
                return;
            }
        }
    }

    void del_edge_loc(uint f_loc) {
        f_edges.erase(f_edges.begin() + f_loc);
    }

    uint get_num_f_edges() {
        return (uint) f_edges.size();
    }

    uint get_f_edge(uint f_loc) {
        return f_edges[f_loc];
    }

    void print_f_edges() {
        if (f_edges.size() == 0) {
            std::cout << "empty" << std::endl;
        } else {
            std::cout << "[";
            for (uint i = 0; i < f_edges.size(); i++) {
                std::cout << f_edges[i];
                if (i < f_edges.size() - 1) 
                    std::cout << " ";
            }
            std::cout << "]" << std::endl;
        }
    }

};

#endif