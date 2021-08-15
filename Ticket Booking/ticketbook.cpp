#include<iostream>
using namespace std;
typedef struct node
{
	char status;
	string name;
	long long mob;
	node *next,*prev;
}node;
class cinemax
{
	node *hn[10];
	public:
		cinemax()
		{


			for(int i=0;i<10;i++)
			{
				hn[i]=NULL;
			}
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<7;j++)
			{
				node *nn;
				nn=new node;
				nn->status='A';
				nn->name=" ";
				nn->mob=0;
				if(hn[i]==NULL)
				{
					hn[i]=nn;
					hn[i]->next=hn[i];
					hn[i]->prev=hn[i];
				}
				else
				{
					node *cn;
					cn=hn[i];
					while(cn->next!=hn[i])
					{
						cn=cn->next;
					}
						cn->next=nn;
						nn->prev=cn;
						nn->next=hn[i];
						hn[i]->prev=nn;
				}
			}
		}
		}

void display()
{
    cout<<"                                     CINEMAX"<<endl;
    cout<<"..................PLATINUM....................\n";
    cout<<"\n";
	for(int i=0;i<3;i++)
	{	node *cn=hn[i];
		for(int j=0;j<7;j++)
		{

			cout<<cn->status<<"\t";
			cn=cn->next;
		}
			cout<<"\n";
	}
	cout<<"\n\n";
	cout<<"..................GOLD.......................\n";
    cout<<"\n";
	for(int i=3;i<6;i++)
	{	node *cn=hn[i];
		for(int j=0;j<7;j++)
		{

			cout<<cn->status<<"\t";
			cn=cn->next;
		}
			cout<<"\n";
	}
	cout<<"\n\n";
	cout<<"..................SILVER.......................\n";
    cout<<"\n";
	for(int i=6;i<10;i++)
	{	node *cn=hn[i];
		for(int j=0;j<7;j++)
		{

			cout<<cn->status<<"\t";
			cn=cn->next;
		}
			cout<<"\n";
	}
	cout<<"\n\n";
	cout<<"Platium=150\nGold=120\nSilver=90\n";
}
void book()
{
    int r,s,n;
    cout<<"Welcome!!Book your tickets..!!\n";
    cout<<"Enter number of tickets to be booked : ";
    cin>>n;
    if(n<1){
        cout<<"Enter a valid number";
    }
    else{
    for(int j=0;j<n;j++)
    {
    cout<<" For ticket number "<<j+1<<"\n";
    cout<<"Enter row number : ";
    cin>>r;
    cout<<"Enter seat number : ";
    cin>>s;
    node *cn=hn[r-1];
    for(int i=1;i<s;i++)
    {
        cn=cn->next;
    }
    if(cn->status=='A')
    {
    cout<<"Your seat of row "<<r<<" "<<"and seat no. "<<s<<" "<<"is available\n";



    char ans;
    cout<<"\nWant to buy?..(y/n) :- ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
        cn->status='B';
    cout<<"Enter your name : ";
    cin>>cn->name;
    cout<<"Enter mob no.: ";
    cin>>cn->mob;
    if(r<4)
    cout<<"Your chosen seat is PLATINUM type....amount to be paid is : "<<150<<"\n";
    else if(r>3&&r<7)
    cout<<"Your chosen seat is GOLD type....Amount to be paid is : "<<120<<"\n";
    else if(r>6&&r<=10)
    cout<<"Your chosen seat is SILVER type....Amount to be paid is : "<<90<<"\n";

    }
    else if(ans=='n'||ans=='N')
    {
        cout<<"Thank you for visiting cinemax theatre booking\n";
    }
    }
    else if(cn->status=='B')
    {
    cout<<"Sorry!!Already booked\n";
j--;
    }
    }
}
}
void cancel()
{
    long long mob;
	int flag=0;
    cout<<"\nFor cancellation :-\n";
    cout<<"Enter your mobile number : ";
    cin>>mob;
    for(int i=0;i<7;i++)
    {
        node *cn=hn[i];
        for(int j=0;j<7;j++)
        {
            if(cn->mob==mob)
            {
		flag=1;
                cout<<"\nYour booking record is available\n";
                cout<<"Here are your details :-\n";
                cout<<"BOOKING STATUS : "<<cn->status<<endl;
                cout<<"NAME : "<<cn->name<<endl;
                cout<<"MOBILE NO. : "<<cn->mob<<endl;
                char v;
                cout<<"Are you sure you want to cancel?(y/n) : ";
                cin>>v;
                if(v=='y'||v=='Y')
                {
                    cn->status='A';
                    cout<<".....Booking successfully cancelled.....\n";
                }
                else
                {
                    cout<<"\nBooking record retained...no cancellation\n";
                }
            }

            cn=cn->next;
        }

    }
     if(flag==0)
	{
		cout<<"\nSorry...invalid credentials!!";
	}


}
};
int main()
{
    char a;
    int choice;
	cinemax c1;
	c1.display();
	do{
	    cout<<"\nEnter choice : 1.BOOK TICKETS 2.CANCEL BOOKING\n";
	    cin>>choice;
	    switch(choice)
	    {

	        case 1:c1.book();
	c1.display();
	break;
	case 2:c1.cancel();
	c1.display();
	break;
	default:cout<<"\n invalid choice\n";
	    }cout<<"\nContinue??...(y/n)  :- ";
	    cin>>a;
	}while(a=='y'||a=='Y');

	return 0;
}
