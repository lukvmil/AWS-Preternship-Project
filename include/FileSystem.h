//File: FileSystem.h
//Author: Catherine Evans


#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Edge.h"
#include "File.h"
#include "Vertex.h"

#define COUT std::cout 
#define CIN std::cin
#define ENDL std::endl

// A couple of things in this file need to be updated according to the Tree.h file once it's created 

template<class T>
class FileSystem {
    private:
        Graph<T> graph;
        Tree<T> tree; 
        int location; //value of node at current location

        //Default Constructor 
        FileSystem(): graph(), tree(), location() {}

        //Overloaded Constructor
        FileSystem( Graph<T> graphIn, Tree<t> treeIn, int locIn) : graph(graphIn), tree(treeIn), location(locIn) {}

    public: 
        void newTaxon(T data) {
            tree.add_node(data); //no such method exists yet, change fxn name accordingly 
        }

        void newFile(File inputFile) {
            graph.add_vert(inputFile)
        }

        void findFile(File inputFile) {
            //right now, this function is basically the same as the one below. This one could potentially be a search by location as well 
            tempLocation = -1;
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

        void findFileName(File inputFile) {
            tempLoc = -1;
            for (int j = 0; j < graph.verts.length(); ++j) {
                if (graph.verts[j] == inputFile) {
                    tempLoc = 1
                    COUT << "The file exists under the category " //add the node on the tree here that it's at here
                }
            }
            if (tempLoc == -1) {
                COUT << "We're sorry! The requested file does not exist in your taxonomy." << ENDL;
            }
        } 

        void findFileCategory() {
            //to be implemented once Tree.h is done 
        }
}

//menu of actions for the user to perform with taxonomy  
void listOfCommands() {
    std::string input = "";

    while (input != "q"){
    COUT << "
    Press 1 to enter a new category to the catalog./n
    Press 2 to add a file at your current location./n
    Press 3 to traverse to a specific file./n
    Press 4 to search for a file by name./n
    Press 5 to search for a file by category./n
    Press q to quit./n" << ENDL;
    //adding real text file to filesystem in c++ (loading into file struct then into filesystem)

    if (input == "1") {
        newTaxon();
    }
    else if (input == "2") {
        newFile();
    }
    else if (input == "3") {
        findFile();
    }
    else if (input == "4") {
        findFileName();
    }
    else if (input == "5") {
        findFileCategory();
    }
    else if (input == "q") {
        COUT << "Bye!" << ENDL;
        break;
    }
    else {
        COUT << "Please enter a valid command, or q to quit the program." << ENDL;
    }
    }

}
#endif