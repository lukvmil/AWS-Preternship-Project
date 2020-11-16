//File: File.h
//Author: Catherine Evans 

#ifndef FILE_H
#define FILE_H

#include "Vertex.h"
#include <string>

#define uint unsigned int

class File: public Vertex {
private:
    std::string name;
    uint id;
    long uint size;
    std::string data;
    std::vector<uint> taxons;
    bool deleted;

public:
    //Default Constructor 
    File(): name(), id(), size(), data(), taxons(), deleted(false) {}

    //Overloaded Constructor
    File( std::string nameIn, std::string dataIn) : name(nameIn), id(), size(), data(dataIn), taxons(), deleted(false) {
        size = data.size();
    }

    // getters and setters for name and data
    void set_name(std::string nameIn) {
        name = nameIn;
    }

    std::string get_name() {
        return name;
    }

    void set_id(uint id_in) {
        id = id_in;
    }

    uint get_id() {
        return id;
    }

    void set_data(std::string dataIn) {
        data = dataIn;
        size = data.size();
    }

    std::string get_data() {
        return data;
    }

    long uint get_size() {
        return size;
    }

    void del() {
        deleted = true;
    }

    bool alive() {
        return !deleted;
    }

    void add_taxon(uint dest) {
        for (uint i = 0; i < taxons.size(); i++) {
            if (taxons[i] == dest) {
                std::cout << "Error: Could not add. Taxon " << dest << " already exists." << std::endl;
                return;
            }
        }
        taxons.push_back(dest);
    }

    void del_taxon(uint dest) {
        for (uint i = 0; i < taxons.size(); i++) {
            if (taxons[i] == dest) {
                taxons.erase(taxons.begin() + i);
                return;
            }
        }
    }

    void del_taxon_loc(uint loc) {
        taxons.erase(taxons.begin() + loc);
    }

    uint get_num_taxons() {
        return (uint) taxons.size();
    }

    uint get_taxon(uint loc) {
        return taxons[loc];
    }

    void print_taxons() {
        if (taxons.size() == 0) {
            std::cout << "empty" << std::endl;
        } else {
            std::cout << "[";
            for (uint i = 0; i < taxons.size(); i++) {
                std::cout << taxons[i];
                if (i < taxons.size() - 1) 
                    std::cout << " ";
            }
            std::cout << "]" << std::endl;
        }
    }

};

#endif