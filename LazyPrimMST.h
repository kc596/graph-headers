/**
@author Kunal Chaudhary

Dependencies: 	 Edge.h, EdgeWeightedGraph.h

API:-
class LazyPrimMST
 - LazyPrimMST(EdgeWeightedGraph G)		//constructor
 - queue<int> edges()					//edges in MST
 - double weight()						//total weight of MST
*/

class LazyPrimMST{
	private:
		struct cmp{
			bool operator()(Edge a, Edge b) const{
				return a.weight()>b.weight();
			}
		};

		bool *_marked;
		queue<Edge> _mst;
		priority_queue<Edge, vector<Edge>, cmp> pq;


		void visit(EdgeWeightedGraph G, int v){
			_marked[v]=true;
			Edge *adj=G.adj(v);
			int len=G.degree(v);
			for(int i=0; i<len; i++){
				if(!_marked[adj[i].other(v)]) pq.push(adj[i]);
			}
		}

	public:
        LazyPrimMST(EdgeWeightedGraph G){
        	_marked = new bool[G.V()];
        	for(int i=0; i<G.V(); i++) _marked[i]=false;
			visit(G,0);

			while(!pq.empty()){
				Edge e=pq.top();
				pq.pop();
				int v=e.either(), w=e.other(v);
				if(_marked[v] && _marked[w]) continue;
				_mst.push(e);
                if(!_marked[v]) visit(G,v);
                if(!_marked[w]) visit(G,w);
			}
        }

        queue<Edge> edges(){
			return _mst;
		}

		double weight(){
			double wt=0;
            Edge *t=&_mst.front();
			while(t!=&_mst.back()){
				wt+=(*t).weight();
				t++;
			}
			wt+=(*t).weight();
			return wt;
		}
};
