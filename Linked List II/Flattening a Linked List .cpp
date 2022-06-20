/*
Problem link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
Solution link: https://takeuforward.org/data-structure/flattening-a-linked-list/
Solution video: https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=39
*/

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/
Node* merge(Node *a, Node *b) {
    Node* res = new Node(0);
    Node *temp = res;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->bottom = a;
            a = a->bottom;
        }
        else {
            temp->bottom = b;
            b = b->bottom;
        }
        temp = temp->bottom;
    }

    if (a)   temp->bottom = a;
    else    temp->bottom = b;

    return res->bottom;
}

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    // Your code here
    if (root == NULL || root->next == NULL)   return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}


/*
Time Complexity: O(N), where N is the total number of nodes present
Reason: We are visiting all the nodes present in the given list.

Space Complexity: O(1)
Reason: We are not creating new nodes or using any other data structure.
*/