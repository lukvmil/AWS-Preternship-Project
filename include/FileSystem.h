#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Edge.h"
#include "File.h"
#include "Vertex.h"

#define COUT std::cout 
#define CIN std::cin
#define ENDL std::endl

int main() {
    unsigned int location = 0; //dont know what im doing here 
    listOfCommands(); 
}

void newTaxon() {

}

void newFile() {}

void findFile() {} 

void findFileName() {} 

void findFileCategory() {}

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