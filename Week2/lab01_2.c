#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int n, int pos, int valInsert) {
  
    // Shift elements to the right  
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    // Insert val at the specified position
    arr[pos] = valInsert;

    // Increase the current size
    n++;
}
void delete(int arr[],int n,int pos) {
    int i;
    for(i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
}
int main(){
    int n1,n2,*arr1,*arr2,i,j,valInsert;
    scanf("%d",&n1);
    arr1 = (int*)malloc(n1 * sizeof(int)); // จอง memory arr1
    //รับค่าเข้า arr1
    for (int i = 0; i < n1; i++)
    {
        scanf("%d ",arr1 + i);
    }
    scanf("%d",&n2);
    arr2 = (int*)malloc(n2 * sizeof(int)); // จอง memory arr2
    //รับค่าเข้า arr2
    for (int i = 0; i < n2; i++)
    {
        scanf("%d ",arr2 + i);
    }

    //line 5 insert
    scanf("%d", &i);

    scanf("%d",&valInsert);
    insert(arr1, n1, i, valInsert);

    //delete
    scanf("%d", &j);
    delete(arr1,n1,j);
}