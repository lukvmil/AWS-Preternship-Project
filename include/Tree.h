#ifndef TREE_H
#define TREE_H

#include <stack>
#include <queue>
#include "Graph.h"
#include "Taxon.h"


class Tree: public Graph<Taxon> {
private:
    std::queue<unsigned int> vacancies;

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
    Tree() : vacancies() {
        Taxon root("root", 0);
        add_vert(root);
    }

    ~Tree() {}

    void add_taxon(std::string parent, std::string name) {
        int child_id, parent_id;

        // parent id found through private depth first search function
        parent_id = DFS(parent);

        // DFS returns -1 if taxon wasn't found
        if (parent_id == -1) {
            std::cout << "Error: Parent does not exist." << std::endl;
            return;
        }

        // creates new child taxon
        Taxon child(name, parent_id);

        // checks for any vacancies from lazy deletion to fill
        if (vacancies.empty()) {
            // child id will be the next element in verts
            child_id = (int) verts.size();
            add_vert(child);
        } else {
            // fills vacancy
            child_id = (int) vacancies.front();
            std::cout << "using " << child_id << std::endl;
            vacancies.pop();

            // overrides deleted taxon
            verts[child_id] = child;
        }

        //  connects child to tree
        add_edge(parent_id, child_id);
    }

    void del_taxon(std::string name, bool recursive = false) {
        int id = DFS(name);
        unsigned int curr_edge;
        unsigned int parent_id = verts[id].get_parent();

        // lazy deletion
        verts[id].del();
        vacancies.push(id);

        // removes connection from parent
        verts[parent_id].del_edge(id);

        if (!recursive) {
            // iteratively moves all child taxons to be children of the deleted taxon's parent
            for (unsigned int i = 0; i < verts[id].get_num_edges(); i++) {
                curr_edge = verts[id].get_edge(i);

                verts[curr_edge].set_parent(parent_id);
                verts[parent_id].add_edge(curr_edge);
            }
        } else {
            // recursively deletes child taxons
            for (unsigned int i = 0; i < verts[id].get_num_edges(); i++) {
                curr_edge = verts[id].get_edge(i);
                std::cout << "deleting " << verts[curr_edge].get_name() << std::endl;
                del_taxon(verts[curr_edge].get_name(), true);
            }
        }

    }

    int find_taxon(std::string name) {
        return DFS(name);
    }

    void print() {
        std::cout << "Tree size: " << verts.size() << " verts (" << vacancies.size() << " vacancies)" << std::endl;

        for (unsigned int i = 0; i < verts.size(); i++) {
            if (verts[i].alive()) {
                std::cout << i << ": " << "[" << verts[i] << "]" << " -> ";
                verts[i].print_edges();
            } else {
                std::cout << i << ": " << "*DELETED*" << std::endl;
            }
        }
    }

};

#endif