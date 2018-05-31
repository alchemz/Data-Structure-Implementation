/*
 * C++ Program to Implement Hash Tables Chaining with 
 * Doubly Linked Lists
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
const int TABLE_SIZE = 25;
using namespace std;
/*
 * Node Declaration
 */
struct HashNode
{
    int data, key;
    HashNode *next;
    HashNode *prev;
};
/*
 * Class Declaration
 */
class HashMap
{
    public:
        HashNode **htable, **top;
        HashMap()
        {
            htable = new HashNode*[TABLE_SIZE];
            top = new HashNode*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                htable[i] = NULL;
                top[i] = NULL;
            }
        }
        ~HashMap()
        {
            delete [] htable;
        }
 
        /* 
         * Hash Function 
         */
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
 
        /* 
         * Insert Element at a key 
         */
        void insert(int key, int value)
        {
            int hash_val = HashFunc(key);
            HashNode *entry = htable[hash_val];
            if (entry == NULL)
            {
                entry = new HashNode;
                entry->data = value;
                entry->key = key;
                entry->next = NULL;
                entry->prev = NULL;
                htable[hash_val] = entry;
                top[hash_val] = entry;
            }
            else
            {
                while (entry != NULL)
                    entry = entry->next;
                entry = new HashNode;
                entry->data = value;
                entry->key = key;
                entry->next = NULL;
                entry->prev = top[hash_val];
                top[hash_val]->next = entry;
                top[hash_val] = entry;
            }
        }
 
        /*
         * Remove Element at a key
         */
        void remove(int key)
        {
            int hash_val = HashFunc(key);
            HashNode *entry = htable[hash_val];
            if (entry->key != key || entry == NULL)
            {
                cout<<"No Element found at key: "<<key<<endl;
                return;
            }
            while (entry != NULL)
            {
                if (entry->next == NULL)
                {
                    if (entry->prev == NULL)
                    {
                        htable[hash_val] = NULL;
                        top[hash_val] = NULL;
                        delete entry;
                        break;
                    }
                    else
                    {
                        top[hash_val] = entry->prev;
                        top[hash_val]->next = NULL;
                        delete entry;
                        entry = top[hash_val];
                    }
                }
                entry = entry->next;
            }
        }
        /*
         * Search Element at a key
         */
        void get(int key)
        {
            int hash_val = HashFunc(key);
            bool flag = false;
            HashNode* entry = htable[hash_val];
            if (entry != NULL)
            {
                while (entry != NULL)
                {
                    if (entry->key == key)
                    {
                        flag = true;
                    }
                    if (flag)
                    {
                        cout<<"Element found at key "<<key<<": ";
                        cout<<entry->data<<endl;
                    }
                    entry = entry->next;
                }
            }
            if (!flag)
                cout<<"No Element found at key "<<key<<endl;
        }
};