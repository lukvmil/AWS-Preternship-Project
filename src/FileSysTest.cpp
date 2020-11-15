#include "../include/FileSystem.h"
#include <iostream>

int main() {
    FileSystem<File> fs;

    std::string root = "root";
    std::string first = "first category";
    std::string second = "second category";
    std::string subFirst = "sub category of first";
    std::string subSecond = "sub category of second";
    std::string subsubFirst = "sub category of sub category of first category";


    fs.newTaxon(root, first);
    fs.newTaxon(root, second);

    fs.newTaxon(first, subFirst);
    fs.newTaxon(second, subSecond);

    fs.newTaxon(subFirst, subsubFirst);

    fs.printTaxonomy();

    fs.printCategory(first);

    //fs.findFileCategory();// add later
}