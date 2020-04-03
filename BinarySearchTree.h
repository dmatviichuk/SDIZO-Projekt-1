#ifndef SDIZO_PROJEKT_1_BINARYSEARCHTREE_H
#define SDIZO_PROJEKT_1_BINARYSEARCHTREE_H
#include <string>

using namespace std;
struct Node
{
    int data;
    Node *up, *left, *right;

};

class BinarySearchTree
{

public:
    BinarySearchTree();
    ~BinarySearchTree();
    int size;
    string cr, cl, cp;
    Node * root;
    Node * getRoot();
    Node * findValue(Node* node,int value);
    Node * predecessor(Node * p);
    Node * successor(Node * p);
    Node * minNode(Node*root);
    Node * maxNode(Node*root);
    Node * deleteValue(int value);
    Node * deleteNode(Node * root);
    Node * turnRight(int value);
    Node * turnLeft(int value);

    void addValue(int value);
    void delAll(Node * root);
    void rotateLeft(Node * A);
    void rotateRight(Node * A);
    void printBST(string sp, string sn,Node * root);

};

#endif //SDIZO_PROJEKT_1_BINARYSEARCHTREE_H
