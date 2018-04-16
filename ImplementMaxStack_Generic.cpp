#include<bits/stdc++.h>
using namespace std;

template <class T>
class MaxStack {
public:
    MaxStack() {}
    void push(T x);
    T pop();
    T top();
    T peekMax();
    T popMax();

private:
    stack<T> s1, s2;
};
template <class T>
void MaxStack<T>::push(T x){
        if (s2.empty() || s2.top() <= x) s2.push(x);
        s1.push(x);
}
template <class T>    
T MaxStack<T>::pop() {
        if (!s2.empty() && s2.top() == s1.top()) s2.pop();
        int t = s1.top(); s1.pop();
        return t;
}
template <class T>    
T MaxStack<T>::top() {
        return s1.top();
}
template <class T>    
T MaxStack<T>::peekMax() {
        return s2.top();
}
template <class T>    
T MaxStack<T>::popMax() {
        int mx = s2.top();
        stack<int> t;
        while (s1.top() != s2.top()) {
            t.push(s1.top()); s1.pop();
        }
        s1.pop(); s2.pop();
        while (!t.empty()) {
            push(t.top()); t.pop();
        }
        return mx;
}

int main(){
  MaxStack<int> ms;
  ms.push(2);
  ms.push(0);
  ms.push(3);
  ms.push(0);
  
  cout<<ms.popMax();
  return 0;
}