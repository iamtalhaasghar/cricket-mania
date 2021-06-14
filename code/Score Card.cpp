// Score Card .cpp


//   includes the functions related to Scorecard / Match Stats



// Libraries used in this source file


#pragma comment(lib, "winmm.lib")			// library to play the sound
#include<iostream>							
#include<conio.h>					
#include<iomanip>							// libray for input and output manipulation
#include<ctime>								// library to determine the current time and date
#include<string>							// libraries to use string classes
#include<Windows.h>							// library "Windows.h"

using namespace std;


// defination of function "Scorecard" which will print and update the current match stats

void score_card(string teamA ,string teamB, int total_overs )
{
	
	int score1=0;			// score of team 1
	int wicket1=0;			// wickets lost by team 1
	int overs1=0;			// overs played by team 1
	int balls1=0;			// balls of overs played by team 1
	int extra1=0;			// extra scores given to team 1
	int fours1=0;			// no. of fours scored by team 1
	int sixes1=0;			// no. of sixes scored by team 1
	
	char a='0';				// variable to get choice of user



    time_t now = time(0); // current date / time based on current system
	
    char* dt = ctime(&now);				// convert now to string form
	


	while(1)				// infinte while loop for match stats of team 1
	{						
			
		
			// print the Title and available options to user
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


			system("cls");
			cout<<"\n\t\t\t\t\"WELCOME TO SCORECARD\"\n"<<dt<<setfill(' ')<<setw(65)<<static_cast<char>(16)<<"LIVE Update\n";
			
			// print names of team 1 and team 2 and total overs of match

			cout<<"\t\t\t\t"<<teamA<<" V "<<teamB<<"\n\n";
			cout<<teamA<<setw(65)<<"Total Overs : "<<total_overs<<"\n";
			cout<<setfill('-')<<setw(27)<<"\n";
		
			// print the available buttons and their functions

			cout<<"Score: "<<score1<<"\t"<<"Wickets: "<<wicket1<<endl;
			cout<<"Overs: "<<overs1<<"."<<balls1<<"\n\n";
			cout<<"Fours: "<<fours1<<"\n";
			cout<<"Sixes: "<<sixes1<<"\tExtras:"<<extra1<<"\n\n";
			cout<<"Run Rate: \n\n";
			cout<<setfill('*')<<setw(80)<<"\n\n";
			cout<<"W = Wicket\t4 = Four\t6 = Six \t 2 = Double Runs\n1 = Single Run"<<"\tw = WIDE BALL\t";
			cout<<"n = No Ball\t 0 = Dot Ball \n\n";
			cout<<setfill('-')<<setw(80)<<"\n";
			cout<<"i=Skip Innings"<<setfill(' ')<<setw(65)<<"e=Exit\n\n";


			
			a=_getch();				// get choice of user

		// switch statement to do an action as user presses the button

		switch (a)
		{	
		
			case ('0'):			// if choice is'0' increse 1 ball
			{
				balls1++;
				
				if(balls1>5)
				{
					overs1++;
					balls1=0;
				}
				break;
			
			}


			case ('1'):			// if choice is '1' add 1 to score and increse a ball
			{
				score1++;
				balls1++;
				
				if(balls1>5)
				{
					overs1++;
					balls1=0;
				}
				break;
			}
			

			case ('2'):			// if choice is'2' increse add 2 to scores and increse a ball
			{
				score1+=2;
				balls1++;
				
				if(balls1>5)
				{
					overs1++;
					balls1=0;
				}
				break;
			}

			
			case ('w'):			// if choice is'w' increse add 1 to score (wide ball)
			{
				score1++;
				extra1++;
				break;
			}
			
			
			case ('4'):				// if choice is '4' add 4 to scores and increse a ball
			{
				fours1++;
				score1+=4;
				balls1++;
				
				if(balls1>5)
				{
					overs1++;
					balls1=0;
				}
				
								// play sound "four.wav" for boundary

				PlaySound(TEXT("four.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(5000);

				break;
			
			}
			
			case ('6'):						// if choice is '6' add 6 to scores and increse a ball
			{
				sixes1++;
				score1+=6;
				balls1++;
				
				if(balls1>5)
				{
					overs1++;
					balls1=0;
				}

									// play sound "six.wav" when a six is scored
				
				PlaySound(TEXT("six.wav"), NULL, SND_FILENAME | SND_ASYNC);				
				Sleep(7000);


				break;
			
			}


			case ('W'):				// if choice is 'W' increse wicket by 1 and also increase ball by 1
			{
				wicket1++;
				balls1++;
				
				if(balls1>5)
				{
					overs1++;
					balls1=0;
				}

							// play sound "wicket.wav" when a player is out

				PlaySound(TEXT("wicket.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(10500);

				break;
			
			}


			case ('n'):			// "no ball"
			{
				score1++;
				extra1++;
							// play sound for no ball
				PlaySound(TEXT("noball.wav"), NULL, SND_FILENAME | SND_ASYNC);
							// prompt a message showing "free hit"
				MessageBox(0,"NO BALL! Free Hit!!!", "Team2", MB_OK );
				Sleep(10000);				
				break;
			
			}
			
			
			case ('i'):			// if choice is 'i' skip the innings of that team
			{
				// prompt the warning message

				MessageBox(0,"Caution! You are leaving your innings!\n This may affect the overall result of the match.", "Team 1 Skips", MB_OK );			
				goto TEAMB;	
			}
			

			case('m'):			// if choice is 'm' decrease ball by 1		(Secret Button)
			{
				if(balls1==0 && overs1>0 )
				{
					balls1=5;
					overs1--;
				}
				else if(balls1>0 && overs1>=0)
				{
					balls1--;
				}
				
				break;
			}	
			case('z'):			// if choice is 'z' decrease score by '1'  ( another second Button )
			{
				if(score1>0)
					score1--;
				break;
			
			}
			case('e'):			// if choice is 'e' exit the scorecard
			{

				// prompt a warning message before exiting scorecard

				MessageBox(0,"Caution! You are leaving the match!\n It will be counted as your defeat.", "Team 1 leaves", MB_OK );			
				cout<<"\nMatch is terminated by \" "<<teamA<<" \".\n";
				cout<<"\n \" "<<teamB<<" \" wins.\n\n";
				goto END;		// goto label "END" which marks end of program
			}


			default:			// else if another key is pressed 
			{
				// prompt a warning message

				MessageBox(0,"Error! Invalid Key is pressed.", "Scorecard Team1", MB_OK );
				break;
			}
			

		}						// end of switch 

		//	quit the innings of team  if their all batsmen are out or if overs are up

		if(wicket1==10 || overs1==total_overs )
			goto TEAMB;			// goto label "TEAMB" and now print their match stats
		
		
	
	}						// end of while loop of Team 1


	// Print the match stats for "TEAMB"



TEAMB:	
	int score2=0;			// score of team 2
	int wicket2=0;			// wickets lost by team 2
	int overs2=0;			// overs played by team 2
	int balls2=0;			// balls of overs played by team 2
	int extra2=0;			// extra scores given to team 2
	int fours2=0;			// no. of fours scored by team 2
	int sixes2=0;			// no. of sixes scored by team 2
	a='0';
	
	while(1)
	{

		// Print the title of Scorecard 
	
		system("cls");
		cout<<"\n\t\t\t\t\"WELCOME TO SCORECARD\"\n"<<dt<<setw(65)<<static_cast<char>(16)<<"LIVE Update\n\n";
		

		// Print the target for team 2 and total overs

		cout<<"Total Overs : "<<total_overs<<"\n"<<setw(70)<<"Target="<<score1+1<<"\n";

		// Print the name of teams playing the match
		cout<<teamA<<"\t\t\t\t\t"<<teamB<<"\n";

		// Print the match stats of previous innings and match stats of team 2 

		cout<<setfill('-')<<setw(29)<<"\t\t";cout<<setfill('-')<<setw(34)<<"\n";
		cout<<"Score: "<<score1<<"\t"<<"Wickets: "<<wicket1<<"\t\t"<<"Score: "<<score2<<"\t"<<"Wicket: "<<wicket2<<endl;
		cout<<"Overs: "<<overs1<<"."<<balls1<<"\t\t\t\t"<<"Overs: "<<overs2<<"."<<balls2<<"\n\n";
		cout<<"Fours: "<<fours1<<"\t\t\t\t"<<"Fours: "<<fours2<<"\n";
		cout<<"Sixes: "<<sixes1<<"\tExtras:"<<extra1<<"\t\t"<<"Sixes: "<<sixes2<<"\tExtras:"<<extra2<<"\n\n";
		//		cout<<"Run Rate: \t\t\t\t"<<"Run rate: \n\n";
		// print the available buttons for their functions
		
		cout<<setfill('*')<<setw(80)<<"\n\n";
		cout<<"W = Wicket\t4 = Four\t6 = Six \t 2 = Double Runs\n1 = Single Run"<<"\tw = WIDE BALL\t";
		cout<<"n = No Ball\t 0 = Dot Ball \n\n";
		cout<<setfill('-')<<setw(80)<<"\n";
		cout<<setfill(' ')<<setw(80)<<"e=Exit\n\n";
	

		// if team 2 completed target then

		if(score2>=score1+1)
		{
			// prompt a message showing that they are winners

			MessageBox(0,"Team 2 has won the match!!!", "Team 2 Wins!", MB_OK );
			cout<<"\n\" "<<teamB<<" \""<<" has won the match by \' "<<10-wicket2<<" \' wickets !\n";
			goto END;		// and goto lable "END" which marks the end of program
		
		}

		// if team 2 has lost its all of wickets or has played all overs then

		if(wicket2==10||overs2==total_overs )
		{
			// check if score of team 2 is equal to score made by team 1

			if(score2==score1)
			{
				// print message showing that the match has been counted as Draw

				MessageBox(0,"No one wins!!!", "Match Draw!", MB_OK );			
				cout<<"\n Match is Over without any result.\n";			
				goto END;
			}
			
			// check if score of team 2 is less than score of team 1

			else if(score2<score1)
			{
				// print message showing that team 1 has won the match

				MessageBox(0,"Team 1 has won the match!!!", "Team 1 Wins!", MB_OK );			
				cout<<"\n\" "<<teamA<<" \""<<" has won the match by \' "<<score1-score2<<" \' runs !\n";			
				goto END;
			}

		}					// end of if....statement

		
		// getting the choice of user

		a=_getch();
					
		
		// switch statement to do an action as user presses the button

		switch (a)
		{	
		
			case ('0'):				// if choice is '0' increse 1 ball
			{
				balls2++;
				
				if(balls2>5)
				{
					overs2++;
					balls2=0;
				}
				break;
			
			}


			case ('1'):				// if choice is '1' add 1 to score and increse a ball
			{
				score2++;
				balls2++;
				
				if(balls2>5)
				{
					overs2++;
					balls2=0;
				}
				break;
			}
			

			case ('2'):				// if choice is'2' increse add 2 to scores and increse a ball
			{
				score2+=2;
				balls2++;
				
				if(balls2>5)
				{
					overs2++;
					balls2=0;
				}
				break;
			}

			
			case ('w'):				// if choice is'w' increse add 1 to score (wide ball)
			{
				score2++;
				extra2++;
				break;
			}
			
			
			case ('4'):				// if choice is '4' add 4 to scores and increse a ball
			{
				fours2++;
				score2+=4;
				balls2++;
				
				if(balls2>5)
				{
					overs2++;
					balls2=0;
				}
				
									// play sound "four.wav" for boundary
				PlaySound(TEXT("four.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(5000);

				break;
			
			}
			
			case ('6'):				// if choice is '6' add 6 to scores and increse a ball
			{
				sixes2++;
				score2+=6;
				balls2++;
				
				if(balls2>5)
				{
					overs2++;
					balls2=0;
				}

								// play sound "six.wav" when a six is scored
				PlaySound(TEXT("six.wav"), NULL, SND_FILENAME | SND_ASYNC);				
				Sleep(7000);
				break;
			
			}


			case ('W'):			// if choice is 'W' increse wicket by 1 and also increase ball by 1
			{
				wicket2++;
				balls2++;
				
				if(balls2>5)
				{
					overs2++;
					balls2=0;
				}

						// play sound "wicket.wav" when a player is out
				PlaySound(TEXT("wicket.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(10500);
				break;
			
			}


			case ('n'):			// "no ball"
			{
				score2++;
				extra2++;

						// play sound for no ball
				PlaySound(TEXT("noball.wav"), NULL, SND_FILENAME | SND_ASYNC);

				// prompt a message showing "free hit"
				MessageBox(0,"NO BALL! Free Hit!!!", "Team1", MB_OK );
				

				Sleep(10000);								
				break;
			
			}


			case('m'):					// if choice is 'm' decrease ball by 1		(Secret Button)
			{
				if(balls2==0 && overs2>0 )
				{
					balls2=5;
					overs2--;
				}
				else if(balls2>0 && overs2>=0)
				{
					balls2--;
				}
				
				break;
			}
			
			case('z'):				// if choice is 'z' decrease score by '1'  ( another second Button )
			{
				if(score2>0)
					score2--;
				break;
			}



			case('e'):				// if choice is 'e' exit the scorecard
			{
				
				// prompt a warning message before exiting scorecard

				MessageBox(0,"Caution! You are leaving the match!\n  It will be counted as your defeat.", "Team 2 leaves", MB_OK );			
				cout<<"\nMatch is terminated by \" "<<teamB<<" \".\n";
				cout<<"\n \" "<<teamA<<" \" wins.\n\n";
				goto END;			// goto label "END" which marks end of program

			}


			default:			// else if another key is pressed 
			{

					// prompt a warning message

				MessageBox(0,"Error! Invalid Key is pressed.", "Scorecard Team2", MB_OK );
				break;
			}
			

		}					//  end of 2nd switch statement


		
	}							// end of 2nd while loop
	
END:	cout<<"\nThe Match is concluded !";			// end of program

	_getch();
}						// end of function "scorecard"



// ((((((((((((((((((((((((((((((((((		END OF SOURCE FILE "Score Card.cpp" )))))))))))))))))))))))))))))))))))))))))))))))))))
