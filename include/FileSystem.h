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

template<class T>
class FileSystem {
    private:
        Tree tree;

        //Default Constructor
        FileSystem(): tree() {}

        //Overloaded Constructor
        FileSystem( Tree treeIn ) : tree(treeIn) {}

    public:
        void newTaxon(std::string parent, std::string name) {
            tree.add_taxon(parent, name);
        }

        void newFile(File<T> inputFile) {
            graph.add_vert(inputFile); //ASK LUKE idk how to do that 
        }

        void printTaxonomy(){
          tree.print();
        }

        //new!
        void printCategory(std::string taxon) {
            int parentVal = DFS(taxon);
            for (unsigned int i = 0; i < tree.verts.size(); ++i) {
                if ((tree.verts[i].get_parent() == parentVal)) {
                    if (tree.verts[i].alive()) {
                        COUT << i << ": " << "[" << verts[i] << "]" << " -> ";
                        verts[i].print_edges();
                    }
                    else {
                        COUT << i << ": " << "*DELETED*" << ENDL;
                    }

                }
            }
        }

        void findFile(File<T> inputFile) { //ADJUST LATER
            int tempLocation = -1;
            for (int i = 0; i < graph.verts.length(); ++i) {
                if (graph.verts[i] == inputFile) {
                    tempLocation = graph.verts[i];
                    location = tempLocation;
                }
            }
            if (tempLocation == -1) {
                COUT << "Our apologies, the requested file does not exist in your catalog. " << ENDL;
            }

        }

        void findFileName(File<T> inputFile) { //ADJUST LATER 
            int tempLoc = -1;
            for (int j = 0; j < graph.verts.length(); ++j) {
                if (graph.verts[j] == inputFile) {
                    tempLoc = 1;
                    COUT << "The file exists under the category "; //add the node on the tree here that it's at here
                }
            }
            if (tempLoc == -1) {
                COUT << "We're sorry! The requested file does not exist in your taxonomy." << ENDL;
            }
        }

        void findFileCategory(std::string taxon) {
            int loc = tree.find_taxon(taxon);
            if (loc != -1) {
                COUT << "The taxon exists at location " << loc << ENDL;
            }
            else {
                COUT << "The taxon you're searching for doesn't exist in your taxonomy." << ENDL;
            }
        }

        void deleteFile(File<T> f){ //ADJUST LATER
          int locat = graph.find_vert_loc(f);
          graph.del_vert(locat);
        }

        void deleteTaxon(std::string inputTaxonName){
          tree.del_taxon(inputTaxonName);
        }
};
#endif
