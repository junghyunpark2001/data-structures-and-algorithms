#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class Stack{
private:
    vector<T> stack;
public:
    void push(const T& value){
        stack.push_back(value);
    }
    void pop(){
        if(isEmpty()){
            throw runtime_error("Stack underflow: Attempt to pop from an empty stack.");
        }
        stack.pop_back();
    }

    T top() const{
        if (isEmpty()) {
            throw runtime_error("Stack underflow: Attempt to access top of an empty stack.");
        }
        return stack.back();   
    }

    bool isEmpty() const{
        return stack.empty();
    }

    size_t size() const{
        return stack.size();
    }
};

int main() {
    Stack<int> s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.top() << endl; // Output: 30
    cout << "Stack size: " << s.size() << endl; // Output: 3
    
    s.pop();
    
    cout << "Top element after pop: " << s.top() << endl; // Output: 20
    cout << "Stack size after pop: " << s.size() << endl; // Output: 2

    while (!s.isEmpty()) {
        cout << "Popping: " << s.top() << endl;
        s.pop();
    }


    return 0;
}