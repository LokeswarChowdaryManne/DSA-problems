#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int Data;
    Node *right;
    Node *left;
    Node(int data=0)
    {
        Data=data;
        right=NULL;
        left=NULL;
    }
};

class BinarySearchtree
{
public:
    Node *root;
    BinarySearchtree()
    {
        root=NULL;
    }
    void displayInorder(Node *);
    void displayPostorder(Node *);
    void displayPreorder(Node *);
    void insert(int );
    bool search(int);
    int findMax();
    int findLeftChild(int );
    int findRightChild(int );
};

int BinarySearchtree::findLeftChild(int value)
{
    if(value==root->Data)
    {
        return root->left->Data;
    }
    else
    {
        Node *current=root;
        while(current!=NULL)
        {
            if(current->Data==value)
            {
                return current->left->Data;
            }
            else
            {
                if(value>current->Data)
                {
                    current=current->right;
                }
                else
                {
                    current=current->left;
                }
            }
        }
    }
}
int BinarySearchtree::findRightChild(int value)
{
    if(value==root->Data)
    {
        return root->right->Data;
    }
    else
    {
        Node *current=root;
        while(current!=NULL)
        {
            if(current->Data==value)
            {
                return current->right->Data;
            }
            else
            {
                if(value>current->Data)
                {
                    current=current->right;
                }
                else
                {
                    current=current->left;
                }
            }
        }
    }

}
int BinarySearchtree::findMax()
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        Node *current=root;
        while(current->right!=NULL)
        {
            current=current->right;
        }
        return current->Data;
    }



}
bool BinarySearchtree::search(int value)
{
    Node *current=root;
    while(current!=NULL)
    {
        if(current->Data==value)
        {
            return true;
        }
        else
        {
            if(value>current->Data)
            {
                current=current->right;
            }
            else
            {
                current=current->left;
            }
        }
    }
}
void BinarySearchtree::insert(int value)
{
    if(root==NULL)
    {
        root=new Node(value);
        return;
    }
    else
    {
        Node *current=root;
        while(true)
        {
            if(value==current->Data)
            {
                return;
            }
            else
            {
                if(value<current->Data)
                {
                    if(current->left==NULL)
                    {
                        current->left=new Node(value);
                        return;
                    }
                    else
                    {
                        current=current->left;
                    }

                }
                else
                {
                    if(current->right==NULL)
                    {
                        current->right=new Node(value);
                        return;
                    }
                    else
                    {
                        current=current->right;
                    }
                }
            }

        }
    }
}
void BinarySearchtree::displayPostorder(Node *current)
{
    if(current==NULL)
    {
        return;

    }
    displayPostorder((current->left));
    displayPostorder((current->right));
    cout<<current->Data<<" ";
    return;

}
void BinarySearchtree::displayPreorder(Node *current)
{
    if(current==NULL)
    {
        return;
    }
    cout<<current->Data<<" ";
    displayPreorder(current->left);
    displayPreorder(current->right);
}

void BinarySearchtree::displayInorder(Node* current)
{
    if(current==NULL)
    {
        return;
    }
    displayInorder(current->left);
    cout<<current->Data<<" ";
    displayInorder(current->right);
    return;
}
int main()
{
    BinarySearchtree hi;
    hi.insert(100);
    hi.insert(50);
    hi.insert(30);
    hi.insert(60);
    hi.insert(70);
    hi.insert(120);
    hi.insert(110);
    hi.insert(125);
    cout<<"Inorder"<<endl;
    hi.displayInorder(hi.root);
    cout<<endl;
    cout<<"Postorder"<<endl;
    hi.displayPostorder(hi.root);
    cout<<endl;
    cout<<"Preorder"<<endl;
    hi.displayPreorder(hi.root);
    cout<<endl;
    cout<<"Maximum"<<endl;
    cout<<hi.findMax()<<endl;
    cout<<"Left child of 50"<<endl;
    cout<<hi.findLeftChild(50)<<endl;
    cout<<"Right child of 50"<<endl;
    cout<<hi.findRightChild(50)<<endl;

    return 0;
}
