#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int productA; 
    int productB; 
    int productC; 
    int productD; 
} Cart;

typedef struct Node {
    Cart cart;
    struct Node* next;
} Node;

typedef struct {
    Node* first; 
    Node* last;  
} Queue;

void initQueue(Queue* q) {
    q->first = NULL;
    q->last = NULL;
}

int isEmpty(Queue* q) {
    return q->first == NULL;
}

void enqueue(Queue* q, Cart cart) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->cart = cart;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->first = newNode;
    } else {
        q->last->next = newNode;
    }
    q->last = newNode;
}

Cart dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Trống!\n");
        exit(1);
    }
    Node* temp = q->first;
    Cart cart = temp->cart;
    q->first = q->first->next;
    if (q->first == NULL) {
        q->last = NULL;
    }
    free(temp);
    return cart;
}

int calculateCartTotal(Cart cart) {
    return cart.productA * 5 + cart.productB * 4 + cart.productC * 3 + cart.productD * 2;
}

int main() {
    Queue queue;
    initQueue(&queue);
  // Thêm các giỏ và số lượng hàng thông qua khu vực này, thêm queue ở dưới
    Cart cart1 = {2, 1, 0, 3}; 
    Cart cart2 = {0, 2, 1, 1}; 
    Cart cart3 = {3, 0, 2, 0}; 

    enqueue(&queue, cart1);
    enqueue(&queue, cart2);
    enqueue(&queue, cart3);

    int sum = 0; 
    int totalA = 0;   

    printf("Initializing...:\n");
    while (!isEmpty(&queue)) {
        Cart currentCart = dequeue(&queue);
        int cartTotal = calculateCartTotal(currentCart);
        sum += cartTotal;
        totalA += currentCart.productA;

        printf("Trong giỏ thằng này có: %dA, %dB, %dC, %dD -> Tổng tiền phải trả: %d$\n",
               currentCart.productA, currentCart.productB, currentCart.productC, currentCart.productD, cartTotal);
    }

    printf("\nTổng doanh thu trong một phiên mần việc: %d$\n", sum);
    printf("Tổng số sản phẩm A đã bán: %d\n", totalA);

    return 0;
}
