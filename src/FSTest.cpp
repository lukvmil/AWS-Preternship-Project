#include <iostream>
#include "../include/FileSystem.h"
#include "../include/File.h"

int main() {
    FileSystem fs;
    fs.add_taxon("schoolwork");
    fs.add_taxon("projects");
    fs.add_taxon("coding", "projects");
    fs.add_taxon("python", "coding");
    fs.add_taxon("art", "projects");
    fs.add_taxon("writing", "projects");
    fs.print_tree();
    fs.print_list();
    fs.add_file(File("notes.txt", "1 + 1 = 2"));
    fs.link("notes.txt", "writing");
    fs.get_file("notes.txt")->print_taxons();
    fs.get_taxon("writing")->print_f_edges();
    fs.unlink("notes.txt", "writing");
    fs.get_file("notes.txt")->print_taxons();
    fs.get_taxon("writing")->print_f_edges();
    return 0;
}