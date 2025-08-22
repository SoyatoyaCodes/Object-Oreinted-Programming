#include <iostream>
#include <string>
#include <memory>
using namespace std;

class file_node {
public:
    string file_name;
    int file_size;
    string file_type;
    file_node* left;
    file_node* right;

    file_node(string name, int size, string type)
        : file_name(name), file_size(size), file_type(type), left(nullptr), right(nullptr) {
    }

    // Overload the << operator: print file info
    friend ostream& operator<<(ostream& os, const file_node& node) {
        os << "File Name: " << node.file_name << ", Type: " << node.file_type << ", Size: " << node.file_size << "MB";
        return os;
    }
};

class file_bst {
private:
    file_node* root;

    file_node* insert(file_node* node, string name, int size, string type) {
        if (!node) {
            return new file_node(name, size, type);
        }

        if (name < node->file_name) {
            node->left = insert(node->left, name, size, type);
        }
        else if (name > node->file_name) {
            node->right = insert(node->right, name, size, type);
        }
        else {
            cout << "Error!! Duplicate file name " << name << " not allowed." << endl;
        }

        return node;
    }


    file_node* delete_file(file_node* node, string name) {
        if (!node) return node;

        if (name < node->file_name) {
            node->left = delete_file(node->left, name);
        }
        else if (name > node->file_name) {
            node->right = delete_file(node->right, name);
        }
        else {
            if (!node->left) {
                file_node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                file_node* temp = node->left;
                delete node;
                return temp;
            }

            file_node* temp = minvalnode(node->right);
            node->file_name = temp->file_name;
            node->file_size = temp->file_size;
            node->file_type = temp->file_type;
            node->right = delete_file(node->right, temp->file_name);
        }

        return node;
    }

    file_node* minvalnode(file_node* node) {
        file_node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }
    void inorder(file_node* node) {
        if (node) {
            inorder(node->left);
            cout << *node << endl;
            inorder(node->right);
        }
    }

    void preorder(file_node* node) {
        if (node) {
            cout << *node << endl;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(file_node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << *node << endl;
        }
    }

    void searchfilesbysize(file_node* node, int size) {
        if (node) {
            if (node->file_size > size) {
                cout << *node << endl;
            }
            searchfilesbysize(node->left, size);
            searchfilesbysize(node->right, size);
        }
    }

public:
    file_bst() : root(nullptr) {}
    void insert_file(string name, int size, string type) {
        root = insert(root, name, size, type);
    }

    void delete_file_by_name(string name) {
        if (!root) {
            cout << "error!! Cannot delete from an empty tree." << endl;
            return;
        }
        root = delete_file(root, name);
    }

    void rename_file(string old_name, string new_name) {
        if (!root) {
            cout << "Error!! Cannot rename a empty tree." << endl;
            return;
        }
        root = delete_file(root, old_name);
        cout << "Renaming " << old_name << " to " << new_name << endl;
        insert_file(new_name, 10, "txt");
    }

    void search_files_larger_than(int size) {
        cout << "files larger than " << size << "MB:" << endl;
        searchfilesbysize(root, size);
    }

    void inorder_traversal() {
        inorder(root);
    }

    void preorder_traversal() {
        preorder(root);
    }

    void postorder_traversal() {
        postorder(root);
    }
};

int main() {
    file_bst bst;

    bst.insert_file("file1.txt", 10, "txt");
    bst.insert_file("file2.pdf", 20, "pdf");
    bst.insert_file("file3.exe", 30, "exe");
    cout << "inorder traversal:" << endl;
    bst.inorder_traversal();
    cout << "\npreorder Traversal:" << endl;
    bst.preorder_traversal();
    cout << "\npostorder Traversal:" << endl;
    bst.postorder_traversal();
    cout << "\nsearching for file2.pdf:" << endl;
    bst.search_files_larger_than(15);
    cout << "\nddeleting file2.pdf:" << endl;
    bst.delete_file_by_name("file2.pdf");
    bst.inorder_traversal();
    cout << "\nrenaming file1.txt to renamed_file1.txt:" << endl;
    bst.rename_file("file1.txt", "renamed_file1.txt");
    bst.inorder_traversal();

    return 0;
}
