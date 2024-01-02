#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int readFile(string[][20], string[], char[], char[]);
int compareAns(int, char[][20], char[], bool[]);
void printMissQuestion(int, char[][20], char[], bool[]);
void printReport(string[], string[], int[], char[]);

int main(){
	string name[10], 				// Student name read from file
	       matricNumber[10];			// Student ID read from file
	char studentAns[10][20], 			// Student answer read from file
	     correctAns[20], 				// Correct answer read from file
	     grade[10];					// Grade computed of each student
	bool correctedAns[20];	
	int percentage[10];				// Percentage computed of each student
	int studentNum, 
	    studentIndex = -1, 
	    missNum;
	const int QUES_NUM = 20;
	ofstream outFile;
	
	studentNum = readFile(name, matricNumber, studentAns, correctAns);
	
	// Find percentage and grade
	for (int i = 0; i < QUES_NUM; i++){
		missNum = compareAns(studentIndex, studentAns, correctAns, correctedAns);
		percentage[i] = (QUES_NUM - missNum) / static_cast<double>(QUES_NUM) * 100;
		if(percentage >= 80)
			grade[i] = 'A';
		else if(percentage >= 70)
			grade[i] = 'B';
		else if(percentage >= 60)
			grade[i] = 'C';
		else
			grade[i]  = 'F';
	}

	printReport(name, matricNumber, percentage, grade);
	
	// Get Matric Number and find student index
	do{
		cout << "Enter the student ID: ";
		cin >> studentID;
		for (int i = 0; i < studentNum; i++){
			if (matricNumber[i] == studentID){
				studentIndex = i;
				break;
			}
		}
		if (studentIndex == -1){
			cout << "The ID does not exist in the database\n";
		}
	}
	while(studentIndex == -1);

	// Print Report
	cout
	<< "EXAM RESULT\n"
	<< "Name: " << name[studentIndex] << endl
	<< "Student ID: " << matricNumber[studentIndex] << endl
	<< "Number of questions missed: " << compareAns(studentIndex, studentAns, correctAns, correctedAns) << endl
	<< printMissQuestion(studentIndex, studentAns, correctAns, correctedAns)
	<< "Percentage: " << percentage[studentIndex] << "%, GRED: " << grade[studentIndex];
	
	return 0;
}


 void printMissQuestion (int stuIndex, char stuAns [][20], char correctAns [], bool TF [] ) {
	
	int wrongQues ;
	wrongQues = compare (stuIndex, stuAns, correctAns, TF) ; 
	cout << "List of the questions missed : \n " 
		 << left << setw(15) << "Question " << setw(15) << "Correct Answer" << setw(15) << "Student Answer \n" ;
	
	for ( int i = 0; i < 21; i++ ){
		
	if ( TF == 1 )
		continue ;
		
	else {             // when TF == 0, print out the wrong ans
		cout << left << setw(15) << ++i << setw(15) << correctAns [i] << setw(15) << stuAns [stuIndex][i] << endl ;
	}
	}
	
} 



void printReport(string name[], string id[], int percentage[], char grade[] ){
	
	ofstream outFile ;
	outFile.open (" Output1.txt") ;
	
	outFile << "LIST OF STUDENTS AND GRADES " << endl ;
	
	outFile << left << setw(15) << "NAME " << setw(15) << "ID" << setw(15) << "PERCENTAGE" << setw(15) << "GRADE" << endl ;
	for (int stuIndex = 0; stuIndex < 16; stuIndex++ ){

		outFile << setw(15) << name [stuIndex] << setw(15) << id [stuIndex] << setw(15) << percentage[stuIndex] << setw(15) << grade[stuIndex]<< endl ;
	
	}
	
	outFile.close() ;
}
