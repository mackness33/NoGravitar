#include <iostream>
#include <curses.h>

using namespace std;

int main(void){
	initscr();			/* Start curses mode 		  */
	cout << "Hello World !!!" << endl;	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
	return 0;
}
