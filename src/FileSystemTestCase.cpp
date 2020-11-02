//File: FileSystemTestCase.cpp
//Author: Catherine Evans 
//Note: part of Week 2 Coding 

#include <iostream>
#include <string>
#include <vector>
#include "../include/FileSystem.h"

#define COUT std::cout
#define CIN std::cin

int main() {
    FileSystem testCase = new FileSystem;

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
    testCase.newTaxon(std::string school);

    //traverse into school category to add subcategories
    testCase.findCategory(std::string school);

    //subcategory of school
    testCase.newTaxon(std::string type);

    //traverse into type category to add subcategories
    testCase.newTaxon(std::string notes);
    testCase.newTaxon(std::string hw);
    testCase.newTaxon(std::string tests);

    //go back up to the school category to build anoter child of school 
    testCase.findCategory(std::string school);

    //add "Major" subcategory 
    testCase.newTaxon(std::string major);

    //traverse into major category 
    testCase.findCategory(std::string major);

    //add subcategories of major 
    testCase.newTaxon(std::string cs);
    testCase.newTaxon(std::string art);

    //traverse into Computer Science category to add subcategories
    testCase.findCategory(std::string cs);

    //add Computer Science subcategories 
    testCase.newTaxon(std::string ds);
    testCase.newTaxon(std::string sp);
    testCase.newTaxon(std::string fc);
    testCase.newTaxon(std::string dm);

    //go back up to Art category to add its subcategories
    testCase.findCategory(std::string art);

    //add Art subcategories
    testCase.newTaxon(std::string pottery);
    testCase.newTaxon(std::string pp);
    testCase.newTaxon(std::string painting);
    testCase.newTaxon(std::string drawing);

    //print tree! 
    COUT << "Test Tree:" << ENDL;
    testCase.printTaxonomy();

    //add real files
}