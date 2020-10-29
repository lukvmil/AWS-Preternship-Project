#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <iostream>
#include "Edge.h"

template<class T>
class Vertex {
private:
    std::vector<Edge> edges;
    T data;

public:
    Vertex() : edges(), data() {}
    Vertex(const T& data_in) : edges(), data(data_in) {}

    T get_data() {
        return data;
    }

    void set_data(T data_in) {
        data = data_in;
    }

    void add_edge(unsigned int dest) {
        // checks to make sure edge to requested destination doesn't already exist
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].dest == dest) {
                std::cout << "Error: Could not add. Edge to " << dest << " already exists." << std::endl;
                return;
            }
        }
        edges.push_back(Edge(dest, 1));
    }

    void del_edge(unsigned int dest) {
        // linear search to find and erase edge to requested destination
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].dest == dest) {
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
        for (int i = 0; i < edges.size(); i++) {
            std::cout << edges[i].dest;
            if (i < edges.size()- 1) 
                std::cout << " ";
        }
        std::cout << "]" << std::endl;
    }

    unsigned int get_num_edges() {
        return (unsigned int) edges.size();
    }

    Edge get_edge(unsigned int loc) {
        return edges[loc];
    }

};

#endif