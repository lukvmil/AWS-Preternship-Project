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
    // tree.print_list();
    tree.move_taxon("writing", "coding");
    tree.print();
    // tree.print();
    // tree.print_list();
    // tree.print_list();
    // tree.print("coding");
    // tree.del_taxon("projects");
    // // tree.del_taxon("writing");
    // tree.print_tree();
    // tree.add_taxon("coding", "java");
    // tree.print_tree();
    return 0;
}