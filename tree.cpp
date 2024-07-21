#include <iostream>

using namespace std;

struct tree_node{
    int data;
    tree_node* left_child;
    tree_node* right_child;
    tree_node(int val) : data(val), left_child(nullptr), right_child(nullptr) {}
};

class binary_tree{
public:
    tree_node* root;
    binary_tree(): root(nullptr){}

    void insert(int val){
        root = insert_node(root, val);
    }


private:
    tree_node* insert_node(tree_node* node, int val){
        if(node == nullptr){
            return new tree_node(val);
        }
        if(val<node->data){
            node->left_child = insert_node(node->left_child, val);
        } else{
            node->right_child = insert_node(node->right_child, val);
        }
        return node;
    }
};