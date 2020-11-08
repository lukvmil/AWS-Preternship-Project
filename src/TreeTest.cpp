#include <iostream>
#include "../include/Taxon.h"
#include "../include/Graph.h"
#include "../include/Tree.h"

int main() {
    Tree tree;
    tree.add_taxon("root", "schoolwork");
    tree.add_taxon("root", "projects");
    tree.add_taxon("projects", "coding");
    tree.add_taxon("coding", "python");
    tree.print();
    std::cout << tree.find_taxon("python") << std::endl;
    return 0;
}