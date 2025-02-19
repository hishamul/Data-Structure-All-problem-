#include <stdio.h>
#define MAX 50
int main(){
    int a[MAX][MAX];
    int arows,acolumns;
    int brows,bcolumns;
    printf("Enter the rows and columns of the matrix a: ");
    scanf("%d%d", &arows,acolumns);
    printf("Enter the rows and columns of the matrix b: ");
    scanf("%d%d", &brows,bcolumns);
    return 0;
}