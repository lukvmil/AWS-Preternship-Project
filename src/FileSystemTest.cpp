/************************************
* File: FileSystemTest.cpp
* Author: Olivia Johnson
*
* This file contains the main driver function
* to test the filesystem data structure
*************************************/

#include <iostream>
#include <string>
#include <vector>
#include "../include/FileSystem.h"

#define COUT std::cout
#define CIN std::cin

/************************************
* Function Name: addTaxons
* Pre-Conditions: &FileSystem
* Post-Conditions: void
*
* This function adds user inputted taxons
* to the passed FileSystem
*************************************/
void addTaxons(&FileSystem fs){
  COUT << ENDL << "Adding Taxons" << ENDL;
  std::string input;
  char continueInput;
  // loop to insert all taxons specified by the user
  do{
    // ask for user input
    COUT << "What category would you like to include? ";
    CIN >> input;
    // add input to file system
    fs.addTaxon(input);
    // ask if there is further input
    COUT << "Do you want to add more categories? [y/n]";
    CIN >> continueInput;
  } while(continueInput == 'y');
}

/************************************
* Function Name: addFiles
* Pre-Conditions: &FileSystem
* Post-Conditions: void
*
* This function adds user inputted files
* to the passed FileSystem
*************************************/
void addFiles(&FileSystem fs){
  std::string input;
  char continueInput;
  COUT << "Adding Files" << ENDL;
  std::string fileName;
  // loop to insert all files specified by the user
  do{
    // get file name
    COUT << "What file would you like to include? ";
    CIN >> fileName;
    // second loop to tag files with user defined taoxns
    std::vector <std::string> fileTaxons;
    do{
      // get file taxons
      COUT << "What category does the file belong to? ";
      CIN >> input;
      fileTaxons.push_back(input);
      // ask if there is further input
      COUT << "Do you want to add more categories to the file? [y/n]";
      CIN >> continueInput;
    } while(continueInput == 'y');
    // add to file system
    fs.addFile(fileName, fileTaxons);
    // ask if there is further input
    COUT << "Do you want to add more categories? [y/n]";
    CIN >> continueInput;
  } while(continueInput == 'y');

}

/************************************
* Function Name: printFileSystem
* Pre-Conditions: &FileSystem
* Post-Conditions: none
*
* This function prints out the passed
* FileSystem object
*************************************/
void printFileSystem(&FileSystem fs){
  COUT << fs << ENDL;
}

/************************************
* Function Name: printTaxons
* Pre-Conditions: &FileSystem
* Post-Conditions: none
*
* This function prints out all of the taxons in the
* passed FileSystem object
*************************************/
void printFileSystem(&FileSystem fs){
  COUT << fs.getTaxons() << ENDL;
}

/************************************
* Function Name: searchByName
* Pre-Conditions: &FileSystem
* Post-Conditions: none
*
* This function searches the FileSystem
* for a user specified file name
*************************************/
void searchByName(&FileSystem fs){
  std::string input;
  COUT << "What file are you searching for? ";
  CIN >> input;
  fs.findFile(input);
}

/************************************
* Function Name: searchByTaxon
* Pre-Conditions: &FileSystem
* Post-Conditions: none
*
* This function searches the FileSystem
* for a file matching user specified taxons
*************************************/
void searchByTaxon(&FileSystem fs){
  std::vector <std::string> fileTaxons;
  std::string input;
  do {
    // get user input and store in vector
    COUT << "What category does the file you are searching for belong to? ";
    CIN >> input;
    fileTaxons.push_back(input);
    // ask if there is further input
    COUT << "Are there more categories the file belongs to? [y/n]";
    CIN >> continueInput;
  } while (continueInput == 'y');
  // find the file
  fs.findFileByAssociation(fileTaxons);
}

/************************************
* Function Name: deleteFile
* Pre-Conditions: &FileSystem
* Post-Conditions: none
*
* This function deletes the the user
* specified file name from the passed
* FileSystem
*************************************/
void deleteFile(&FileSystem fs){
  std::string input;
  COUT << "What file do you want to delete? ";
  CIN >> input;
  fs.deleteFile(input);
}

/************************************
* Function Name: deleteTaxon
* Pre-Conditions: &FileSystem
* Post-Conditions: none
*
* This function deletes the the user
* specified taxon from the passed
* FileSystem
*************************************/
void deleteTaxon(&FileSystem fs){
  std::string input;
  COUT << "What category do you want to delete? ";
  CIN >> input;
  fs.deleteTaxon(input);
}

/************************************
* Function Name: commandMenu
* Pre-Conditions: &FileSystem
* Post-Conditions: none
*
* This function prints out a menu and
* allows the user to build and traverse
* their FileSystem
*************************************/
void commandMenu(&FileSystem fs) {
    char input;
    // loop until the user chooses to exit
    while (input != 'q'){
      // print the menu
      COUT << "Press 1 to enter a new category to the FileSystem" << ENDL;
      COUT << "Press 2 to add a file to the FileSystem" << ENDL;
      COUT << "Press 3 to print the system." << ENDL;
      COUT << "Press 4 to print all of the categories in the system." << ENDL;
      COUT << "Press 5 to search for a file by name." << ENDL;
      COUT << "Press 6 to search for a file by category." << ENDL;
      COUT << "Press 7 to delete a file by name." << ENDL;
      COUT << "Press 8 to delete a taxon." << ENDL;
      COUT << "Press q to quit." << ENDL;

      // add a new taxon
      if (input == '1') {
        addTaxons(fs);
      }
      // add a new file
      else if (input == '2') {
        addFiles(fs);
      }
      // print the FileSystem
      else if (input == '3') {
        printFileSystem(fs);
      }
      // search print all the taxons in the FileSystem
      else if (input == '4') {
        printTaxons(fs);
      }
      // search for a file by name
      else if (input == '5') {
        ;
      }
      // search for a file by taxon
      else if (input == '6') {
        ;
      }
      // delete a file
      else if (input == '7') {
        ;
      }
      // delete a taxon
      else if (input == '8') {
        ;
      }
      // quit
      else if (input == 'q') {
        COUT << "Bye!" << ENDL;
        break;
      }
      // invalid input
      else {
        COUT << "Please enter a valid command, or q to quit the program." << ENDL;
      }
   }
}

/************************************
* Function Name: main
* Pre-Conditions: none
* Post-Conditions: int
*
* This is the main driver function that
* implements the filesystem class defined
* in filesystem.h
*************************************/
int main(){
  FileSystem fs;
  commandMenu(fs);

  return 0;
}
