#include<bits/stdc++.h>
using namespace std;
struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
};

struct comp{
  bool operator()(ListNode *p, ListNode *q){
    return p->val>q->val;
  }
};

ListNode* mergeKLists(vector<ListNode*>& lists){
  priority_queue<ListNode*, vector<ListNode*>, comp>pq;
  ListNode *dummy = new ListNode(0);
  ListNode *cur = dummy;
  
  for(unsigned i=0; i<lists.size(); i++)
    if(lists[i]) pq.push(lists[i]); //store everything in pq
  
  while(!pq.empty()){
    cur->next=pq.top();
    cur=cur->next;
    pq.pop();
    if(cur->next) pq.push(cur->next);
  }
  
  return dummy->next;
}

ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}


int main(){
  int a[]={1,2,5};
  int b[]={2,3,6};
  int c[]={4,5,7};
  ListNode *l1=createList(a, sizeof(a)/sizeof(a[0]));
  ListNode *l2=createList(b, sizeof(b)/sizeof(b[0]));
  ListNode *l3=createList(c, sizeof(c)/sizeof(c[0]));
  vector<ListNode*> lists;
  lists.push_back(l1);
  lists.push_back(l2);
  lists.push_back(l3);
  
  ListNode *dummy=mergeKLists(lists);
  while(dummy != nullptr){
    cout<<dummy->val<<" ";
    dummy=dummy->next;
  }
  return 0;
}