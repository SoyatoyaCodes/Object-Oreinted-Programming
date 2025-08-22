#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;

class node {
private:
    int data;
    node* left;
    node* right;
public:
    node(int d) : data(d), left(nullptr), right(nullptr) {}

    //a pointer to a node obj is passed. so the left ptr points to it
    void setleft(node* l) {
        left = l;
    }

    void setright(node* r) {
        right = r;
    }

    int getdata() {
        return data;
    }

    node* getleft() {
        return left;
    }

    node* getright() {
        return right;
    }

};

class tree {
private:
    //vector to store all nodes
    vector<node*> treestore;
    node* root;
public:
    tree() : root(nullptr) {
        //  t.resize(n);
    }

    int gettreesize() {
        return treestore.size();
    }

    void addnode(int val) {
        node* newnode = new node(val);
        treestore.push_back(newnode);
    }

    void addchild(int index, int index2, bool which) {
        if (!which) { //if bool is 0, create left child.
            treestore[index]->setleft(treestore[index2]);
        }
        else { //otherwise right
            treestore[index]->setright(treestore[index2]);
        }
    }

    void setroot(int index) {
        root = treestore[index];
    }
    node* getroot() {
        return root;
    }

    ~tree() {
        for (node* it : treestore) {
            delete it;
        }
    }
    //[2,3,4,5,6]
        //inorder: left, root and then right
    void recursion_display(node* current, int space) {
        //start current off by pointing at root 
        string s(space, ' ');
        if (current == nullptr) {
            return;//you return back to your root node.
        }
        recursion_display(current->getleft(), space + 4);
        cout << s << current->getdata() << endl;
        recursion_display(current->getright(), space + 4);
    }

    void prettyprinting(tuple<node*, int, int>& t) {
        static int prevlen;
        string s(get<2>(t), ' ');
        cout << s << get<0>(t)->getdata();
        if (prevlen != get<1>(t)) {
            cout << endl;
        }
        prevlen = get<1>(t);
        return;
    }


    void BFSprinting(node* root, int level, int pos, int height) {
        int gap = pow(2, height);

        queue<tuple <node*, int, int>> q;
        //make_tuple(node-pointer, level of tree, postion)
        //get<i>(tuple name) : accesses the ith element in the tuple.

        q.push(make_tuple(root, level, pos));

        int curr_lvl = 0; //to track when to change gap


        while (!q.empty()) {

            auto t = q.front(); //capture the front tuple
            prettyprinting(t);
            q.pop();
            //yet to understand this part 
            node* current = get<0>(t);
            int node_lvl = get<1>(t);
            int node_pos = get<2>(t);

            if (current->getleft() != nullptr) {
                q.push(make_tuple(current->getleft(), node_lvl + 1, node_pos - gap));
            }
            if (current->getright() != nullptr) {
                q.push(make_tuple(current->getright(), node_lvl + 1, node_pos + gap));
            }
            //where are we updating the current lvl? are we?

            if (curr_lvl != node_lvl) {
                gap = gap / 2;//change gap only if level changes
                curr_lvl = node_lvl;
            }
        }
    }

    //COMPUTING TREE HEIGHT
    int getheight(node* current) {
        if (current == nullptr) {
            return 0;
        }
        return 1 + max(getheight(current->getleft()), getheight(current->getright()));
    }

};


int main() {
    cout << "note: a sideways i.e 90 degree rotated tree is displayed. Also, its flipped in z axis as well(mirror)" << endl;
    //deeper nodes appear further to the right.
    tree t;
    t.addnode(2);
    t.addnode(3);
    t.addnode(4);
    t.addnode(5);
    t.addnode(6);
    t.addchild(0, 1, 0);
    t.addchild(0, 2, 1);
    t.addchild(1, 3, 0);
    t.addchild(1, 4, 1);
    t.setroot(0);
    t.recursion_display(t.getroot(), 0);


    int mid = t.gettreesize() / 2;
    int height = t.getheight(t.getroot());
    t.BFSprinting(t.getroot(), 0, mid, height);
    //how do i calculate height?
    cout << endl;
    return 0;

    /*
             5
          3 /
        /   \
(root) 2      6
        \
         4
    */
}
