#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int arr[100];
int ind = 0;

struct node* insert(struct node* root, int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->right = temp->left = NULL;
    if(root == NULL){
        root = temp;
    }
    
    else{
        if(root->data > temp->data){
            root->left = insert(root->left, val);
        }
        else{
            root->right = insert(root->right, val);
        }
    }
    return root;
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        arr[ind] = root->data;
        ind++;
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root!=NULL){
        arr[ind] = root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        arr[ind] = root->data;
    }
}

void equal(int in1, int in2){
    // to check if the inorder is equal
    int flag = 1;
    for(int i = 0; i<in1; i++){
        if(arr[i] != arr[in1+i]){
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        printf("Not equal");
    }
    else{
        printf("equal");
    }
}
int main() {
    int size;
    scanf("%d", &size);
    struct node* root1 = (struct node*)malloc(sizeof(struct node));
    struct node* root2 = (struct node*)malloc(sizeof(struct node));
    root1 =NULL;
    root2 = NULL;
    
    int data;
    
    for(int i =0; i<size; i++){
        scanf("%d", &data);
        root1 = insert(root1, data);
    }
    for(int i = 0; i<size; i++){
        scanf("%d", &data);
        root2 = insert(root2, data);
    }
    inorder(root1);
    int ind1 = ind;
    inorder(root2);
    
    equal(ind1, ind);
    
    
    return 0;
}
