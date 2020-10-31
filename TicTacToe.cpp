#include<bits/stdc++.h>// contains every lib including iostream
#include<conio.h>
using namespace std;
int x,y,d;
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
//int count =0;
int checkwin();
void board();
void user();                  //function for user's move
void pc();                    //function for pc's move
int main()
{
    while(1)
    {int x,y,z;


        square[1]= '1';
        square[2]= '2';
        square[3]= '3';
        square[4]= '4';
        square[5]= '5';
        square[6]= '6';
        square[7]= '7';
        square[8]= '8';
        square[9]= '9';
        //cout<<square[k];
        cout << "----------------------------MENU-----------------------------"<<endl<<
                                          "     1. NEW GAME " << endl << "     2. EXIT "<<endl;
    cin >> z;
    if(z==1)
    {
        int u;
        cout << "---------------------------NEW GAME---------------------------" << endl;
        cout << "     1. SINGLE PLAYER" << endl << "     2. MULTIPALYER" << endl;
        cin >> u;
        if(u==1)
        {
            rand();                  //initialize random function calling
            int d=rand() %2 ;              //random function call
            // for(i=0;i<3;i++)
            //     for(j=0;j<3;j++)
            //     tic[i][j]=' ';        //assigning space ' ' to all elements of matrix
            board();                    //display function call
            d==0?user():pc();             //random starting of the game depending on d
            getch();                      //provides output by getting input without returning to program
            //return 0;                     //return int to main function
        }


















        else if(u==2)
                {
                    int player = 1,i,choice;

                    char mark;
                    do
                    {
                        board();
                        player=(player%2)?1:2;

                        cout << "Player " << player << ", enter a number:  ";
                        cin >> choice;

                        mark=(player == 1) ? 'X' : 'O';

                        if (choice == 1 && square[1] == '1')

                            square[1] = mark;
                        else if (choice == 2 && square[2] == '2')

                            square[2] = mark;
                        else if (choice == 3 && square[3] == '3')

                            square[3] = mark;
                        else if (choice == 4 && square[4] == '4')

                            square[4] = mark;
                        else if (choice == 5 && square[5] == '5')

                            square[5] = mark;
                        else if (choice == 6 && square[6] == '6')

                            square[6] = mark;
                        else if (choice == 7 && square[7] == '7')

                            square[7] = mark;
                        else if (choice == 8 && square[8] == '8')

                            square[8] = mark;
                        else if (choice == 9 && square[9] == '9')

                            square[9] = mark;
                        else
                        {
                            cout<<"Invalid move ";

                            player--;
                            cin.ignore();
                            cin.get();
                        }
                        i=checkwin();

                        player++;
                    }while(i==-1);
                    board();
                    if(i==1)

                        cout<<"==>\aPlayer "<<--player<<" win ";
                    else
                        cout<<"==>\aGame draw";

                    cin.ignore();
                    cin.get();
                }
        }
        else if (z==2)
        {
            return 0;
        }
        else
        {
            cout<<"******************INVALID CHOICE**********************"<<endl<<endl;
        }
                    //    count++;

}
    return 0;
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}



void board()
{
    system("cls");
    //Clrscr();
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}


void user()                  //user function definition
{ //int x;
    //("cls");
cout<<"ENTER THE CO-ORDINATES WHERE YOU WANT TO PUT UR 'X' ";
cin>>x;
if((x<1)||(x>9))  //check for valid co-ordinates
	{
	cout<<"ENTER THE CORRECT CO-ORDINATES";
	user();    //user function call
	}
else
	{
	if(square[x]!='X' && square[x]!='O')    //check for vacant space at entered co-ordinates
		{
	    square[x]='X';  //assigning user 'X' to the co-ordinates
		board();    //newdisp function call
		}
	else
		{
		cout<<"THIS POSITION IS ALREADY FILLED. CHOOSE SOME OTHER CO-ORDINATES"<<endl;
		user();       //user function call
		}
	}
d=checkwin();            //check function call
if(d==-1)
pc();                 //pc function call
else if(d==1)
	{
	cout<<"==> \a YOU WIN"<<endl;
	getche();     //requires enter to return to program. prevents return without display
	//exit(1);      //program termination
	}
    else
    {
        cout<<"==>\aGame draw"<<endl;
    }
}


void pc()          //pc function call
{
   // ("cls");
int f;
rand();       //initialize random function calling
cout<<"THIS IS THE COMPUTER'S MOVE "<< endl;
for(int i=0;i<=20;i++)
	{
	f=(rand()% 9) + 1;
	//z=rand()%3;
	if(square[f]!='X' && square[f]!='O')    //check for vacant space at entered co-ordinates
		{
		square[f]='O';  //assigning pc 'O' to the co-ordinates
		goto x;         //exiting for loop to display new tictactoe
		}
	else
	continue;               //
	}
x:board();                    //newdisp function call
cout << "COMPUTER PLAYED 'O' at " <<f<<endl;
d=checkwin();                      //check function call
if(d==-1)
user();                         //user function call
else if(d==1)
	{
	cout<<"==> \aCOMPUTER WINS"<<endl;
	getche();           //requires enter to return to program. prevents return without display
	//exit(1);            //program termination
	}
    else
    {
        cout<<"==>\aGame draw"<<endl;

    }

}


