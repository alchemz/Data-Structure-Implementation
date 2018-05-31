/*
https://coolshell.cn/articles/17225.html
https://blog.csdn.net/suwei19870312/article/details/7442786
https://www.geeksforgeeks.org/cuckoo-hashing/
https://www.sanfoundry.com/cpp-program-hash-tables-double-hashing/

*/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10
 
// choices for position
#define ver 2

class CuckooHashing{
private:
  int hashtable[ver][MAXN];
  int pos[ver];
  
public:
  void initTable();
  int hash(int function, int key);
  void place(int key, int tableID, int cnt, int n);
  void printTable();
  void cuckoo(int keys[], int n);
  
};

void CuckooHashing::initTable()
{
    for (int j=0; j<MAXN; j++)
        for (int i=0; i<ver; i++)
            hashtable[i][j] = INT_MIN;
}

int CuckooHashing::hash(int function, int key)
{
    switch (function)
    {
        case 1: return key%MAXN;
        case 2: return (key/MAXN)%MAXN;
    }
  return 0;
}

void CuckooHashing::place(int key, int tableID, int cnt, int n)
{
    if (cnt==n)
    {
        cout<<key<<" unpositioned\n";
        cout<<"Cycle present. REHASH.\n";
        return;
    }

    for (int i=0; i<ver; i++)
    {
        pos[i] = hash(i+1, key);
        if (hashtable[i][pos[i]] == key)
           return;
    }

    if (hashtable[tableID][pos[tableID]]!=INT_MIN)
    {
        int dis = hashtable[tableID][pos[tableID]];
        hashtable[tableID][pos[tableID]] = key;
        place(dis, (tableID+1)%ver, cnt+1, n);
    }
    else 
       hashtable[tableID][pos[tableID]] = key;
}

void CuckooHashing::printTable()
{
    cout<<"Final hash tables:\n";

    for (int i=0; i<ver; i++){
      cout<<"\n";
        for (int j=0; j<MAXN; j++){
            (hashtable[i][j]==INT_MIN)? cout<<"- ":cout<<" "<<hashtable[i][j];
        }
    }

   cout<<"\n";
}

void CuckooHashing::cuckoo(int keys[], int n)
{
    initTable();

    for (int i=0, cnt=0; i<n; i++, cnt=0)
        place(keys[i], 0, cnt, n);

    printTable();
}

int main()
{
    int keys_1[] = {20, 50, 53, 75, 100, 67, 105,3, 36, 39};
 
    int n = sizeof(keys_1)/sizeof(int);
    CuckooHashing CH;
    CH.cuckoo(keys_1, n);
 
    int keys_2[] = {20, 50, 53, 75, 100, 67, 105,3, 36, 39, 6};
 
    int m = sizeof(keys_2)/sizeof(int);
 
    CH.cuckoo(keys_2, m);
 
    return 0;
}
