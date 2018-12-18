#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
void ran(int arr[]){
    int x;
    while(1){
           /* Intializes random number generator */
        time_t t;
        srand((unsigned) time(&t));
        x=rand()%9;
        if(arr[x] ==0){
            arr[x]=1;
         //   printf("%d",x);
            break;
        }
    }

}

char gridChar(int i) {
 //   printf("%d\n",i);
    switch(i) {
        case 2:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}


void draw(int b[9]) {
        system("cls");
        int counter = 1;
      	puts("");
      	for(int i = 0;i < 9;i++)
        {
          printf(" %c ",gridChar(b[i]));
          if(counter < 3)
          {
            printf("| ");
          }
          else
          {
            printf("\n");
            printf("---+----+---\n");
            counter = 0;
          }
          counter ++;
        }
}

int win(const int board[9]) {
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}

/////////////////////////
long int findSize(char file_name[])
{
    // opening the file in read mode
    FILE* fp = fopen(file_name, "r");

    // checking if the file exist or not
    if (fp == NULL) {
        printf("File Not Found!\n");
        return -1;
    }


    long int res = 0;int c=0;
    while(1){
        if((c=fgetc(fp)) == EOF)
            break;
        if(c == '\n')
            res++;
    }

    fclose(fp);

    return res;
}


void computerMove(int board[9]) {
   // puts("am here");
    int i;
    FILE *f;
    int list[9]={0};
    char name[20]="new.txt";
    f=fopen("new.txt","r");
    FILE *f2=fopen("neg.txt","r");
    int hena=-1,adad=0;int flag=0;

    long int res = findSize(name);
   // printf("l=%ld\n\n\n\n\n",res);



    ///////////////////////////////////////////////////////////////*neg


   // printf("l=%ld\n\n\n\n\n",res);

    for(i=res;i>=0;i--)
    {
      //  memset(list, 0,9);
     //   printf("%d\n",i);
        hena=-1;
        flag=0;
        for(int g=0;g<9;g++)
            fscanf(f,"%1d",&list[g]);



      //      printf("%d == %d\n",main_space,b(list));/**/
            //yla bena wla 2yh :D
            adad=0;
            for(int f=0;f<9;f++){
                if(list[f]== board[f])
               //     printf("%d == %d\n",list[f],board[f]);
                    continue;
                else{
                    adad++;
                    if(list[f]==1)
                                            hena=f;
                    }
            }
                if(adad==1)
                    flag=1;
                else{
                    flag=0;
                     }


                if(flag == 1){
         //   puts("Ttttttt");
            if(adad == 1){
                if(board[hena] == 0){
            //   puts("from +");printf("%d\n",i);
              //  for(int iff=0;iff<9;iff++)//***************************************************************************************
                //    printf("%d",list[iff]);puts("");
                board[hena]=1;
                break;
                }
            }
        }
    }

   if(flag == 0){
    int rer=findSize("neg.txt");
  //  printf("%d",rer);
    for(i=rer;i>=0;i--)
    {
      //  memset(list, 0,9);
     //   printf("%d\n",i);
        hena=-1;
        flag=0;
        for(int g=0;g<9;g++)
            fscanf(f2,"%1d",&list[g]);
            adad=0;
            for(int f=0;f<9;f++){
                if(list[f]== board[f])
                    continue;
                else{
                    adad++;
                    }
                if(list[f]==2){
                    hena=f;
                    }

      //     printf("%d",adad);
            if(adad==2)
                flag=1;
            else
                flag=0;

        }
            if(adad == 2){
                if(board[hena] == 0){
         //       printf("from ned");


    //                   puts("from -");printf("%d\n",i);
      //         for(int iff=0;iff<9;iff++)//***************************************************************************************
        //           printf("%d",list[iff]);puts("");
                board[hena]=1;
                break;
                }
            }

        }

    }
       // puts("");
      //  for(int ir=0;ir<9;ir++){
        //    printf("%d",list[ir]);
       // }puts("");

     //   printf("%d>>%d/n",i,flag);
    //************************************
 //   draw(board);


    if(flag == 0){
   //     printf("R");
        ran(board);
    }
    fclose(f);
    fclose(f2);
}



void playerMove(int board[9],char player_turn[]) {
  int move ;
  do
  {
    start:
        printf("\n%s,Input move ([1..9]): ",player_turn);
        scanf("%d", &move);
        if(board[move-1] != 0)
        {
            printf("Its Already Occupied !");
            //printf("%d",board[move-1]);
            goto start;
        }
        printf("\n");
  } while (move > 9 || move < 0 );
  //count++;
  if(strcmp(player_turn,"P1") == 0)
  {
    board[move-1] = 2;
  }
  else if(strcmp(player_turn,"P2") == 0)
  {
    board[move-1] = 1;
  }
}
void turn (int player,int board[],char mode[])//Checks whose turn to play
{
  int turn;//door meen yel3ab
  char player_turn[3];//ya player 1 ya player 2.
  for(turn = 0; turn < 9 && win(board) == 0; turn++)
  {
      if((turn+player) % 2 == 0)//player here either represents Player 1 or just a player against the computer
      {
        if(strcmp(mode,"PVP") == 0 || strcmp(mode,"pvp") == 0 || strcmp(mode,"1") == 0)
        {
          draw(board);
          strcpy(player_turn,"P2");
          playerMove(board,player_turn);
        }
        else if(strcmp(mode,"PVC") == 0 || strcmp(mode,"pvc") == 0 || strcmp(mode,"2") == 0)
        {
            computerMove(board);
        }
      }
      else
      {
          draw(board);
          strcpy(player_turn,"P1");
          playerMove(board,player_turn);
      }
  }
}
int main() {
  char mode[4];
  int board[9] = {0},player = 0;
  printf("Enter your mode:\n");
  printf("      1.PVP     \n");
  printf("      2.PVC     \n");
  scanf("%s",mode);
  printf("\n");
  while(strcmp(mode,"PVP") != 0 && strcmp(mode,"pvp") != 0 && strcmp(mode,"PVC") != 0 && strcmp(mode,"pvc") != 0 && strcmp(mode,"1") != 0 && strcmp(mode,"2") != 0)
  {
      system("cls");
      printf("Enter your mode:\n");
      printf("      1.PVP     \n");
      printf("      2.PVC     \n");
      scanf("%s",mode);
      printf("\n");
  }
  if(strcmp(mode,"PVP") == 0 || strcmp(mode,"pvp") == 0 || strcmp(mode,"1") == 0)
  {
    printf("Player 1: X, Player 2: O\nPlayer 1 plays (1)st or (2)nd? ");
    scanf("%d",&player);//player represents here player 1
    printf("\n");
    turn(player,board,mode);
  }
  else if(strcmp(mode,"PVC") == 0 || strcmp(mode,"pvc") == 0 || strcmp(mode,"2") == 0)
  {
    printf("Computer: O, You: X\nPlay (1)st or (2)nd? ");
    scanf("%d",&player);//beyda55al enta 3ayez tebda2 el awal walla el computer, player represents here the player.
    printf("\n");
    turn(player,board,mode);
  }
    draw(board);
    draw(board);
    switch(win(board)) {
        case 0:
            printf("It's draw. How droll.\n");
            break;
        case 1:
            draw(board);
            if(strcmp(mode,"PVC") == 0 || strcmp(mode,"pvc") == 0 || strcmp(mode,"2") == 0)
            {
              printf("You lose.\n");
              FILE *fs=fopen("new.txt","a");
              for(int s=0;s<9;s++)
              {
                fprintf(fs,"%d",board[s]);
              }
                    fprintf(fs,"\n");
                    printf("data ++\n");
                    fclose(fs);
            }
            else if(strcmp(mode,"PVP") == 0 || strcmp(mode,"pvp") == 0 || strcmp(mode,"1") == 0)
            {
              printf("Player 2 wins.\n");
            }
            break;
        case 2:
        if(strcmp(mode,"PVC") == 0 || strcmp(mode,"pvc") == 0 || strcmp(mode,"2") == 0)
        {
            printf("You win. Inconceivable!\n");
            FILE *f2=fopen("neg.txt","a");
            for(int s=0;s<9;s++){
                fprintf(f2,"%d",board[s]);
                }
                fprintf(f2,"\n");
                fclose(f2);
                printf("but i Ml\n :p\n");
        }
        else if(strcmp(mode,"PVP") == 0 || strcmp(mode,"pvp") == 0 || strcmp(mode,"1") == 0)
        {
          printf("Player 1 wins.\n");
        }
            break;
    }
    printf("\n\t\t ©yousef and yahya(yojogo)\n");
    getch();
}
