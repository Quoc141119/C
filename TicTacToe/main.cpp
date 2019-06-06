#include <cstdlib>
#include <iostream> 
using namespace std;


// change do kho cua game
const int maxarray = 10;
int sizearray = 100; 

int welcome(){
	int c;
	cout<<"Welcome To Tic-tac-toe game! Play with your way!\n";
	cout<<"If you find any problem, please contact john.nguyen@gameloft.com\n";
	cout<<"\nSELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): ";
	cin>>c;
	return c;
}

void showarray(char a[maxarray][maxarray]){
	for(int i=0;i<maxarray;i++){
		for(int j=0;j<maxarray;j++){
			if(a[i][j]!='X' && a[i][j]!='O')
				cout<<"-"<<"  ";
			else
				cout<<a[i][j]<<"  ";
		}		
		cout<<endl;
	}
}

//check vi tri danh co hop le khong
int check_dd(char a[maxarray][maxarray], int b){
	if(b/10>(maxarray-1) || b/10<0 || b%10>(maxarray-1)){
		cout<<"khong xac dinh duoc vi tri\n";
		return 0;
	}
	if(a[b/10][b%10]=='X' || a[b/10][b%10]=='O'){
		cout<<"Vi tri da duoc chon\n";
		return 0;
	}
	return 1;
}

int checkwin(char a[maxarray][maxarray], int b, int c){
	char x;
	int check = 1;
	
	if(c%2==0)
		x ='O';
	else
		x ='X';	
	
	//check ngang	
	for(int j = 0; j<maxarray; j++){
		if(a[b/10][j]!=x){
			check = 0;
			break;
		}			
	}
	
	//check doc
	if(check == 0){
		check = 1;
		for(int j = 0; j<maxarray; j++){
			if(a[j][b%10]!=x){
				check = 0;
				break;
			}			
		}
	}
	
	//check cheo
	if(check == 0){
		if(b%10==b/10){	
			check = 1;
			for(int j=0; j<maxarray; j++){
				if(a[j][j]!=x){
					check = 0;
					break;
				}			
			}		
		}
	}
	
	if(check == 0){
		if((b%10)+(b/10)==maxarray-1){
			check = 1;
			for(int j=0; j<maxarray; j++){
				if(a[j][maxarray-1-j]!=x){
					check = 0;
					break;
				}			
			}	
		}	
	}
	
	return check;
}

int main(int argc, char** argv) {
	char a[maxarray][maxarray];
	char player1[20], player2[20];
	int win = 0;
	
	if(welcome()==1){
		cout<<"Enter Player 1 Name: ";
		cin>>player1;
		cout<<"Enter Player 2 Name: ";
		cin>>player2;
		for(int i=0; i<sizearray; i++){
			system("cls");
			showarray(a);
			int arr;
			if(i%2==0){
				do{
					cout<<"Your Turn "<<player1<<" - O: ";
					cin>>arr;
				}while(check_dd(a,arr)==0);
				a[arr/10][arr%10]='O';
				system("cls");
				showarray(a);
				if(checkwin(a,arr,i) == 1){
					cout<<player1<<" WIN\n";
					cout<<"CHUC MUNG NHE !!!";
					win = 1;
					break;
				}
			}
			else{
				do{
					cout<<"Your Turn "<<player2<<" - X: ";
					cin>>arr;
				}while(check_dd(a,arr)==0);
				a[arr/10][arr%10]='X';
				system("cls");	
				showarray(a);
				if(checkwin(a,arr,i) == 1){
					cout<<player2<<" WIN\n";
					cout<<"CHUC MUNG NHE !!!";
					win = 1;
					break;
				}
			}
		}
	}
	
	if(win==0)
		cout<<"HOA ROI NHE !!!";
		
	return 0;
}
