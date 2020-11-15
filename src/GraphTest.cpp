#include <iostream>
#include <vector>
#include "../include/Graph.h"
#include "../include/Vertex.h"

int main() {
    Graph<Vertex> graph;
    
    for (unsigned int i = 0; i < 7; i++) {
        graph.add_vert(Vertex());
    }

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 3);
    graph.add_edge(3, 7);
    graph.add_edge(3, 8);
    graph.add_edge(2, 4);
    graph.add_edge(2, 5);
    graph.add_edge(2, 6);

    graph.print_graph();
}