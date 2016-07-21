/**
@author Kunal Chaudhary

API:-
class Digraph
 - Digraph(int V)					//constructor
 - void addEdge(int v, int w)		//add a new edge v -> w
 - int* adj(int v)					//vertices starting from v
 - int degree(int v)				//number of vertices starting from v
 - int V()							//number of vertices in given Digraph
 - int E()							//number of edges in given Digraph
 - Digraph reverse()				//reverse of the given Digraph
*/

class Digraph{
	private:
		int _V, _E, *_degree;
		vector<int> *_adj;

	public:
		Digraph(int v){
			_V=v;
			_E=0;
			_adj = new vector<int>[v];
			_degree = new int[v];
			for(int i=0; i<v; i++) _degree[i]=0;
		}

		void addEdge(int v, int w){
			_adj[v].push_back(w);
			_degree[v]++;
			_E++;
		}

		int* adj(int v){
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

		Digraph reverse(){
			Digraph R(_V);
			for(int i=0; i<_V; i++){
				int *ad=adj(i);
				int len=degree(i);
				for(int j=0; j<len; j++) R.addEdge(ad[j], i);
			}
			return R;
		}
};
