#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    bool rthread;
    bool lthread;
};

node *CreateNode(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->left = temp->right = NULL;
    temp->rthread = true;
    temp->lthread = true;
    return temp;
}

node *InsertNode(node *root, int val)
{
    node *ptr = root;
    node *par = NULL;

    while(ptr != NULL)
    {
        if(val == (ptr->data))
        {
            cout <<"duplicate key";
            return root;
        }
        par = ptr;
        if(val < ptr->data)
        {
            if(ptr->lthread == false)
            {
                ptr = ptr->left;
            }
            else
            {
                break;
            }
        }
        else{
              if(ptr->rthread == false)
              {
                ptr = ptr->right;
              }  
              else{
                break;
              }
            }
    }
    node *temp = new node();
    temp->data = val;
    temp->lthread = true;
    temp->rthread = true;

    if(par == NULL)
    {
        root = temp;
        temp->left = NULL;
        temp->right = NULL;
    }
    else if(val <(par->data))
    {
        temp->left = par->left;
        temp->right = par;
        par->lthread = false;
        par->left = temp;
    }
    else{
        temp->left = par;
        temp->right = par->right;
        par->rthread = false;
        par->right = temp;
    }
    return root;
}

void InOrder(node *root)
{
    if(root == NULL){
        return;
    }
    if(root->lthread == false)
    InOrder(root->left);

    cout << root->data <<" ";
    
    if(root->rthread == false)
    InOrder(root->right);
}

void PreOrder(node *root)
{
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    
    if(root->lthread == false)
    PreOrder(root->left);

    if(root->rthread == false)
    PreOrder(root->right);
}

void PostOrder(node *root)
{
    if(root == NULL){
        return;
    }
    if(root->lthread == false)
    PostOrder(root->left);

    if(root->rthread == false)
    PostOrder(root->right);

    cout << root->data <<" ";
}

void NonRecursivePreOrder(node *root)
{
    node *ptr;
    if(root == NULL)
    {
        cout <<"Tree is empty";
        return;
    }
    ptr = root;
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        if(ptr->lthread == false)
        {
            ptr = ptr->left;
        }
        else if(ptr->rthread == false)
        {
            ptr = ptr->right;
        }
        else
        {
            while(ptr != NULL && ptr->rthread == true)
            {
                ptr = ptr->right;
                if(ptr != NULL)
                {
                    ptr = ptr->right;
                }
            }
        }
    }

}

void NonRecursivePostOrder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    node *curr = root;
    node *pre = NULL;

    while(curr != NULL)
    {
        if(curr->lthread == false)
        {
            if(pre == curr->left)
            {
                cout <<curr->data<< " ";
                pre = curr;
                curr = curr->right;
            }
            else{
                pre = curr;
                curr = curr->left;
            }
        }
        if(pre == curr->right)
        {
            cout << curr->data <<" ";
            pre = curr;
            curr = NULL; 
        }
        else
        {
            pre = curr;
            curr = curr->right;
        }
    }
}

node *leftmost(node *n)
{
    if(n == NULL)
    {
        return NULL;
    }
    while(n->left != NULL)
    {
        n = n->left;
    }
    return n;
}

void NonRecursiveInOrder(node *root)
{
    node *curr = leftmost(root);
    while(curr != NULL)
    {
        cout << curr->data <<" ";
        curr = curr->right;
    }
}

node *CaseA(node *root, node *par, node *ptr)
{
    if(par == NULL)
    {
        root = NULL;
    }
    else if(ptr == par->left)
    {
        par->lthread = true;
        par->left = ptr->left;
    }
    else
    {
        par->rthread = true;
        par->right = ptr->right;
    }
    free(ptr);
    return root;
}

// node *CaseB(node *root, node *par, node *ptr)
// {
//     node *child;

//     if(ptr->lthread == false)
//     {
//         child = ptr->left;
//     }
//     else
//     {
//         child = ptr->right;
//     }

//     if(par == NULL)
//     {
//         root = child;
//     }
//     else if(ptr == par->left)
//     {
//         par->left = child;
//     }
//     else
//     {
//         par->right = child;
//     }

//     node *succ = InOrderSuccessor(ptr);
//     node *pred = InOrderPredecessor(ptr);

//     if(ptr->lthread == false){
//         pred->right = succ;
//     }
//     else
//     {
//         if(ptr->rthread == false)
//         ptr->left = pred;
//     }
//     free(ptr);
//     return root;
// }

// node *InOrderPredecessor(node *ptr)
// {
//     if(ptr->lthread == true)
//     {
//         return ptr->left;
//     }

//     ptr = ptr->left;
//     while(ptr->rthread == false)
//     {
//         ptr = ptr->right;
//     }
//     return ptr;
// }

// node *InOrderSuccessor(node *ptr)
// {
//     if(ptr->rthread == true)
//     {
//         return ptr->right;
//     }
//     ptr = ptr->right;
//     while(ptr->lthread == false)
//     {
//         ptr = ptr->left;
//     }
//     return ptr;
// }

node *InOrderPredecessor(node *ptr) 
{
    if (ptr->lthread == true) 
    {
        return ptr->left;
    }
    ptr = ptr->left;
    while (ptr->rthread == false) 
    {
        ptr = ptr->right;
    }
    return ptr;
}

