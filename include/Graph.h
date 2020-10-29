#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

#include "Vertex.h"

template<class T>
class Graph {
private:
    std::vector< Vertex<T> > verts;

public:
    Graph() : verts() {}

    void add_vert(Vertex<T> vert) {
        verts.push_back(vert);
    }

    void add_vert(T data) {
        verts.push_back(Vertex<T>(data));
    }

    void add_edge(unsigned int origin, unsigned int dest) {
        verts[origin].add_edge(dest);
    }

    void del_vert(unsigned int loc) {
        verts.erase(verts.begin() + loc);

        for (int i = 0; i < verts.size(); i++) {
            verts[i].del_edge(loc);
        }
    }

    void print() {
        std::cout << "Graph size: " << verts.size() << " verts" << std::endl;

        for (int i = 0; i < verts.size(); i++) {
            std::cout << i << ": " << "[" << verts[i].get_data() << "]" << " -> ";
            verts[i].print_edges();
        }
    }

};

#endif