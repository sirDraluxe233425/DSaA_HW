#include<stdio.h>
#include<math.h>
int PrimeExtractor(long n){ //a.k.a. check-for-prime function
    if (n == 2) return 1;
    if (n == 3) return 1;
    int checkP = 0;
    if (n > 3) {
        for(int i = 2; i <= sqrt(n); i++){
            if (n % i == 0) {
                checkP++;
                break;
            }
        }
    }
    if (checkP == 0) return 1; 
        else return 0;
}
int main() {
    int p = 2;
    int q = 2;
    //long res;
    long arr[100000];
    long Parliament[100000];
    long Perception[100000]; 
    int count = 0;
    int Sumcount = 0;
    long n;
    long m;
    scanf("%ld", &n);
    while(p*q < n) { //semiprime array generator - pre-task
        while (p*q < n){
            if ((p % 4 == 3) && (q % 4 == 3)) {
            arr[count] = p*q;
            count++;
            }
            do {
                q++;
            } while (PrimeExtractor(q) == 0);
        }
        do {
            p++;
        } while (PrimeExtractor(p) == 0);
        q = p;
        do {
            q++;
        } while (PrimeExtractor(q) == 0);
    }
    for (int i = 0; i < count; i++){
        printf("%ld ",arr[i]);
    }
    printf("\n");
    for(int i = 1; i < count; i++){ //checksum - 1st subtask
        for(int j = 0; j < i; j++){
            int sum = arr[j] + arr[i];
            if (sum < n){
                for (int k = 2; k <= sqrt(sum); k++){
                    if((sum % k == 0) && (PrimeExtractor(k) == 1) && (PrimeExtractor(sum/k) == 1) && (k % 4 == 3) && (sum/k % 4 == 3)){ // checking for semiprime
                        Parliament[Sumcount] = arr[i];
                        Perception[Sumcount] = arr[j];
                        Sumcount++;
                    }
                }
            }
        }
    }
    if (Sumcount == 0) printf("Not available! \n"); else {
        for (int i = 0; i < Sumcount; i++){
            printf("%ld %ld \n", Parliament[i], Perception[i]);
        }
    }
    scanf("%ld", &m); //searching for exist number - 2nd subtask
    int ava = 0;
    if (m < n){
                for (int k = 2; k <= sqrt(m); k++){
                    if((m % k == 0) && (PrimeExtractor(k) == 1) && (PrimeExtractor(m / k) == 1) && (k % 4 == 3) && (m/k % 4 == 3)){ 
                        ava++;
                        break;
                    }
                }
    }
    if (ava != 0) printf("Available!"); else printf("Not available!");
    return 0;
}
