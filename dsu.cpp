#include<bits/stdc++.h>
using namespace std;
#define ll long long
class DisjointSet{
	vector<int>rank,size,parent;
public:
	DisjointSet(int n){
		rank.resize(n+1,0);
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i] = i;
		} // each node is parent of itself at start.
	}
	int findUPar(int node){
		if( node == parent[node])
			return node;
		return parent[node] = findUPar(parent[node]);
	} // all ultimate parent are stored in the parent array.
	void unionByRank(int u,int v){
		int ulp_u = findUPar(u); 
		int ulp_v = findUPar(v);
		if(ulp_u == ulp_v) return;
		// connnect smaller rank to larger rank
		// no change in size will occur if we connect the smaller rank to the larger rank,
		// also by doing that the lenght of the tree like str. formed will of lesser height.
		if(rank[ulp_u]<rank[ulp_v]){
			parent[ulp_u] = ulp_v;
		}
		else if(rank[ulp_v]<rank[ulp_u]){
			parent[ulp_v] = ulp_u;
		}
		// when the two ultimate parend of the equal rank then connencting one to aonther
		// will increment the rank of the parent to which the other parent will ge connected.
		else{
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}
	void unionBySize(int u,int v){
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if(ulp_u == ulp_v)return;
		// connect the smaller size to the larger size.
		if(size[ulp_v] > size[ulp_u]){
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
		else{
			parent[ulp_v] = ulp_u;
			size[ulp_u]+=size[ulp_v];
		}
	}
};
int main(){
  // This is Klez's Template.
  // Policy Based Data Structures Are Also included.
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  cout.tie(NULL);
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // #endif
  DisjointSet ds(7);
  ds.unionBySize(1,2);
  ds.unionBySize(2,3);
  if(ds.findUPar(3) == ds.findUPar(1)){
  	cout << "same\n";
  }
  else cout << "not same\n";
  ds.unionBySize(4,5);
  ds.unionBySize(6,7);
  if(ds.findUPar(3) == ds.findUPar(7)){
  	cout << "same\n";
  }
  else cout << "not same\n";
  ds.unionBySize(3,7);
  if(ds.findUPar(3) == ds.findUPar(7)){
  	cout << "same\n";
  }
  else cout << "not same\n";

  return 0;
}
