#ifndef TREE_H
#define TREE_H

#include <stack>
#include "Graph.h"
#include "Taxon.h"


class Tree: public Graph<Taxon> {
private:

    int DFS(std::string name) {
        std::stack<unsigned int> next_node;
        unsigned int curr_node;

        next_node.push(0);

        while (!next_node.empty()) {
            curr_node = next_node.top();
            next_node.pop();

            // returns node value if requested taxon is found
            if (verts[curr_node].get_name() == name) {
                return curr_node;
            }

            // iterates through all edges in the current node
            for (unsigned int i = 0; i < verts[curr_node].get_num_edges(); i++) {
                // adds each to the stack
                next_node.push(verts[curr_node].get_edge(i));
            }
        }

        return -1;
    }

public:
    Tree() {
        Taxon root("root", 0);
        add_vert(root);
    }

    ~Tree() {}

    void add_taxon(std::string parent, std::string name) {
        // child id will be the next element in verts
        int child_id = (int) verts.size();
        // parent id found through private depth first search function
        int parent_id = DFS(parent);

        // DFS returns -1 if taxon wasn't found
        if (parent_id == -1) {
            std::cout << "Error: Parent does not exist." << std::endl;
            return;
        }
        
        // creates new child taxon and connects into tree
        Taxon child(name, parent_id);
        add_vert(child);

        add_edge(parent_id, child_id);
    }

    // void del_taxon(std::string name, bool recursive = false) {
    //     int id = DFS(name);



    // }

    int find_taxon(std::string name) {
        return DFS(name);
    }

};

#endif