/**
@author Kunal Chaudhary

API:-
class Graph
 - Graph(int V)						//constructor
 - void addEdge(int v, int w)		//adding a new edge b/w v and w
 - int *adj(int v)					//pointer to list of vertices adjacent to v
 - int degree(int v)				//length of adjacency list of v
 - int V()							//number of vertices in Graph
 - int E()							//number of edges in Graph
*/

class Graph{
    private:
		int _V, _E, *_adj_size;
		vector<int> *_adj;

	public:
		Graph(int v){
			_V=v;
			_E=0;
			_adj= new vector<int>[v];
			_adj_size=new int[v];
			for(int i=0; i<v; i++) _adj_size[i]=0;
		}

		void addEdge(int v, int w){
			_adj[v].push_back(w);
			_adj[w].push_back(v);
			_adj_size[v]++;
			_adj_size[w]++;
			_E++;
		}

		int* adj(int v){
			return &_adj[v][0];
		}

		int degree(int v){
			return _adj_size[v];
		}

		int V(){
			return _V;
		}

		int E(){
			return _E;
		}
};
