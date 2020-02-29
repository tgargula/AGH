/*
12. Proszę napisać funkcję, która otrzymując jako parametr wskazujący
na początek listy jednokierunkowej, przenosi na początek listy te z nich,
które mają parzystą ilość piątek w zapisie ósemkowym.
*/

#include <iostream>

using namespace std;

struct node {
    int v;
    node * next;
};

void insertFirst (node *&f, int x) {
    node * r = new node;
    r->v = x;
    r->next = f;
    f = r;
}

void output (node * f) {
    while (f != NULL) {
        cout << f->v << " ";
        f = f->next;
    }
    cout << endl;
}

bool condition (int x) {
    int ctr = 0;
    while (x > 0) {
        if (x % 8 == 5) ctr++;
        x /= 8;
    }
    return ctr %2 == 0;
}

void rearrange (node * prev, node *&head) {
    node * r = prev->next;
    prev->next = prev->next->next;
    r->next = head;
    head = r;
}

void function (node *&head) {
    if (head == NULL) return;
    node * curr = head->next;
    node * prev = head;
    while (curr != NULL) {
        if (condition(curr->v)) {
            curr = curr->next;
            rearrange(prev,head);
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void test() {
    node * f = NULL;
    insertFirst(f,45); insertFirst(f,13); insertFirst(f,4); insertFirst(f,5);
    /*
    5_10 = 5_8 => one five => false
    4_10 = 4_8 => zero fives => true;
    13_10 = 15_8 => one five => false;
    45_10 = 55_8 => two fives => true;
    */ 
    output(f);
    function(f);
    output(f);
}

int main() {
    
    test();

    return 0;
}