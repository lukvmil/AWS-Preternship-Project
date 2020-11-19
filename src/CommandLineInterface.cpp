#include <string>
#include <iostream>
#include <sstream>
#include "../include/FileSystem.h"
#include "../include/Taxon.h"
#include "../include/File.h"

int main() {
    FileSystem fs;
    Taxon taxon;
    File file;
    int curr_taxon = 0;
    std::string line;
    std::string c_name;
    std::string c_param;

    fs.add_taxon("test");
    fs.add_taxon("yo");

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
        }

        // if (!(std::cin >> input >> input >> input)) break;

    }


    return 0;
}