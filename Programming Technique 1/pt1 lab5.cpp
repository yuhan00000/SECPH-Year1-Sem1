// LIM YU HAN  A23CS0241  SECTION 02  13/12/2023
#include<iostream>
#include<cstring>
using namespace std;

//function prototype
void dispStatus (int);
void getInput (int&, int&, int&, int&);
void dispOutput (int);
int calcAverage (int, int);


//main function
int main ()
{
	char stateName[50];
	char highstateName[50];
	int atvCases, totCases, newCases, totDeath, totRecov;
	int totatvCases = 0, numStates = 0, highatvCases = 0; 
	
   do
   {
   	cout << "\n<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>" << endl;
   	cout << "State name      : ";
   	cin.getline(stateName, 50);
   	
   	getInput(totCases, newCases, totDeath, totRecov);
   	atvCases = totCases + newCases - totDeath - totRecov;
   	
	cout << "\n<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>" << endl;
   	dispOutput(atvCases);
   	
	cout << "\n\nPress <ENTER> to continue..." ;
	cin.ignore();
   	totatvCases += atvCases;
   	
   	if (atvCases > highatvCases)
		{
			highatvCases = atvCases;
			strcpy(highstateName, stateName);
	    }
	
	
	numStates++;
	   
   } while (cin.get() == '\n');
   
   cout << "\n<<<<<<<<< ACTIVE CASES >>>>>>>>>>" << endl;
   cout << "Total   : " << totatvCases << endl;
   cout << "Hihgest : " << highatvCases << "  " << "(" << highstateName << ")" << endl;
   cout << "Average for " << numStates << " states : " << calcAverage (numStates, totatvCases) << endl; 
   
   return 0;
}


//function defenition
void dispStatus (int atvCases)
{
	if (atvCases > 40)
	    cout << "Red zone";
	else if (atvCases >= 21 && atvCases <= 40)
	    cout << "Orange zone";
    else if (atvCases >= 1 && atvCases <= 20)
        cout << "Yellow zone";
    else 
        cout << "Green zone";
}


void getInput (int& totCases, int& newCases, int& totDeath, int& totRecov)
{
	cout << "Total cases     : ";
	cin >> totCases;
	cout << "New cases       : ";
	cin >> newCases;
	cout << "Total death     : ";
	cin >> totDeath;
	cout << "Total recovered : ";
	cin >> totRecov;
}


void dispOutput (int atvCases)
{
    cout << "Active cases    : " << atvCases << endl;
    cout << "Status          : ";
	dispStatus (atvCases);	
}


int calcAverage (int numStates, int totatvCases)
{
	int avg;
	avg = totatvCases / numStates;
	return avg;
}
