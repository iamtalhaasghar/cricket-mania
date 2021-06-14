
//	C/C++ 1st SEMESTER FINAL PROJECT	

			
//									"Cricket and Code for Good"
									



/*==========================================================================================
										Group Info
============================================================================================
						
	Department			:			Compputer Science
	Semester			:			1st Semester
	Lecturer			:			Engnr. Dr. Naeem Maroof
	 _______________________________________________________
	|	Members			|	Roll Numbers	|
	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
	|	Talha Asghar		:		69	|
	|	Abdul Basit		:		62	|
	|	Zain-ul-Abideen		:		72	|
	|	M. Junaid Nawab		:		80	|
	|	Raheel Abbas		:		82	|
	|_______________________________________________________|

	
*/


/*****************************************************************************************

				 Libraies used in the project
				===============================================

******************************************************************************************/


/*--------------------------------------------------
	>	C/C++ Standard Built-In Libraires used
---------------------------------------------------*/


#pragma comment(lib, "winmm.lib")		// library to load and play sound files
#include<iostream>						// input, output stream
#include<conio.h>						// library of "conio.h"
#include<iomanip>						// input, output manipulator
#include<stdlib.h>						// c-standard library
#include<string>						// libray to handle "stirngs"
#include<fstream>						// library "filestream" to handle files
#include<Windows.h>						// library "Windows.h"



/*	----------------------------
	>	our own libraries
	----------------------------
*/

#include"cricket.h"			//  library "cricket.h"


//.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~


using namespace std;					// the standard namespace


/*			functions used from libray "cricket.h"
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void total_teams(void);													// function to print the available teams
int check_team(string team);											// function to check if user selected correct team
void team_players (string team, string t_players[] , int size=11);		// function to select the players of team selected by user
string toss(string choice,string team1, string team2);					// function for "toss"
void toss_decision( string toss_winner, string &team1, string &team2);	// fucntion to get the decision of team winning the toss


/*			function used from "DLSM.cpp"
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


double target(double R1, double R2, double S , double G);				// function to calculate the revised target
double percent_resource(int total_overs, int overs_interruption , int overs_resumption , int wickets_lost );			// function to calculate the percent resource
double resource_table (int overs , int wickets_lost  );					// function to determine the resource available from table using overs and wickets 



/*			function used from "BMI.cpp"	
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void bmi(string players[],int size=11);				// function to calculate the "BMI" of all players of a team


/*			 function used from "Score Card.cpp"	
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


void score_card(string teamA ,string teamB, int total_overs );			// function to display the current match stats and update them "live"


/*			 Miscellaneous functions	
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


	// defination of a function to clear the screen after some seconds
inline void wait_cls(void)
{
	Sleep(1000);
	system("cls");

}


	// defination of a function to clear the screen when a key is pressed
inline void cls(void)					
{
	_getch();
	system("cls");


}			// end of body of inline function "cls"



/*			>	Global variables used
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

const int size=11;					// constant integer "size" which stores the total numbers of players in team  


int main()							// defination of function "main"
{											

	system("color 3F");				// sets the colour of console as "aqua background and white text"
	

/*		variables (local to "main") used in program
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

	string			choice="0";				// variable to get different choices from user
	string			team1="teamA";			// name of first team
	string			team2="teamB";			// name of second team

	string			players1[size]={"players of team 1"};			// players of first team
	string			players2[size]={"players of team2"};			// players of second team


	int				N=0;					// total number of overs per innings
	double			G=245.0;				// a constant used in calculation of revised target
	double			S=0.0;					// total score made by first team
	double			T=0.0;					// revised target for second team
	double			R1=0.0;					// total percentage resource available to first team
	double			R2=0.0;					// total percentage resource available to second team
	int				wickets=0 ;				// wicket lost when interruption occured
	string			coin_face="\0";			// coin face selected by a team in "toss" segment
	int				over=0;					// overs played by a team when interruption occured	
	int				overs_lost=0;			// overs decided by match officials to deduct from total overs due to interruption

//.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~

	

	do				//	master do...while....  loop 
	{
		
			// print the purpose of program 

			system("cls");		
			cout<<setfill(' ')<<"\n\n"<<setw(52)<<"\" Cricket Mania \"\n\n";
			cout<<">Press any key when ready: \t";
			cls();
			

			
			/*+++++++++++++++++++++++++++++++++++++++++ 
				Prompts user to select two teams
			+++++++++++++++++++++++++++++++++++++++++*/

			cout<<setfill(' ')<<setw(45)<<"\"Selection of Teams\"";
			cout<<endl<<setfill('-')<<setw(110);
			cout<<"\n\n> Please Enter name of two Teams : \n";
			total_teams();										// calling function "total_teams()"
			Sleep(4000);
			cout<<"\nTeam1 : \t";

