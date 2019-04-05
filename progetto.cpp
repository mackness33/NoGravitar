#include <iostream>
#include <conio.h>
using namespace std;

/*
	link utili:
		-> https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns
		-> https://docs.microsoft.com/en-us/windows/desktop/inputdev/keyboard-input
*/
int main(){
	int ciao;

	char matrice [10][20];

	for(int i=0;i<10;i++)
		for(int j=0;j<20;j++)
			matrice [i][j]=' ';

	int p1=5,p2=10;
	matrice [p1][p2]='O';

	char n;

	while(1){

		system("cls");

		for(int i=0;i<10;i++){
			for(int j=0;j<20;j++)
				cout << matrice[i][j] << " ";

			cout<< "\n";
		}

		n=getch();

		if(n=='a'){
			matrice[p1][p2]=' ';
			p2=p2-1;
			matrice[p1][p2]='O';
		}
		else if(n=='d'){
			matrice[p1][p2]=' ';
			p2=p2+1;
			matrice[p1][p2]='O';
		}
		else if(n=='w'){
			matrice[p1][p2]=' ';
			p1=p1-1;
			matrice[p1][p2]='O';
		}
		else if(n=='s'){
			matrice[p1][p2]=' ';
			p1=p1+1;
			matrice[p1][p2]='O';
		}

	}

	return 0;
}
