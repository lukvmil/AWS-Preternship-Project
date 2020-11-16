#include <iostream>
#include "../include/FileSystem.h"
#include "../include/File.h"

std::string dino =
"               __ "
"              / _)"
"     _.----._/ /  "
"    /         /   "
" __/ (  | (  |    "
"/__.-'|_|--|_|    ";


int main() {
    FileSystem fs;
    int f1, f2, f3;
    int a, b, c, d, e, f;

    f1 = fs.add_file(File("dino.txt", dino));
    f2 = fs.add_file(File("pi.txt", "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"));
    f3 = fs.add_file(File("reading.txt", "I don't know how to read."));
    fs.print_file(f1); fs.print_file(f2); fs.print_file(f3);

    a = fs.add_taxon("schoolwork");
    b = fs.add_taxon("projects");
    c = fs.add_taxon("coding", b);
    d = fs.add_taxon("python", c);
    e = fs.add_taxon("art", b);
    f = fs.add_taxon("writing", b);

    fs.print_tree();
    fs.print_tree_list();

    fs.link(f1, a);
    fs.link(f3, a);
    fs.link(f3, f);
    fs.link(f1, b);
    fs.link(f2, d);

    fs.print_file_taxons(f1);
    fs.print_file_taxons(f2);
    fs.print_file_taxons(f3);

    fs.print_taxon_files(a);
    fs.print_taxon_files(f);
    std::cout << std::endl;

    // fs.del_file(f1);

    fs.print_file_taxons(f1);
    fs.print_file_taxons(f2);
    fs.print_file_taxons(f3);

    fs.print_taxon_files(a);
    fs.print_taxon_files(f);

    std::cout << std::endl;

    fs.del_taxon(f);

    fs.print_file_taxons(f1);
    fs.print_file_taxons(f2);
    fs.print_file_taxons(f3);

    fs.print_taxon_files(a);
    fs.print_taxon_files(f);

    fs.print_tree();

    return 0;
}