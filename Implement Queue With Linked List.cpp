#include<iostream>
using namespace std;
 
struct Node{
    int data;
    Node *next;
};

template<class T>
class Queue{
    public:
    Node *front,*rear;
    Queue(){front=rear=NULL;}
 
    void push(T n);
    void pop();
    void display();
    ~Queue();
};

template<class T> 
void Queue<T>::push(T n){
    Node *temp=new Node;
    if(temp==NULL){
        cout<<"Overflow"<<endl;
        return;
    }
    temp->data=n;
    temp->next=NULL;
 
    //for first node
    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    cout<<n<<" has been pushed successfully."<<endl;
}

template<class T>
void Queue<T>::pop()
    {
    if (front==NULL){
        cout<<"underflow"<<endl;
        return;
    }
     
    cout<<front->data<<" is being popped "<<endl;
    if(front==rear)//if only one node is there
        front=rear=NULL;
    else
        front=front->next;
}

template<class T>
void Queue<T>::display(){
    if(front==NULL){
        cout<<"Underflow."<<endl;
        return;
    }
    Node *temp=front;
    //will check until NULL is not found
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

template<class T>
Queue<T>::~Queue()
{
    while(front!=NULL)
    {
        Node *temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
}
 
 
int main(){
    Queue<int> Q;
    Q.display();
 
    Q.push(10);
    Q.push(24);
    Q.push(28);
    Q.push(32);
    Q.push(30);
     
    Q.display();
     
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    
    Q.display();
    return 0;
}
