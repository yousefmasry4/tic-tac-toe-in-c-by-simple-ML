#include <stdio.h>
#include <string.h>
void reco(char arr[]){
    char you[9];
    you[6]=arr[0];
    you[7]=arr[3];
    you[8]=arr[6];
    you[3]=arr[1];
    you[4]=arr[4];
    you[5]=arr[7];
    you[0]=arr[2];
    you[1]=arr[5];
    you[2]=arr[8];
    strcpy(arr,you);
    }

int main(){
    char arr[9];
    FILE *fd=fopen("new.txt","w");
    FILE *f=fopen("data.txt","r");
    for(int i=0;i<669;i++){
	fscanf(f,"%s",arr);
    	puts(arr);
        reco(arr);
        fprintf(fd,"%s\n",arr);
       // break;
	}
    fclose(f);
    
}
