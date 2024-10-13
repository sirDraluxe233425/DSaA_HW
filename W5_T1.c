#include <stdio.h>
#include <string.h>
int main () {
    char str[10];
    //char str_void[1];
    int n;
    //printf("Note: You can type by using English or Vietnamese but the program will display the result in English\n");
    //printf("How many colors do you have for us? \n");
    scanf("%d", &n);
    n++; //idk why but wtf the program always misses the last color, so i put it on.
    //printf("Type 'em, once you completed a single one, press 'enter' to proceed. \n");
    //printf("Warning, don't try to put all colors in a single column, this may break the program. \n");
    int Rcount = 0;
    int Wcount = 0;
    int Bcount = 0;
    for(int i = 0; i < n; i++){
        gets(str);
        if ((str[0] == 'r') || (str[0] == 'd')) Rcount++;
        if ((str[0] == 'w') || (str[0] == 't')) Wcount++;
        if ((str[0] == 'b') || (str[0] == 'x')) Bcount++;
        
    }
    for (int i = 0; i < Rcount; i++) printf("red ");
    for (int i = 0; i < Wcount; i++) printf("white ");
    for (int i = 0; i < Bcount; i++) printf("blue ");

    return 0;
}