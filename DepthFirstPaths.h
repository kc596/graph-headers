/**
@author Kunal Chaudhary

Dependencies: Graph.h

API:-
class DepthFirstPaths
 - DepthFirstPaths(Graph G, int source)		//constructor
 - bool hasPathTo(int v)					//is there a path b/w source and v?
 - stack<int> pathTo(int v)					//path from s to v
*/

class DepthFirstPaths{
	private:
		bool *_marked;
		int *_edgeTo;
		int _s;

		void dfs(Graph G, int v){
			_marked[v]=true;
			int *adj=G.adj(v), w=G.degree(v);
			for(int i=0; i<w; i++){
				if(!_marked[adj[i]]){
					dfs(G, adj[i]);
					_edgeTo[adj[i]]=v;
				}
			}
		}

    public:
		DepthFirstPaths(Graph G, int s){
			_s=s;
			_edgeTo=new int[G.V()];
			_marked=new bool[G.V()];
			for(int i=0; i<G.V(); i++) _marked[i]=false;
			dfs(G,s);
		}

		bool hasPathTo(int v){
			return _marked[v];
		}

		stack<int> pathTo(int v){
			stack<int> path;
			if(!hasPathTo(v)) return path;
			for(int i=v; i!=_s; i=_edgeTo[i]) path.push(i);
			path.push(_s);
			return path;
		}
};
