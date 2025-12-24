#include <stdio.h>
#include <math.h>

int main(){

    int n;
    float xc, yc, xr, yr;
    
    scanf("%d", &n);
    scanf("%f %f %f %f", &xc, &yc, &xr, &yr);

    float buracos[n][2];
    float draposa, dcoelho;


    for (int i = 0; i < n; i++){
        scanf("%f %f", &buracos[i][0], &buracos[i][1]);
        
        draposa = sqrt(pow(buracos[i][0] - xr, 2) + pow(buracos[i][1] - yr, 2));
        dcoelho = sqrt(pow(buracos[i][0] - xc, 2) + pow(buracos[i][1] - yc, 2));

        if (dcoelho <= draposa / 2) {
            printf("O coelho pode escapa pelo (%.3f %.3f).\n", buracos[i][0], buracos[i][1]);
            return 0;
        } 
    }

    printf("O coelho nao pode escapar\n");
    return 0;
}