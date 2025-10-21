#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node() {}
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < size&& index>=0) {
            Node* tmp = head;
            int count = 0;
            while (count < index) {
                tmp = tmp->next;
                count++;
            }return tmp->val;
        }else {
            return -1;
        }
    } //O(N)

    void addAtHead(int val) {
        Node* tmp = new Node(val);
        if (head == nullptr) {
            head = tmp;
        }
        else {
            tmp->next = head;
            head = tmp;
        }size++; //O(1)
    }

    void addAtTail(int val) {
        Node* tmp = new Node(val);
        Node* newNode = head;
        if (head == nullptr) {
            head = tmp;
        }
        else {
            while (newNode->next != nullptr) {
                newNode = newNode->next;
            }newNode->next = tmp;
        }size++;   //O(N)
    }

    void addAtIndex(int index, int val) {
        if (index <0|| index >size)
        {
            return;
        }
        if (index == 0) {
            addAtHead(val);
        }else if (index==size){
            addAtTail(val);
        }
        else if (index >0 || index <size) {
            Node* tmp = head;
            Node* result = new Node(val);
            tmp = head;
            int count = 0;
            while (count < index - 1) {
                tmp = tmp->next;
                count++;
            }
            result->next = tmp->next;
            tmp->next = result;
            size++;
        }

    }//O(N)
    void deleteHead (Node* head){
        if (head==nullptr){
            return;
        }
        else{
            head=head->next;
        }
    } //O(1)

    void deleteAtIndex(int index) {
        if (size > 0 && index <size ) {
            if (index == 0) {
                deleteHead (head);
            }
            else {
                Node* tmp = head;
                int count = 0;
                while (count < index - 1) {
                    tmp = tmp->next;
                    count++;
                }
                tmp->next = tmp->next->next;
            }size--;
        }else {
            return;
        }
    }//O(N)

    void duyetxuoi (Node* head){
        while (head){
            cout <<head->val<<" ";
            head=head->next;
        }
    }void duyetnguoc (Node* head){
        vector <Node*> tmp;
        while (head){
            cout <<head->val<<" ";
            tmp.push_back (head);
            head=head->next;
        }for (int i=tmp.size();i>=0;i--){
            cout <<tmp[i]->val<<" ";
        }
    }
};

class StackLinkedList{
public:
    MyLinkedList stacklinkedlist;
    bool isEmpty (){
        if (stacklinkedlist.size <1){
            return false;
        }return true;
    }
    void push (int item){
        stacklinkedlist.addAtHead(item);
    } //O (1)
    int pop (){
        int result = stacklinkedlist.head->val;
        stacklinkedlist.deleteHead(stacklinkedlist.head);
        return result;
    }//O(1)
    int size (){
        return stacklinkedlist.size;
    }
    int top (){
        return stacklinkedlist.head->val;
    }//O (1)

};



int main (){
    return 0;
}
