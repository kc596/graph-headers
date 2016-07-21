/**
@author Kunal Chaudhary

API:-
class UnionFind
 - UnionFind(int v)					//constructor
 - void connect(int p, int q)		//join p's and q's network
 - bool connected(int p, int q)		//are p and q connected?
*/

class UnionFind{
	private:
		int *_id, *_size;

		int root(int i){
			while(i!=_id[i]){
				_id[i]=_id[_id[i]];
				i=_id[i];
			}
			return i;
		}

	public:
		UnionFind(int v){
			_id=new int[v];
			_size=new int[v];
			for(int i=0; i<v; i++){
				_id[i]=i;
				_size[i]=1;
			}
		}

		void connect(int p, int q){
			int i=root(p);
			int j=root(q);
			if(i==j) return;
			if(_size[i]>_size[j]){
				_id[j]=i;
				_size[i]+=_size[j];
			}
			else{
				_id[i]=j;
				_size[j]+=_size[i];
			}
		}

		bool connected(int p, int q){
			return root(p)==root(q);
		}
};
