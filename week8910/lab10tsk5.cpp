// Task 5: 
// Implement a generic class BinaryTree that models a simple binary tree. The class should include the following functionalities: 
// insert: A method to insert a node with a given value into the tree, ensuring that the binary tree properties are maintained. 
// The new node should be inserted in the correct position based on the binary search tree (BST) rule, where all nodes in 
// the left subtree have values less than the root, and all nodes in the right subtree have values greater than the root. 
// in_order_traversal: A method that performs an in-order traversal of the tree and returns an array of node values. In an 
// in-order traversal, the tree is recursively traversed as follows: first, the left subtree is visited, then the current node, and 
// finally, the right subtree. This ensures that nodes are visited in ascending order in a binary search tree. The method 
// should return an array containing these values. 
//  clear: A method to clear the tree, deleting all nodes and freeing up memory. This method ensure that all dynamically 
// allocated memory is properly released to avoid memory leaks. 
//  operator(): A method that takes in a vector of values and inserts each value into the binary tree using the insert method. 
// Then does an in-order traversal adding the values to the vector. This gives a sorted array of the values in the vector.
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    bool isroot;
    node(int d) : data(d), isroot(0), left(nullptr), right(nullptr) {}
};

class binarytree {
private:
    vector<node*> tree;
    node* root;
public:

    void insertnodes(vector<int>& v) {
        //inserting values in the tree
        for (int i = 0; i < v.size(); i++) {
            node* newnode = new node(v[i]);
            //tree[i] = (newnode);//this is wrong cause tree is empty. pushback instead
            tree.push_back(newnode);
        }
    }

    void setroot(int treeindex) {
        root = tree[treeindex];
    }
    //put index =0; and node = root
    node* buildtree(node* current, node* value) {
        if (current == nullptr) {
            return value;
        }

        if (current->data < value->data) {
            current->right = buildtree(current->right, value);

        }

        else {
            current->left = buildtree(current->left, value);
        }

        return current;
    }

    void insert() {
        for (int i = 0; i < tree.size(); i++) {
            if (tree[i] == root) continue;
            // buildtree(root, tree[i]); this is fine but what if root is nullptr? look the basecase fixes it makes tree[0] as root if none exists at first 
            root = buildtree(root, tree[i]);

        }
    }

    vector<int> inorder(node* current) {

        if (current == nullptr) {

        }
    }

    void clear() {

    }

    ~binarytree() {

    }


};

int main() {
    vector<int> values{ 3,5,6,2,2,6,3,2,5,6,3,2 }; //pass this to the binarytree func and it will generate a tree for me ie return a sorted vector



}















// class binarytree {
// private:
//     vector<node*> tree; //this will store all of our nodes
//     node* root;
// public:

//     void setroot(int index) {
//         if (tree.empty()) {
//             cout << "populate tree first to make a node into root" << endl;
//             return;
//         }
//         if (index < tree.size() and index >= 0) {
//             root = tree[index];
//             tree[index]->isroot = true;
//         }
//         else {
//             cout << "bro enter correct index of node to make root!" << endl;
//         }
//     }

//     //insert a node
//     void insertnode(int val) {
//         node* newnode = new node(val);
//         tree.push_back(newnode);
//     }

//     void createconnections(int node_index, int lp, int rp) { //leftpointer :lp
//         if (node_index < 0 or node_index >= tree.size()) {
//             cout << "invalid node provided\n";
//             return;
//         }


//         if (lp >= 0 and lp < tree.size() and rp >= 0 and rp < tree.size()) {

//             if (tree[node_index]->data < tree[rp]->data) {
//                 tree[node_index]->right = tree[rp];
//             }
//             else {
//                 cout << "right node association could not be made because value is smaller than root" << endl;
//             }

//             if (tree[node_index]->data > tree[lp]->data) {
//                 tree[node_index]->left = tree[lp];
//             }
//             else {
//                 cout << " left side could not be assigned. it invalidates binary tree property\n";
//             }


//         }
//         else {
//             cout << "invalid indexes were provided!\n";
//             return;
//         }
//     }

//     ~binarytree() {
//         for (node* it : tree) {
//             delete it;
//         }
//     }



// };


