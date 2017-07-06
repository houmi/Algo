#include <iostream>
#include <vector>

class Graph {
    public:
        
        void addEdge(int v, int w);
        int degree(int v);
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

int main() {

    Graph g;



    return 0;
}
