				
			
					//  C++ 1st SEMESTER FINAL PROJECT 


	

/*****************************************************************************************

		Libraies used in the project
		============================

******************************************************************************************/


/*
	>	C/C++ Standard Built-In Libraires
*/


#pragma comment(lib, "winmm.lib")	
#include<iostream>						// input, output stream
#include<conio.h>						
#include<iomanip>						// input, output manipulator
#include<stdlib.h>						// c-standard library
#include<string>						// libray to handle "stirngs"
#include<fstream>						// library "filestream" to handle files
#include<Windows.h>						// library "Windows.h"



/*
	>	Library made by us
*/

#include"cricket.h";					// our own library "cricket.h"


//.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~


using namespace std;					// the standard namespace


										
// functions used from libray "cricket.h"

void total_teams(void);
int check_team(string team);
void team_players (string team, string t_players[] , int size=11);
string toss(string choice,string team1, string team2);
void toss_decision( string toss_winner, string &team1, string &team2);
void throw_coin(void);


// function used from "DSLM.cpp"

double target(double R1, double R2, double S , double G);
double percent_resource(int total_overs, int overs_interruption , int overs_resumption , int wickets_lost );
double resource_table (int overs , int wickets_lost  );
int balls( double over );


// function used from "BMI.cpp"			

void bmi(string players[],int size=11);

// function used from "Score Card.cpp"			

void score_card(string teamA ,string teamB, int total_overs );



// Miscellaneous functions

inline void cls(void)
{
	_getch();
	system("cls");


}


//	>	Global variables

const int size=11;					// constant integer named as "size" & initialized to value "11"  


