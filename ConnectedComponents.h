/**
@author Kunal Chaudhary

Dependencies: Graph.h

API:-
class CC
 - CC(Graph g)						//constructor
 - int count()						//number of connected components
 - int id(int v)					//id of component in which v is connected
 - bool connected(int w, int v)		//are w and v connected?
*/

class CC{
	private:
		int _count;
		bool *_marked;
		int *_id;

		void dfs(Graph G, int v){
			_marked[v]=true;
			_id[v]=_count;
			int *adj=G.adj(v);
			int len=G.degree(v);
			for(int i=0; i<len; i++){
				if(!_marked[adj[i]]){
					dfs(G, adj[i]);
				}
			}
		}

	public:
		CC(Graph G){
			_count=0;
			_marked=new bool[G.V()];
			_id=new int[G.V()];
			for(int i=0; i<G.V(); i++){
				_marked[i]=false;
				_id[i]=i;
			}

			for(int i=0; i<G.V(); i++){
				if(!_marked[i]){
					dfs(G,i);
					_count++;
				}
			}
		}

		int count(){
			return _count;
		}

		int id(int v){
			return _id[v];
		}

		bool connected(int v, int w){
			return _id[v]==_id[w];
		}
};
