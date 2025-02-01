#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node *right;
    node *left;
};
node *CreateNode(int val){
    node *temp = new node();
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
node *insertNode(node* root, int val){
    if(root == NULL){
        return CreateNode(val);
    }
    if(val < root->data){
        root->left = insertNode(root->left, val);
    }
    else if(val > root->data){
        root->right = insertNode(root->right, val);
    }
    return root;
}
void InOrder(node* root){
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    cout << root->data <<" ";
    InOrder(root->right);
}
void PreOrder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void PostOrder(node* root){
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data <<" ";
}
void NonRecursiveInOrder(node* root){
    stack<node*>s;
    node *current = root;
    while(current != NULL || s.empty() == false){
        while(current != NULL){
            s.push(current);
            current = current->left;
        }
        while(s.empty() == false){
            current = s.top();
            s.pop();
            cout << current->data <<" ";
            current = current->right;
        }
    }
}
void NonRecursivePreOrder(node* root){
    stack<node*>s;
    node *current = root;
    while(current != NULL){
        cout << current->data << " ";
        s.push(current);
        current = current->left;

    }
    while(s.empty() == false){
        current = s.top();
            s.pop();
            current = current->right;
        while(current != NULL){
            cout << current->data << " ";
            s.push(current);
            current = current->left;
        }
    }

}
void NonRecursivePostOrder(node* root){
    stack<node*>s1, s2;
    node *current = root;
    s1.push(current);
    while(s1.empty() == false){
        current = s1.top();
        s1.pop();
        s2.push(current);
    if(current->left != NULL){
        s1.push(current->left);
    }
    if(current->right != NULL){
        s1.push(current->right);
    }
    }
    while(s2.empty() == false){
        root = s2.top();
        s2.pop();
        cout << root->data <<" ";
    }

}

int hei
int tree_height(node *root)
{
    if (!root)
    {
        return 0;
    }
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    return max(left_height, right_height) + 1;
}

void print_level(node *root, int level_no)
{
    if (!root)
    {
        return;
    }
    if (level_no == 0)
    {
        cout << root->data << " ";
    }
    else
    {
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }
}

void LevelwisePrinting(node *root)
{
    if (!root)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    int height = tree_height(root);
    for (int i = 0; i < height; i++)
    {
        print_level(root, i);
        cout << endl;  
    }
}


int main(){
    int choice, num;
    node* root = NULL;
    char ch;

    do{
        cout << "1.Insertion" << endl;
        cout << "2.Recursive Inorder" << endl;
        cout << "3.Recursive Preorder" << endl;
        cout << "4.Recursive Postorder" << endl;
        cout << "5.Non Recursive Inorder" << endl;
        cout << "6.Non Recursive Preorder" << endl;
        cout << "7.Non Recursive Postorder" << endl;
        cout << "8.Level Wise Printing" << endl;
        cout << "9.Deletion" << endl;
        cout << "10.Search" << endl;
        cout << "11. Exit" << endl;
        cout <<"Enter your choice : ";
        cin >> choice;
        switch(choice){
            case 1:
            cout <<"Enter the num you want to insert : ";
            cin >> num;
            root = insertNode(root, num);
            cout << endl;
            break;

            case 2:
            cout <<"Recursive Inorder is : ";
            InOrder(root);
            cout << endl;
            break;

            case 3:
            cout <<"Recursive Preorder is : ";
            PreOrder(root);
            cout << endl;
            break;

            case 4:
            cout <<"Recursive Postorder is : ";
            PostOrder(root);
            cout << endl;
            break;

            case 5:
            cout <<"Non Recursive Inorder is : ";
            NonRecursiveInOrder(root);
            cout << endl;
            break;

            case 6:
            cout <<"Non Recursive Preorder is : ";
            NonRecursivePreOrder(root);
            cout << endl;
            break;

            case 7:
            cout <<"Non Recursive Postorder is : ";
            NonRecursivePostOrder(root);
            cout << endl;
            break;

            case 8:
            cout <<"Level Wise Printing : ";
            LevelwisePrinting(root);
            break;

            // case 9:
            // break;

            // case 10:
            // cout << "Enter element to search: ";
            // cin >> element;
            // node *result = search(root, element);
            // if (result != NULL)
            // {
            //     cout << "Element Found!" << endl;
            // }
            // else
            // {
            //     cout << "Element Not Found!" << endl;
            // }
            // break;

            case 11:
            cout <<"Exit";
            break;

            default:
            cout <<"Wrong choice"<< endl;
            break;

            cout <<"Do you want to continue ?"<< endl;
            cin >> ch;

        }
    }while(ch != 'N');
}