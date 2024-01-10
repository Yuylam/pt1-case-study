
double grandTotal;
double averageSales[12], monthlyTotalSales[12];

double totalSalesStore[5];
int sales[5][12];
string stores[5];

double highSales, lowSales;
int highMonth, lowMonth;
string highStore, lowStore;

void readFile(int sales[][12], string stores[]){
	
}

double grandTotalSales(double totalSalesStore[]){
	int sum = 0;
	for (int i = 0; i < 5; i++){
		sum += totalSalesStore[i];
	}
	return sum;
}

int totalSalesByMonth(int sales[5][12], int month){
	int sum = 0;
	for (int i = 0; i < 5; i++){
		sum += sales[i][month];
	}
	return sum;
}

int totalSalesByStore(int sales[5][12], int store){
	int sum = 0;
	for (int i = 0; i < 12; i++){
		sum += sales[store][i];
	}
	return sum;
}

void highestSale(double& highSales, int& highMonth, string& highStore, int sales[][12]){
	
}

void lowestSale(double& lowSales, int& lowMonth, string& lowStore, int sales[][12]){
	
}









#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Function Prototype
void readFile(int[][12], string[]);
int grandTotalSales(int[]);
int totalSalesByMonth(int[5][12], int);
int totalSalesByStore(int[5][12], int);
void highestSale(int&, int&, string&, int[][12]);
void lowestSale(int&, int&, string&, int[][12]);

int main(){
	// Define Variable
	int grandTotal, monthlyTotalSales[12];
	double averageSales;
	
	int totalSalesStore[5];
	int sales[5][12], store;
	int i, month;
	string stores[5];
	string Month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	
	int highSales, lowSales;
	int highMonth, lowMonth;
	string highStore, lowStore;
		
	// Call readFile function to main function
	readFile(sales, stores);
	
	// Calculate the total sales over all stores
	for (i = 0; i < 5; i++){
		totalSalesStore[i] = totalSalesByStore(sales, i);
	}
	
	// The grand total sales ang average sales for 12 months
	grandTotal = grandTotalSales(totalSalesStore);
	averageSales = grandTotal/12.0;
	
	cout << "total of sales over all stores: RM " << fixed << setprecision(2) << setw(10) << grandTotal*1000.00 << endl
		 <<	"Average sales per month: RM " << fixed << setprecision(2) << setw(10) << averageSales*1000 << endl << endl;
	
	// The highest sales' store, month and the amount of sales
	highestSale(highSales, highMonth, highStore, sales);
	cout << "The highest sales:" << endl 
		 << "------------------" << endl
		 << "Store: " << highStore << endl
		 << "Month: " << Month[highMonth-1] << endl
		 << "Sales: RM " << fixed << setprecision(2) << setw(10) << highSales*1000.00 << endl << endl;
	
	// The lowest sales' store, month and the amount of sales
	lowestSale(lowSales, lowMonth, lowStore, sales);
	cout << "The lowest sales: " << endl 
		 << "------------------" << endl
		 << "Store: " << lowStore << endl
		 << "Month: " << Month[lowMonth-1] << endl
		 << "Sales: RM " << fixed << setprecision(2) << setw(10) << lowSales*1000.00 << endl << endl;
		
	// Total Sales By Month
	for (i = 0; i < 12; i++){                
		monthlyTotalSales[i] = totalSalesByMonth(sales, i);
	}
	cout << "Total sales by month:" << endl
		 << "Month    Sales" << endl 
		 << left << setw(9) << "-----" << "-----" << endl;
	for (i = 0; i < 12; i++){
		cout << left << setw(6) << Month[i] << "RM " << fixed << setprecision(2) << setw(10) << monthlyTotalSales[i]*1000.00 << endl ;
	}
	
	// Total Sales By Store
	for (i = 0; i < 5; i++){                     
		totalSalesStore[i] = totalSalesByStore(sales, i);
	}
	cout << left << setw(10) << "\nTotal sales by store:" << endl 
	     << setw(17) << "Stores" << "Total Sales" << endl 
		 << setw(17) << "-----" << "-----------" << endl;
	for (i = 0; i < 5; i++){
		cout << left << setw(15) << stores[i] << "RM  " << fixed << setprecision(2) << setw(10) << totalSalesStore[i]*1000.00 << endl;
	}

	// Profitable stores
	cout << "\nProfitable stores:" << endl
		 << "-----------------" << endl;
	
	for (i = 0; i < 5; i++){
		if (totalSalesStore[i] > 600)
			cout << stores[i] << endl;
	}
	return 0;	 
}

void readFile (int sales [][12], string stores []) {
	
	// int j = 0 ;
	ifstream inFile ;
	inFile.open("sales2014.dat") ;
	
	for (int i = 0; i < 5 ; i++){
		
		for (int j = 0; j < 12; j++){

		inFile >> sales[i][j] ;
		}
		inFile.ignore() ;
		getline(inFile, stores [i]);
	}
	
	inFile.close() ;
}

int grandTotalSales(int totalSalesStore[]){
	int sum = 0;
	for (int i = 0; i < 5; i++){
		sum += totalSalesStore[i];
	}
	return sum;
}

int totalSalesByMonth(int sales[5][12], int month){
	int sum = 0;
	for (int i = 0; i < 5; i++){
		sum += sales[i][month];
	}
	return sum;
}

int totalSalesByStore(int sales[5][12], int store){
	int sum = 0;
	for (int i = 0; i < 12; i++){
		sum += sales[store][i];
	}
	return sum;
}

void highestSale(int& highSales, int& highMonth, string& highStore, int sales[][12]){

}

void lowestSale(int& lowSales, int& lowMonth, string& lowStore, int sales[][12]){

}




