

// Library "cricket.h"

/*  
	NOTE:		The library contains some common function realted to cricket like team selection,
				player selection and toss.

*/


#include<iostream>
#include<string>			
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

using namespace std;


/*			functions defined in this library are
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void total_teams(void);													// function to print the available teams
int check_team(string team);											// function to check if user selected correct team
void team_players (string team, string t_players[] , int size);		// function to select the players of team selected by user
string toss(string choice,string team1, string team2);					// function for "toss"
void toss_decision( string toss_winner, string &team1, string &team2);	// fucntion to get the decision of team winning the toss


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



fstream TEAM;			// creates a global object for file streaing named as "TEAM"




// definations of functions


//		function to read and print the names of available teams from file "total_teams.txt"

void total_teams(void)
{

	string team="0";		// variable to store the names of teams
	

	// open the file "total_teams.txt" in input mode

	TEAM.open("total_teams.txt",ios::in);	
	

	//	if it does not opens print an error message

	if(!TEAM)
	{
		cout<<"\n\nError in opening \"total_teams.txt\"";
	}
	

	// read and getlines from file and store it in string variable until "End of File" is reached

	while( !TEAM.eof() )
	{
		getline(TEAM,team);
		cout<<team<<endl;			// print the names of teams just read from file
		
	}

	TEAM.close();		// close the file

}		// end of body of function "total_teams"

//........................................................................................................



// function to check if user entered a valid team name

int check_team(string team)
{
	string temp="0";		// variable to store string temporarily
	

	// open the file "teams.txt" in input mode

	TEAM.open("teams.txt",ios::in);	
	
	// if it does not opens print an error message

	if(!TEAM)
	{
		cout<<"\n\nError in opening \"teams.txt\"";
	}

	// read and getlines from file and store it in string variable until "End of File" is reached

	while( !TEAM.eof() )
	{
		getline(TEAM,temp);		// get data line by line and store in "temp"
		
		
		// if value stored in "temp" is equal to team name entered by user then that team is available

		if(temp==team)
			{
				TEAM.close();
				return 1;			// return 1 indicating postive result
			}

	}

	TEAM.close();			// close the file

	return 0;				// and return 0 indicating negative result


}			// end of body of function "check_team"


//........................................................................................................



// function to get the player names of the team selected by user


void team_players (string team, string t_players[] , int size)
{
	
	string temp="0";		// variable to store string temporarily


	// open the file "players.txt" in input mode

	TEAM.open("players.txt",ios::in);	
	
	// if file does not opened print an error message

	if(!TEAM)
	{
		cout<<"\n\nError in opening \"players.txt\"";
	}
	
	// read and getlines from file and store it in string variable until "End of File" is reached
	
	while( !TEAM.eof() )
	{
		
		getline(TEAM,temp);
		
		if(temp==team)			// if value stored in "temp" is equal to team name entered by user then 
		{

			// read the names of players from file and store it in array 

			for (int counter=0 ; counter<size  ; counter++)
			{
				getline(TEAM,t_players[counter]);
			
			}		// end of for loop
		
		}			// end of body of if statement
		
	}			// end of body of while statement 

	TEAM.close();		// close the file at end
	
}			// end of body of function team_players 



//........................................................................................................

//			function for "Toss" of the match

string toss(string choice,string team1, string team2)
{
	
	int random_num=0;		// variable to store the random number generated
	
	// seed the rand() with time(0) and convert type of "time(0)" to "unsigned int"

	srand  (static_cast <unsigned int >(time(0)) );		

	random_num=rand()%2;		// generate the random number with scaling factor of '2'
	
	cout<<"\n\n"<<setfill('*')<<setw(80);			

	if(choice=="head")		// if team 2 has selected "head"
	{
		if(random_num==0)	// and random generated is '0' then 
		{
							// team 2 wins
			cout<<"\n\n"<<team2<<" has won the toss!\n";
			return team2;	// return team2
				
		}
		else				// else random number is '1'
		{ 
							// so team 1 wins
			cout<<"\n\n"<<team1<<" has won the toss!\n";
			return team1;	// return team1
		}
	}
	
	
	else if(choice=="tail")		// if team 2 has selected "tail"
	{
		if(random_num==1)		// and random generated is '1' then
		{ 
								// team 2 wins
			cout<<"\n\n"<<team2<<" has won the toss!\n";
			return team2;		// return team2
		}
		else					// else random number will be '0'
		{						
								// team 1 wins
			cout<<"\n\n"<<team1<<" has won the toss!\n";
			return team1;		// return team 1
		}
	}
	return "line#148";			// return "line#148" in other cases


}				// end of body of function "toss"



//........................................................................................................


// fuction to get the decision of team winning the 'toss'

void toss_decision( string toss_winner, string &team1, string &team2)
{
	
	string decision="\0";		// variable to store the decision of team 

		// prompt the team winning the toss for choice

	cout<<"\n\nWill "<<toss_winner<<" Bat first or Bowl first?\n\nBowl(ball) or Bat(bat) : ";


TOSS_DECISION:
	
	cin>>decision;		// input the choice of "toss_winner"


	// if choice is neither "bat" nor "ball" then it is invalid

	if (!( decision=="bat" || decision=="ball" ))
	{
		// prompt an error message

		MessageBox(0,"Error! Select \"ball\"or \"bat\"", "Coin Face", MB_OK );
		goto TOSS_DECISION;		// go to label "TOSS_DECISION" and get the decison again
	}


	if(decision=="bat")		// if decision is "bat"
	{
		if(toss_winner==team2)		// and "toss_winner" is team 2 then swap the team names
		{
			toss_winner=team1;		//	.....
			team1=team2;			//	swapping is being done in these steps
			team2=toss_winner;		//	.....
		
		}
	
	}
	else if(decision=="ball")		// if decision is "ball"
	{
		if(toss_winner==team1)		// and "toss_winner" is team 1 then swap the team names
		{
			toss_winner=team2;		//	......
			team2=team1;			// swapping is being done in these steps
			team1=toss_winner;		//	......
		
		}
	
	}
	else		// esle print error message (which is impossible)
		cout<<"\n\nError in function\"toss_decision\"!\a";
		
	
}			// end of body of functin "toss_decision"


void throw_coin(void)
{
	char head=169;
	char tail=184;
	int c=0;
	
	system("cls");
	
	while( c<20)
	{
		
		
		
		if(c%2==0)
		{
			Sleep(1500);
			cout<<"\n\n\n\t"<<head<<endl;
		}
		else
		{
			Sleep(1500);
			cout<<"\n\n\n\t"<<tail<<endl;
		}
		system("cls");	
		c++;
	}

	
}


// ((((((((((((((((((((((((((((((((((		END OF HEADER FILE "cricket.h" )))))))))))))))))))))))))))))))))))))))))))))))))))
