#include <stdio.h>

int fibo(int num){
    if (num >2){
        return fibo(num-2)+fibo(num-1);
    }
    else{
        return 1;
    }
}


int main(void){
    
    int num;
    printf("Type A Number: ");
    scanf("%d",&num);
    printf("Result : %d\n",fibo(num));
    return 0;
}
