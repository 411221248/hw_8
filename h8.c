#include "alo.c"
#include "abc.h"

int main(){
  Axis start,end,current,noExit={-1,-1};
  Stack stack,stack2;
  stack2.top=-1;
  stack.top=-1;
  memcpy(mark,maze,sizeof(mark));
  memset(mark2,0,sizeof(mark2));
  printf("start:");
  scanf("%d %d",&start.x,&start.y);
  printf("end:");
  scanf("%d %d",&end.x,&end.y);
  current=start;
  mark[current.x][current.y]='*';
  mark2[current.x][current.y]=1;
  while(!EQU(current,end)){
    current=findMove(&stack,current);     
    if(EQU(current,noExit)){
      printf("NO EXIT\n");
      return 0;
    }
    //printf("move to %d %d\n",current.x,current.y);
    push(&stack2,current);
    mark2[current.x][current.y]=1;
  }
  Axis temp={-1,-1},c=pop(&stack2),c2;
  while(!EQU(c,temp)){
    c2=pop(&stack2);
    if(EQU(c2,temp)) break;
    if((c2.x-c.x)*(c2.y-c.y)==0&&(abs(c2.x-c.x)==1||abs(c2.y-c.y)==1)){
      c=c2;
      continue;
    }
    mark2[c2.x][c2.y]=0;
    //printf("remove mark %d %d\n",c2.x,c2.y);
  }
  for(int i=0;i<10;i++){
    for (int j = 0; j < 10; j++){
      if(mark[i][j]=='*'){
        if(mark2[i][j]){
          printf("%c",mark[i][j]);
        }else{
          printf("0");
        }
      }else{
        printf("%c",mark[i][j]);
      }      
    }
    printf("\n");
  }  
}
