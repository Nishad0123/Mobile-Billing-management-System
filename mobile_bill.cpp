#include <iostream>
#include <string>
#include "bill.h"
using namespace std;
#define MAX 10

/*****************************************************************************
							Mobile Billing System								
******************************************************************************/



void showMenu()
{
	
	
	cout<<"***************************************************************************************************************************************\n";
	cout<<" 						Welcome to mobile Billing System"			<<endl;
	cout<<"***************************************************************************************************************************************\n";
	cout<<" 1. Check all customers allCusts()"			<<endl;	//			
	cout<<" 2. Add Customer  addCust()"					<<endl; //
	cout<<" 3. Edit Customer  editCust(string)"			<<endl; //
	cout<<" 4. Delete Customer  deleteCust()"			<<endl; //

	cout<<" 5. Search by customer ID searchById(string)"<<endl; //
	
	cout<<" 6. Check all plans allPlans()"				<<endl; //
	cout<<" 7. Add plan  addPlan()"						<<endl; //
	cout<<" 8. Edit plan  editPlan()"					<<endl;
	cout<<" 9. Delete plan deletePlan()"				<<endl;
	cout<<" 10. RATE CARD"		<<endl;
	cout<<" 11. Search plan srch_plan()"				<<endl;
	cout<<" PRESS 0 TO EXIST\n"							<<endl;
}

int main()
{
//	int topidx=-1;
//	int stk_arr[MAX];


//Customer head1;
//Bill top1;

//Customer *head=&head1;
//Bill *top=&top1;


Customer *head;
Bill *top;
head=NULL;
top=NULL;

int choise=0;

showMenu();
cout<<" Enter a Choise = ";
cin>>choise;
cout<<"Choise Entered ="<<choise<<endl;
	//while(choise>0 && choise<14)
	while(choise!=0)
	{
		if(choise==1)
		{
			cout<<"Option 1 selected"<<endl;
			cout<<"Printing All Customers"<<endl;
			if(users==0)
			{
				cout<<"SORRY NO USERS AVAILABLE\n";
				
			}
			if(head->allCusts(&head)==1)
			{
				cout<<"SHOW ALL Customer Success\n";
				users++;
			//allCust();
			}
			
		}
		else if(choise==2)
		{
			cout<<"Option 2 selected"<<endl;
			cout<<"Add new customer"<<endl;
			
			if(head->addCust(&head, &top)==1)
			{
				cout<<"ADD Customer Success\n";
				users++;
			//addCust();
			}
		}
		else if(choise==3)
		{
			cout<<"Option 3 selected"<<endl;
			cout<<"Edit Customer"<<endl;
			if(users==0)
			{
				cout<<"SORRY NO USERS AVAILABLE\n";
			}
			if(head->editCust(&head)==1)
			{
				cout<<"EDIT Customer Success\n";
				
			//editCust();
			}
			
		}
		else if(choise==4)
		{
			cout<<"Option 4 selected"<<endl;
			cout<<"Delete Customer "<<endl;
			if(users==0)
			{
				cout<<"SORRY NO USERS AVAILABLE\n";
			}
			if(head->deleteCust(&head)==1)
			{
				cout<<"DELETE Customer Success\n";
				users++;
			//deleteCust();
			}

		}
		else if(choise==5)
		{
			cout<<"Option 5 selected"<<endl;
			cout<<"Search customer by ID"<<endl;
			
			if(users==0)
			{
				cout<<"SORRY NO USERS AVAILABLE\n";
			}
			
			Customer *new_temp;
			new_temp=head->searchById(&head);
			if(new_temp!=NULL)
			{
				cout<<"Search Customer Success\n";
				
			}
			//searchById(string);
		}
		else if(choise==6)
		{
			cout<<"Option 6 selected"<<endl;
			cout<<"Show all plans"<<endl;
			if(plans==0)
			{
				cout<<"SORRY NO PLANS AVAILABLE\n";
			}
			
			if(top->allPlans(&top)==1)
			{
				cout<<"SHOW ALL PLAN\n";
			//allPlans();
			}
		}
		else if(choise==7)
		{
			cout<<"Option 7 selected"<<endl;
			cout<<"Add PLAN details"<<endl;
			if(plans==0)
			{
				cout<<"SORRY NO PLANS AVAILABLE\n";
			}
			if(top->addPlan(&top)==1)
			{
				cout<<"ADD PLAN SUCCESS\n";
				plans++;
				//addBill();
			}
			
		}
		else if(choise==8)
		{
			cout<<"Option 8 selected"<<endl;
			cout<<"Edit PLAN details"<<endl;
			if(plans==0)
			{
				cout<<"SORRY NO PLANS AVAILABLE\n";
			}
			if(top->editPlan(&top)==1)
			{
				cout<<"EDIT PLAN SUCCESS\n";
				
				//editPlan();
			}
		}
		else if(choise==9)
		{
			cout<<"Option 9 selected"<<endl;
			cout<<"Delete PLAN details"<<endl;
			if(plans==0)
			{
				cout<<"SORRY NO PLANS AVAILABLE\n";
			}
			if(top->deletePlan(&top)==1)
			{
				cout<<"DELETE PLAN Success\n";
				plans++;
			//deleteCust();
			}
		}
		else if(choise==10)
		{
			cout<<"Option 10 selected"<<endl;
			cout<<"RATE CARD"<<endl;
			if(plans==0)
			{
				cout<<"SORRY NO PLANS AVAILABLE\n";
			}
			if(top->rateCard(&top)==1)
			{
				//srchPlan();
				cout<<"PLAN FOUND Success\n";
				//srch_bno();
			}
		}
		else if(choise==11)
		{
			cout<<"Option 11 selected"<<endl;
			cout<<"Search PLAN"<<endl;
			if(plans==0)
			{
				cout<<"SORRY NO PLANS AVAILABLE\n";
			}
			if(plans==0)
			{
				cout<<"SORRY NO PLANS AVAILABLE\n";
			}
			if(top->srchPlan(&top)!=NULL)
			{

				cout<<"PLAN FOUND Success\n";
				//srch_bno();
			}
		}
		else if(choise<0 || choise>11)
		{
			cout<<"Wrong Option selected"<<endl;
			cout<<"Exiting.."<<endl;
			return 0;
		}
		int opo=0;
		cout<<"Press any number to continue\n";
		//getchar();
	cin>>opo;
	showMenu();
	cout<<"Enter New choise"<<endl;
	cin>>choise;
	cout<<"Choise Entered ="<<choise<<endl;

	}
return 0;
}