node *InOrderSuccessor(node *ptr) 
{
    if (ptr->rthread == true) 
    {
        return ptr->right;
    }
    ptr = ptr->right;
    while (ptr->lthread == false) 
    {
        ptr = ptr->left;
    }
    return ptr;
}

node *CaseB(node *root, node *par, node *ptr) 
{
    node *child;

    if (ptr->lthread == false) {
        child = ptr->left;
    } else {
        child = ptr->right;
    }

    if (par == NULL) {
        root = child;
    } else if (ptr == par->left) {
        par->left = child;
    } else {
        par->right = child;
    }

    node *succ = InOrderSuccessor(ptr);
    node *pred = InOrderPredecessor(ptr);

    if (ptr->lthread == false) {
        pred->right = succ;
    } else {
        if (ptr->rthread == false)
            ptr->left = pred;
    }
    free(ptr);
    return root;
}

// node *InOrderPredecessor(node *ptr);
// node *InOrderSuccessor(node *ptr);

// node *CaseB(node *root, node *par, node *ptr)
// {
//     node *child;

//     if(ptr->lthread == false)
//     {
//         child = ptr->left;
//     }
//     else
//     {
//         child = ptr->right;
//     }

//     if(par == NULL)
//     {
//         root = child;
//     }
//     else if(ptr == par->left)
//     {
//         par->left = child;
//     }
//     else
//     {
//         par->right = child;
//     }

//     node *succ = InOrderSuccessor(ptr);
//     node *pred = InOrderPredecessor(ptr);

//     if(ptr->lthread == false){
//         pred->right = succ;
//     }
//     else
//     {
//         if(ptr->rthread == false)
//             ptr->left = pred;
//     }
//     free(ptr);
//     return root;
// }


node *CaseC(node *root, node *par, node *ptr)
{
    node *ParSucc = ptr;
    node *Succ = ptr->right;

    while(Succ->lthread == false)
    {
        ParSucc = Succ;
        Succ = Succ->left;
    }
    ptr->data = Succ->data;

    if(Succ->lthread == true && Succ->rthread == true)
    {
        root = CaseA(root, ParSucc, Succ);
    }
    else{
        root = CaseB(root, ParSucc, Succ);
    }
    return root;
}

node *delNode(node *root, int val)
{
    node *par = NULL;
    node *ptr = root;

    int flag = 0;

    while(ptr != NULL)
    {
        if(val == ptr->data)
        {
            flag = 1;
            break;
        }
        par = ptr;
        if(val < ptr->data)
        {
            if(ptr->lthread == false)
            {
                ptr = ptr->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(ptr->rthread == false)
            {
                ptr = ptr->right;
            }
            else
            {
                break;
            }
        }
        if(flag == 0)
        {
            cout <<" value not present in tree "<< endl;
        }
        else if(ptr->lthread == false && ptr->rthread == false)
        {
            root = CaseC(root, par, ptr);
        }
        else if(ptr->lthread == false)
        {
            root = CaseB(root, par, ptr);
        }
        else
        {
            root = CaseA(root, par, ptr);
        }
    }
    return root;
}
int main()
{
    node *root = NULL;
    int num, choice, x;
    char ch;

    do{
        cout <<"1.Insertion"<< endl;
        cout <<"2.Search"<< endl;
        cout <<"3.Recursive Inorder"<< endl;
        cout <<"4.Recursive Preorder"<< endl;
        cout <<"5.Recursive Postorder"<< endl;
        cout <<"6.Non Recursive Inorder"<< endl;
        cout <<"7.Non Recursive Preorder"<< endl;
        cout <<"8.Non Recursive Postorder"<< endl;
        cout <<"9.Deletion"<< endl;
        cout <<"Enter the choice "<< endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
            cout << "Enter number of nodes to insert: ";
            cin >> x;
            cout <<"Enter numbers" << endl;
            for(int i = 0; i < x; i++) {
                cin >> num;
                root = InsertNode(root, num);
                }
                cout << endl;
            break;

            // case 2:
            // break;

            case 3:
            cout <<"Recursive Inorder is - ";
            InOrder(root);
            cout << endl;
            break;

            case 4:
            cout <<"Recursive Preorder is - ";
            PreOrder(root);
            cout << endl;
            break;

            case 5:
            cout <<"Recursive Postorder is - ";
            PostOrder(root);
            cout << endl;
            break;

            case 6:
            cout <<"Recursive Inorder is - ";
            NonRecursiveInOrder(root);
            cout << endl;
            break;

            case 7:
            cout <<"Recursive Preorder is - ";
            NonRecursivePreOrder(root);
            cout << endl;
            break;

            case 8:
            cout <<"Recursive Postorder is - ";
            NonRecursivePostOrder(root);
            cout << endl;
            break;

            case 9:
            cout << "Enter number to delete: ";
            cin >> num;
            root = delNode(root, num);
            cout << "Deleted" << endl;
            break;

            default:
            cout <<"Wrong choice" <<endl;
            cout << endl;
            break;
        }     
        cout <<"Do you want to continue? "<< endl;
        cin >> ch;
    }
    while(ch == 'Y' || ch == 'y');

}