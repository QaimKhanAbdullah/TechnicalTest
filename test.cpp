/*
Author: ABDULLAH QAIM KHAN
Date: 18-Septemeber 2021

To avoid file location path conflicts the configuration of the cassettes are hardcoded in the driver code.  
ASSUMPTIONS:
Total Cassettes 5.
Number of Active Cassettes are those whose STATUS value is set to 0 during initialization in the driver code.  


HOW IT WORKS: The program takes the amount as input from the Console. It finds the combination of denomination that make up the total requested amount
*/

#include<iostream>
#include<cstring>

using namespace std;

typedef struct cdm_cashunit
{
int Type;
char UnitID;
short Denomination;
int Count;
int Maximum; 
short Status;
} CASHUNIT, *LPCASHUNIT;

typedef struct cdm_cu_info
{
int Count;
LPCASHUNIT *lppList;
} CUINFO, *LPCUINFO;

/**
         * Method to print the cash Unit State
         *
         *return void
*/
void printCashUnitState(CASHUNIT cashArray[],int size);
/**
         * Method to print the available denomination Combination
         *
         *return void
*/        
void printDenominationCombinations(CASHUNIT cashArray[],int amount,int size);

//driver Code
int main(){
// configurations are hardcoded for simplicity.
CASHUNIT  TotalCassettes[5] = {
{0,'A',5,10,1,0},
{0,'B',10,10,1,0},
{0,'C',20,10,1,0},
{1,'D',50,10,1,1},
{1,'E',100,10,1,1}
};
TotalCassettes[0].Denomination = 5;
TotalCassettes[1].Denomination = 10;
TotalCassettes[2].Denomination = 20;
TotalCassettes[3].Denomination = 50;
TotalCassettes[4].Denomination = 100;


int amount=0;
int size = 5;
printCashUnitState(TotalCassettes,size);
//Taking amount as input from the user.
cout<<"Enter the Amount (It should be multiple of 5s)"<<endl;

//if amount is not in multiple of 5 then we will reject the transaction.
bool flag= 0;
do{
	if(flag ==1 )
	cout<<"Invalid Amount Entered, Please Enter Again."<<endl;
	cin>>amount;
	flag =1;
} while( (amount < 0) || (amount % 5 != 0));

printDenominationCombinations(TotalCassettes,amount,size);

printCashUnitState(TotalCassettes,size);
}


//function definitions 

void printCashUnitState(CASHUNIT cashArray[],int size)
{
	cout<<"Type		";
	cout<<"UnitID		";
	cout<<"DENOMINATION		";
	cout<<"TRAY COUNT    	";
	cout<<"MAXIMUM			";
	cout<<"Status		"<<endl;
	for(int i = 0 ; i< size ; i++){
		cout<<"["<<cashArray[i].Type<<"]		";
		cout<<"["<<cashArray[i].UnitID<<"]		";
		cout<<"["<<cashArray[i].Denomination<<"]			";
		cout<<"["<<cashArray[i].Count<<"]			";
		cout<<"["<<cashArray[i].Maximum<<"]		";
		cout<<"["<<cashArray[i].Status<<"]		";
		cout<<endl;
	}
	cout<<endl<<endl<<endl<<endl;
	
}      

void printDenominationCombinations(CASHUNIT cashArray[],int amount,int size)
{
	int Num_of_Five, Num_of_Ten,Num_of_Twenty,Num_of_Fifty;
	int HundredDenomination = 0;
	HundredDenomination = amount / 100;
	bool flag = 0;
	if((HundredDenomination < cashArray[size-1].Count) && (cashArray[size-1].Type == 0)  && (cashArray[size-1].Status == 0))
	{
		amount = amount - (HundredDenomination *100);
		cashArray[size-1].Count  = cashArray[size-1].Count - HundredDenomination;
		cout<<"100 notes ["<<HundredDenomination<<"] ";
		flag =1;
	}
	
	if(amount > 0)
	{
		Num_of_Fifty = amount / 50;
		if((Num_of_Fifty < cashArray[size-2].Count) && (cashArray[size-2].Type == 0)  && (cashArray[size-2].Status == 0))
		{
			amount = amount - (Num_of_Fifty *50);
			cashArray[size-2].Count  = cashArray[size-2].Count - Num_of_Fifty;
			cout<<"50 notes ["<<Num_of_Fifty<<"] ";
			flag =1;
		}
		
	  
	}
	if(amount > 0)
	{
		Num_of_Twenty = amount / 20;
		if((Num_of_Twenty < cashArray[size-3].Count) && (cashArray[size-3].Type == 0) && (cashArray[size-3].Status == 0))
		{
			amount = amount - (Num_of_Twenty*20);
			cashArray[size-3].Count  = cashArray[size-3].Count - Num_of_Twenty;
			cout<<"20 NOTES ["<<Num_of_Twenty<<"] ";
			flag =1;
		}
	  
	}
	if(amount > 0)
	{
		Num_of_Ten = amount / 10;
		if((Num_of_Ten < cashArray[size-4].Count) && (cashArray[size-4].Type == 0) && (cashArray[size-4].Status == 0))
		{
			amount = amount - (Num_of_Ten *10);
			cashArray[size-4].Count  = cashArray[size-4].Count - Num_of_Ten;
			cout<<"10 notes ["<<Num_of_Ten<<"] ";
			flag =1;
		}
	  
	}
	if(amount > 0){
		Num_of_Five = amount / 5;
		if((Num_of_Five < cashArray[size-5].Count) && (cashArray[size-5].Type == 0) && (cashArray[size-5].Status == 0))
		{
			amount = amount - (Num_of_Five*5);
			cashArray[size-5].Count  = cashArray[size-5].Count - Num_of_Five;
			cout<<"5 notes ["<<Num_of_Five<<"] ";
			flag =1;
		}
	  
	}
	if(flag == 0 )
	{
		cout<<"ATM IS OUT OF CASH."<<endl;
	}
	cout<<endl<<endl<<endl;
	
	
}

