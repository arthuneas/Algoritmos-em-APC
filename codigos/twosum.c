#include <stdio.h>

int twosum (int nums[], int size, int target){
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (nums[i] + nums[j] == target){
                return target;
            }
        }
    }
}

int main(){

    twosum();

    return 0;
}