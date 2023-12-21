#include "abc.h"
void push(Stack *s,Axis e){
  if(s->top<N*N){
    s->top++;
    s->block[s->top]=e;
  }
}
Axis pop(Stack *s){
  Axis temp={-1,-1};
  if(s->top>=0){
    temp=s->block[s->top];
    s->top--;    
  }
  return temp;
}
