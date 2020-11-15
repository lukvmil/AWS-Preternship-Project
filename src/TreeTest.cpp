#include <iostream>
#include "../include/Taxon.h"
#include "../include/Graph.h"
#include "../include/Tree.h"
#include "../include/File.h"


int main() {
    Tree tree;
    tree.add_taxon("root", "schoolwork");
    tree.add_taxon("root", "projects");
    tree.add_taxon("projects", "coding");
    tree.add_taxon("coding", "python");
    tree.add_taxon("projects", "art");
    tree.add_taxon("projects", "writing");
    tree.print();
    tree.move_taxon("writing", "coding");
    tree.print();
    
    File f("test.txt", "hello world!");

    return 0;
}