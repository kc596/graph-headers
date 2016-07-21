/**
@author Kunal Chaudhary

Dependencies: Graph.h

API:-
class BreadthFirstPaths
 - BreadthFirstPaths(Graph g, int source)		//constructor
 - bool hasPathTo(int v)						//is there a path b/w source and v?
 - stack<int> pathTo(int v)						//shortest path from source to v
 - int distTo(int v)							//number of edges in shortest path from source to v
*/

class BreadthFirstPaths{
    private:
		bool *_marked;
		int *_edgeTo;
		int *_distTo;

		void bfs(Graph g, int s){
			_marked[s]=true;
			_distTo[s]=0;
			queue<int> q;
			q.push(s);
			while(!q.empty()){
				int v=q.front();
				q.pop();
				int *adj=g.adj(v);
				int len=g.degree(v);
				for(int i=0; i<len; i++){
					int w=adj[i];
					if(!_marked[w]){
						q.push(w);
						_edgeTo[w]=v;
						_marked[w]=true;
						_distTo[w]=_distTo[v]+1;
					}
				}
			}
		}

	public:
		BreadthFirstPaths(Graph G, int s){
            _marked=new bool[G.V()];
            _edgeTo=new int[G.V()];
            _distTo=new int[G.V()];
            for(int i=0; i<G.V(); i++){
				_marked[i]=false;
				_distTo[i]=INT_MAX;
            }
            bfs(G,s);
		}

		bool hasPathTo(int v){
			return _marked[v];
		}

		stack<int> pathTo(int v){
			stack<int> path;
			if(!hasPathTo(v)) return path;
			int i;
			for(i=v; _distTo[i]!=0; i=_edgeTo[i]) path.push(i);
			path.push(i);
			return path;
		}

		int distTo(int v){
			return _distTo[v];
		}
};
