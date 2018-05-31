#include<bits/stdc++.h>
using namespace std;
template<class T>
struct Node{
  Node<T>* next;
  T data;
};

template<class T>
class LinkedList{
private:
  Node<T>* head;
  Node<T>* tail;
  
public:
  LinkedList();
  ~LinkedList();
  void addNode(T value);
  void display();
};

template<class T>
LinkedList<T>::LinkedList(){
  head=tail=NULL;
}

template<class T>
LinkedList<T>::~LinkedList(){
  Node<T> *curr=head;
  while(head){
    head=head->next;
    delete curr;
    curr=head;
  }
}

template<class T>
void LinkedList<T>::addNode(T value){
  Node<T> *tmp= new Node<T>;
  tmp->data=value;
  tmp->next=NULL;
  
  if(head==NULL){
    head=tmp;
    tail=tmp;
  }else{
    tail->next=tmp;
    tail=tail->next;
  }
}

template<class T>
void LinkedList<T>::display(){
  Node<T> *tmp = new Node<T>;
  tmp=head;
  while(tmp!=NULL){
    cout<<tmp->data<<"\t";
    tmp=tmp->next;
  }
}

int main(){
  //test cases
  LinkedList<int> s;
  s.addNode(1);
  s.addNode(2);
  s.display();
  
  return 0;
}