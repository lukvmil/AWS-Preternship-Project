#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Edge.h"
#include "File.h"
#include "Vertex.h"

#define COUT std::cout 
#define CIN std::cin
#define ENDL std::endl

int main() {
    listOfCommands(); 
}

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

    }
    else if (input == "2") {

    }
    else if (input == "3") {

    }
    else if (input == "4") {

    }
    else if (input == "5") {

    }
    else if (input == "q") {

    }
    else {
        COUT << "Please enter a valid command, or q to quit the program." << ENDL;
    }
    }

}
#endif