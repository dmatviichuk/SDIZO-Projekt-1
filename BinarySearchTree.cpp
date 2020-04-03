#include "BinarySearchTree.h"
#include <iostream>


Node * BinarySearchTree::getRoot()
{
    return root;
}
//Konstruktor
BinarySearchTree::BinarySearchTree(){

    BinarySearchTree::root = NULL;
    BinarySearchTree::size = 0;
}
//Destruktor
BinarySearchTree::~BinarySearchTree()
{

    delAll(root);
}
void BinarySearchTree::delAll(Node* node)
{
    if (node)
    {
        delAll(node->left);
        delAll(node->right);
        delete node;
    }
}


Node * BinarySearchTree::findValue(Node * p, int k)
{
    while (p && p->data != k)
        p = (k < p->data) ? p->left : p->right;

    return p;
}



Node * BinarySearchTree::predecessor(Node * node)
{
    Node * r;

    if (node)
    {
        if (node->left) return maxNode(node->left);
        else
        {
            r = node->up;
            while (r && (node == r->left))
            {
                node = r;
                r = r->up;
            }
            return r;
        }
    }
    return node;
}

Node * BinarySearchTree::successor(Node * node)
{
    Node * r;

    if (node)
    {
        if (node->right) return minNode(node->right);
        else
        {
            r = node->up;
            while (r && (node == r->right))
            {
                node = r;
                r = r->up;
            }
            return r;
        }
    }
    return node;
}

Node * BinarySearchTree::minNode(Node*root)
{
    if (root) while (root->left) root = root->left;

    return root;
}

Node * BinarySearchTree::maxNode(Node*root)
{
    if (root) while (root->right) root = root->right;

    return root;
}




void BinarySearchTree::addValue(int value)
{
    Node *node;
    size++;
    Node* w = new Node();

    w->left = w->right = NULL;
    w->data = value;

    node = root;

    if (!node)
        root = w;
    else
        while (true)
            if (value < node->data)
            {
                if (!node->left)
                {
                    node->left = w;
                    break;
                }
                else node = node->left;
            }
            else
            {
                if (!node->right)
                {
                    node->right = w;
                    break;
                }
                else node = node->right;
            }

    w->up = node;
}

Node * BinarySearchTree::deleteValue(int value)
{
    size--;
    return deleteNode(findValue(root,value));
}



Node * BinarySearchTree::deleteNode(Node * node)
{
    Node * nodeB, *nodeC;

    if (node)
    {
        if(!node->left || !node->right)
        {
            nodeB = node;
        }
        else nodeB = successor(node);
        if(nodeB->left)
        {
            nodeC=nodeB->left;
        }
        else nodeC=nodeB->right;
        if(nodeC)
        {
            nodeC->up = nodeB->up;
        }
        if (!nodeB->up)
        {
            root = nodeC;
        }
        else if (nodeB == nodeB->up->left) {
            nodeB->up->left = nodeC;
        }
        else nodeB->up->right = nodeC;
        if (nodeB != node) node->data = nodeB->data;

        delete nodeB;

    }
    return node;
}


Node * BinarySearchTree::turnRight(int value)
{
    if(findValue(root, value)!=nullptr)
    {
        rotateRight(findValue(root, value));
        return findValue(root, value);
    }
    else return nullptr;


}

Node * BinarySearchTree::turnLeft(int value)
{
    if (findValue(root, value) != nullptr)
    {
        rotateLeft(findValue(root, value));
        return findValue(root, value);
    }
    else return nullptr;
}


void BinarySearchTree::rotateLeft(Node * nodeA)
{
    Node * nodeB = nodeA->right, *p = nodeA->up;

    if (nodeB)
    {
        nodeA->right = nodeB->left;
        if (nodeA->right) nodeA->right->up = nodeA;

        nodeB->left = nodeA;
        nodeB->up = p;
        nodeA->up = nodeB;

        if (p)
        {
            if (p->left == nodeA) p->left = nodeB; else p->right = nodeB;
        }
        else root = nodeB;
    }
}


void BinarySearchTree::rotateRight(Node * nodeA)
{
    Node * nodeB = nodeA->left, *p = nodeA->up;

    if (nodeB)
    {
        nodeA->left = nodeB->right;
        if (nodeA->left) nodeA->left->up = nodeA;

        nodeB->right = nodeA;
        nodeB->up = p;
        nodeA->up = nodeB;

        if (p)
        {
            if (p->left == nodeA) p->left = nodeB; else p->right = nodeB;
        }
        else root = nodeB;
    }
}

void BinarySearchTree::printBST(string sp, string sn, Node * v)
{
    string s;

    if (v)
    {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printBST(s + cp, cr, v->right);

        s = s.substr(0, sp.length() - 2);
        cout << s << sn << v->data << endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printBST(s + cp, cl, v->left);
    }
}

