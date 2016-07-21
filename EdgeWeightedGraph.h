/**
@author Kunal Chaudhary

Dependencies: Edge.h

API:-
class EdgeWeightedGraph
 - EdgeWeightedGraph(int V)		//constructor - create an edge-weighted graph with V vertices
 - void addEdge(Edge e)			//add Edge e to graph
 - int* adj(int v)				//list of vertices adjacent to v
 - int degree(int v)			//number of vertices adjacent to v
 - int V()						//total number of vertices in graph
 - int E()						//total number of edges in graph
 - vector<Edge> edges()			//list of edges of graph
*/

class EdgeWeightedGraph{
	private:
		int _V, _E, *_degree;
		vector<Edge>* _adj;
		vector<Edge> _edges;

	public:
		EdgeWeightedGraph(int V){
			_V=V;
			_E=0;
			_adj=new vector<Edge>[V];
			_degree=new int[V];
			for(int i=0; i<V; i++) _degree[i]=0;
		}

		void addEdge(Edge e){
			_edges.push_back(e);
            int v=e.either();
            int w=e.other(v);
            _adj[v].push_back(e);
            _adj[w].push_back(e);
            _degree[v]++;
            _degree[w]++;
            _E++;
		}

		Edge* adj(int v){
			return &_adj[v][0];
		}

		int degree(int v){
			return _degree[v];
		}

		int V(){
			return _V;
		}

		int E(){
			return _E;
		}

		vector<Edge> edges(){
			return _edges;
		}
};
