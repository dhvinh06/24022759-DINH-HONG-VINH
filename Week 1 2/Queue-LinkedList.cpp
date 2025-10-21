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
    Node* tail;
    int size;
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
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
            this->head = tmp;
            this->tail = tmp;
        }
        else {
            tmp->next = head;
            this->head = tmp;
        }size++; //O(1)
    }

    void addAtTail(int val) {
        Node* tmp = new Node(val);
        Node* newNode = tail;
        if (head == nullptr) {
            this->head = tmp;
            this->tail = tmp;
        }
        else {
            this->tail ->next =tmp;
            this->tail= tail->next;
        }size++;   //O(1)
    }

    void addAtIndex(int index, int val) {
        if (index <0|| index >size){
            return;
        }
        if (index == 0) {
            addAtHead(val);
        }
        else if (index==size){
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
    void deleteHead (){
        if (head==nullptr){
            return;
        }
        else{
            this->head=head->next;
            size--;
        }
    } //O(1)
    void deleteTail (){
        if (head==nullptr){
            return;
        }
        else{
            if (size ==1){
                deleteHead();
                size--;
            }else{
                Node* tmp = head;
                while (tmp->next !=tail){
                    tmp=tmp->next;
                }this->tail = tmp;
                this->tail->next= nullptr;
                size--;
            }
        }
    } //O(N)

    void deleteAtIndex(int index) {
        if (size > 0 && index <size ) {
            if (index == 0) {
                deleteHead ();
            }else if (index ==size-1){
                deleteTail();
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
        Node *tmp = head;
        while (tmp){
            cout <<tmp->val<<" ";
            tmp=tmp->next;
        }
    }void duyetnguoc (){
        vector <Node*> tmp;
        Node * tmp1=this->head;
        while (tmp1){
            tmp.push_back (tmp1);
            tmp1=tmp1->next;
        }for (int i=tmp.size()-1;i>=0;i--){
            cout <<tmp[i]->val<<" ";
        }
    }
};

class QueueLinkedList{
public:
    MyLinkedList queuelinkedlist;
    QueueLinkedList (){};
    bool isEmpty(){
        if (queuelinkedlist.size <1){
            return true;
        }return false;
    }
    void enqueue (int item){
        queuelinkedlist.addAtTail(item);
    }
    int dequeue(){
        int result = queuelinkedlist.head->val ;
        queuelinkedlist.deleteHead();
        return result;
    }
    int peek (){
        return queuelinkedlist.head->val;
    }
    int size (){
        return queuelinkedlist.size;
    }
};




int main (){
    return 0;
}
