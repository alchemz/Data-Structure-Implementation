#include<bits/stdc++.h>
using namespace std;

class HashEntry {
private:
      int key;
      int value;

public:
      HashEntry(int key, int value) {
            this->key = key;
            this->value = value;
      }

      int getKey() {
            return key;
      }

      int getValue() {
            return value;
      }
};

const int TABLE_SIZE = 128;

class HashMap {
private:
      HashEntry **table;
public:
  HashMap();
  int get(int key);
  void put(int key, int value);
  void display();
  ~HashMap();
};

HashMap::HashMap() {
      table = new HashEntry*[TABLE_SIZE];
      for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
}

int HashMap::get(int key) {
      int hash = (key % TABLE_SIZE);
      while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
  
      if (table[hash] == NULL)
         return -1;
      else
        return table[hash]->getValue();
}

void HashMap::put(int key, int value) {
      int hash = (key % TABLE_SIZE);
      while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
  
      if (table[hash] != NULL)
            delete table[hash];
  
      table[hash] = new HashEntry(key, value);
}     
void HashMap::display(){
  for(int i=0; i< TABLE_SIZE; i++){
    if(table[i] !=NULL && table[i]->getKey() !=-1)
      cout<<"key-> "<< table[i]->getKey()<<" "
      <<"value-> "<<table[i]->getValue()<<endl;
  }
}

HashMap::~HashMap() {
      for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
                  delete table[i];
      delete[] table;
}

int main(){
  HashMap HP;
  HP.put(1, 2);
  HP.put(2,3);
  HP.put(3,4);
  HP.put(4,5);
  HP.put(5,6);
  HP.display();
  return 0;
}
/*
http://www.algolist.net/Data_structures/Hash_table/Simple_example
*/