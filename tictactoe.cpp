#include<stdio.h>
#include<iostream>
using namespace std;

int board[3][3];

void printboard(){
	int i,j;
	printf("\nCurrent board:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		printf("\t%2d",board[i][j]);
		printf("\n");
	}
		
}

int wincond(int num,int play){
	int row=num/3;
	int col=num%3;
	int rc=0,cc=0,ldc=0,tdc=0;
	int itr,i,j;
	
	//same row
	for(itr=0;itr<3;itr++){
		if(board[row][itr]==play)
		rc++;
	}
	//same column
	for(itr=0;itr<3;itr++){
		if(board[itr][col]==play)
		cc++;
	}
	
	//leading diagonal
	for(i=0;i<3;i++){
		if(board[i][i]==play)
		ldc++;
	}
	
	//trailing diagonal
	for(i=0;i<3;i++){
		if(board[i][2-i]==play)
		tdc++;
	}
	
	
	//final condition check
	if(rc==3||cc==3||ldc==3||tdc==3)
	return 1;
	else
	return 0;
	
	
}

main(){
	int player=1,moves=0;
	int i,j,ch,win;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		board[i][j]=0;
	}
	
	printf("\nLet's play!");
	printboard();
	
	while(moves<9){
		printf("\n Player %d enter number from 1-9:",player);
		scanf("%d",&ch);
		ch=ch-1;
		if(board[ch/3][ch%3]==0){
			board[ch/3][ch%3]=player;
			printboard();
			win=wincond(ch,player);
			if(win==1){
				printf("\nCongrats player %d",player);
				break;
			}
			moves+=1;
			player=3-player;
		}
		else{
			printf("\n Please enter valid move");
			printboard();
		}
		
		if(moves==9)
		printf("\nThe match is tied");
	}
	
	//printboard();
}
