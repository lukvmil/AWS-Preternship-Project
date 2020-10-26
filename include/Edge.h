#ifndef EDGE_H
#define EDGE_H

struct Edge {
    unsigned int dest;
    int weight;

    Edge() : dest(), weight() {}
    Edge(unsigned int d, int w) : dest(d), weight(w) {}
};

#endif
