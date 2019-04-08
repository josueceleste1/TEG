#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <stdio.h>
#include <list>
#define MAXN 10
#define MAXM 20
#include <fstream>
#include <string>
#include "graph.h"

void showGraphFile(Graph *g){
    int tam = g->adj.size();
    for(int i=0; i<tam; i++){
        cout << g->adj.front() << endl;
        g->adj.pop_front();
    }
}

void showVertex(Vertex *v){
    cout << v->getId() << " : ";
    showEdges(v);
    cout << "\n";
}
void showEdges(Vertex *v){
    Vertex *aux = v;
    int tam = aux->edges.size();
    int i;
    for(i=0; i<tam; i++){
        cout << aux->getEdges().front() << " ";
        aux->edges.pop_front();
    }
}

void buildGraph(Graph *g, Vertex *v){
    list<int>    node;
    list<int>    edges;
    list<string> strFormated;
    list<int>::iterator it;

    int tam = g->adj.size();

    for(int i=0; i<tam; i++){

        char delim = ':';
        strFormated = formatString(g->adj.front(), delim);
        g->adj.pop_front(); // tira da fila tendo em vista que ja foi processado

        edges = castToInt(strFormated.back());
        node = castToInt(strFormated.front());

        v->setEdges(edges);
        v->setId(node.front());

       /* cout << "vertex" << endl;
        cout << v->getId() << endl;

        cout << "edges" << endl;
        for( it = edges.begin(); it != edges.end(); it++ ){
                cout << v->getEdges().front() << endl;
                v->edges.pop_front();
            }*/
        g->nodes.push_front(*v);
    }
}

list<string> formatString(string s, char delim){
  	int          posDelim;
	string       value = "";
	list<string> result;

	while( !s.empty() ){
		posDelim = s.find( delim );
		value = s.substr( 0, posDelim );
		s.erase( 0, posDelim + 1 );

		if( !value.empty() ){
			result.push_back( value );
		}

		if( posDelim < 0 ){
			break;
		}

	}

	return result;
}
 list<int> castToInt(string s){
    list<int>    result;
	stringstream ss( s );
	int          value;

	while( ss >> value ){
		result.push_back( value );
	}

	return result;
}
void readGraphByFile(Graph *g){

    ifstream grafo;
    string linha;
    grafo.open("grafo1.txt");

    if(grafo.is_open()){
        while(getline(grafo, linha)){
           g->adj.push_front(linha);

        }
    }else{
        cout << "Not was possible to open this file" << endl;
    }
}
void graph_bfs(Graph *g){


}