TEAM1:		cin >> team1;				// get the name of first team selected
			
			if( check_team(team1) == 0 )		// call the function "check_team()"	and check team
			{
				// if team1 is not available prompt error message
				
				MessageBox(0,"Error! No such team is available.", "Incorrect Team1", MB_OK );
				goto TEAM1;				// go and get the name of "team1"
			
			
			}	// end of body of if statement



			//	Similarly get and check the availability of selected "team2"

			cout<<"\nTeam2 : \t";
TEAM2:		cin>>team2;

			if( (check_team(team2)==0) || team2==team1 )
			{
				// if team2 is not available prompt error message

				MessageBox(0,"Error! This team has already been selected or is not available.", "Incorrect Team2", MB_OK );
				goto TEAM2;				// go and get the name of "team2"
			
			}


			system("cls");


			/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
				 Read and Print the names of players of both teams selected by user
			++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


			cout<<"The players of slected teams are :\n\n\n";
			cout<<setfill(' ')<<"\t   "<<left<<setw(30)<<team1<<setw(30)<<team2<<"\n\n\n";
			
			team_players(team1,players1);		// calling function "team_players"

			team_players(team2,players2);		// again calling function "team_players" for team2
			
			
			// Print the names of players using for loop

			for (int counter=0 ; counter<size  ; counter++)
			{
				cout<<"\t   "<<left<<setw(30)<<players1[counter]<<setw(30)<<players2[counter]<<endl;
			
			}			// end of body of for loop

			cls();
			
			
			/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
						calculating the BMI of every player of team 1 
			++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


			cout<<"\n\n"<<right<<setw(45)<<"\" BMI Calculator \"\n\n\n";
			cout<<"Caclulating BMI of players of team \" "<<team1<<" \" .\n\n";
			bmi(players1);			// calling function "bmi"
			
			wait_cls();

			/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
						calculating the BMI of every player of team 1 
			++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


			cout<<"\n\n"<<right<<setw(45)<<"\" BMI Calculator \"\n\n\n";
			cout<<"Caclulating BMI of players of \" "<<team2<<" \" .\n\n";
			bmi(players2);			// again calling function "bmi" for team2

			wait_cls();


			/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
					Select the match type from available matches or create match of your own type
			+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


			// 

MATCH:		system("cls");
			cout<<"\n\n\n 1 = T-10 \t 2 = Twenty-20 \t 5 = ODI \n"
					<<" 0 = Custom Match";				// print available match types
			

			cout<<endl<<setfill('-')<<setw(110);			
			cout<<"\n\n\nSelect Match Type (or Total Overs):	";
			
			cout<<(choice=_getch());								// get users choice

			if(choice=="1")
			{
				N=10;		// T-10 Match type
				G=200;			
				
			}
			else if( choice=="2" ) 
			{
				N=20;		// T-20 Match
				G=245;
			}
			else if (choice=="5")
			{
				N=50;		// ODI
				G=245;
			}
				
			else if( choice=="0" )
			{

				// custom match with overs between 0 and 50

				cout<<endl<<setfill('.')<<setw(72)<<"\n";
				cout<<"\n\nEnter the Total Number of Overs in an Innings: ";
				cin>>N;
				
				
				// prompt error message if wrong numbers of overs are entered

				if( N>=50 || N<=0 || N==10 || N==20 )
				{
					MessageBox(0,"Invalid Custom Match!.", "Custom Match", MB_OK );
					goto MATCH;		// go and get users` choice for match type
				}
						
				G=200;
			
			}				
				
			else
			{
				// prompt error message if users` choice was wrong

				MessageBox(0,"Error! No such match type is available.", "Match Selection", MB_OK );
				goto MATCH;		// go and get users` choice for match type
				
			}


			wait_cls();
			

			// 



			/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++
									the "TOSS"
			++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



