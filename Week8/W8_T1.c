#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int heso;
    unsigned int somu;
    struct Node* next;
} Node;
Node* taoNode(int heso, unsigned int somu) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->heso = heso;
    newNode->somu = somu;
    newNode->next = NULL;
    return newNode;
}
void them(Node** head, int heso, unsigned int somu) {
    Node* newNode = taoNode(heso, somu);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void inDthuc(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->heso != 0) {
            if (temp != head && temp->heso > 0) printf(" + ");
            else if (temp->heso < 0) printf(" - ");
            printf("%dx^%d", abs(temp->heso), temp->somu);
        }
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    Node* dthuc = NULL;
    int n, heso;
    unsigned int somu;
    printf("Da thuc can in ra co bao nhieu hang tu?  ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap he so va so mu cua hang tu thu %d: ", i + 1);
        scanf("%d %u", &heso, &somu);
        them(&dthuc, heso, somu);
    }
    printf("Da thuc in ra: f(x) = ");
    inDthuc(dthuc);
    Node* temp;
    while (dthuc != NULL) {
        temp = dthuc;
        dthuc = dthuc->next;
        free(temp);
    }

    return 0;
}
