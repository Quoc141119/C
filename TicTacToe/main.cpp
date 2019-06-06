#include <cstdlib>
#include <iostream> 
using namespace std; 


int welcome(){
	int c;
	cout<<"Welcome To Tic-tac-toe game! Play with your way!\n";
	cout<<"If you find any problem, please contact john.nguyen@gameloft.com\n";
	cout<<"\nSELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): ";
	cin>>c;
	return c;
}

void show(char a[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<a[i][j]<<"  ";
		}		
		cout<<endl;
	}
}

int check_dd(char a[3][3], int b){
	if(b/10>2 || b/10<0 || b%10>2){
		cout<<"khong xac dinh duoc vi tri\n";
		return 0;
	}
	if(a[b/10][b%10]!='*'){
		cout<<"Vi tri da duoc chon\n";
		return 0;
	}
	return 1;
}


int checkwin(char a[3][3], int b, int c){
	char x;
	int check = 1;
	
	if(c%2==0)
		x ='O';
	else
		x ='X';	
	
	//check ngang	
	for(int j = 0; j<3; j++){
		if(a[b/10][j]!=x){
			check = 0;
			break;
		}			
	}
	
	//check doc
	if(check == 0){
		check = 1;
		for(int j = 0; j<3; j++){
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
			for(int j=0; j<3; j++){
				if(a[j][j]!=x){
					check = 0;
					break;
				}			
			}		
		}
	}
	
	if(check == 0){
		if((b%10)+(b/10)==2){
			check = 1;
			for(int j=0; j<3; j++){
				cout<<"xu ly check cheo\n";
				if(a[j][2-j]!=x){
					check = 0;
					break;
				}			
			}	
		}	
	}
	
	return check;
}

int main(int argc, char** argv) {
	char a[3][3]={'*','*','*','*','*','*','*','*','*'};
	char player1[20], player2[20];
	int win = 0;
	
	if(welcome()==1){
		cout<<"Enter Player 1 Name: ";
		cin>>player1;
		cout<<"Enter Player 2 Name: ";
		cin>>player2;
		for(int i=0; i<9; i++){
			system("cls");
			show(a);
			int arr;
			if(i%2==0){
				do{
					cout<<"Your Turn "<<player1<<" - O: ";
					cin>>arr;
				}while(check_dd(a,arr)==0);
				a[arr/10][arr%10]='O';
				system("cls");
				show(a);
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
				show(a);
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
