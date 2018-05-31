/*
 * C++ Program to Implement Hash Tables with Linear Probing
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int TABLE_SIZE = 5;
 
/*
 * HashNode Class Declaration
 */
class HashNode
{
public:
    int key;
    int value;
    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};
 
/*
 * DeletedNode Class Declaration
 */
class DeletedNode:public HashNode
{
private:
    static DeletedNode *entry;
    DeletedNode():HashNode(-1, -1)
    {}
public:
    static DeletedNode *getNode()
    {
        if (entry == NULL)
            entry = new DeletedNode();
        return entry;
    }
};
DeletedNode *DeletedNode::entry = NULL;
/*
 * HashMap Class Declaration
 */
class HashMap
{
private:
    HashNode **htable;
public:
    HashMap()
    {
        htable = new HashNode* [TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            htable[i] = NULL;
        }
    }
 
    ~HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (htable[i] != NULL && htable[i] != DeletedNode::getNode())
                delete htable[i];
        }
        delete[] htable;
    }

    int HashFunc(int key)
    {
        return key % TABLE_SIZE;
    }
 
    void Insert(int key, int value)
    {
        int hash_val = HashFunc(key);
        int init = -1;
        int deletedindex = -1;
        while (hash_val != init && (htable[hash_val]
                        == DeletedNode::getNode() || htable[hash_val]
                        != NULL && htable[hash_val]->key != key))
        {
            if (init == -1)
                init = hash_val;
            if (htable[hash_val] == DeletedNode::getNode())
                deletedindex = hash_val;
            hash_val = HashFunc(hash_val + 1);
        }
        if (htable[hash_val] == NULL || hash_val == init)
        {
            if(deletedindex != -1)
                htable[deletedindex] = new HashNode(key, value);
            else
                htable[hash_val] = new HashNode(key, value);
        }
        if(init != hash_val)
        {
            if (htable[hash_val] != DeletedNode::getNode())
            {
                if (htable[hash_val] != NULL)
                {
                    if (htable[hash_val]->key == key)
                        htable[hash_val]->value = value;
                }
            }
            else
                htable[hash_val] = new HashNode(key, value);
        }
    }

    int Search(int key)
    {
        int hash_val = HashFunc(key);
        int init = -1;
        while (hash_val != init && (htable[hash_val]
                        == DeletedNode::getNode() || htable[hash_val]
                        != NULL && htable[hash_val]->key != key))
        {
            if (init == -1)
                init = hash_val;
            hash_val = HashFunc(hash_val + 1);
        }
        if (htable[hash_val] == NULL || hash_val == init)
            return -1;
        else
            return htable[hash_val]->value;
    }
       
    void Remove(int key)
    {
        int hash_val = HashFunc(key);
        int init = -1;
        while (hash_val != init && (htable[hash_val]
                        == DeletedNode::getNode() || htable[hash_val]
                        != NULL && htable[hash_val]->key != key))
        {
            if (init == -1)
                init = hash_val;
            hash_val = HashFunc(hash_val + 1);
        }
        if (hash_val != init && htable[hash_val] != NULL)
        {
            delete htable[hash_val];
            htable[hash_val] = DeletedNode::getNode();
        }
    }
};
 
/*
 * Main Contains Menu
 */
int main()
{
    HashMap hash;
    int key, value;
    return 0;
}