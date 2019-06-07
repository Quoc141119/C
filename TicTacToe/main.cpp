#include <cstdlib>
#include <iostream> 
#include <iomanip>
#include <math.h>
using namespace std;


// change do kho cua game
const int maxarray = 5;
int sizearray = pow(maxarray,2); 
char array[maxarray][maxarray];
char player1[20], player2[20];

//comfirm to play 
int welcome(){
	int mode;
	cout<<"Welcome To Tic-tac-toe game! Play with your way!\n";
	cout<<"If you find any problem, please contact john.nguyen@gameloft.com\n";
	cout<<"\nSELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): ";
	cin>>mode;
	return mode;
}

//show array
void showarray(char *array){
	for(int i=0;i<maxarray;i++){
		for(int j=0;j<maxarray;j++){
			if(*array!='X' && *array!='O')	
				cout<<setw(4)<<"-";
			else
				cout<<setw(4)<<*array;
			array++;
		}
		cout<<endl<<endl;
	}
}

//check point
int checkpoint(char array[maxarray][maxarray], int point){
	
	if(point/10>(maxarray-1) || point<0 || point%10>(maxarray-1)){
		cout<<"khong xac dinh duoc vi tri\n";
		return 0;
	}
	
	if(array[point/10][point%10]=='X' || array[point/10][point%10]=='O'){
		cout<<"Vi tri da duoc chon\n";
		return 0;
	}
	
	return 1;
}

//check winer 
int checkwin(char array[maxarray][maxarray], int point, int idsign){
	char sign;
	int check = 1;
	
	if(idsign%2==0)
		sign ='O';
	else
		sign ='X';	
	
	//check row	
	for(int j = 0; j<maxarray; j++){
		if(array[point/10][j]!=sign){
			check = 0;
			break;
		}			
	}
	
	//check column
	if(check == 0){
		check = 1;
		for(int j = 0; j<maxarray; j++){
			if(array[j][point%10]!=sign){
				check = 0;
				break;
			}			
		}
	}
	
	//check cheo
	if(check == 0){
		if(point%10==point/10){	
			check = 1;
			for(int j=0; j<maxarray; j++){
				if(array[j][j]!=sign){
					check = 0;
					break;
				}			
			}		
		}
	}
	
	//check cheo
	if(check == 0){
		if((point%10)+(point/10)==maxarray-1){
			check = 1;
			for(int j=0; j<maxarray; j++){
				if(array[j][maxarray-1-j]!=sign){
					check = 0;
					break;
				}			
			}	
		}	
	}
	
	return check;
}

//player1 play
int player1play(int idsign){
	int win = 0;
	int point;
	
	do{
		cout<<"Your Turn "<<player1<<" - O: ";
		cin>>point;
	}while(checkpoint(array,point)==0);
	
	array[point/10][point%10]='O';
	system("cls");
	showarray(*array);
	
	if(checkwin(array,point,idsign) == 1){
		cout<<player1<<" WIN\n";
		cout<<"CHUC MUNG NHE !!!\n";
		win = 1;
	}
	
	return win;
}

//player2 play
int player2play(int idsign){
	int win = 0;
	int point;
	
	do{
		cout<<"Your Turn "<<player2<<" - X: ";
		cin>>point;
	}while(checkpoint(array,point)==0);
	
	array[point/10][point%10]='X';
	system("cls");	
	showarray(*array);

	if(checkwin(array,point,idsign) == 1){
		cout<<player2<<" WIN\n";
		cout<<"CHUC MUNG NHE !!!\n";
		win = 1;
	}
	
	return win;
}

//start play
void play(){
	int win;
	
	cout<<"Enter Player 1 Name: ";
	cin>>player1;
	cout<<"Enter Player 2 Name: ";
	cin>>player2;
	
	//so chan thi player1 play and so le thi player2 play
	for(int i=0; i<sizearray; i++){
		system("cls");
		showarray(*array);
		
		if(i%2==0){    	//player1 play
			win = player1play(i);
			if(win == 1)
				break;
		}
		else{			//player2 play
			win = player2play(i);
			if(win == 1)
				break;
		}
	}

	if(win==0)
		cout<<"HOA ROI NHE !!!\n";
}

int main(int argc, char** argv) {
	if(welcome()==1)
		play();			
	return 0;
}
