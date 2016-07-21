/**
@author Kunal Chaudhary

Dependencies: Edge.h, EdgeWeightedGraph.h, UnionFind.h

API:-
class KruskalMST
 - KrushkalMST(EdgeWeightedGraph G)		//constructor
 - queue<int> edges()					//edges in MST
 - double weight()						//total weight of MST
*/

class KruskalMST{
	private:
		queue<Edge> _mst;

		struct cmp{
			bool operator ()(Edge a, Edge b) const{
				return a.weight() > b.weight();
			}
		};

	public:
		KruskalMST(EdgeWeightedGraph G){
			priority_queue<Edge, vector<Edge>, cmp> pq;		//min PQ
			vector<Edge>:: iterator it;
			vector<Edge> edges=G.edges();
			for(it=edges.begin(); it!=edges.end(); ++it) pq.push(*it);
			UnionFind uf(G.V());
			while(!pq.empty() && _mst.size()<G.V()-1){
                Edge e=pq.top();
                pq.pop();
                int v=e.either(), w=e.other(v);
                if(!uf.connected(v,w)){
					uf.connect(v,w);
					_mst.push(e);
                }
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
