//isn't complete yet, still contain some error!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int typing_cmd (char s[], int a[]){
    printf("Nhan 'N' de nhap so nam can import\n");
    printf("Nhan 'S' de tra cuu dan so theo nam\n");
    printf("Nhan 'X' de ket thuc chuong trinh lmao\n");
    printf("Chon: ");
    gets(s);
    if (s[0] == 'X' || s[0] == 'x') return 0;
    if (s[0] == 'S' || s[0] == 'S') return searching_option(s, a);
    if (s[0] == 'N' || s[0] == 'n') return importing_data_1st(s,a);
    return typing_cmd(s, a);
}
int searching_option(char s[], int a[]){
    printf("Nhan 'Q' de tim so nam trung so nguoi sinh\n");
    printf("Nhan 'W' de tra cuu nam co dan so max\n");
    printf("Nhan 'R' de tra cuu nam co dan so min\n");
    printf("Nhan 'X' de thoat\n");
    printf("Chon: ");
    gets(s);
    if (s[0] == 'X' || s[0] == 'x') return typing_cmd;
    if (s[0] == 'Q' || s[0] == 'q') return searching_duplicate_data(s, a);
    if (s[0] == 'W' || s[0] == 'w') return searching_max_data(s, a);
    if (s[0] == 'R' || s[0] == 'r') return searching_min_data(s, a);
    return searching_option(s, a);
}
int searching_duplicate_data (char s[], int a[]){
    int n;
    scanf("%d", &n);
    int dcount = 0;
    for (int i = 0; i < 2025; i++){
        if (a[i] == n){
            dcount++;
        }
    }
    printf("\n %d \n", dcount);
    return searching_option(s, a);
}
int searching_max_data (char s[], int a[]){
    int max = a[0];
    int imax = 0;
    for(int i = 1; i < 2025; i++){
        if (a[i] > max){
            max = a[i];
            imax = i;
        }
    }
    printf("\n %d \n", imax);
    return searching_option(s,a);
}
int searching_min_data (char s[], int a[]){
    int min = a[0];
    int imin = 0;
    for(int i = 1; i < 2025; i++){
        if (a[i] < min){
            min = a[i];
            imin = i;
        }
    }
    printf("\n %d \n", imin);
    return searching_option;
}
int importing_data_2nd (char s[], int a[]){
    printf("Nhap so nam can import du lieu: ");
    gets(s);
    if (s[0] == 'E' || s[0] == 'e') return typing_cmd(s, a);
    if (atoi(s) < 0 || atoi(s) > 2024){
        printf("Error!\n");
        return importing_data_2nd(s,a);
    }
    if (atoi(s) >= 0 || atoi(s) <= 2024){
        a[atoi(s)]++;
    }
    return importing_data_2nd(s,a);
}
int importing_data_1st (char s[], int a[]){
    printf("Nhap so nam can import du lieu, nhan 'E' de thoat ve menu chinh: ");
    gets(s);
    if (s[0] == 'E' || s[0] == 'e') return typing_cmd(s, a);
    if (atoi(s) < 0 || atoi(s) > 2024){
        printf("Error!\n");
        return importing_data_2nd(s,a);
    }
    if (atoi(s) >= 0 || atoi(s) <= 2024){
        a[atoi(s)]++;
    }
    return importing_data_2nd(s,a);
}
int main () {
    int arr[2025];
    for(int i = 0; i < 2025; i++){
        arr[i] = 0;
    }
    int yr;
    int memcount;
    int yrcount;
    char cmd[4];
    printf("BO PHAN QUAN LY DAN SO PHUONG LMAO \n");
    printf("    Version 0.0.against_dl-lmao  \n");
    printf("       So nam hop le 0~2024 \n");
    //gets(cmd);
    //printf("%c", cmd[0]);
    typing_cmd(cmd,arr);
    printf("Cam on quy khach da su dung dich vu lmao\n");
    return 0;
}
