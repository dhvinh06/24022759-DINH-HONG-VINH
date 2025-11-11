#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std; // Thêm using namespace std

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

class SeparateChainingHashST {
public:
    int M;
    vector<Node*> st;

    int hash(int val) {
        return (hash<int>{}(val)) % M;
    }

    SeparateChainingHashST(int M = 97) : M(M), st(M, nullptr) {}

    SeparateChainingHashST() {
        for (int i = 0; i < M; ++i) {
            Node* x = st[i];
            while (x != nullptr) {
                Node* temp = x->next;
                delete x;
                x = temp;
            }
        }
    }

    bool contains(int val) {
        int i = hash(val);
        for (Node* x = st[i]; x != nullptr; x = x->next) {
            if (val == x->val) {
                return true;
            }
        }
        return false;
    }

    void add(int val) {
        int i = hash(val);

        for (Node* x = st[i]; x != nullptr; x = x->next) {
            if (val == x->val) {
                return;
            }
        }

        Node* newNode = new Node(val);
        newNode->next = st[i];
        st[i] = newNode;
    }

    void remove(int val) {
        int i = hash(val);
        Node* x = st[i];
        Node* prev = nullptr;

        while (x != nullptr) {
            if (val == x->val) {
                if (prev == nullptr) {
                    st[i] = x->next;
                } else {
                    prev->next = x->next;
                }
                delete x;
                return;
            }
            prev = x;
            x = x->next;
        }
    }
};
