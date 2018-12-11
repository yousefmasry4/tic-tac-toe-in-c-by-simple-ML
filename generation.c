#include <stdio.h>
#include <stdlib.h>

void ran(int arr[]){
    int x;
    while(1){
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

int b(int arr[]){
    int b=0;
    for(int k=0;k<9;k++){
        if(arr[k]==0)
            b++;
    }
    return b;
}

void draw(int b[9]) {
	system("clear");
	puts("");
    printf(" %c | %c | %c\n",gridChar(b[6]),gridChar(b[7]),gridChar(b[8]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",gridChar(b[3]),gridChar(b[4]),gridChar(b[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",gridChar(b[0]),gridChar(b[1]),gridChar(b[2]));
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

    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    long int res = ftell(fp);

    // closing the file
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
    int main_space=b(board);
    int hena=-1,adad=0;int flag=0;

    long int res = findSize(name)/10;
   // printf("l=%ld\n\n\n\n\n",res);



    ///////////////////////////////////////////////////////////////*neg

    res = findSize("neg.txt")/10;
   // printf("l=%ld\n\n\n\n\n",res);

    for(i=res;i>=0;i--)
    {
      //  memset(list, 0,9);
     //   printf("%d\n",i);
        hena=-1;
        flag=0;
        for(int g=0;g<9;g++)
            fscanf(f,"%1d",&list[g]);


       //     printf("data:%d\n",list[0]);//system("clear");
        if(main_space==1+b(list)){

      //      printf("%d == %d\n",main_space,b(list));/**/
            //yla bena wla 2yh :D
            adad=0;
            for(int f=0;f<9;f++){
                if(list[f]== board[f])
               //     printf("%d == %d\n",list[f],board[f]);
                    continue;
                else{
         //        printf("%d != %d\n",list[f],board[f]);
                    if(list[f]==1){
                        adad++;
                        if(adad=1)
                            flag=1;
                        else
                            flag=0;
                        hena=f;
                        }
                    }


            }

                if(flag == 1){
         //   puts("Ttttttt");
            if(adad == 1){
                if(board[hena] == 0){
                board[hena]=1;
                break;
                }
            }
        }



            }

            }

   if(flag == 0){
    int rer=findSize("neg.txt")/10;
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
            }
      //      printf("%d",adad);
            if(adad==2)
                flag=1;
            else
                flag=0;

    if(flag == 1){
     //       puts("i am in negative");

                    puts("");
        for(int ir=0;ir<9;ir++){
            printf("%d",list[ir]);
        }puts("");



            if(adad == 2){
                if(board[hena] == 0){
                board[hena]=1;
                break;
                }
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
        printf("R");
        ran(board);
    }
    fclose(f);
    fclose(f2);
}



void playerMove(int board[9]) {
int move ;
    do {
    start:
        printf("\nInput move ([1..9]): ");
        scanf("%d", &move);
       // printf("you enter %d\n",move);
        if(board[move-1] != 0) {
            printf("Its Already Occupied !");
            printf("%d",board[move-1]);
            goto start;
        }
        printf("\n");
    } while (move > 8 && move < 0 );
        board[move-1] = 2;
        move--;
        draw(board);

}

int main() {
    int board[9] = {0};
    printf("Computer: O, You: X\nPlay (1)st or (2)nd? ");
    int player=0;
    scanf("%d",&player);
    printf("\n");
    int mini=0,maxx=0;
    unsigned turn;
    for(turn = 0; turn < 9 && win(board) == 0; ++turn) {
        if((turn+player) % 2 == 0)
            computerMove(board);
        else {
            draw(board);
            playerMove(board);
         //   printf("\n%d /////////////////////// %d\n",mini,maxx);
        }
    }
    switch(win(board)) {
        case 0:
            printf("A draw. How droll.\n");
            break;
        case 1:
            draw(board);
            printf("You lose.\n");
            break;
        case 2:
            printf("You win. Inconceivable!\n");
            FILE *f2=fopen("neg.txt","a");
            for(int s=0;s<9;s++){
            //    printf("%d",board[s]);
                fprintf(f2,"%d",board[s]);
                }
                fprintf(f2,"\n");
                fclose(f2);
                printf("but i Ml\n :p\n");

            break;
    }
}
