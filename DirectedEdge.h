class DirectedEdge{
	private:
		int _v, _w;
		double _weight;

	public:
		DirectedEdge(int from, int to, double weight){
			_v=from;
			_w=to;
			_weight=weight;
		}

		int from(){
			return _v;
		}

		int to(){
			return _w;
		}

		int weight(){
			return _weight;
		}

		bool operator < (const DirectedEdge &e) const{
			return _weight < e._weight;
		}

		bool operator > (const DirectedEdge &e) const{
			return _weight > e._weight;
		}
};
