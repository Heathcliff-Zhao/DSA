#include<iostream>

template<typename T>
class Set {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;
        bool isRed;
        Node(const T& value) : data(value), left(nullptr), right(nullptr), parent(nullptr), isRed(true) {}
    };

    Node* root;
    size_t size;

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (!x->parent) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (!y->parent) {
            root = x;
        }
        else if (y == y->parent->right) {
            y->parent->right = x;
        }
        else {
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }

    void fixViolation(Node* z) {
        while (z->parent && z->parent->isRed) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y && y->isRed) {
                    z->parent->isRed = false;
                    y->isRed = false;
                    z->parent->parent->isRed = true;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->isRed = false;
                    z->parent->parent->isRed = true;
                    rightRotate(z->parent->parent);
                }
            }
            else{
                Node* y = z->parent->parent->left;
                if (y && y->isRed) {
                    z->parent->isRed = false;
                    y->isRed = false;
                    z->parent->parent->isRed = true;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->isRed = false;
                    z->parent->parent->isRed = true;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->isRed = false;
    }

    Node* insert(Node* root, Node* node) {
        if (!root) {
            return node;
        }
        if (node->data < root->data) {
            root->left = insert(root->left, node);
            root->left->parent = root;
        }
        else if (node->data > root->data) {
            root->right = insert(root->right, node);
            root->right->parent = root;
        }
        return root;
    }

    void inorderHelper(Node* root) const {
        if (!root) {
            return;
        }
        inorderHelper(root->left);
        std::cout << root->data << " ";
        inorderHelper(root->right);
    }

public:
    Set() : root(nullptr), size(0) {}

    void insert(const T& data) {
        Node* newNode = new Node(data);
        root = insert(root, newNode);
        fixViolation(newNode);
        ++size;
    }

    void inorder() const {
        inorderHelper(root);
        std::cout << std::endl;
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    Set<int> mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(5);
    mySet.insert(15);

    std::cout << "Set contents (inorder traversal): ";
    mySet.inorder();

    std::cout << "Size of set: " << mySet.getSize() << std::endl;

    return 0;
}