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
    testCase.add_taxon(school); //inserts at root 

    //print after first insert 
    COUT << "Test Case Tree after first insert of a taxon: " << ENDL;
    testCase.print_tree();
    COUT << ENDL << ENDL; 

    //traverse into school category to add subcategories
    int schoolNode = testCase.get_taxon(school);

    //subcategory of school
    testCase.add_taxon(type, schoolNode);

    //traverse into type category to add subcategories
    int typeNode = testCase.get_taxon(type);
    testCase.add_taxon(notes, typeNode);
    testCase.add_taxon(hw, typeNode);
    testCase.add_taxon(tests, typeNode);

    //add "Major" subcategory 
    testCase.add_taxon(major, schoolNode);

    //traverse into major category 
    int majorNode = testCase.get_taxon(major);

    //add subcategories of major 
    testCase.add_taxon(cs, majorNode);
    testCase.add_taxon(art, majorNode);

    //traverse into Computer Science category to add subcategories
    int csNode = testCase.get_taxon(cs);

    //add Computer Science subcategories 
    testCase.add_taxon(ds, csNode);
    testCase.add_taxon(sp, csNode);
    testCase.add_taxon(fc, csNode);
    testCase.add_taxon(dm, csNode);

    //go back up to Art category to add its subcategories
    int artNode = testCase.get_taxon(art);

    //add Art subcategories
    testCase.add_taxon(pottery, artNode);
    testCase.add_taxon(pp, artNode);
    testCase.add_taxon(painting, artNode);
    testCase.add_taxon(drawing, artNode);

    //print tree! 
    COUT << "Final Test Case Tree Taxonomy:" << ENDL;
    testCase.print_tree();
    COUT << ENDL << ENDL;

    //create two sample files to add to taxonomy in different locations 
    File file1;
    file1.set_name("file example 1");
    file1.set_data("sample text for file 1");

    File file2;
    file2.set_name("file example 2");
    file2.set_data("sample text for file 2");

    //insert test files into taxonomy
    testCase.add_file(file1);
    testCase.add_file(file2);

    //print list of files 
    COUT << "Files in taxonomy: " << ENDL;
    testCase.print_file_list();
    COUT << ENDL << ENDL;

    //print text inside of files 
    COUT << "Text inside file 1: " << ENDL;
    testCase.print_file(0);
    COUT << ENDL;
    COUT << "Text inside file 2: " << ENDL;
    testCase.print_file(1);
    COUT << ENDL;

    //links to different locations 
    testCase.link(0, csNode);
    testCase.link(1, artNode);

    //print tree with files at this stage
    COUT << "Complete tree with files now linked. File 1 linked to computer science taxon and File 2 linked to art taxon: " << ENDL;
    testCase.print_tree();
    COUT << ENDL << ENDL;

    //link file 2 to computer science and notes and systems programming as well (test of two files to one node and one file to more than one node)
    int spNode = testCase.get_taxon(sp);
    int notesNode = testCase.get_taxon(notes);
    testCase.link(1, csNode);
    testCase.link(1, spNode);
    testCase.link(1, notesNode);

    COUT << "File 2 now links to computer science, systems programming, and notes taxons as well (test of a taxon pointing to more than one file from a different category and a file being linked to multiple taxons): " << ENDL;
    testCase.print_tree();
    COUT << ENDL << ENDL;

    //print file taxons test
    COUT << "File 2 points to taxons: " << ENDL;
    testCase.print_file_taxons(1);
    COUT << ENDL << ENDL;

    //test of unlinking 
    testCase.unlink(1, artNode);

    COUT << "File 2 now unlinked from art taxon:" << ENDL;
    testCase.print_tree();
    COUT << ENDL << ENDL;

    //test of deleting a file
    testCase.del_file(1);

    COUT << "Complete tree after deleting file 2:" << ENDL;
    testCase.print_tree();
    COUT << ENDL << ENDL;

    return 0;
}