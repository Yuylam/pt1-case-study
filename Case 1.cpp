#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	string name[10], matricNumber[10];
	char studentAns[10][20], correctAns[20], grade[10];
	bool correctedAns[20];
	int percentage[10];
	int studentNum, studentIndex, missNum;
	
	studentNum = readFile(name, matricNumber, studentAns, correctAns);
	
	// Get Matric Number
	
	// Find student index
	
	// Find percentage and grade
	
	// Output file
	
	missNum = compareAns(studentIndex, studentAns, correctAns, correctedAns);
	
	printReport(studentIndex, studentAns, correctAns, correctedAns, percentage, grade);
	
	
	return 0;
}
