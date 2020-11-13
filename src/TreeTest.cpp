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
    tree.add_taxon("projects", "art");
    tree.add_taxon("projects", "writing");
    tree.print();
    tree.del_taxon("projects");
    tree.del_taxon("writing");
    tree.print();
    tree.add_taxon("coding", "java");
    tree.print();
    return 0;
}