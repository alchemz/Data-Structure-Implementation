#include<bits/stdc++.h>
using namespace std;

class SparseVector{
  map<int, double>st;
  int N;

public:
  SparseVector(int N){
    this->N=N;
    st = new map<int, double>();
  }
  
  void put(int i, double value){
    if(i<0 || i>=N)
      return 0;
    if(value==0.0)
      st.erase(i);
    else
      st.emplace(i, value);
  }
  
  double get(int i){
    if(i<0|| i>=N)
      return 0;
    if(st.count(i)>0)
      return st.get(i);
    else
      return 0.0;
  }
  
  int size(){
    return N;
  }
  
  SparseVector plus(SparseVector b){
    SparseVector a= this;
    if(a.N != b.N)
      return 0;
    for(auto it=b.begin(); it!=b.end(); ++it)
      a[it->first] += it->second;
    
    return a;
  }
  
};

int main()
{
  int n=10;
  SparseVector v1= new SparseVector(n);
  SparseVector v2= new SparseVector(n);
  return 0;
}