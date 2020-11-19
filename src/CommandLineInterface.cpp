#include <string>
#include <iostream>
#include <sstream>
#include "../include/FileSystem.h"
#include "../include/Taxon.h"
#include "../include/File.h"

int main() {
    FileSystem fs;

    std::string school = "School";

    std::string type = "Type";
    std::string notes = "Notes";
    std::string hw = "Homework";
    std::string tests = "Tests";


    std::string major = "Major";

    std::string cs = "Computer_Science";
    std::string ds = "Data_Structures";
    std::string sp = "Systems_Programming";
    std::string fc = "Fundamentals_of_Computing";
    std::string dm = "Discrete_Math";

    std::string art = "Art";
    std::string pottery = "Pottery";
    std::string pp = "Pinch_Pot";
    std::string painting = "Painting";
    std::string drawing = "Drawing";

    //first category of taxonomy is school 
    fs.add_taxon(school); //inserts at root 
    int schoolNode = fs.get_taxon(school);
    fs.add_taxon(type, schoolNode);
    int typeNode = fs.get_taxon(type);
    fs.add_taxon(notes, typeNode);
    fs.add_taxon(hw, typeNode);
    fs.add_taxon(tests, typeNode);
    fs.add_taxon(major, schoolNode);
    int majorNode = fs.get_taxon(major);
    fs.add_taxon(cs, majorNode);
    fs.add_taxon(art, majorNode);
    int csNode = fs.get_taxon(cs);
    fs.add_taxon(ds, csNode);
    fs.add_taxon(sp, csNode);
    fs.add_taxon(fc, csNode);
    fs.add_taxon(dm, csNode);
    int artNode = fs.get_taxon(art);
    fs.add_taxon(pottery, artNode);
    fs.add_taxon(pp, artNode);
    fs.add_taxon(painting, artNode);
    fs.add_taxon(drawing, artNode);
    File file1;
    file1.set_name("file example 1");
    file1.set_data("sample text for file 1");
    File file2;
    file2.set_name("file example 2");
    file2.set_data("sample text for file 2");
    fs.add_file(file1);
    fs.add_file(file2);
    fs.link(0, csNode);
    fs.link(1, artNode);
    int spNode = fs.get_taxon(sp);
    int notesNode = fs.get_taxon(notes);
    fs.link(1, csNode);
    fs.link(1, spNode);
    fs.link(1, notesNode);

    Taxon taxon;
    File file;
    int curr_taxon = 0;
    std::string line;
    std::string c_name;
    std::string c_param;

    while (1) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;
        std::istringstream iss(line);

        iss >> c_name;

        if (c_name == "quit" || c_name == "q" || c_name == "exit") {
            break;
        } else if (c_name == "tree") {
            fs.print_tree();
        } else if (c_name == "list") {
            iss >> c_param;
            taxon = fs.get_taxon_obj(curr_taxon);
            if (c_param == "taxon") {
                for (unsigned int i = 0; i < taxon.get_num_edges(); i++) {
                    std::cout << fs.get_taxon_obj(taxon.get_edge(i)).get_name() << " ";
                }
                std::cout << std::endl;
            } else if (c_param == "file") {
                for (unsigned int i = 0; i < taxon.get_num_files(); i++) {
                    std::cout << fs.get_file_obj(taxon.get_file(i)).get_name() << " ";
                }
                std::cout << std::endl;
            }
        } else if (c_name == "add") {
            iss >> c_param;
            if (c_param == "taxon") {
                iss >> c_param;
                fs.add_taxon(c_param, curr_taxon);
            }
        } else if (c_name == "del") {
            iss >> c_param;
            if (c_param == "taxon") {
                iss >> c_param;
                fs.del_taxon(fs.DFS(c_param, curr_taxon));
            }
        } else if (c_name == "moveto") {
            iss >> c_param;
            curr_taxon = fs.DFS(c_param, curr_taxon);
        } else if (c_name == "moveup") {
            curr_taxon = fs.get_taxon_obj(curr_taxon).get_parent();
        } else if (c_name == "compare") {
            int t1, t2;
            std::vector<int> comps;
            iss >> c_param;
            t1 = fs.DFS(c_param);
            iss >> c_param;
            t2 = fs.DFS(c_param);
            comps = fs.intersection_search(t1, t2);
            for (unsigned int i = 0; i < comps.size(); i++) {
                std::cout << comps[i] << std::endl;
            }
        }

        // if (!(std::cin >> input >> input >> input)) break;

    }


    return 0;
}