#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <list>
#include <vector>
#include "graph.h"

int main()
{
    Graph  *g = new Graph();
    Vertex *v = new Vertex();

    readGraphByFile(g);
    //showGraphFile(g);
    buildGraph(g, v);

    list<Vertex>::iterator it;
    for( it = g->nodes.begin(); it != g->nodes.end(); it++ ){
        showVertex(&g->nodes.front());
        g->nodes.pop_front();
    }




    free(g);
    free(v);
    //graph_bfs(g);
    return 0;
}
