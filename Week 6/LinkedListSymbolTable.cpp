
struct Node {
    int key;
    int value

    Node* next;
    Node() {}
    Node(int x,int y) {
        key = x;
        value = y
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
            }return tmp->key;
        }else {
            return -1;
        }
    } //O(N)

    void addAtHead(int key,int value) {
        Node* tmp = new Node(key,value);
        if (head == nullptr) {
            head = tmp;
        }
        else {
            tmp->next = head;
            head = tmp;
        }size++; //O(1)
    } //O(1)

    void addAtTail(int key,int value) {
        Node* tmp = new Node(key,value);
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

    void addAtIndex(int index,int key, int value) {
        if (index <0|| index >size)
        {
            return;
        }
        if (index == 0) {
            addAtHead(key,value);
        }else if (index==size){
            addAtTail(key,value);
        }
        else if (index >0 || index <size) {
            Node* tmp = head;
            Node* result = new Node(key,value);
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
        Node *tmp = head;
        while (tmp){
            cout <<tmp->key<<""<<tmp->value<<" ";
            tmp=tmp->next;
        }
    }void duyetnguoc (){
        vector <Node*> tmp;
        Node * tmp1=this->head;
        while (tmp1){
            tmp.push_back (tmp1);
            tmp1=tmp1->next;
        }for (int i=tmp.size()-1;i>=0;i--){
            cout <<tmp->key<<""<<tmp->value<<" ";
        }
    }

};

class SymbolTable{
    MyLinkedList mylnkedlist;
    SymbolTable(){
    mylnkedlist = new MyLinkedList;

}   void insert(int key,int value){
        mylnkedlist.addAtTail(key,value);
}   void search (Node*head,int key){
        Node *tmp = mylnkedlist.head;
        int count = 0;
        while (tmp){
            if (head.key == key){
                mylnkedlist.get(count);
            }else{
                tmp=tmp->next;
                count++;
            }

}



};


