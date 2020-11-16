#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include <iostream>

#include "Vertex.h"

#define uint unsigned int

template<class V>
class Graph {
protected:
    std::vector<V> verts;

public:
    Graph(): verts() {}

    virtual ~Graph() {}

    void add_vert(V vert) {
        verts.push_back(vert);
    }

    void add_edge(uint origin, uint dest) {
        // prevents a loop in the graph (edge to itself)
        if (origin != dest) {
            verts[origin].add_edge(dest);
        } else {
            std::cout << "Error: Loopback protection, edge wasn't added." << std::endl;
        }
    }

    void del_vert(uint loc) {
        verts.erase(verts.begin() + loc);

        for (int i = 0; i < verts.size(); i++) {
            verts[i].del_edge(loc);
        }
    }

    V get_vert(uint loc) {
        return verts[loc];
    }

    int get_vert_loc(V vert){
      for (int i = 0; i < verts.size(); ++i){
        if (verts[i].equals(vert)){
          return i;
        }
      }
      return -1;
    }

    virtual void print_graph() {
        std::cout << "Graph size: " << verts.size() << " verts" << std::endl;

        for (int i = 0; i < verts.size(); i++) {
            std::cout << i << ": " << "[" << i << "]" << " -> ";
            verts[i].print_edges();
        }
    }

};

#endif
