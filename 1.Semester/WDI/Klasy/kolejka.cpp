#include <iostream>

class Queue {
private:
    int v;
    Queue * next;
public:
    void init() {
        Queue * queue = new Queue;
    }
    void put(Queue *&queue, int value) {
        Queue * newElem = new Queue;
        newElem->v = value;
        newElem->next = NULL;
        
        if ( empty(queue) ) {
            queue = newElem;
            return;
        }
        Queue * curr = queue;
        Queue * prev = NULL;
        while(curr != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newElem;
    }
    void get(Queue *&queue) {
        if ( empty(queue) ) return;
        Queue * temp = queue;
        queue = queue->next;
        std::cout << temp->v << std::endl;
        delete temp;
    }
    bool empty(Queue * queue) {
        return queue == NULL ? true : false;
    }
};

int main() {
    using std::cout;
    using std::endl;

    Queue * xD = NULL;
    xD->put(xD,1);
    xD->put(xD,2);
    xD->get(xD);
    xD->put(xD,3);
    xD->get(xD);
    if(xD->empty(xD)) cout << "EMPTY" << endl;
    else cout << "NOT EMPTY" << endl;
    xD->get(xD);
    if(xD->empty(xD)) cout << "EMPTY" << endl;
    else cout << "NOT EMPTY" << endl;

    return 0;
}

