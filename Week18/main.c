#include <stdio.h>
#include <stdlib.h>

int arr[100][100]; 
int visit[100];    
int n;               

void rvisit() {
    for (int i = 0; i < n; i++) {
        visit[i] = 0;
    }
}

void GphType() {
    printf("Nhập số đỉnh: ");
    scanf("%d", &n);

    printf("Nhập ma trận (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void DFS(int vtx) {
    printf("%d ", vtx);
    visit[vtx] = 1;

    for (int i = 0; i < n; i++) {
        if (arr[vtx][i] != 0 && !visit[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[100], f = 0, r = 0;

    queue[r++] = start;
    visit[start] = 1;

    while (f < r) {
        int crr = queue[f++];
        printf("%d ", crr);

        for (int i = 0; i < n; i++) {
            if (arr[crr][i] != 0 && !visit[i]) {
                queue[r++] = i;
                visit[i] = 1;
            }
        }
    }
}

int main() {
    GphType();

    int c, firstVtx;
    do {
        printf("\nMenu:\n");
        printf("1. Duyệt chiều sâu\n");
        printf("2. Duyệt chiều rộng\n");
        printf("3. Exit\n");
        printf("Ans: ");
        scanf("%d", &c);

        switch (c) {
        case 1:
            printf("Chọn 1 đỉnh bất kì: ");
            scanf("%d", &firstVtx);
            rvisit();
            printf("Thứ tự duyệt sâu: ");
            DFS(firstVtx);
            printf("\n");
            break;
        case 2:
            printf("Chọn 1 đỉnh bất kì: ");
            scanf("%d", &firstVtx);
            rvisit();
            printf("Thứ tự duyệt rộng: ");
            BFS(firstVtx);
            printf("\n");
            break;
        case 3:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choose!\n");
        }
    } while (c != 3);

    return 0;
}
