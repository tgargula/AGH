#include <iostream>

using namespace std;

struct node {
    int v;
    node *next;
};

node *reverseList (node *head) {
    if(head == NULL or head->next == NULL) return head;
    
    node *prev = head;
    node *curr = head->next;
    node *foll = head->next;

    prev->next = NULL;

    while(curr != NULL) {
        foll = foll->next;
        curr->next = prev;
        prev = curr;
        curr = foll;
    }

    return prev;
}

void output (node *f) {
    if(f->v == 0) f = f->next;
    while(f != NULL) {
        cout << f->v;
        f = f->next;
    }
    cout << " ";
}

void insertLast (node *&f, int x) {
    node *r = new node;
    r->v = x;
    r->next = NULL;

    if( f == NULL ) { f = r; return; }

    node *prev = f;
    node *curr = f;
    while(curr != NULL ) {
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = r;
}

node *sum (node *f, node *s) {
    if (f == NULL) return s;
    if (s == NULL) return f;

    node *rf = reverseList(f);
    node *rs = reverseList(s);

    node *RSUM = new node;
    node *rsum = RSUM;
    node *prev_rsum = NULL;

    int p = 0;
    while(rf != NULL and rs != NULL) {
        rsum->v = rf->v + rs->v + p;
        p = (rsum->v / 10);
        rsum->v %= 10;

        prev_rsum = rsum;
        rsum->next = new node;  // I don't know why but it did not work without it
        rsum = rsum->next;
        rf = rf->next;
        rs = rs->next;
    }
    
    if(rf == NULL and rs == NULL) {
        if(p == 0) {
            prev_rsum->next = NULL;
        }
        else {
            rsum->v = 1;
        }
    }

    else if(rf == NULL) {
        while(rs != NULL) {
            rsum->v = rs->v + p;
            p = 0;

            rsum->next = new node;
            rsum = rsum->next;
            rs = rs->next;
        }
    }

    else if(rs == NULL) {
        while(rf != NULL) {
            rsum->v = rf->v + p;
            p = 0;
            
            rsum->next = new node;
            rsum = rsum->next;
            rf = rf->next;
        }
    }
    
    return reverseList(RSUM);
}

int main() {
    node *f = NULL;
    node *s = NULL;

    insertLast(f,9); insertLast(f,4); insertLast(f,1);

    insertLast(s,9); insertLast(s,9); insertLast(s,5);

    output(f); cout << "+ "; output(s); cout << "= "; output(sum(f,s));

    return 0;
}