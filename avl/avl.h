#ifndef _AVL_H_
#define _AVL_H_

struct Node {
    int key;
    int value;
    int height;
    Node* parent;
    Node* lchild;
    Node* rchild;
};

class AVL {
public:
    AVL();
    ~AVL();

    int get(int key) {
        Node* node = get(this->root, key);
        if (node == nullptr) {
            return -1;
        }
        return node->value;
    }  


private:
    void detachFromParent() {
        if (this->root == nullptr || this->root->parent == nullptr) {
            return;
        }
        if (this->root->parent->lchild == this->root) {
            this->root->parent->lchild = nullptr;
        } else {
            this->root->parent->rchild = nullptr;
        }
    }

    Node* maxNode() {
        for (Node* p = this->root; p != nullptr; p = p->rchild) {
            if (p->rchild == nullptr) {
                return p;
            }
        }

        return nullptr;
    }

    int getHeight() {
        if (this->root == nullptr) {
            return 0;
        }
        return this->root->height;
    }

    // 将this->root的父节点指向target
    void shareParent(Node* target) {
        Node* parent = this->root->parent;
        if (target != nullptr) {
            target->parent = parent;
        }
        if (this->root == nullptr) {
            return;  
        }

        if (this->root->lchild  ==  this->root) {
            parent->lchild = target;
        } else {
            parent->rchild = target;
        }
    }

     Node* get(Node* node, int key) {
        for (Node* p = this->root; p != nullptr; ) {
            if (p->key == key) {
                return p;
            } else if (p->key > key) {
                p = p->lchild;
            } else {
                p = p->rchild;
            }
        }
        return nullptr;
     }


public:
    Node* root;
};

AVL::AVL() {
    root = nullptr;
}



#endif