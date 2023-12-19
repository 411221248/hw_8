#include <stdio.h>
#include <string.h>
#include "abc.h"

char maze[N][N]={
  { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
  { '0', '0', '0', '1', '1', '0', '1', '1', '0', '1' },
  { '1', '0', '1', '1', '0', '0', '0', '0', '0', '1' },
  { '1', '0', '0', '0', '0', '1', '0', '1', '0', '1' },
  { '1', '1', '1', '0', '1', '1', '0', '1', '1', '1' },
  { '1', '0', '1', '1', '1', '0','0', '1', '0', '1' },
  { '1', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
  { '1', '0', '1', '1', '1', '1', '1', '0', '0', '1' },
  { '1', '0', '0', '0', '0', '0', '0', '0', '1', '1' },
  { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' }
};
char mark[N][N];
void push(Stack *s,Axis e){
  s->top++;
  s->block[s->top]=e;
}
Axis pop(Stack *s){
  Axis temp={-1,-1};
  if(s->top>=0){
    temp=s->block[s->top];
    s->top--;    
  }
  return temp;
}
Axis findMove(Stack *s,Axis c){
  for(int dx=-1;dx<2;dx++){
    for(int dy=-1;dy<2;dy++){
      if(dx*dy==0&&(dx!=0||dy!=0)){
          Axis space;
          space.x=c.x+dx;
          space.y=c.y+dy;
          if(space.x>=0&&space.y>=0&&space.x<N&&space.y<N){
            if(maze[space.x][space.y]=='0' && mark[space.x][space.y]!='*'){
              mark[space.x][space.y]='*';
              push(s,space);
            
            }
          }
          
      }
    }
  }
  return pop(s);
}
int main(){
  Axis start,end,current,noExit={-1,-1};
  Stack stack;
  stack.top=-1;
  memcpy(mark,maze,sizeof(mark));
  printf("start:");
  scanf("%d %d",&start.x,&start.y);
  printf("end:");
  scanf("%d %d",&end.x,&end.y);
  current=start;
  mark[current.x][current.y]='*';
  while(!EQU(current,end)){
    current=findMove(&stack,current);
    if(EQU(current,noExit)){
      printf("NO EXIT\n");
      return 0;
    }
    printf("move to %d %d\n",current.x,current.y);
  }
  for(int i=0;i<10;i++){
    for (int j = 0; j < 10; j++){
      printf("%c",mark[i][j]);
    }
    printf("\n");
  }
  
}
