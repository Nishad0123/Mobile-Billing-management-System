#include <iostream>
#include <string>

#define MAX 10
#define SUCCESS 1
#define fail 0
using namespace std;
/*****************************************************************************
							Mobile Billing System								
******************************************************************************/
int users=0;
int plans=0;


class Bill
{
	public:
	//VARIABLES
	string plan_name;					//Plan name.
	//string plan_card;					//Plan Rate card
	int call_chrg;						//charge of call
	int sms_chrg;						//charge of sms 	
	Bill *blink;		
	//string plan_detail;				//Plan Details
			
	//FUNCTIONS		
	int allPlans(Bill **top);						//Print all plans 
	int addPlan(Bill **top);				//make plan
	int editPlan(Bill **top);						//modify plan
	int deletePlan(Bill **top);					//delete plan
	int rateCard(Bill **top);						//show all PLANS Detils
			
	int plan_detail(Bill *temp);				//show plan details of 1 PLAN
	Bill* srchPlan(Bill **top);			//search plan
	//int srchPlan(Bill **top, string buf_plan_name);	
	
	Bill()
	{
		//plan_name=NULL;
		//plan_card=NULL;
		call_chrg=0;
		sms_chrg=0;
		
	}
	//void planDesc();					//print bill remarks
};


class Customer
{
	public:	
	//VARIABLES
	int cust_id;					//customer ID
	string cust_name;				//Customer name	
	int bill_no;					//Bill no.
	int tot_bill_amt;				//bill amount
	string plan_name;					//which Plan name
	string cust_msg;				//customer message/remarks
	Customer *clink;	
		
	//FUNCTIONS	
	int allCusts(Customer **head);					//print all customers
	//void addCust();				//add new customer

	int addCust(Customer **head, Bill **top);
	int editCust(Customer **head);			//edit customer details		
	int deleteCust(Customer **head);				//delete customer
	int custMsg(Customer **head);					//print customer remarks	
	int cust_detail(Customer *temp);
	Customer * searchById(Customer **head);	//search customer by customer id
		
