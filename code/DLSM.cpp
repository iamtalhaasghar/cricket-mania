
// Source code of Duckworth lewis Methodology


					// Duckworth Lewis Stern Methdology




// Libraries used in the program


#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
#include<Windows.h>


using namespace std;


// Prototypes of functions defined in this source file


//	1.		function to calculate revised "target" for team2
double target(double R1, double R2, double S , double G);

//	2.		function to determine the percent resource of a team
double percent_resource(int total_overs, int overs_interruption , int overs_resumption , int wickets_lost );	

//	3.		function to determine the resource available from table using overs and wickets
double resource_table (int overs , int wickets_lost  );				

int balls( double over );
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Definations of functions being used




//	>> function to calculate the revised target using given information

double target(double r1, double r2, double s , double g)
{
	double result=0.0;					// variable to store the "result" of calculations
	
	cout<<endl<<setfill('-')<<setw(100);



//  if team 1 has higher resource than calculate target as follows

	if(r1>r2)
	{
		
		result = s * r2 / r1  + 1.0 ;
	

	}
//  if team 2 has higher resource than calculate target as follows

	else 
		if(r2>r1)
		{
			
			result = s +( r2 - r1 ) * g / 100.0  + 1.0 ;
		
		}
		
		else			// else as the resources are equal there is no need of revised target 
		{
			MessageBox(0,"As Both teams have equal resources there is no need to calculate the revised target.", "Target", MB_OK );
			result=s+1;
		}

	return result;


}			// end of body of function "target"





// >> function to determine the percent resource of a team using given total overs, overs at interruption, overs at resumption and wickets lost

double percent_resource(int total_overs, int overs1 , int overs2 , int wickets )
{

	double result1=0, result2=0, result3=0 ;		// variable to store percent resources at interrupton, resumption and net resource

	cout<<endl<<setfill('.')<<setw(90);

	result1=	resource_table(total_overs, 0 );			// call fucntion "resource_table" to calculate resource at start of innings
	cout<<"\n\nResource at start of innings :"<<result1;

	result2=	resource_table( (total_overs-overs1) , wickets);	// call fucntion "resource_table" to resource when interruption started
	cout<<"\nResource when interruption started :"<<result2;


	result3=	resource_table( (total_overs-overs1)-overs2 , wickets);	// resource when interruption ended
	cout<<"\nResource when interruption ended :"<<result3;
	cout<<endl<<setfill('.')<<setw(88);
	

	return result1-(result2-result3);				// return the value of net percent resource


}			// end of body of function "percent_resources"





// >> function to determine the resource available from table using overs and wickets


double resource_table( int overs , int wickets )
{

	double result=0;				// variable to store the result of calculation .i.e. getting resource from table
	double percent_resource[51][10];		//  array to store the table of percent_resource by overs and wickets (51 overs and 10 wicets)

	fstream file;					// create an object to read the file
	

	// open the file"DLSM_Table_O.txt" in read mode and check if opened correctly

	file.open("DSLM_Table_O.txt",ios::in);
    
	if(!file)
	{
			// if file does not opens print error message

        cout<<"Error in opening file.\"DSLM_Table_O.txt\"";
        _getch();
		return 0;
    }



	// while loop to read the file and store the table in array "percent_resource"

	while( !file.eof() )
	{

		for(int i=0; i<51; i++)
		{
		
			for( int j=0; j<10 ; j++)
			{
				
				// get data from file and store it in array

				file>>percent_resource[i][j];
			
			}	// end of nested "for loop"
		}		// end of outer "for loop"
	
	}	// end of "while loop"
	


	// now compare the given number of overs and wickets with the data stored in array and store value in "result"

	for(int i=0; i<= overs ; i++)
	{
		
		for( int j=0; j<=wickets ; j++)
		{
			
				// store the desired determined value in "result"
			result=percent_resource[i][j];
			
		}	// end of nested "for loop"
	
	
	}		// end of "outer for loop"

	file.close();		// close the opened file after calculation
	
	return result;		// return the value stored in result to the "main"


}					// end of body of function "resouurce_table"

int balls( double over )
{
	int balls=0;
	int temp=0;
	temp=over*10;
	balls+=temp%10;
	temp/=10;
	balls+=temp*6;

	return balls;

}

// ((((((((((((((((((((((((((((((((((		END OF SOURCE FILE "DSLM.cpp" )))))))))))))))))))))))))))))))))))))))))))))))))))
