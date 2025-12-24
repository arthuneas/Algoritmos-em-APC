#include <stdio.h>

int pell(int n){
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return 2 * pell(n - 1) + pell(n - 2);
    }
}

int main(){
    int n; 
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("%d ", pell(i));
    }

    return 0;
}