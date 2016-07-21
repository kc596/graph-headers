/**
@author Kunal Chaudhary

Dependencies:- Digraph.h, DepthFirstOrder.h

API:-
class KosarajuSharirSCC
 - KosarajuSharirSCC(Digraph G)
 - int count()								//constructor
 - int id(int v)							//id of component in which v is connected
 - bool stronglyConnected(int v, int w)		//are v and w strongly connected?
*/

class KosarajuSharirSCC{
	private:
		int _count;
		bool *_marked;
		int *_id;

        void dfs(Digraph G, int v){
            _marked[v]=true;
            _id[v]=_count;
            int *adj=G.adj(v);
            int len=G.degree(v);
            for(int i=0; i<len; i++){
				if(!_marked[adj[i]]){
					dfs(G,adj[i]);
				}
            }
        }

	public:
		KosarajuSharirSCC(Digraph G){
			_count=0;
			_marked=new bool[G.V()];
			_id=new int[G.V()];
			for(int i=0; i<G.V(); i++){
				_marked[i]=false;
				_id[i]=i;
			}
            Digraph R=G.reverse();
            DepthFirstOrder dfo(R);
            stack<int> s=dfo.reversePost();
			while(!s.empty()){
				int v=s.top();
				s.pop();
				if(!_marked[v]){
                    dfs(G,v);
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

		bool stronglyConnected(int v, int w){
			return _id[v]==_id[w];
		}
};
