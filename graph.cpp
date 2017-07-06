#include <iostream>
#include <vector>

class Graph {
    public:
        
        void add_edge(Graph *, int, int, bool);
        int degree(int);
        Graph() { initialize_graph(); }
        ~Graph() {}
        void initialize_graph();

    private:

        Graph(const Graph &obj);
        Graph& operator=( const Graph& other);
        
          
        struct edge_node {
            int destination;
            int weight;
            edge_node *next;
            edge_node(int dest, int weight): destination(dest), weight(weight), next(nullptr) {}
        };

        int numEdges;
        int numVertices;
        bool directed;

        edge_node *edges[1001];
        int degrees[1001];


};

void Graph::initialize_graph() {

    numVertices = 0;
    numEdges = 0;
    directed = true;

    for (int i=1; i<=1001; ++i) {
        degrees[i] = 0;
        edges[i] = nullptr;
    }

}

void Graph::add_edge(Graph *g, int v, int w, bool directed = true) {
    edge_node *node = new edge_node(w, 0);
    
    node->next = g->edges[v];
    g->edges[v] = node; // insert at front
    g->numEdges++;
    g->degrees[v]++;
    g->numVertices += 2;

    // if directed == false TBD add_edge(g, w, x, false)
}

int main() {

    Graph *g = new Graph;



    return 0;
}