	//void show();					//show menu 
	/*
	Customer()
	{
		cust_id=0;
		//cust_name=NULL;
		bill_no=1234;
		tot_bill_amt=0;
		//plan_name=NULL;
		//cust_msg=NULL;
		//clink=NULL;
	}
	*/
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int Bill::plan_detail(Bill *temp)
{
	cout<<"************PLAN DETAILS**************\n";
	cout<<"PLAN NAME : "<<temp->plan_name<<endl;
	cout<<"CALL CHARGE : "<<temp->call_chrg<<endl;
	cout<<"SMS CHARGE : "<<temp->sms_chrg<<endl;
	return 1;
}

Bill * Bill::srchPlan(Bill **top)	
{
	string buf_plan_name;
	cout<<"Enter the Plan name to search: ";
	cin>>buf_plan_name;
	
	Bill *temp_bill=*top;
	while(temp_bill!=NULL)
	{
		if(buf_plan_name==temp_bill->plan_name)
		{
			cout<<"Plan found\n";
			if(plan_detail(temp_bill)==1)
			{
				cout<<"details FOUND\n";
				return temp_bill;		
			}
		}
		temp_bill=temp_bill->blink;
	}
	return NULL;
}
/*
int srchPlan(Bill **top, string buf_plan_name)	
{
	//string buf_plan_name;
	//cout<<"Enter the Plan name to search: ";
	//cin>>buf_plan_name;
	
	Bill *temp_bill=*top;
	while(temp_bill!=NULL)
	{
		if(buf_plan_name==temp_bill->plan_name)
		{
			cout<<"Plan found\n";
			if(plan_detail(temp_bill)==1)
			{
				cout<<"details FOUND\n";
				return 1;	
			}
		}
		temp_bill=temp_bill->blink;
	}
	return 0;
}

*/
int Customer::addCust(Customer **head, Bill **top)
//int addCust(Customer **head)
{
	//cout<<"top plan name="<<(*top)->plan_name<<endl;
	
	//Bill *top=*top1;
	if(plans==0)
	{
		cout<<"ERROR: create PLans for users first\n";
		return 0;
	}
	Customer *fresh=new(nothrow) Customer;
	
	if(fresh==NULL)
	{
		
		cout<<"Memory Allocation failed\n";
		return 0;
	}
	
	cout<<"Enter Customer ID:\n";
	cin>>fresh->cust_id;
	
	cout<<"Enter Customer name:\n";
	cin>>fresh->cust_name;
	
	//cout<<"Enter Customer name:\n";
	//cin>>fresh->bill_no;
	fresh->bill_no=fresh->bill_no+fresh->cust_id;
	
	cout<<"Enter the Bill:\n";
	cin>>fresh->tot_bill_amt;
	
	//cout<<"Enter Plan name:\n";
	//cin>>temp_plan;				
	//cin>>fresh->plan_name;
		char msg[30];
	string temp_plan;
	Bill *buff_plan;
	buff_plan=(*top)->srchPlan(top);				//using top ptr here for passing it for searching   write it as (*top)->//
	//error: request for member ‘srchPlan’ in ‘* top’, which is of pointer type ‘Bill*’ (maybe you meant to use ‘->’ ?)
	
	if(buff_plan!=NULL)
	{
		fresh->plan_name=buff_plan->plan_name;
		cout<<"Plan is assigned!\n";
	}
	else
	{
		cout<<"THIS PLAN DOESN't EXIST\n";
		cout<<"Providing default PLAN\n";
		fresh->plan_name=(*top)->plan_name;
	}


	
	cout<<"Enter Customer remarks:\n";
	//scanf("%[^\n]s",msg);
	//fresh->cust_msg=msg;
	cin>>fresh->cust_msg;
	

	if(*head==NULL)
	{
		*head=fresh;
		return SUCCESS;
	}
	Customer *temp_cust=*head;
	while(temp_cust->clink!=NULL)
	{
		temp_cust=temp_cust->clink;
	}
	temp_cust->clink=fresh;		//replace NULL with the address of new node
	fresh->clink=NULL;		//new node's link is now NULL
	return SUCCESS;
}



int Bill::addPlan(Bill **top)
{
	Bill *fresh_bill=new(nothrow) Bill;	
	if(fresh_bill==NULL)
	{
		
		cout<<"Memory Allocation failed\n";
		return 0;
	}
	cout<<"Enter Plan Name:\n";
	cin>>fresh_bill->plan_name;;
	
	//cout<<"Enter Plan card:\n";
	//cin>>fresh_bill->plan_card;

	cout<<"Enter call_chrg:\n";
	cin>>fresh_bill->call_chrg;
	
	cout<<"Enter sms_chrg:\n";
	cin>>fresh_bill->sms_chrg;
	
	if(*top==NULL)
	{
		*top=fresh_bill;
	}	
	Bill *temp_bill=*top;
	while(temp_bill->blink!=NULL)
	{
		temp_bill=temp_bill->blink;
	}
	temp_bill->blink=fresh_bill;		//replace NULL with the address of new node
	fresh_bill->blink=NULL;		//new node's link is now NULL
	return SUCCESS;	
}

int Customer::cust_detail(Customer *temp)
{
	cout<<"************CUSTOMER DETAILS**************\n";
	cout<<"CUSTOMER ID : "<<temp->cust_id<<endl;
	cout<<"CUSTOMER NAME : "<<temp->cust_name<<endl;
	cout<<"CUSTOMER BILL NO. : "<<temp->bill_no<<endl;
	cout<<"CUSTOMER TOTAL BILL : "<<temp->tot_bill_amt<<endl;
	cout<<"CUSTOMER PLAN NAME : "<<temp->plan_name<<endl;
	cout<<"CUSTOMER MESSAGE : "<<temp->cust_msg<<endl;
	return 1;
}

Customer * Customer::searchById(Customer **head)
{
	
	int buf_cust_id;
	cout<<"Enter the Customer ID to search: ";
	cin>>buf_cust_id;
	
	Customer *temp_cust=*head;
	while(temp_cust!=NULL)
	{
		if(buf_cust_id==temp_cust->cust_id)
		{
			cout<<"CUSTOMER found\n";
			if(cust_detail(temp_cust)==1)
			{
				cout<<"CUSTORMER details FOUND\n";
				//return 1;
				return temp_cust;
			}	
		}
		temp_cust=temp_cust->clink;
	}
	return NULL;
}


int Customer::editCust(Customer **head)
{
	cout<<"Enter the Customer ID to Edit information\n";
	int optio=0;
	Customer *new_temp;
	new_temp=searchById(head);
	
	if(new_temp!=NULL)
	{
		while(optio!=7)
		{
			cout<<"Search Customer Success for EDIT operation\n";
			cout<<"Enter the OPTION to edit \n";
			cout<<"\
			1.CUSTOMER ID\n\
			2.CUSTOMER NAME\n\
			3.CUSTOMER BILL NO.\n\
			4.CUSTOMER TOTAL BILL\n\
			5.CUSTOMER PLAN NAME\n\
			6.CUSTOMER MESSAGE\n\
			7.EXIT\n";

//int cust_id;				
//string cust_name;		
//int bill_no;		
//int tot_bill_amt;
//string plan_name;
//string cust_msg;
	
			cin>>optio;
			if(optio==1)
			{
				cout<<"option 1 Enter new ID to edit\n";
				cin>>new_temp->cust_id;
				cout<<"ID MODIFIED\n";
			}
			if(optio==2)
			{
				cout<<"option 2 Enter new name to edit\n";
				cin>>new_temp->cust_name;
				cout<<"NAME MODIFIED\n";
			}
			if(optio==3)
			{
				cout<<"option 3 Enter new name to edit\n";
				cin>>new_temp->bill_no;
				cout<<"BILL No. MODIFIED\n";
			}
			if(optio==4)
			{
				cout<<"option 3 Enter new name to edit\n";
				cin>>new_temp->tot_bill_amt;
				cout<<"BILL AMOUNT MODIFIED\n";
			}
			if(optio==5)
			{
				cout<<"option 3 Enter new name to edit\n";
				cin>>new_temp->plan_name;
				cout<<"PLAN NAME MODIFIED\n";
			}
			if(optio==6)
			{
				cout<<"option 3 Enter new name to edit\n";
				cin>>new_temp->cust_msg;
				cout<<"MESSSAGE MODIFIED\n";
			}
		}

		return 1;
	}
	else
	{
		cout<<"SORRY NO SUCH ID FOUND\n";
	}
	return 0;	
}
int Customer::deleteCust(Customer **head)
{
	cout<<"Enter the Customer ID to Delete information\n";
	Customer *del_temp;
	
	del_temp=searchById(head);
	
	if(del_temp!=NULL)
	{
		cout<<"Search Customer Success for Delete operation\n";
		
		Customer *temp_node=*head;
		Customer *temp_node2=NULL;
		while(temp_node!=NULL)
		{
			if (temp_node->cust_id==del_temp->cust_id && temp_node==*head)
			{
				*head=temp_node->clink;
				return 1;
			}
			else if(temp_node->cust_id==del_temp->cust_id && temp_node!=*head)
			{
				
				temp_node2->clink=temp_node->clink;
				return 1;
				
			}
			temp_node2=temp_node;
			temp_node=temp_node->clink;
			
		}
		//return 1;
	}	
	return 0;	
}


int Bill::editPlan(Bill **top)
{
	cout<<"Enter the PLAN NAME Edit information\n";
	int optio=0;
	Bill *temp_bill;
	temp_bill=srchPlan(top);
	
	if(temp_bill!=NULL)
	{
		while(optio!=4)
		{
			cout<<"Search PLAN Success for EDIT operation\n";
			cout<<"Enter the OPTION to edit \n";
			cout<<"\
			1.PLAN NAME\n\
			2.PLAN CALL CHARGE\n\
			3.PLAN SMS CHARGE \n\
			4.EXIT\n";
	
			if(optio==1)
			{
				cout<<"option 1 Enter PLAN NAME to edit\n";
				cin>>temp_bill->plan_name;
				cout<<" PLAN NAME MODIFIED\n";	
				//return 1;
			}
			if(optio==2)
			{
				cout<<"option 2 Enter CALL CHARGE to edit\n";
				cin>>temp_bill->call_chrg;
				cout<<" PLAN CALL CHARGE MODIFIED\n";	
				//return 1;
			}	
			if(optio==3)
			{
				cout<<"option 3 Enter SMS CHARGE to edit\n";
				cin>>temp_bill->sms_chrg;
				cout<<" PLAN CALL CHARGE MODIFIED\n";	
				//return 1;
			}				
		}
		return 1;
	}		
	else
	{
		cout<<"SORRY NO SUCH PLAN FOUND\n";
	}
	return 0;
}
int Bill::deletePlan(Bill **top)
{

	cout<<"Enter the Customer ID to Delete information\n";
	Bill *del_temp;
	del_temp=srchPlan(top);
	if(del_temp!=NULL)
	{
		cout<<"Search Customer Success for Delete operation\n";
		
		Bill *temp_node=*top;
		Bill *temp_node2=NULL;
		while(temp_node!=NULL)
		{
			if (temp_node->plan_name==del_temp->plan_name && temp_node==*top)
			{
				*top=temp_node->blink;
				return 1;
			}
			else if(temp_node->plan_name==del_temp->plan_name && temp_node!=*top)
			{
				
				temp_node2->blink=temp_node->blink;
				return 1;
				
			}
			temp_node2=temp_node;
			temp_node=temp_node->blink;
			
		}
		//return 1;
	}	
	return 0;	

}


int Customer::allCusts(Customer **head)
{
	cout<<"SHOWING ALL CUSTOMERS\n";
	int i=0;
	Customer *temp;
	temp=*head;
	while(temp!=NULL)
	{ 	cout<<"Customer "<<++i<<endl;
		cust_detail(temp);
		temp=temp->clink;
	}
	return 1;
}


int Bill::allPlans(Bill **top)
{
	cout<<"SHOWING ALL PLANS\n";
	int i=0;
	Bill *temp;
	temp=*top;
	while(temp!=NULL)
	{ 	cout<<"Plan "<<++i<<endl;
		plan_detail(temp);
		temp=temp->blink;
	}
	return 1;
}

int Bill::rateCard(Bill **top)
{
	cout<<"SHOWING RATE CARD\n";
	allPlans(top);
	return 1;
}