#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int x,y;
  char dir;
}position;
typedef enum{
  FALSE=0,TRUE=1
}Boolean;
typedef struct{
  int size;
  int top;
  position *element;
}stack;
stack *createS(int size){
  stack *s;
  s=(stack*)malloc(sizeof(stack));
  s->size=size;
  s->element=(position*)malloc(size*sizeof(position));
  s->top=-1;
  return s;
}
void push(stack *s,position e){
  if(!IsFull(s)){
    s->top++;
    s->element[s->top]=e;
  }
}
position pop(stack *s){
  position i;
  if(!IsEmpty(s)){
    i=s->element[s->top];
    s->top--;
    return i;
  }
}
Boolean IsFull(stack *s){
  if(s->top==s->size-1)
  return TRUE;
  else
  return FALSE;
}
Boolean IsEmpty(stack *s){
  if(s->top==-1)
  return TRUE;
  else
  return FALSE;
}
int main()
{
  int t,cases;
  scanf("%d",&cases);     //input test case

  for(t=0;t<cases;t++){
    int col,row,i,j,k,test,entryX,entryY,exitX,exitY,next_x,next_y,success,temp;
    int mark[100][100];
    char bin,next_dir;
    char maze[100][100],output[100];
    char dir[4]={'N','W','S','E'};
    position pos;
    stack *mystack;
    mystack=createS(100);
    scanf("%d%d",&col,&row);     //input size of maze
    scanf("%c",&bin);     //input Enter
    for(i=0;i<row;i++){
      for(j=0;j<col;j++){
        scanf("%c",&maze[i][j]);   //input maze
        scanf("%c",&bin);     //input space and Enter
      }
    }
    for(i=0;i<row;i++){
      for(j=0;j<col;j++){
        mark[i][j]=0;     //initialize mark
      }
    }
    for(i=0;i<row;i++){
      for(j=0;j<col;j++){
        if(maze[i][j]=='E'){
          entryX=i;     //locate entry
          entryY=j;
        }
        if(maze[i][j]=='X'){
          exitX=i;     //locate exit
          exitY=j;
        }
      }
    }
    pos.x=entryX;     //initialize pos
    pos.y=entryY;
    pos.dir='N';
    push(mystack,pos);     //initialize stack
    success=0;     //initialize success
    while(!IsEmpty(mystack)&&success==0){
      pos=pop(mystack);
      mark[pos.x][pos.y]=1;
      test=0;
      while(test<4&&success==0){
        next_dir=dir[test];
        pos.dir=next_dir;
        switch(next_dir){
          case'N':
          next_x=pos.x-1;
          next_y=pos.y;
          break;
          case'W':
          next_x=pos.x;
          next_y=pos.y-1;
          break;
          case'S':
          next_x=pos.x+1;
          next_y=pos.y;
          break;
          case'E':
          next_x=pos.x;
          next_y=pos.y+1;
          break;
        }
        if((next_x==exitX)&&(next_y==exitY)){
          temp=mystack->top;
          for(k=temp;k>=0;k--)
          output[k]=pop(mystack).dir;
          for(k=0;k<=temp;k++)
          printf("%c",output[k]);
          printf("%c\n",next_dir);
          success=1;
        }
        else if((maze[next_x][next_y]=='0')&&(mark[next_x][next_y]==0)){
          mark[next_x][next_y]=1;
          push(mystack,pos);
          pos.x=next_x;
          pos.y=next_y;
          test=0;
        }
        else
        test++;
      }
    }
    if(success==0)
    printf("No-answer\n");
  }
  return 0;
}
