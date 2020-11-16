//File: FileSystem.h
//Author: Catherine Evans


#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "File.h"
#include "Vertex.h"
#include "Taxon.h"
#include "Graph.h"
#include "Tree.h"
#include <string>
#include <vector>

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl

class FileSystem: public Tree {
private:
    std::vector<File> files;
    std::queue<unsigned int> f_vacancies;

public:
    //Default Constructor
    FileSystem(): files(), f_vacancies() {}

    ~FileSystem() {}

    // adding files checks to fill spots of deleted files first
    int add_file(File new_file) {
        if (f_vacancies.empty()) {
            new_file.set_id((uint) files.size());
            files.push_back(new_file);
        } else {
            new_file.set_id(f_vacancies.front());
            files[f_vacancies.front()] = new_file;
            f_vacancies.pop();
        }

        return new_file.get_id();
    }

    // file delete using lazy deletion
    void del_file(int f) {
        File* file = &files[f];

        for (uint i = 0; i < file->get_num_taxons(); i++) {
            verts[file->get_taxon(i)].del_f_edge(file->get_id());
        }

        file->del();
        f_vacancies.push(file->get_id());
    }

    int get_file(std::string name) {
        for (uint i = 0; i < files.size(); i++) {
            if (files[i].get_name() == name) {
                return i;
            }
        }
        return -1;
    }

    void del_taxon(int id) {
        Tree::del_taxon()
    }

    void link(int f, int t) {
        File* file = &files[f];
        Taxon* taxon = &verts[t];
        
        file->add_taxon(taxon->get_id());
        taxon->add_f_edge(file->get_id());
    }

    void unlink(int f, int t) {
        File* file = &files[f];
        Taxon* taxon = &verts[t];
        
        file->del_taxon(taxon->get_id());
        taxon->del_f_edge(file->get_id());
    }

    void print_file_list() {
        std::cout << "Number of files: " << files.size() << " (" << f_vacancies.size() << " vacancies)" << std::endl;
        for (uint i = 0; i < files.size(); i++) {
            if (files[i].alive()) {
                std::cout << i << ": " << files[i].get_name() << " (" << files[i].get_size() << " bytes)" << std::endl;
            } else {
                std::cout << i << ": *DELETED*" << std::endl;
            }
        }
    }

    void print_file(int f) {
        std::cout << files[f].get_data() << std::endl;
    }

    void print_file_taxons(int f) {
        File* file = &files[f];

        if (file->alive()) {
            std::cout << file->get_name() << ": (";
            for(uint i = 0; i < file->get_num_taxons(); i++) {
                std::cout << verts[file->get_taxon(i)].get_name();
                if (i < file->get_num_taxons() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << ")" << std::endl;
        } else {
            std::cout << "*DELETED*" << std::endl;
        }
    }

    void print_taxon_files(int t) {
        Taxon* taxon = &verts[t];
        if (taxon->alive()) {
            std::cout << taxon->get_name() << " -> ";
            for(uint i = 0; i < taxon->get_num_f_edges(); i++) {
                std::cout << files[taxon->get_f_edge(i)].get_name();
                if (i < taxon->get_num_f_edges() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "*DELETED*" << std::endl;
        }
    }



    // void findFile(File<T> inputFile) { //ADJUST LATER
    //     int tempLocation = -1;
    //     for (int i = 0; i < graph.verts.length(); ++i) {
    //         if (graph.verts[i] == inputFile) {
    //             tempLocation = graph.verts[i];
    //             location = tempLocation;
    //         }
    //     }
    //     if (tempLocation == -1) {
    //         COUT << "Our apologies, the requested file does not exist in your catalog. " << ENDL;
    //     }

    // }

    // void findFileCategory(std::string taxon) {
    //     int loc = tree.find_taxon(taxon);
    //     if (loc != -1) {
    //         COUT << "The taxon exists at location " << loc << ENDL;
    //     }
    //     else {
    //         COUT << "The taxon you're searching for doesn't exist in your taxonomy." << ENDL;
    //     }
    // }
};
#endif
