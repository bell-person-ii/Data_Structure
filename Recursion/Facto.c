#include <stdio.h>

int facto(int num){
    
    if (num ==1){
        return 1;
    }
    else{
        return num * facto(num -1);
    }
    
}


int main(void){
    
    int num;
    
    printf("Type integer number: ");
    scanf("%d",&num);
    printf("%d! = %d\n", num,facto(num));
    
    
    return 0;
}
