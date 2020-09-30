#include <stdio.h>
#include <stdlib.h>
char num[9]={'1','2','3','4','5','6','7','8','9'};
void p1 ();
void p2 ();
void pattern (char a[]);
int win1(char a[]);
int count=0;//tie condition
int turn[9]={0};

int main()//driver code
{

    pattern(num);
    p1();

    return 0;
}
void pattern(char a[])
{
     int i,j;
     system("cls");
     printf("\t\t\t\t\t tic tac toe game\n");
     printf(" player1-x\tplayer2-o\n");

    for(i=0;i<7;i+=3)
    {
       for(j=i;j<=(i+2);j++)
       {
          printf("%c|",a[j]);
       }
       printf("\n");
    }
}
void p1() //player1
{
  int index,i,loc;
  printf("turn of player1 ");
  scanf("%d",&loc);//c4
  index=loc-1;//c2
  if(turn[index]==0){
  turn[index]=1;
  num[index]='x';
    pattern(num);
     if(win1(num)==1)
       printf(" \nplayer1 wins!!!");
       else if( count==8)
       {
           printf(" \n it's a tie");//////
       }
       else
        p2();
  }
  else{
      printf("\ninvalid move");
    p1();
  }
}
int win1(char a[]) //win condition
{
    int i;
    count++;
    //rows
     for(i=0;i<=6;i+=2)
    {
        if( a[i]==a[i+1] && a[i]==a[i+2] && a[i+1]==a[i+2])
        {
            return (1);
        }
    }
    //column
     for(i=0;i<=2;i++)
    {
        if( a[i]==a[i+3] && a[i]==a[i+6] && a[i+3]==a[i+6])
        {

            return 1;
        }
    }
    //diagonal
    if( (a[0]==a[4] && a[0]==a[8] && a[4]==a[8]) || ( a[2]==a[4] && a[2]==a[6] && a[4]==a[6]))

    return 1;


}

void p2() //player2
{
  int index,i,loc;
  printf("turn of player2 ");
  scanf("%d",&loc);//c3
  index=loc-1; //c1
  if(turn[index]==0){
        turn[index]=1;
    num[index]='o';
    pattern(num);
    if(win1(num)==1)
       printf(" \nplayer2 wins!!!");
       else
        p1();
  }
  else{
        printf("\ninvalid move ");
        p2();
  }
}


