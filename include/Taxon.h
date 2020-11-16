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
    std::vector<uint> files;

public:
    Taxon(std::string name_in, uint parent_id) : name(name_in), id(), parent(parent_id), deleted(false), files() {}

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
    void add_file(uint f_dest) {
        for (uint i = 0; i < files.size(); i++) {
            if (files[i] == f_dest) {
                std::cout << "Error: Could not add. File edge to " << f_dest << " already exists." << std::endl;
                return;
            }
        }
        files.push_back(f_dest);
    }

    void del_file(uint f_dest) {
        // linear search to find and erase edge to requested destination
        for (uint i = 0; i < files.size(); i++) {
            if (files[i] == f_dest) {
                files.erase(files.begin() + i);
                return;
            }
        }
    }

    void del_edge_loc(uint f_loc) {
        files.erase(files.begin() + f_loc);
    }

    uint get_num_files() {
        return (uint) files.size();
    }

    uint get_file(uint f_loc) {
        return files[f_loc];
    }

    void print_files() {
        if (files.size() == 0) {
            std::cout << "empty" << std::endl;
        } else {
            std::cout << "[";
            for (uint i = 0; i < files.size(); i++) {
                std::cout << files[i];
                if (i < files.size() - 1) 
                    std::cout << " ";
            }
            std::cout << "]" << std::endl;
        }
    }

};

#endif