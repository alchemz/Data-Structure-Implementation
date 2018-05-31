#include <iostream>
using namespace std;

class MyVector {
private:
    const int MIN;
    int capacity;
    int _size;
    int * buffer;
        
public:
    MyVector();
    ~MyVector();
    int operator[](int y) const;
    void push_back(int y);
    void pop_back();
    int size();

private:
    void allocateNewArray();
};

MyVector::MyVector() : MIN(5) {
    capacity = MIN;
    _size = 0;
    buffer = new int[MIN];
}

void MyVector::allocateNewArray() {
    capacity += MIN;
    int * temp = new int [capacity];

    // copy a to tmep
    for(int i = 0; i < _size; i++) temp[i] = buffer[i];

    delete [] buffer;   
    buffer = temp;
}

int MyVector::operator[](int index) const {
        if ( index < _size && index > -1 )
            return buffer[index];
        else 
            std::cout<< "array index must be within bounds ( < size and > 0)!! \n";
        return 0;
}

void MyVector::push_back(int y) {
    if ( _size >= capacity ) allocateNewArray();
    buffer[_size++] = y;
}

void MyVector::pop_back() {
    _size--;
}

int MyVector::size() {
    return _size;
}

MyVector::~MyVector() {
    delete [] buffer;
}

int main() {
    MyVector vec;
    for(int i = 0; i < 105; i++) vec.push_back(i);
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();

    std::cout<< "size: " << vec.size() << "\n";   
    
}