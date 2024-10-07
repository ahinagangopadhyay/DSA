#include <iostream>
#include <queue>
#include <vector>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRec(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {
            node->right = insertRec(node->right, key);
        }
        return node;
    }

    Node* deleteRec(Node* node, int key) {
        if (node == nullptr) return node;

        if (key < node->key) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->key) {
            node->right = deleteRec(node->right, key);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteRec(node->right, temp->key);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* searchRec(Node* node, int key) {
        if (node == nullptr || node->key == key) return node;
        if (key < node->key) return searchRec(node->left, key);
        return searchRec(node->right, key);
    }

    void inOrderRec(Node* node) {
        if (node != nullptr) {
            inOrderRec(node->left);
            std::cout << node->key << " ";
            inOrderRec(node->right);
        }
    }

    void preOrderRec(Node* node) {
        if (node != nullptr) {
            std::cout << node->key << " ";
            preOrderRec(node->left);
            preOrderRec(node->right);
        }
    }

    void postOrderRec(Node* node) {
        if (node != nullptr) {
            postOrderRec(node->left);
            postOrderRec(node->right);
            std::cout << node->key << " ";
        }
    }

    void dfsRec(Node* node, std::vector<int>& result) {
        if (node != nullptr) {
            result.push_back(node->key);
            dfsRec(node->left, result);
            dfsRec(node->right, result);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteNode(int key) {
        root = deleteRec(root, key);
    }

    Node* search(int key) {
        return searchRec(root, key);
    }

    void inOrder() {
        std::cout << "In-order Traversal: ";
        inOrderRec(root);
        std::cout << std::endl;
    }

    void preOrder() {
        std::cout << "Pre-order Traversal: ";
        preOrderRec(root);
        std::cout << std::endl;
    }

    void postOrder() {
        std::cout << "Post-order Traversal: ";
        postOrderRec(root);
        std::cout << std::endl;
    }

    std::vector<int> dfs() {
        std::vector<int> result;
        dfsRec(root, result);
        return result;
    }

    std::vector<int> bfs() {
        std::vector<int> result;
        if (root == nullptr) return result;

        std::queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node* current = queue.front();
            queue.pop();
            result.push_back(current->key);

            if (current->left != nullptr) queue.push(current->left);
            if (current->right != nullptr) queue.push(current->right);
        }
        return result;
    }
};

void menu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Delete\n";
    std::cout << "3. Search\n";
    std::cout << "4. In-order Traversal\n";
    std::cout << "5. Pre-order Traversal\n";
    std::cout << "6. Post-order Traversal\n";
    std::cout << "7. DFS Traversal\n";
    std::cout << "8. BFS Traversal\n";
    std::cout << "9. Exit\n";
}

int main() {
    BinarySearchTree bst;
    int choice, value;

    while (true) {
        menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                bst.insert(value);
                break;
            case 2:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                bst.deleteNode(value);
                break;
            case 3:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (bst.search(value)) {
                    std::cout << "Value " << value << " found in the tree.\n";
                } else {
                    std::cout << "Value " << value << " not found in the tree.\n";
                }
                break;
            case 4:
                bst.inOrder();
                break;
            case 5:
                bst.preOrder();
                break;
            case 6:
                bst.postOrder();
                break;
            case 7: {
                std::cout << "DFS Traversal: ";
                std::vector<int> dfsResult = bst.dfs();
                for (int key : dfsResult) {
                    std::cout << key << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 8: {
                std::cout << "BFS Traversal: ";
                std::vector<int> bfsResult = bst.bfs();
                for (int key : bfsResult) {
                    std::cout << key << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 9:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
