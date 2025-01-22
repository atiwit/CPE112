#include <stdio.h>
#include <stdlib.h>

int main() {
    int *allnum,n,choice;
    int haveAns = 0; //ไม่มีคำตอบ
    scanf("%d",&n);
    allnum = (int*)malloc(n * sizeof(int));//กำหนด size memory ที่จอง
    for (int i = 0; i < n; i++)
    {
        scanf("%d ",allnum + i);
    }
    
    scanf("%d",&choice); //รับ choice ว่าเอาตำแหน่งคู่หรือคี่

    if(choice == 1) {
        for (int i = 1; i < n; i+=2)
        {
            printf("%d ",*(allnum + i));
            haveAns = 1;
        }
        
    } else if(choice == 0) {
        for (int i = 0; i < n; i+=2)
        {
            printf("%d ",*(allnum + i));
            haveAns = 1;
        }
    }
    if (haveAns == 0) {
        printf("none");
    }
    free(allnum);
}