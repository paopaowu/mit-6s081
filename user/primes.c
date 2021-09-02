#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
void func(int p){
    int buff=0;
    
    if(read(p,&buff,1)==0){
        
        printf("eixt\n");
    }
    printf("prime %d\n",buff);
    
    if(fork()==0){
        func(p);
    }
    else{
        wait(0);
        exit(0);
    }
    
}
int
main(int argc, char *argv[])
{
    int p[2];
    int m[11]={2,3,5,7,11,13,17,19,23,29,31};
    pipe(p);
    int i=0;
    while(i<11){
        write(p[1],(m+i),1);
    
        i++;
    }
    close(p[1]);
    if(fork()==0){
        func(p[0]);
        exit(0);
    }
    else{
    
    wait(0);
    
    exit(0);
    }
}