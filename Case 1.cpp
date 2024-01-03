#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int numQuestions = 20;
const int numStudents = 20;

void readFile(string name[20], string matricNum[10], char studentAns[30], char correctAns[30])
{
    ifstream inFile;
    inFile.open("StudentAnswer.dat");

    if (!inFile)
    {
    cerr << "ERROR. File not found.\n";
    exit(1);
    }

for (int i = 0; i < numStudents; ++i)
{
inFile >> name[i] >> matricNum[i];

for (int j = 0; j < numQuestions; ++j)
    {
    inFile >> studentAns[i][j];
    }
}

inFile.close();

    ifstream inFile2;
    inFile2.open("CorrectAns.txt");

    if(!inFile2)
{
        cerr << "Error. File not found.\n";
        exit(1);
}

    for (int j = 0; j < numQuestions; ++j)
    {
        inFile2 >> correctAns[j];
    }

    inFile2.close()

}
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
