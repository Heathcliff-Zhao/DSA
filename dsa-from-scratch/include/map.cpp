#include<iostream>

template<typename Key, typename Value>
class Map {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;
        Node* parent;
        bool isRed;
        Node(const Key& k, const Value& v) : key(k), value(v), left(nullptr), right(nullptr), parent(nullptr), isRed(true) {}
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
        }
        return root;
    }

    Node* findNode(Node* root, const Key& key) const {
        if (!root || root->key == key) {
            return root;
        }
        if (key < root->key) {
            return findNode(root->left, key);
        }
        return findNode(root->right, key);
    }

    void inorderHelper(Node* root) const {
        if (!root) {
            return;
        }
        inorderHelper(root->left);
        std::cout << "(" << root->key << ", " << root->value << ") ";
        inorderHelper(root->right);
    }

public:
    Map() : root(nullptr), size(0) {}

    void insert(const Key& key, const Value& value) {
        Node* newNode = new Node(key, value);
        root = insert(root, newNode);
        fixViolation(newNode);
        ++size;
    }

    bool find(const Key& key, Value& value) const {
        Node* node = findNode(root, key);
        if (node) {
            value = node->value;
            return true;
        }
        return false;
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
    Map<int, std::string> myMap;
    myMap.insert(10, "Ten");
    myMap.insert(20, "Twenty");
    myMap.insert(5, "Five");
    myMap.insert(15, "Fifteen");

    std::cout << "Map contents (inorder traversal): ";
    myMap.inorder();

    std::string value;
    if (myMap.find(10, value)) {
        std::cout << "Found key 10 with value: " << value << std::endl;
    }

    std::cout << "Size of map: " << myMap.getSize() << std::endl;

    return 0;
}