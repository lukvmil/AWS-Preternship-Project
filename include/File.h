//File: File.h
//Author: Catherine Evans 

#ifndef FILE_H
#define FILE_H

#include "Vertex.h"
#include <string>

class File: public Vertex {
private:
    std::string name;
    unsigned int id;
    long unsigned int size;
    std::string data;
    std::vector<unsigned int> taxons;
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

    void set_id(unsigned int id_in) {
        id = id_in;
    }

    unsigned int get_id() {
        return id;
    }

    void set_data(std::string dataIn) {
        data = dataIn;
        size = data.size();
    }

    std::string get_data() {
        return data;
    }

    long unsigned int get_size() {
        return size;
    }

    void del() {
        deleted = true;
    }

    bool alive() {
        return !deleted;
    }

    void add_taxon(unsigned int dest) {
        for (unsigned int i = 0; i < taxons.size(); i++) {
            if (taxons[i] == dest) {
                std::cout << "Error: Could not add. Taxon " << dest << " already exists." << std::endl;
                return;
            }
        }
        taxons.push_back(dest);
    }

    void del_taxon(unsigned int dest) {
        for (unsigned int i = 0; i < taxons.size(); i++) {
            if (taxons[i] == dest) {
                taxons.erase(taxons.begin() + i);
                return;
            }
        }
    }

    void del_taxon_loc(unsigned int loc) {
        taxons.erase(taxons.begin() + loc);
    }

    unsigned int get_num_taxons() {
        return (unsigned int) taxons.size();
    }

    unsigned int get_taxon(unsigned int loc) {
        return taxons[loc];
    }

    void print_taxons() {
        std::cout << "[";
        for (unsigned int i = 0; i < taxons.size(); i++) {
            std::cout << taxons[i];
            if (i < taxons.size()- 1) 
                std::cout << " ";
        }
        std::cout << "]" << std::endl;

        if (taxons.size() == 0) {
            std::cout << "empty" << std::endl;
        }
    }

};

#endif