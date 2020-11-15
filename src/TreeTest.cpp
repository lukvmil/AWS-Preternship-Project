#include <iostream>
#include "../include/Taxon.h"
#include "../include/Graph.h"
#include "../include/Tree.h"
#include "../include/File.h"


int main() {
    Tree tree;
    tree.add_taxon("schoolwork");
    tree.add_taxon("projects");
    tree.add_taxon("coding", "projects");
    tree.add_taxon("python", "coding");
    tree.add_taxon("art", "projects");
    tree.add_taxon("writing", "projects");
    tree.print_tree();
    tree.move_taxon("coding", "art");
    tree.move_taxon("writing", "coding");
    tree.print_tree();
    tree.del_taxon("art");
    tree.print_tree();

    return 0;
}