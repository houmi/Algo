#include <iostream>
#include <vector>

using namespace std;

class Graph {
    public:
        
        void add_edge(Graph *, int, int, bool);
        int degree(int);
        void print_graph(Graph *);
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
    g->numVertices++;

    // if directed == false TBD add_edge(g, w, x, false)
}

void Graph::print_graph(Graph *g) {
    edge_node *node = nullptr;
    for (int i=1, len = g->numVertices; i<=len ; ++i) {
        cout << i << ": ";
        node = g->edges[i];
        while (node != nullptr) {
            cout << " " << node->destination;
            node = node->next;
        }
        cout << endl;
    }
}

int main() {

    Graph *g = new Graph;
    g->add_edge(g, 1, 2);
    g->add_edge(g, 2, 4);
    g->add_edge(g, 2, 3);
    g->add_edge(g, 3, 5);
    g->add_edge(g, 4, 5);
    g->add_edge(g, 5, 6);
    g->add_edge(g, 6, 7);
    g->print_graph(g);

    return 0;
}
