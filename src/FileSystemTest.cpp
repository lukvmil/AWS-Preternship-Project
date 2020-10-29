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
#include "../include/filesystem.h"

#define COUT std::cout
#define CIN std::cin

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
  // initialize the filesystem
  FileSystem fs;
  COUT << "File System Test"

  // add taxons
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

  // add files
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

  // print initial file system
  COUT << fs << ENDL;

  // print taxons (ensure the traversal of taxons works as intended)
  COUT << fs.getTaxons() << ENDL;

  // delete a taxon test
  COUT << ENDL << "Deleting taxons" << ENDL;
  COUT << "What category do you want to delete? ";
  CIN >> input;
  fs.deleteTaxon(input);

  // printing new file system
  COUT << fs << ENDL;

  // delete a nonexistant taxon test
  COUT << "What category do you want to delete? ";
  CIN >> input;
  fs.deleteTaxon(input);

  // print file system
  COUT << fs << ENDL;

  // search for a file by name test 
  COUT << ENDL << "Seaching for files by name" << ENDL;
  COUT << "What file are you searching for? ";
  CIN >> input;
  fs.findFile(input);

  // search for a nonexistant file by name test
  COUT << "What file are you searching for? ";
  CIN >> input;
  fs.findFile(input);

  // search for a file by taxon test
  COUT << ENDL << "Searching for files by taxons" << ENDL;
  // empty vector to store taxons
  fileTaxons.clear();
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

  // seach for a nonexistant file by taxon test
  fileTaxons.clear();
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


  return 0;
}
