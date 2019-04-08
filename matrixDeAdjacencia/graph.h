using namespace std;

class Vertex{
    public:
	int       id;
	list<int> edges;
	int       degree;

	int getId(){
		return id;
	}

	void setId( int value ){
		id = value;
	}

	list<int> getEdges(){
		return edges;
	}

	void setEdges( list<int> values ){
		edges = values;
	}
};


class Graph{
public:
    list<Vertex> nodes;
    list <string> adj;
};
void showVector(vector<int> g);
void showGraphFile(Graph *g);
void showVertex(Vertex *v);
void showEdges(Vertex *v);
void criaMatrizNaoDirecionado();
void readGraphByFile(Graph *g);
void criaGradoNoArquivo();
void showGraphFile(Graph *g);
void graph_bfs(Graph *g);
list<int> castToInt(string s);
list<string> formatString(string s, char delim);
void buildGraph(Graph *g, Vertex *v);

