/**
@author Kunal Chaudhary

Dependencies: Digraph.h

API:-
class DepthFirstOrder
 - DepthFirstOrder(Digraph G)		//constructor
 - stack<int> reversePost()			//topological order
*/

class DepthFirstOrder{
	private:
		bool *_marked;
		stack<int> _reversePost;

		void dfs(Digraph G, int v){
			_marked[v]=true;
			int *adj=G.adj(v);
			int len=G.degree(v);
			for(int i=0; i<len; i++)
				if(!_marked[adj[i]]) dfs(G,adj[i]);
			_reversePost.push(v);
		}

    public:
		DepthFirstOrder(Digraph G){
			//if(isCyclic(G)) Error! Only Acyclic directed graph have a topological order.
            _marked = new bool[G.V()];
            for(int i=0; i<G.V(); i++)
				_marked[i]=false;
            for(int i=0; i<G.V(); i++)
				if(!_marked[i]) dfs(G,i);
		}

		stack<int> reversePost(){
			return _reversePost;
		}
};
