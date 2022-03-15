#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void agac_olusturma(int yukseklik){
  if(yukseklik==0){return;}

  int pid1 = fork();
  if(pid1>0)
  {
     int pid2=fork();
     if(pid2>0)
     {
     wait(NULL);
     printf("parent:%d, cocuk1:%d,cocuk2:%d\n",getpid(),pid1,pid2);
     fflush(stdout);
  
     }
     
     else if(pid2==0){
  
        agac_olusturma(--yukseklik);
     }
  }
  else if(pid1==0){

     agac_olusturma(--yukseklik);
  }
}

int main()
{
   int a;
   printf("yuksekligi giriniz"); scanf("%d",&a);
   agac_olusturma(a);
}
