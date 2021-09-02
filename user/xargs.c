#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    char *cargv[MAXARG];
    int i=0;
    for(;i<argc-1;i++){
        cargv[i]=argv[i+1];
    }
    
    char buff[256], *p,*q;
    p=buff;
    q=p;
    while(read(0,buff+strlen(buff),sizeof(buff)));
    
    printf("%s", p);
    //printf("i:%d\n", i);
    
    int n=strlen(buff);
    for(int j=0;j<n;j++){
        printf("%c:%d\n",buff[j], buff[j]);
        if(buff[j]=='\n' ){
            p[j]=0;
            cargv[i]=q;
            //printf(":%s\n", cargv[i]);
            
            q=p+j+1;
            i++;

        }
    }
    //i--;  
/*
    for(int j=0;j<i;j++){
        
            printf("%s\n", cargv[j]);
            
        
    }
        printf("i:%d\n", i);
        */
   /*
    if((strcmp("grep",  cargv[0])) != 0){
      printf("xargs: cannot open %s\n",cargv[0]);
      printf("xargs: cannot open %d\n",strlen(cargv[0]));

      exit(1);
    }
    */
    if(fork()==0){
        exec(argv[1],cargv);
        exit(0);
    }
    else{
    
    wait(0);
    
    exit(0);
    }
}