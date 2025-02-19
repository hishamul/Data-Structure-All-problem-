#include <stdio.h>
#define MAX 50
int main(){
    int a[MAX][MAX];
    int b[MAX][MAX];
    int product[MAX][MAX];
int sum=0;
    int arows,acolumns;
    int brows,bcolumns;
    printf("Enter the rows and columns of the matrix a: ");
    scanf("%d%d", &arows,&acolumns);

printf("Enter the elements of matrix a:");
for (int  i = 0; i <arows; i++)
{
    for (int j = 0; j <acolumns; j++)
    {
        scanf("%d",&a[i][j]);
    }

}
printf("Enter the rows and columns of the matrix b: ");
    scanf("%d%d", &brows,&bcolumns);

printf("Enter the elements of matrix b:");
for (int  i = 0; i <arows; i++)
{
    for (int j = 0; j <acolumns; j++)
    {
        scanf("%d",&a[i][j]);
    }

}

for (int i = 0; i <arows; i++)
{
    for (int j = 0; j < bcolumns; j++)
    {
        for (int  k = 0; i < brows; k++)
        {
            sum +=a[i][k] * b[k][j];
        }
        product[i][j]=sum;
        sum=0;
    }

}
printf("resultant matrix\n");
for (int  i = 0; i <arows; i++)
{
    for (int j = 0; j < bcolumns; j++)
    {
        printf("%d",product[i][j]);
    }
  printf("\n");
}

    return 0;
}