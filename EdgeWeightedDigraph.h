class EdgeWeightedDigraph{
	private:
		int _V, _E;
		vector<int>* _adj;
		int *_degree;

	public:
		EdgeWeightedDigraph(int V){
			_V=V;
            _E=0;
            _adj=new vector<int>[V];
            _degree=new int[V];
            for(int i=0; i<V; i++) _degree[i]=0;
		}

		void addEdge(DirectedEdge e){
            int v=e.from();
            _adj[v].push_back(e);
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
};
