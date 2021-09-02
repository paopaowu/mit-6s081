#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p[2];
  pipe(p);
  if(fork()==0){
    char buff;
    read(p[0],&buff,1);
    printf("%d: received ping\n",getpid());
    exit(0);
  }
  else{
    char bye='1';
  write(p[1],&bye,1);
  wait(0);
  printf("%d: received pong\n",getpid());
    
  exit(0);
    }
}