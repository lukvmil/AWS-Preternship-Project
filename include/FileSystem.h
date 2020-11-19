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
        // if there are no vacancies, it adds a new file to the files vector
        if (f_vacancies.empty()) {
            new_file.set_id((uint) files.size());
            files.push_back(new_file);
        // if there is a vacancy, uses the first available id
        } else {
            new_file.set_id(f_vacancies.front());
            files[f_vacancies.front()] = new_file;
            f_vacancies.pop();
        }
        // returns newly added file's id
        return new_file.get_id();
    }

    // file delete using lazy deletion
    void del_file(int f) {
        File* file = &files[f];

        // iteratively removes any taxon links to the file
        for (uint i = 0; i < file->get_num_taxons(); i++) {
            verts[file->get_taxon(i)].del_file(file->get_id());
        }

        // sets file state to deleted
        file->del();
        // opens up spot for new file
        f_vacancies.push(file->get_id());
    }

    // linear search for file name, returns id
    int get_file(std::string name) {
        for (uint i = 0; i < files.size(); i++) {
            if (files[i].get_name() == name) {
                return i;
            }
        }
        return -1;
    }  

    // returns a file object from its id
    File& get_file_obj(int id) {
        return files[id];
    }

    // returns a taxon obj from its id
    Taxon& get_taxon_obj(int id) {
        return verts[id];
    }

    void del_taxon(int t_id) {
        // detaches all files from deleted taxon
        Taxon* taxon = &verts[t_id];
        for (unsigned int f_id = 0; f_id < taxon->get_num_files(); f_id++) {
            unlink(taxon->get_file(f_id), t_id);
        }

        // calls lazy delete function from Tree class
        Tree::del_taxon(t_id);
    }

    // links a taxon to a file
    void link(int f, int t) {
        File* file = &files[f];
        Taxon* taxon = &verts[t];
        
        file->add_taxon(taxon->get_id());
        taxon->add_file(file->get_id());
    }

    // unlinks a taxon from a file
    void unlink(int f, int t) {
        File* file = &files[f];
        Taxon* taxon = &verts[t];
        
        file->del_taxon(taxon->get_id());
        taxon->del_file(file->get_id());
    }

    std::vector<int> intersection_search(int tid1, int tid2) {
        std::vector<int> file_ids;
        Taxon t1 = get_taxon_obj(tid1);
        Taxon t2 = get_taxon_obj(tid2);
        int f_id1, f_id2;
        for (unsigned int i = 0; i < t1.get_num_files(); i++) {
            f_id1 = t1.get_file(i);

            for (unsigned int j = 0; j < t2.get_num_files(); j++) {
                f_id2 = t2.get_file(i);
                if (f_id1 == f_id2) {
                    file_ids.push_back(f_id1);
                }
            }
        }
        return file_ids;
    }

    // prints the vector containing all the files
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

    // prints the text data stored in a file
    void print_file(int f) {
        std::cout << files[f].get_data() << std::endl;
    }

    // prints all of the taxons a file is linked to
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

    // prints all of the files a taxon is linked to
    void print_taxon_files(int t) {
        Taxon* taxon = &verts[t];
        if (taxon->alive()) {
            std::cout << taxon->get_name();
            if (taxon->get_num_files())
                std::cout << " -> ";
            for(uint i = 0; i < taxon->get_num_files(); i++) {
                std::cout << files[taxon->get_file(i)].get_name();
                if (i < taxon->get_num_files() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "*DELETED*" << std::endl;
        }
    }

    // prints out a visualization of the tree
    void print_tree(uint curr=0, uint depth=0, bool last=false, std::string head="") {
        Taxon* node = &verts[curr];
        std::string disp_str = "";
        std::string send_str = "";

        if (depth) {
            disp_str = head + (last ? "└── " : "├── ");
        }

        std::cout << disp_str;
        // if (node->get_num_files())
        print_taxon_files(curr);

        for (uint i = 0; i < node->get_num_edges(); i++) {
            if (depth) {
                send_str = head + (last ? "    " : "|   ");
            }

            print_tree(
                node->get_edge(i),              // passes in the next node
                depth + 1,                      // increases tree (and recursion) depth by one
                i == node->get_num_edges() - 1, // passes true if next call is the last child
                send_str                        // passes in the head string for the next line
            );
        }
    }
};
#endif
