#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        for (unsigned int i = 0; i < A.size(); ++i) {
            for (unsigned int k = 0; k < A[0].size(); ++k) {
                if (A[i][k] != 0) {
                    for (unsigned int j = 0; j < B[0].size(); ++j) {
                        if (B[k][j] != 0) res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
}

vector<vector<int>> add(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        for (unsigned int i = 0; i < A.size(); ++i) {
            for (unsigned int k = 0; k < A[0].size(); ++k) {
                if (A[i][k] != 0) {
                    for (unsigned int j = 0; j < B[0].size(); ++j) {
                        if (B[k][j] != 0) res[i][j] += A[i][k] + B[k][j];
                    }
                }
            }
        }
        return res;
}

int main(){
  vector<vector<int>> A={{1,0,0},{-1,0,3}};
  vector<vector<int>> B={{7,0,0},{0,0,0},{0,0,1}};
  
  vector<vector<int>>ans=add(A, B);
  for(unsigned int i=0; i<ans.size(); i++){
    for(unsigned int j=0; j<ans[0].size(); j++){
      cout<<ans[i][j]<<",";
    }
    cout<<endl;
  }
  return 0;
}