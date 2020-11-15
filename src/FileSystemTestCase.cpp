//File: FileSystemTestCase.cpp
//Author: Catherine Evans 
//Note: part of Week 2 Coding 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/FileSystem.h"

#define COUT std::cout
#define CIN std::cin

int main() {
    FileSystem testCase;

    std::string school = "School";

    std::string type = "Type";
    std::string notes = "Notes";
    std::string hw = "Homework";
    std::string tests = "Tests";


    std::string major = "Major";

    std::string cs = "Computer Science";
    std::string ds = "Data Structures";
    std::string sp = "Systems Programming";
    std::string fc = "Fundamentals of Computing";
    std::string dm = "Discrete Math";

    std::string art = "Art";
    std::string pottery = "Pottery";
    std::string pp = "Pinch Pot";
    std::string painting = "Painting";
    std::string drawing = "Drawing";

    //first category of taxonomy is school 
    testCase.add_taxon(school);

    //traverse into school category to add subcategories
    testCase.findCategory(school);

    //subcategory of school
    testCase.add_taxon(type);

    //traverse into type category to add subcategories
    testCase.add_taxon(notes);
    testCase.add_taxon(hw);
    testCase.add_taxon(tests);

    //go back up to the school category to build anoter child of school 
    testCase.findCategory(school);

    //add "Major" subcategory 
    testCase.add_taxon(major);

    //traverse into major category 
    testCase.findCategory(major);

    //add subcategories of major 
    testCase.add_taxon(cs);
    testCase.add_taxon(art);

    //traverse into Computer Science category to add subcategories
    testCase.findCategory(cs);

    //add Computer Science subcategories 
    testCase.add_taxon(ds);
    testCase.add_taxon(sp);
    testCase.add_taxon(fc);
    testCase.add_taxon(dm);

    //go back up to Art category to add its subcategories
    testCase.findCategory(art);

    //add Art subcategories
    testCase.add_taxon(pottery);
    testCase.add_taxon(pp);
    testCase.add_taxon(painting);
    testCase.add_taxon(drawing);

    //print tree! 
    COUT << "Test Tree:" << ENDL;
    testCase.printTaxonomy();

    //test adding a sample file 
    char text[26];

    fstream file;
    file.open("example.txt", ios::out | ios::in );

    COUT << "adding text to sample file" << ENDL;
    CIN.getline(text, sizeof(text));

    //writing on file 
    file << text << ENDL;

    //Testing example file: reads info in file 
    file >> text;
    COUT << text << ENDL;

    //closing sample file
    file.close();

    //make fstream file an object of File class that we created (for two files containing same info)
    File testFile = add_file("testFile", 10, file); //templated data for the file in this case is the fstream object 
    File testFile2 = add_file("testFile2", 10, file);

    //insert test file into taxonomy at current location 
    testCase.add_file(testFile);

    //search for file by name
    testCase.findFile(testFile);

    //test finding category that file is stored under 
    testCase.findFileCategory(testFile);

    //add test file into a different category of taxonomy 
    //first, traverse to different level 
    testCase.findCategory(cs);

    //add file at present location
    testCase.add_file(testFile2);

    //search for for file by name 
    testCase.findFile(testFile2);

    //test finding category that second file is stored under 
    testCase.findFileCategory(testFile2);

    //print taxonomy one last time 
    testCase.printTaxonomy();

    return 0;
}