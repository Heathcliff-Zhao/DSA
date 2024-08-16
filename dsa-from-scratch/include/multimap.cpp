#include <iostream>
#include <vector>
#include <utility>

template<typename Key, typename Value>
class MultiMap {
private:
    struct Node {
        Key key;
        std::vector<Value> values;
        Node* left;
        Node* right;
        Node* parent;
        bool isRed;
        Node(const Key& k, const Value& v) : key(k), left(nullptr), right(nullptr), parent(nullptr), isRed(true) {
            values.push_back(v);
        }
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
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
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
        } else if (y == y->parent->right) {
            y->parent->right = x;
        } else {
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
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->isRed = false;
                    z->parent->parent->isRed = true;
                    rightRotate(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;
                if (y && y->isRed) {
                    z->parent->isRed = false;
                    y->isRed = false;
                    z->parent->parent->isRed = true;
                    z = z->parent->parent;
                } else {
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
        if (node->key < root->key) {
            root->left = insert(root->left, node);
            root->left->parent = root;
        } else if (node->key > root->key) {
            root->right = insert(root->right, node);
            root->right->parent = root;
        } else {
            root->values.push_back(node->values[0]);
        }
        return root;
    }

    void inorderHelper(Node* root) const {
        if (!root) {
            return;
        }
        inorderHelper(root->left);
        for (const auto& value : root->values) {
            std::cout << "(" << root->key << ", " << value << ") ";
        }
        inorderHelper(root->right);
    }

public:
    MultiMap() : root(nullptr), size(0) {}

    void insert(const Key& key, const Value& value) {
        Node* newNode = new Node(key, value);
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
    MultiMap<int, std::string> myMultiMap;
    myMultiMap.insert(10, "Ten");
    myMultiMap.insert(20, "Twenty");
    myMultiMap.insert(10, "Another Ten");
    myMultiMap.insert(5, "Five");

    std::cout << "MultiMap contents (inorder traversal): ";
    myMultiMap.inorder();

    std::cout << "Size of multimap: " << myMultiMap.getSize() << std::endl;

    return 0;
}
