#ifndef TREE_H
#define TREE_H

#include "Graph.h"
#include "Taxon.h"


class Tree: public Graph {
private:

public:
    Tree() : tree_graph() {
        Taxon root_taxon("root");
        Vertex<Taxon> root_node(root_taxon);

        Vertex<Taxon>(Taxon("root"));

        tree_graph.add_vert(Vertex<Taxon>(Taxon("taxon")));

    }

    ~Tree() {}

    void test() {
        tree_graph.print();
        std::cout << tree_graph.get_vert(0).get_data() << std::endl;
    }


};

#endif