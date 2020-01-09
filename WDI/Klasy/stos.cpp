#include <iostream>

class Stack {
private:
    int v;
    Stack * next;
public:
    void init() {
        Stack * stack = new Stack;
    }
    void push(Stack *&stack, int value) {
        Stack * newElem = new Stack;
        newElem->v = value;
        newElem->next = stack;
        stack = newElem;
    }
    void pop(Stack *&stack) {
        if ( empty(stack) ) return;
        Stack * temp = stack;
        stack = stack->next;
        std::cout << temp->v << std::endl;
        delete temp;
    }
    bool empty(Stack * stack) {
        return stack == NULL ? true : false;
    }
};

int main() {
    using std::cout;
    using std::endl;

    Stack * xD = NULL;
    xD->push(xD,1);
    xD->push(xD,2);
    xD->pop(xD);
    xD->push(xD,3);
    xD->pop(xD);
    if(xD->empty(xD)) cout << "EMPTY" << endl;
    else cout << "NOT EMPTY" << endl;
    xD->pop(xD);
    if(xD->empty(xD)) cout << "EMPTY" << endl;
    else cout << "NOT EMPTY" << endl;

    return 0;
}

