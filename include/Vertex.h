#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <iostream>

class Vertex {
private:
    std::vector<unsigned int> edges;

public:
    Vertex() : edges() {}

    virtual ~Vertex() {}

    void add_edge(unsigned int dest) {
        // checks to make sure edge to requested destination doesn't already exist
        for (unsigned int i = 0; i < edges.size(); i++) {
            if (edges[i] == dest) {
                std::cout << "Error: Could not add. Edge to " << dest << " already exists." << std::endl;
                return;
            }
        }
        edges.push_back(dest);
    }

    void del_edge(unsigned int dest) {
        // linear search to find and erase edge to requested destination
        for (unsigned int i = 0; i < edges.size(); i++) {
            if (edges[i] == dest) {
                edges.erase(edges.begin() + i);
                return;
            }
        }
    }

    void del_edge_loc(unsigned int loc) {
        edges.erase(edges.begin() + loc);
    }

    void print_edges() {
        std::cout << "[";
        for (unsigned int i = 0; i < edges.size(); i++) {
            std::cout << edges[i];
            if (i < edges.size()- 1) 
                std::cout << " ";
        }
        std::cout << "]" << std::endl;
    }

    unsigned int get_num_edges() {
        return (unsigned int) edges.size();
    }

    unsigned int get_edge(unsigned int loc) {
        return edges[loc];
    }

};

#endif