COIN_FACE:	system("cls");
			cout<<"\n\n"<<setfill(' ')<<setw(40)<<"\"Toss\"\n\n";
			
			cout<<"\t   "<<left<<setw(40)<<team1<<setw(50)<<team2;

			cout<<right<<setfill('-')<<setw(83)<<endl;

			
			// get the choice (.i.e. Head or Tail) from captain of team 2

			cout<<"\n\nSir! "<<players2[0]
				<<"\n\nPlease select the coin face.\n";
			cout<<"\nHead(\"head\") or Tail(\"tail\") : \t";
			cin>>coin_face;

			if (!( coin_face=="head" || coin_face=="tail" ))
			{
				// if choice is incorrect prompt error message

				MessageBox(0,"Error! Select \"head\"or \"tail\"", "Coin Face", MB_OK );
				goto COIN_FACE;			// go and get "coin face" again
			}
			
			cout<<endl<<setfill('-')<<setw(82);		
			cout<<"\n\nSo! "<<coin_face<<" is the call!\n\n";
			
			
//			>> play sounds for respective calls


			if( coin_face=="head")
			{
				PlaySound(TEXT("head.wav"), NULL, SND_FILENAME | SND_ASYNC);				
				Sleep(4000);
			}
			else
			{
				PlaySound(TEXT("tail.wav"), NULL, SND_FILENAME | SND_ASYNC);				
				Sleep(4000);
			
			
			}
			

//			>> ask captain of team 1 to throw coin

			cout<<"Sir! "<<players1[0]<<"\n\nPlease throw the coin.";
			
			cout<<endl<<setfill('.')<<setw(115);		
							
			cout<<"\n\nPress any key to throw the coin.... ";
			PlaySound(TEXT("throw_coin.wav"), NULL, SND_FILENAME | SND_ASYNC);				
			Sleep(4000);
			
			_getch();

