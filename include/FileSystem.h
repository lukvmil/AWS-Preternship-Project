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
    void add_file(File new_file) {
        if (f_vacancies.empty()) {
            new_file.set_id((unsigned int) f_vacancies.size());
            files.push_back(new_file);
        } else {
            new_file.set_id(f_vacancies.front());
            files[f_vacancies.front()] = new_file;
            f_vacancies.pop();
        }
    }

    // file delete using lazy deletion
    void del_file(std::string name) {
        for (unsigned int i = 0; i < files.size(); i++) {
            if (files[i].get_name() == name) {
                files[i].del();
                f_vacancies.push(i);
            }
        }
    }

    File* get_file(std::string name) {
        for (unsigned int i = 0; i < files.size(); i++) {
            if (files[i].get_name() == name) {
                return &(files[i]);
            }
        }
        return NULL;
    }

    void link(std::string fname, std::string tname) {
        Taxon* taxon = get_taxon(tname);
        File* file = get_file(fname);

        if (taxon && file) {
            file->add_taxon(taxon->get_id());
            taxon->add_f_edge(file->get_id());
        } else {
            std::cout << "Error invalid input names" << std::endl;
        }
    }

    void unlink(std::string fname, std::string tname) {
        Taxon* taxon = get_taxon(tname);
        File* file = get_file(fname);

        if (taxon && file) {
            file->del_taxon(taxon->get_id());
            taxon->del_f_edge(file->get_id());
        } else {
            std::cout << "Error invalid input names" << std::endl;
        }
    }

    void print_file_list() {
        std::cout << "Number of files: " << files.size() << " (" << f_vacancies.size() << " vacancies)" << std::endl;
        for (unsigned int i = 0; i < files.size(); i++) {
            if (files[i].alive()) {
                std::cout << i << ": " << files[i].get_name() << " (" << files[i].get_size() << " bytes)" << std::endl;
            } else {
                std::cout << i << ": *DELETED*" << std::endl;
            }
        }
    }


    void print_file()
    // //new!
    // void printCategory(std::string taxon) {
    //     int parentVal = DFS(taxon);
    //     for (unsigned int i = 0; i < tree.verts.size(); ++i) {
    //         if ((tree.verts[i].get_parent() == parentVal)) {
    //             if (tree.verts[i].alive()) {
    //                 COUT << i << ": " << "[" << verts[i] << "]" << " -> ";
    //                 verts[i].print_edges();
    //             }
    //             else {
    //                 COUT << i << ": " << "*DELETED*" << ENDL;
    //             }

    //         }
    //     }
    // }

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

    // void findFileName(File<T> inputFile) { //ADJUST LATER 
    //     int tempLoc = -1;
    //     for (int j = 0; j < graph.verts.length(); ++j) {
    //         if (graph.verts[j] == inputFile) {
    //             tempLoc = 1;
    //             COUT << "The file exists under the category "; //add the node on the tree here that it's at here
    //         }
    //     }
    //     if (tempLoc == -1) {
    //         COUT << "We're sorry! The requested file does not exist in your taxonomy." << ENDL;
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
