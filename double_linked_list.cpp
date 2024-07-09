#include <iostream>

using namespace std;

struct Node{
    Node* nxt;
    int data;
    Node(int val) : nxt(nullptr), data(val){}  
};

class SingleLinkedList{
private:
    Node* head;
public: 
    SingleLinkedList() : head(nullptr){}
    void insert(int val){
        Node* new_node = new Node(val);
        if(!head){
            head = new_node;
            return;
        }
        Node* last_node = head;
        while(last_node->nxt){
            last_node = last_node->nxt;
        }
        last_node->nxt = new_node;
    }
    void print(){
        Node* cur_node = head;
        while(cur_node){
            cout<<cur_node->data;
            if(cur_node->nxt){
                cout<<"->";
            }
            cur_node = cur_node->nxt;
        }
        cout<<'\n';
    }
};

struct DoubleNode {
    DoubleNode* nxt;
    DoubleNode* prev;
    int data;
    DoubleNode(int val) : nxt(nullptr), prev(nullptr),data(val){}  
};

class DoubleLinkedList{
private:
    DoubleNode* head;
    DoubleNode* tail;
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr){}

    void insert(int val){
        DoubleNode* new_node =new DoubleNode(val);
        if(!head){
            head = new_node;
            tail = new_node;
            return;
        }
        DoubleNode* last_node = tail;
        tail->nxt = new_node;
        tail = new_node;
        tail->prev = last_node;
        
    }



    void print(){
        DoubleNode* cur_node = head;
        while(cur_node){
            cout<<cur_node->data;
            if(cur_node->nxt){
                cout<<" <-> ";
            }
            cur_node = cur_node->nxt;
        }
        cout<<'\n';
    }

 
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    DoubleLinkedList singlelinkedlist;
    singlelinkedlist.insert(10);
    singlelinkedlist.insert(20);
    singlelinkedlist.insert(30);

    singlelinkedlist.print();

}
