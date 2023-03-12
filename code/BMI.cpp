
// source file "BMI.cpp"



// libraries used in this source file
#include<iostream>
//#include<conio.h>
#include <ncurses.h>
#include<string>
#include<stdlib.h>
#include<iomanip>
//#include<Windows.h>

using namespace std;



// functions` definations


// function "bmi" to calculate the bmi of each player of a team 

void bmi(string players[],int size)
{

	double bmi[15];		// array to store the result or BMI of the players

	double weight=0, height=0;		// variables to get height and weight of the player
	string w, h;					// variable to get the unit of height and wight
	
	
	// for loop which will process the BMI`s of all players of a team

	for (int i = 0; i < size; i++)
	{

		// print the heading or title 

		cout<<right<<setfill('*')<<setw(82)<<"\n\n\n";
		cout<<setfill(' ');
		cout<<setw(80)<<" 'e' = exit \n";
		cout <<"Calculating BMI of (Player#"<<i+1<<")  \" "<< players[i] <<" \" :  ";
		
		// if user pressed the key 'e' then exit from loop
		if(getch()=='e')
		{
			cout<<"Exiting BMI!";
			goto END;				// exiting from the for loop
		}


		// get the numerical value of mass of a player

		cout<<"\n\n";
		cout<<left<<setw(50)<< "Enter Mass ( numerical value ) : ";
MASS_M:	cin >> weight;

		if(weight<=0)
		{
			// if user enters wrong number prompt an error message

			//MessageBox(0,"Error! \"Mass\" is never nagative or zero.", "Wrong Mass", MB_OK );
			goto MASS_M;   // go and get the value of mass again
		}


		// get the unit of mass entered

		cout <<setw(50)<< "Enter units of mass ( 'kg' or 'lb' ) : ";
MASS_U:	cin	>> w;
		
	
		// converting all other units of mass in SI unit 'kg'


		if( w=="kg"|| w=="kilogram" )
			;

		else if (w == "lb"||w == "pound"||w == "pounds")
		{
			// if mass is in pounds convert it to "kg"
			weight = weight / 2.20;
		}
		else
		{
			// if incorrect number is entered prompt an error message

			//MessageBox(0,"Error! Incorrect unit of \"mass\" was entered. ", "Wrong Mass", MB_OK );
			goto MASS_U;
		
		}
		
		// get the numerical value of height of the player

		cout<<setfill('.')<<setw(80)<<"\n";
		cout<<setfill(' ')<<setw(50)<< " Enter Height ( numericalvalue ) : ";

HEIGHT_M:	
		cin >> height;
	
		if(height<=0)
		{
			// if wrong height is entered prompt an error message

			//MessageBox(0,"Error! \"Height\" is never nagative or zero.", "Wrong Height", MB_OK );
			goto HEIGHT_M;
		}

		// get the units of height entered

		cout<<setw(50)<<"Enter units of Height ('m','in' or 'cm') : ";

HEIGHT_U:
		cin	>>h;

		// convert all other units of height to SI unit "m"


		if( h=="m" || h=="meter" )
			;
		
		else if ( h == "in"||h == "inch"||h == "inches" )
		{
			// if height is in "inches" convert it in "metres"

			height = height*0.0254;
		}
		else if ( h == "cm"|| h=="centimeter" )
		{
			// if height is in "centimeter"convert it in "metres"

			height = height*0.01;
		}
		
		else
		{
			// else prompt an error message on wrong entry of unit

			//MessageBox(0,"Warning! Incorrect units of \"height\" was entered.", "Wrong Height", MB_OK );
			goto HEIGHT_U;
		}


		// calculating BMI

		bmi[i] =  weight / (height * height) ;

		// printing the BMI for respective player under examination 
		
		cout<<setfill('-')<<setw(80)<<"\n";
		cout << "\n BMI of \" "<<players[i]<<" \" is " << bmi[i]<<".\n";
		
		
		// determining and printing the category of player with respect to score of BMI


		if (bmi[i] < 18.5)
		{
			cout << " You are \"Underweight\"!" << endl;
			cout << " PROPER DIET SHOULD BE TAKEN TO GAIN WEIGHT." << endl;
		}
		
		if (bmi[i] >= 18.5 && bmi[i] <= 24.9)
		{
				cout << " You are \"Normal!\"!" << endl;
		}
		
		
		
		if(bmi[i] >= 25 &&bmi [i] <= 29.9)
		{
			cout<<" You are \"Overweight\".\n";
			cout << " PROPER EXERCISE IS NEEDED TO LOSS WEIGHT\n" << endl;
		}	
		
		
		if (bmi[i] >= 30)
		{
			cout << " You are \"Obese!\"." << endl;
			cout << " PLAYER SHOULD DO PROPER EXERCISE TO LOSS WEIGHT\n" << endl;
		}
		
		
		
		
	}				// end of body of "for loop"
	
END:		cout<<"\n\nEnd of BMI Calculator!\n";	

	

}				// end of body of function "BMI"



// ((((((((((((((((((((((((((((((		END OF "BMI.cpp"			))))))))))))))))))))))))))))))
