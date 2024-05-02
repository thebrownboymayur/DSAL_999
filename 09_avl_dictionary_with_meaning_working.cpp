#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    string key;
    string value;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(string k, string v) : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
};

class AVLDictionary {
private:
    TreeNode* root;

    int height(TreeNode* node) {
        if (!node) return 0;
        return node->height;
    }

    int balance(TreeNode* node) {
        if (!node) return 0;
        return height(node->left) - height(node->right);
    }

    TreeNode* rotate_right(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    TreeNode* rotate_left(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    TreeNode* insert(TreeNode* node, string key, string value) {
        if (!node) return new TreeNode(key, value);

        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else { // Update value if key already exists
            node->value = value;
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balanceFactor = balance(node);

        if (balanceFactor > 1 && key < node->left->key)
            return rotate_right(node);

        if (balanceFactor < -1 && key > node->right->key)
            return rotate_left(node);

        if (balanceFactor > 1 && key > node->left->key) {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }

        if (balanceFactor < -1 && key < node->right->key) {
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }

        return node;
    }

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " : " << node->value << endl;
        inorder(node->right);
    }

    TreeNode* search(TreeNode* node, string key) {
        if (!node || node->key == key)
            return node;

        if (key < node->key)
            return search(node->left, key);

        return search(node->right, key);
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    TreeNode* deleteNode(TreeNode* root, string key) {
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left || !root->right) {
                TreeNode* temp = root->left ? root->left : root->right;

                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                TreeNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root) return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balanceFactor = balance(root);

        if (balanceFactor > 1 && balance(root->left) >= 0)
            return rotate_right(root);

        if (balanceFactor > 1 && balance(root->left) < 0) {
            root->left = rotate_left(root->left);
            return rotate_right(root);
        }

        if (balanceFactor < -1 && balance(root->right) <= 0)
            return rotate_left(root);

        if (balanceFactor < -1 && balance(root->right) > 0) {
            root->right = rotate_right(root->right);
            return rotate_left(root);
        }

        return root;
    }

public:
    AVLDictionary() : root(nullptr) {}

    void add_keyword(string key, string value) {
        root = insert(root, key, value);
    }

    void delete_keyword(string key) {
        root = deleteNode(root, key);
    }

    void display_sorted() {
        inorder(root);
    }

    void insert_word() {
        string key, value;
        cout << "Enter the word: ";
        cin >> key;
        cout << "Enter the meaning: ";
        cin.ignore();
        getline(cin, value);
        add_keyword(key, value);
    }
};

int main() {
    AVLDictionary avl_dict;

    char choice;
    do {
        cout << "Menu:\n";
        cout << "1. Insert a word\n";
        cout << "2. Display dictionary\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                avl_dict.insert_word();
                break;
            case '2':
                cout << "Displaying sorted dictionary:" << endl;
                avl_dict.display_sorted();
                break;
            case '3':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '3');

    return 0;
}
