/**
@author Kunal Chaudhary

API:-
class Edge
 - Edge(int v, int w, double weight)	//constructor
 - int either()							//either endpoint of edge
 - int other(int v)						//the endpoint that is not v
 - double weight()						//weight of edge
 - bool operator < (const Edge &x)		//comparing this edge to x
*/
class Edge{
	private:
		int _v, _w;
		double _weight;

	public:
		Edge(int v, int w, double weight){
			_v=v;
			_w=w;
			_weight=weight;
		}

		int either(){
			return _v;
		}

		int other(int v){
			if(v==_v) return _w;
			else return _v;
		}

		double weight(){
			return _weight;
		}

		bool operator < (const Edge &x) const {
			return (_weight < x._weight);
		}

		bool operator > (const Edge &x) const {
			return (_weight > x._weight);
		}
};