int main()							// defination of function "main"
{											

	system("color 3F");
	
	// variables (local to "main") used in program


	string			choice="0";
	string			team1="teamA";
	string			team2="teamB";

	string			players1[size]={"players of team 1"};
	string			players2[size]={"players of team2"};

	int				N=3;		// total number of overs per innings
	double			G=245.0;
	double			S=0.0;		// total score of team 1
	double			T=0.0;		// target for team 2
	double			R1=0.0;		// resource percentage of team 1
	double			R2=0.0;		// resource percentage of team 2
	int				wickets=0 ;
	string			coin_face="\0";

	int				over=0,overs_lost=0;

//.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~

	

	do				//	master do...while....  loop
	{
		
			// team selection
		
			system("cls");
			
			cout<<"\n\n"<<setw(52)<<"\" Cricket For Good \"\n\n";

			cout<<">Press any key when ready: \t";
			cls();
			
			cout<<endl<<setfill('-')<<setw(110);
			

			cout<<"\n\n> Please Enter name of two Teams : \n";
	
			total_teams();
//			Sleep(4000);

			
			cout<<"\nTeam1 : \t";
TEAM1:		cin>>team1;
			
			if(check_team(team1)==0)
			{
			
				MessageBox(0,"Error! No such team is available.", "Incorrect Team1", MB_OK );
				goto TEAM1;
			
			
			}

			cout<<"\nTeam2 : \t";
TEAM2:		cin>>team2;

			if( (check_team(team2)==0) || team2==team1 )
			{
				MessageBox(0,"Error! This team has already been selected or is not available.", "Incorrect Team2", MB_OK );
				goto TEAM2;
			
			}


			system("cls");

			cout<<"The players of slected teams are :\n\n\n";
			cout<<setfill(' ')<<"\t   "<<left<<setw(30)<<team1<<setw(30)<<team2<<"\n\n\n";
			
			team_players(team1,players1);
			team_players(team2,players2);
			
			
			for (int counter=0 ; counter<size  ; counter++)
			{
				cout<<"\t   "<<left<<setw(30)<<players1[counter]<<setw(30)<<players2[counter]<<endl;
			
			}

			cls();
			
			cout<<"\n\n"<<right<<setw(45)<<"\" BMI Calculator \"\n\n\n";
			cout<<"Caclulating BMI of players of team \" "<<team1<<" \" .\n\n";
			bmi(players1);
			
			cls();
			cout<<"\n\n"<<right<<setw(45)<<"\" BMI Calculator \"\n\n\n";
			cout<<"Caclulating BMI of players of \" "<<team2<<" \" .\n\n";
			bmi(players2);

			cls();

MATCH:		system("cls");
			cout<<"\n\n\n 1 = T-10 \t 2 = Twenty-20 \t 5 = ODI \n"
					<<" 0 = Custom Match";
			

			cout<<endl<<setfill('-')<<setw(110);			
			cout<<"\n\n\nSelect Match Type (or Total Overs):	";
			cin>>choice;

			if(choice=="1")
			{
				N=10;
				G=200;			
				
			}
			else if( choice=="2" ) 
			{
				N=20;
				G=245;
			}
			else if (choice=="5")
			{
				N=50;
				G=245;
			}
				
			else if( choice=="0" )
			{
				cout<<setfill('.')<<setw(72)<<"\n";
				cout<<"\n\nEnter the Total Number of Overs in an Innings: ";
				cin>>N;
				if( N>=50 || N<=0 || N==10 || N==20 )
				{
					MessageBox(0,"Invalid Custom Match!.", "Custom Match", MB_OK );
					goto MATCH;		//line 85
				}
						
				G=200;
			
			}				
				
			else
			{
				MessageBox(0,"Error! No such match type is available.", "Match Selection", MB_OK );
				goto MATCH;		//line 85
				
			}


			cout<<"\n\n";
			system("pause");
			
			
COIN_FACE:	system("cls");
			cout<<"\n\n"<<setfill(' ')<<setw(40)<<"\"Toss\"\n\n";
			
			cout<<"\t   "<<left<<setw(40)<<team1<<setw(50)<<team2;

			cout<<right<<setfill('-')<<setw(83)<<endl;
			
			cout<<"\n\nSir! "<<players2[0]
				<<"\n\nPlease select the coin face.\n";
			cout<<"\nHead(\"head\") or Tail(\"tail\") : \t";
			cin>>coin_face;

			if (!( coin_face=="head" || coin_face=="tail" ))
			{
				MessageBox(0,"Error! Select \"head\"or \"tail\"", "Coin Face", MB_OK );
				goto COIN_FACE;	
			}
			
			cout<<endl<<setfill('-')<<setw(82);		
			cout<<"\n\nSo! "<<coin_face<<" is the call!\n\n";
			
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
			
			cout<<"Sir! "<<players1[0]<<"\n\nPlease throw the coin.";
			
			cout<<endl<<setfill('.')<<setw(115);		
							

			cout<<"\n\nPress any key to throw the coin.... ";
			PlaySound(TEXT("throw_coin.wav"), NULL, SND_FILENAME | SND_ASYNC);				
			Sleep(4000);
			
			getch();

			PlaySound(TEXT("toss.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(5500);
						
			toss_decision( toss(coin_face,team1,team2) , team1 ,team2 )  ;

//			cout<<"\n"<<team1<<"\t"<<team2<<endl;
	
			cout<<setfill('.')<<setw(80)<<"\n\n";		

			system("pause");
			score_card(team1,team2,N);

		do				// D/L Method loop
		{
		
	DSLM:	system("cls");
			cout<<endl<<setfill(' ')<<setw(58)<<"\"Duckworth Lewis Stern Methdology\"\n\n";
			cout<<"\t\t\t\t"<<team1<<" V "<<team2<<"\n";
			cout<<endl<<setfill('*')<<setw(110);

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



			}
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


			}
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

	
			}
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

	
			}
		
			else
			{
				MessageBox(0,"Error! Incorrect type ! ", "DLSM Case Selection", MB_OK );
				goto DSLM;
			}

			getch();
DSLM_AGAIN:
			system("cls");
		
			cout<<"\n\n\nDo you want to calculate the revised target again?";
			cout<<"\n\n y=yes \n n=no ";
			cout<<endl<<setfill('*')<<setw(70)<<"\n";
			
			cout<<"\n\nMy Choice is : ";

			cin>>choice;



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
					G==200;
			
			}
			else if (!(choice=="n" || choice=="N"))
			{
				MessageBox(0,"Incorrect Choice! ", "D/L Choice", MB_OK );
				goto DSLM_AGAIN;
			}

			

		} while( choice=="y" || choice=="Y" );		//end of D/L method Loop

		cout<<endl<<setfill('-')<<setw(70)<<"\n";

		cout<<"\n\n\t\tDSLM Calculator has been closed!";
		getch();

PROJECT_CHOICE:	
		system("cls");

		cout<<"\n\n\nDo you want to start project again?";
		cout<<"\n\n y=yes \n n=no \n";
		cout<<endl<<setfill('*')<<setw(70)<<"\n";
		
		cout<<"\n\nMy Choice is : ";

		cin>>choice;
		
		if (!( choice=="n" || choice=="N" || choice=="y" || choice=="Y" ))
		{
			MessageBox(0,"Incorrect Choice! ", "Project", MB_OK );
			goto PROJECT_CHOICE;
		}

		

	}while ( choice == "y" || choice == "Y" );

	
	cout<<endl<<setfill('-')<<setw(70)<<"\n";

	cout<<"\n\n \t\t\tEND OF PROJECT!!\n";

	_getch();
	return 0;
	
}				// end of body of function "main"


//			((((((((((((((((((((((((((((((		END	OF	PROGRAM		))))))))))))))))))))))))))))))

