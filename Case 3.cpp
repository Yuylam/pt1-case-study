
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
