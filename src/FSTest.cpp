#include <iostream>
#include "../include/FileSystem.h"
#include "../include/File.h"

int main() {
    FileSystem fs;
    int f1, f2, f3;
    int a, b, c, d, e, f;

    f1 = fs.add_file(File("jon.txt", "this guy sucks"));
    f2 = fs.add_file(File("vito.txt", "real bitch"));
    f3 = fs.add_file(File("reading.txt", "i dont know how to read"));
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

    fs.print_file_taxons(f1);
    fs.print_file_taxons(f2);
    fs.print_file_taxons(f3);

    fs.print_taxon_files(a);
    fs.print_taxon_files(f);
    std::cout << std::endl;

    fs.del_file(f1);

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

    // // Taxon* root = fs.get_root();
    // fs.add_taxon("test");
    // fs.get_taxon("root")->print_edges();
    // // Taxon* school = fs.add_taxon("schoolwork", root);
    // // Taxon* projects = fs.add_taxon("projects", root);
    // // Taxon* coding = fs.add_taxon("coding", projects);
    // // Taxon* python = fs.add_taxon("python", coding);
    // // fs.add_taxon("art", projects);
    // // fs.add_taxon("writing", projects);
    // fs.print_tree();
    // fs.print_tree_list();
    // fs.move_taxon(python, school);
    // school->print_edges();
    // fs.print_tree();
    // fs.add_file(File("notes.txt", "1 + 1 = 2"));
    // fs.add_file(File("blugru.txt", "testing"));
    //     fs.print_file_list();

    // fs.link(fs.get_file("notes.txt"), fs.get_taxon("writing"));
    // fs.link(fs.get_file("notes.txt"), fs.get_taxon("art"));
    // fs.link(fs.get_file("blugru.txt"), fs.get_taxon("art"));
    // fs.del_file(fs.get_file("notes.txt"));
    // fs.print_taxon_files(fs.get_taxon("art"));
    // fs.print_taxon_files(fs.get_taxon("writing"));
    // fs.print_file_taxons(fs.get_file("notes.txt"));
    // fs.print_file_taxons(fs.get_file("blugru.txt"));
    // fs.print_file_list();


    return 0;
}