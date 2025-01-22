#include <stdio.h>
int main(){
    int ans,min = 99999,max= -99999,imax=0,imin=0,i = 1;

    while (1)
    {
        scanf("%d",&ans);
        if (ans == -9999) { //ถ้าคำตอบ = -9999 ให้ทำการออกลูป
            break;
        }
        if(ans > max) { 
            max = ans;
            imax = i;
        }
        if(ans < min) {
            min = ans;
            imin = i;
        }
        i++;
    }
    printf("%d %d\n",max,imax);
    printf("%d %d",min,imin);
    
}