#include <stdio.h>
#include <stdlib.h>


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

int minimax(int board[9], int player) {
    int winner = win(board);
    if(winner != 0) return winner*player;
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {//For all moves,
        if(board[i] == 0) {//If legal,
            board[i] = player;//Try the move

            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }
            board[i] = 0;//Reset board after try
        }
    }
    if(move == -1) return 0;
    return score;
}

void computer(int board[9]) {
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = 1;
            int tempScore = -minimax(board, -1);
                    //    draw(board);
            board[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    board[move] = 1;

  //  puts("k");
}

int main()
{
FILE *f=fopen("phone.txt","r");
//FILE *ff=fopen("go.txt","a");

for(int i=0;i<500;i++){
        int arr[9]={0};int board[9]={0};
        for(int j=0;j<9;j++){
            fscanf(f,"%1d",&arr[j]);
        }
        int mar=0;
        for(int j2=0;j2<9;j2++){
      //      printf("arr[%d]==%d\n",j2,arr[j2]);
            if(arr[j2]==2)
                mar++;
        }
    //    printf("mar =%d\n",mar);
        if(mar >4){
            continue;
        }
        for(int q=0;q<9;q++){
        //    printf(">>>%d\n",q);
            if(arr[q] == 2){
          //      printf("yes");
                if(board[q] == 0){
                    board[q]=-1;
                    computer(board);
                //    printf("g");


                }

            }
          //  fclose(ff);
        }
                            for(int qq=0;qq<9;qq++){
                        printf("%d",board[qq]);
                    }
                    printf("\n");
    }
    fclose(f);

}
