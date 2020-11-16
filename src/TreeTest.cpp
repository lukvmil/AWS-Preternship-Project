#include <iostream>
#include "../include/Taxon.h"
#include "../include/Graph.h"
#include "../include/Tree.h"
#include "../include/File.h"


int main() {
    Tree tree;
    int a, b, c, d, e, f;
    a = tree.add_taxon("schoolwork");
    b = tree.add_taxon("projects");
    c = tree.add_taxon("coding", b);
    d = tree.add_taxon("python", c);
    e = tree.add_taxon("art", b);
    f = tree.add_taxon("writing", b);
    tree.print_tree();
    tree.move_taxon(c, e);
    tree.move_taxon(f, c);
    tree.print_tree();
    tree.del_taxon(e);
    tree.print_tree();
    tree.del_taxon(a);
    tree.del_taxon(d);
    tree.print_tree();

    return 0;
}