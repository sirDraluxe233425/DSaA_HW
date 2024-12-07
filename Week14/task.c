#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    char data[10];            
    struct Node* left;        
    struct Node* right;       
} Node;
Node* c(char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int checkempty(Node* root) {
    return root == NULL;
}
void TreeGrowing(Node* root){
    root->left = c("-");
    root->right = c("*");
    root->left->left = c("*");
    root->left->right = c("/");
    root->left->left->left = c("a");
    root->left->left->right = c("5");
    root->left->right->left = c("*");
    root->left->right->right = c("d");
    root->left->right->left->left = c("b");
    root->left->right->left->right = c("^");
    root->left->right->left->right->left = c("c");
    root->left->right->left->right->right = c("16");
    root->right->left = c("-");
    root->right->right = c("^");
    root->right->left->left = c("h");
    root->right->left->right = c("f");
    root->right->right->left = c("e");
    root->right->right->right = c("(1/2)");
}
void PrintingInfix(Node* root) {
    if (root != NULL) {
        if (root->left) printf("");
        PrintingInfix(root->left);
        printf("%s ", root->data);
        PrintingInfix(root->right);
        if (root->right) printf("");
    }
}
void PrintingPrefix(Node* root) {
    if (root != NULL) {
        printf("%s ", root->data);
        PrintingPrefix(root->left);
        PrintingPrefix(root->right);
    }
}
void PrintingPostfix(Node* root) {
    if (root != NULL) {
        PrintingPostfix(root->left);
        PrintingPostfix(root->right);
        printf("%s ", root->data);
    }
}
int main() {
    Node* root = c("+");
    TreeGrowing(root);
    printf("Infix: ");
    PrintingInfix(root);
    printf("\n");
    printf("Prefix: ");
    PrintingPrefix(root);
    printf("\n");
    printf("Postfix: ");
    PrintingPostfix(root);
    printf("\n");
    return 0;
}
