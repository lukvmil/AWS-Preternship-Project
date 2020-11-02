#include <iostream>
#include <vector>
#include "../include/Graph.h"
#include "../include/Vertex.h"
#include "../include/Edge.h"

int main() {
    Graph<int> graph;
    std::vector<int> verts {1, 3, 6, 7, 5, 4, 2, 8, 9};
    
    for (int i = 0; i < verts.size(); i++) {
        graph.add_vert(verts[i]);
    }

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 3);
    graph.add_edge(3, 7);
    graph.add_edge(3, 8);
    graph.add_edge(2, 4);
    graph.add_edge(2, 5);
    graph.add_edge(2, 6);


    graph.print();

    graph.del_vert(4);

    graph.print();

}