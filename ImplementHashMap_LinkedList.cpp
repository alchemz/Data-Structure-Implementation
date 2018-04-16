#include<bits/stdc++.h>
using namespace std;
const int TABLE_SIZE = 128;
 
class HashNode
{
public:
  int key;
  int value;
  HashNode* next;
    HashNode(int key, int value)
    {
      this->key = key;
      this->value = value;
      this->next = NULL;
    }
};
 
class HashMap
{
private:
    HashNode** htable;
public:
  HashMap();
  ~HashMap();
  int HashFunc(int key);
  void Insert(int key, int value);
  void Remove(int key);
  int Search(int key);
  
};
HashMap::HashMap(){
    htable = new HashNode*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        htable[i] = NULL;
}
HashMap::~HashMap(){
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        HashNode* entry = htable[i];
        while (entry != NULL)
        {
            HashNode* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] htable;
}

int HashMap::HashFunc(int key){
    return key % TABLE_SIZE;
}

void HashMap::Insert(int key, int value){
    int hash_val = HashFunc(key);
    HashNode* prev = NULL;
    HashNode* entry = htable[hash_val];
    while (entry != NULL)
    {
        prev = entry;
        entry = entry->next;
    }
    if (entry == NULL)
    {
        entry = new HashNode(key, value);
        if (prev == NULL)
        {
            htable[hash_val] = entry;
        }
        else
        {
            prev->next = entry;
        }
    }
    else
    {
        entry->value = value;
    }
}

void HashMap::Remove(int key){
    int hash_val = HashFunc(key);
    HashNode* entry = htable[hash_val];
    HashNode* prev = NULL;
    if (entry == NULL || entry->key != key)
    {
      cout<<"No Element found at key "<<key<<endl;
        return;
    }
    while (entry->next != NULL)
    {
        prev = entry;
        entry = entry->next;
    }
    if (prev != NULL)
    {
        prev->next = entry->next;
    }
    delete entry;
    cout<<"Element Deleted"<<endl;
}

int HashMap::Search(int key){
    bool flag = false;
    int hash_val = HashFunc(key);
    HashNode* entry = htable[hash_val];
    while (entry != NULL)
    {
        if (entry->key == key)
          {
            cout<<entry->value<<" ";
            flag = true;
          }
        entry = entry->next;
    }
    if (!flag)
        return -1;
    else 
      return htable[hash_val]->value;
}

int main(){
  return 0;
}