#ifndef __ABC_H__
#define __ABC_H__

#define N 10
#define EQU(a,b) (a.x==b.x && a.y==b.y)

typedef struct {
    int x;
    int y;
}Axis;

typedef struct {
    Axis block[N*N];
    int top;
}Stack;
void push(Stack *s,Axis e);
Axis pop(Stack *s);
#endif