//			>> play sound of "coin throw" and wait

			PlaySound(TEXT("toss.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(5500);
						

//			>> get decision from the toss winning team

			toss_decision( toss(coin_face,team1,team2) , team1 ,team2 )  ;		// calling function "toss_decision"

//..........cout<<"\n"<<team1<<"\t"<<team2<<endl;
	
			cout<<setfill('.')<<setw(80)<<"\n\n";		

			wait_cls();


			/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++
							the "Scorecard"
			++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

			score_card(team1,team2,N);			// call the function "scorecard"


			/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++
						the "Duckworth Lewis Stern Methodology"
			++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



		do				// nested do...while loop for D/L Method 
		{
		
	DSLM:	system("cls");
			cout<<endl<<setfill(' ')<<setw(58)<<"\"Duckworth Lewis Stern Methdology\"\n\n";
			cout<<"\t\t\t\t"<<team1<<" V "<<team2<<"\n";
			cout<<endl<<setfill('*')<<setw(110);


//			>> Prompt and get the "interruption type"

			cout<<"\n\nSelect the interruption type : \n";
			cout<<endl<<setfill('-')<<setw(100);
		
			cout<<"\nType 1 = Suspension in "<<team1<<"`s innings.\n\n";
			cout<<"Type 2 = Delay to start of  "<<team2<<"`s innings.\n\n";
			cout<<"Type 3 = Suspension during "<<team2<<"`s innings.\n\n";
			cout<<"Type 4 = Suspension and Termination of "<<team1<<"`s innings "<<" and delay to \n\t  "
				<<team2<<"`s Innings.\n";

			cout<<endl<<setfill('.')<<setw(100);
	
			cout<<"\n\nDelay Type is : Type ";
			cin>>choice;
	
		

			// Interruption of Type 1

			if (choice == "1")
			{
				system("cls");

				cout<<"\n\t\tType 1 = Suspension in "<<team1<<"`s innings.";
				cout<<endl<<setfill('*')<<setw(80)<<"\n\n\n";
				
				cout<<"Overs (played) when interruption occured: ";
				

				do{
					cin>>over;
					if	( over > N || over<0 )
					{
						MessageBox(0,"Error! Incorrect \"Overs\" Entered! ", "Type 1", MB_OK );
					}
				}while( over > N || over<0 );
				


				cout<<"Wickets fell at this stage: ";
				

				do{
					cin>> wickets;
					if	( wickets >= 10 || wickets < 0 )
					{
						MessageBox(0,"Error! Incorrect \"Wickets\" Entered! ", "Type 1", MB_OK );
					}
				}while( wickets >= 10 || wickets < 0 );


				cout<<"Total Overs lost due to termination of play: ";
				

				do{
					cin>>overs_lost;
					if	( overs_lost<0 || overs_lost>(N-over) )
					{
						MessageBox(0,"Error! Incorrect \"Overs Lost\" Entered! ", "Type 1", MB_OK );
					}
				}while( overs_lost<0 || overs_lost>(N-over) );


				cout<<"\nEnter the total score "<<team1<<" made in its innings : ";
				

				do{
					cin>>S;
					if	( S<0 )
					{
						MessageBox(0,"Error! Score can never be negative.", "Type 1", MB_OK );
					}
				}while( S<0 );
			

				cout<<"Overs availabe to "<<team2<<" are : "<<N-(overs_lost/2)<<endl;



				R1=percent_resource( N , over , (overs_lost/2) , wickets);
				cout<<"\n\nTotal Resource avialable to "<<team1<<" is : "<<R1;



				R2=percent_resource( N-(overs_lost/2) , 0 , 0 , 0);
				cout<<"\n\nTotal Resource avialable to "<<team2<<" is : "<<R2;

		

				cout<<"\n\nThe revised target is: "<<target( R1,  R2,  S ,  G);

			}				// end of body of if statement for case 1


			// Interruption of Type 2

			else if (choice == "2")
			{
		
				system("cls");
		
		
				cout<<"\n\t\tType 2 = Delay to start of  "<<team2<<"`s innings.";
				cout<<endl<<setfill('*')<<setw(80)<<"\n\n\n";


				cout<<"Total Overs lost due to termination of play: ";
				
				do{
					cin>>overs_lost;
					if	( overs_lost<0 || overs_lost>(N-over) )
					{
						MessageBox(0,"Error! Incorrect \"Overs Lost\" Entered! ", "Type 1", MB_OK );
					}
				}while( overs_lost<0 || overs_lost>(N-over) );

				cout<<"\nEnter the total score "<<team1<<" made in its innings : ";
				
				do{
					cin>>S;
					if	( S<0 )
					{
						MessageBox(0,"Error! Score can never be negative.", "Type 1", MB_OK );
					}
				}while( S<0 );




				R1=percent_resource( N , 0 , 0 , 0);
				cout<<"\n\nTotal Resource avialable to "<<team1<<" is : "<<R1;
	
				R2=percent_resource( N-overs_lost , 0 , 0 , 0);
				cout<<"\n\nTotal Resource avialable to "<<team2<<" is : "<<R2;

				cout<<"\n\nThe revised target is: "<<target( R1,  R2,  S ,  G);


			}			// end of body of if statement for case 2



			// Interruption of Type 3

			else if (choice == "3")
			{

				system("cls");
		
		
				cout<<"\n\t\tType 3 = Suspension during "<<team2<<"`s innings.";
				cout<<endl<<setfill('*')<<setw(80)<<"\n\n\n";
				
				cout<<"Overs (played) when interruption occured : ";
				
				do{
					cin>>over;
					if	( over > N || over<0 )
					{
						MessageBox(0,"Error! Incorrect \"Overs\" Entered! ", "Type 1", MB_OK );
					}
				}while( over > N || over<0 );
			
				cout<<"Wickets fell at this stage: ";
				
				do{
					cin>> wickets;
					if	( wickets >= 10 || wickets < 0 )
					{
						MessageBox(0,"Error! Incorrect \"Wickets\" Entered! ", "Type 1", MB_OK );
					}
				}while( wickets >= 10 || wickets < 0 );

				cout<<"Total Overs lost due to termination of play: ";
				
				do{
					cin>>overs_lost;
					if	( overs_lost<0 || overs_lost>(N-over) )
					{
						MessageBox(0,"Error! Incorrect \"Overs Lost\" Entered! ", "Type 1", MB_OK );
					}
				}while( overs_lost<0 || overs_lost>(N-over) );


				cout<<"\nEnter the total score "<<team1<<" made in its innings : ";
				
				do{
					cin>>S;
					if	( S<0 )
					{
						MessageBox(0,"Error! Score can never be negative.", "Type 1", MB_OK );
					}
				}while( S<0 );




				R1=percent_resource( N , 0 , 0 , 0);
				cout<<"\n\nTotal Resource avialable to "<<team1<<" is : "<<R1;

				R2=percent_resource( N , over , overs_lost , wickets);
				cout<<"\n\nTotal Resource avialable to "<<team2<<" is : "<<R2;

		

				cout<<"\n\nThe revised target is: "<<target( R1,  R2,  S ,  G);

	
			}				// end of body of if statement for case 3


			// Interruption of Type 4

			else if (choice == "4")
			{
		
				system("cls");

				cout<<"\nType 4 = Suspension and Termination of "<<team1<<"`s innings "<<" and delay to \n\t  "
				<<team2<<"`s Innings.";
				cout<<endl<<setfill('*')<<setw(80)<<"\n\n\n";
				

				cout<<"Overs when interruption occured: ";
				
				do{
					cin>>over;
					if	( over > N || over<0 )
					{
						MessageBox(0,"Error! Incorrect \"Overs\" Entered! ", "Type 1", MB_OK );
					}
				}while( over > N || over<0 );


				cout<<"Wickets fell at this stage: ";
				
				do{
					cin>> wickets;
					if	( wickets >= 10 || wickets < 0 )
					{
						MessageBox(0,"Error! Incorrect \"Wickets\" Entered! ", "Type 1", MB_OK );
					}
				}while( wickets >= 10 || wickets < 0 );

	
				cout<<"Total Overs lost due to termination : ";
			
				do{
					cin>>overs_lost;
					if	( overs_lost<0 || overs_lost>(N-over) )
					{
						MessageBox(0,"Error! Incorrect \"Overs Lost\" Entered! ", "Type 1", MB_OK );
					}
				}while( overs_lost<0 || overs_lost>(N-over) );

				cout<<"\nEnter the total score "<<team1<<" made in its innings : ";
			
				do{
					cin>>S;
					if	( S<0 )
					{
						MessageBox(0,"Error! Score can never be negative.", "Type 1", MB_OK );
					}
				}while( S<0 );


				R1=percent_resource( N , over ,over , wickets);
				cout<<"\n\nTotal Resource avialable to "<<team1<<" is : "<<R1;

				R2=percent_resource( N-overs_lost , 0 , 0 , 0);
				cout<<"\n\nTotal Resource avialable to "<<team2<<" is : "<<R2;

		

				cout<<"\n\nThe revised target is: "<<target( R1,  R2,  S ,  G);

	
			}				// end of body of if statement for case 2
		
			else
			{
				// prompt error message because invalid type chosen

				MessageBox(0,"Error! Incorrect type ! ", "DLSM Case Selection", MB_OK );
				goto DSLM;			// go and get the "interruption type" again
			}

			_getch();
DSLM_AGAIN:
			system("cls");
		

//			>> ask if user wants to calculate the revised target again

			cout<<"\n\n\nDo you want to calculate the revised target again?";
			cout<<"\n\n y=yes \n n=no ";
			cout<<endl<<setfill('*')<<setw(70)<<"\n";
			
			cout<<"\n\nMy Choice is : ";

			cout<<( choice=_getch()) ;



			if(choice=="y"||choice=="Y")
			{
				cout<<endl<<setfill('*')<<setw(70)<<"\n";
				cout<<"\n\nEnter the Total Number of Overs in an Innings: ";
N_FROM_USER:
				cin>>N;
				
				if( N>50 || N<=0 )
				{
					MessageBox(0,"Incorrect Numbers of overs Entered! \n \"Overs=(1-50)\"", "Invalid Overs", MB_OK );
					goto N_FROM_USER;
				
				}
				
				if(N==50||N==20)
					G=245;
				else
					G=200;
			
			}
			else if (!(choice=="n" || choice=="N"))
			{
				MessageBox(0,"Incorrect Choice! ", "D/L Choice", MB_OK );
				goto DSLM_AGAIN;
			}

			

		} while( choice=="y" || choice=="Y" );				//end of D/L method Loop


		// print the message showing that "DLSM Calculator" has been closed

		cout<<endl<<setfill('-')<<setw(70)<<"\n";

		cout<<"\n\n\t\tDSLM Calculator has been closed!";
		_getch();


//		>> ask the user if he wants to start the project again

PROJECT_CHOICE:	
		system("cls");

		cout<<"\n\n\nDo you want to start project again?";
		cout<<"\n\n y=yes \n n=no \n";
		cout<<endl<<setfill('*')<<setw(70)<<"\n";
		
		cout<<"\n\nMy Choice is : ";

		cout<<( choice=_getch()) ;
		
		if (!( choice=="n" || choice=="N" || choice=="y" || choice=="Y" ))
		{
			MessageBox(0,"Incorrect Choice! ", "Project", MB_OK );
			goto PROJECT_CHOICE;
		}

		

	}while ( choice == "y" || choice == "Y" );			
	
					// end of master do...... while..... loop.
	

//	>> print end of project message 

	cout<<endl<<setfill('-')<<setw(70)<<"\n";

	cout<<"\n\n \t\t\tEND OF PROJECT!!\n";

	_getch();
	return 0;
	
}										// end of body of function "main"


//			((((((((((((((((((((((((((((((		END	OF	PROGRAM		))))))))))))))))))))))))))))))

