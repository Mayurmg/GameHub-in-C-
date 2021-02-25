#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
#include"casino.h"
using namespace std;
 const int MAX_TRIES=5;
int letterFill (char, string, string&);
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();

/*void hangagain()
{
    int a;
    cout<<"\nDo you want to play another round of this??";
    cout<<"\nPress 1 to play again and 2 for menu:";
    cin>>a;
    if(a==1)
    {hangman();}
    else{menu();}
}
void againtic()
{
    int a;
    cout<<"\nDo you want to play another round of this??";
    cout<<"\nPress 1 to play again and 2 for menu:";
    cin>>a;
    if(a==1)
    {tictac();}
    else{menu();}
}*/

char hangman()
{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
		"india",
		"pakistan",
		"nepal",
		"malaysia",
		"philippines",
		"australia",
		"iran",
		"ethiopia",
		"oman",
		"indonesia"
	};


	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];

	// Initialize the secret word with the * character.
	string unknown(word.length(),'*');


	cout << "\n\nWelcome to hangman...Guess a country Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Bad luck!! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "Good going...You found a letter! " << endl;
		}
		// Tell user how many guesses has left.
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if user guessed the word.
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
//	hangagain();
//	menu();
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
	}
//	hangagain();
//menu();
	cin.ignore();
	cin.get();
	return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
void tictac()
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

  //  againtic();
//  menu();
    cin.ignore();
    cin.get();

}

/*
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**/

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


/*
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
**/


void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
   cout << endl;
cout<<" --------"<<"--"<<"--"<<"--"<<"--"<<"--" <<endl;
cout << " | | " <<"--"<<"--"<<"--"<<"--"<<"--"<< " | | " <<endl;
cout << " | | " << square[1] << " | " << square[2] << " | " << square[3] <<" "<< " | | " << endl;
cout << " | | " <<"         "<<" "<< " | | " <<endl;
cout << " | | " <<"         "<<" "<< " | | " <<endl;
cout << " | | " << square[4] << " | " << square[5] << " | " << square[6] << " "<< " | | " <<endl;
cout << " | | " <<"         "<<" "<< " | | " << endl;
cout << " | | " <<"         "<<" "<< " | | " << endl;
cout << " | | " << square[7] << " | " << square[8] << " | " << square[9] << " "<< " | | " <<endl;
cout<<" ----------"<<"--"<<"--"<<"--"<<"--"<<endl;
cout<<" --------"<<"--"<<"--"<<"--"<<"--"<<"--" <<endl;
cout << endl << endl;
}
void menu()
{
    int choose;
cout<<"\n\nwhich game do you want to play";
cout<<"\n   1.TIC TAC TOE";
cout<<"\n   2.HANGMAN";
cout<<"\n   3.CASINO";
cout<<"\n   4.EXIT";
cout<<"\n\nenter your choice";
cin>>choose;
switch(choose)
{
    case 1: {system("cls");
        tictac();
        system("cls");
             menu();  }
    case 2: {system("cls");

        hangman();
        system("cls");
            menu();}
    case 3: {system("cls");
               casinno();
               system("cls");
               menu();}
    case 4: {exit(0);}
    default: cout<<"\nwrong input!!!!!";
    menu();
}
}



int main()
{
    cout<<endl<<endl;
    cout<<"                 ||---------------------|| "<<endl;
    cout<<"                 || :-) GAMING HUB (-:  || "<<endl;
    cout<<"                 ||_____________________||"<<endl;
    cout<<"                 ||_____________________||"<<endl;
    menu();
return 0;
}
