#include<iostream>
using namespace std;
typedef struct node
{
    int id;
    string proname;
    double price,amount;
    int quant;
    string type;
    struct node *next;
};
typedef struct i{
    string productname;
    string producttype;
    double productprice=0;
    int quantity=0;
    double productamont=0;
    int identity;
    
}i;
class supermarket
{
    node *hn;
    i item[100];
    int count=0;
    public:
    supermarket()
    {
        hn=NULL;
    }
    void create()
    {
        char c;
        do{
        node *nn=new node;
        count++;
        nn->next=NULL;
        cout<<"\nEnter product ID : ";
        cin>>nn->id;
        cout<<"Enter product type : ";
        cin>>nn->type;
        cout<<"\nEnter product name : ";
        cin>>nn->proname;
        cout<<"\nEnter product rate : ";
        cin>>nn->price;
        cout<<"\nEnter product stock : ";
        cin>>nn->quant;
        if(hn==NULL)
        {
            hn=nn;
        }
        else
        {
            node *cn=hn;
            while(cn->next!=NULL)
            {
                cn=cn->next;
            }
            nn->next=cn->next;
            cn->next=nn;
        }
        cout<<"\nAdd more products? (y/n) :";
        cin>>c;
    }while(c=='y'||c=='Y');
    }
void display()
{
    cout<<"\nTotal no. of products are : "<<count<<"\n";
    
    if(hn==NULL)
    cout<<"\nList is empty\n";
    
    else
    {
        cout<<"Product ID\tProduct type\tProduct Name\t\tStock\tRate\n\n";
        node *cn=hn;
        while(cn!=NULL)
        {
            cout<<cn->id<<"\t"<<cn->type<<"\t"<<cn->proname<<"\t\t"<<cn->quant<<"\t"<<cn->price<<"\n";
            cn=cn->next;
        }
    }
}
void buy()
{
    int ID,n,q,flag=0,j=0;
    int a;
    cout<<"\nHow many products you want to buy : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
    
        cout<<"Enter product id to buy : ";
        cin>>ID;
        node *cn=hn;
        while(cn!=NULL)
        {   
                
    
                if(cn->id==ID)
                {
                    
                flag=1;
                item[i].identity=cn->id;
                cout<<"Product of ID "<<ID<<" is available\n";
                cout<<"Enter quantity : ";
                cin>>q;
                
                if(q<=cn->quant)
                {
                    j++;
                    string s=cn->type;
                    string b=cn->proname;
                    
                    
                    item[i].quantity=q;
                item[i].productname=cn->proname;
                    item[i].producttype=cn->type;
                    item[i].productprice=cn->price;
                    item[i].productamont=item[i].productamont+(item[i].quantity*item[i].productprice);
                    a=i;
                    
                }
                else if(q>cn->quant)
                {
                    cout<<"\nSorry....Out of Stock!!\n";
                    
                }
                
            }
            cn=cn->next;
        }
        if(flag==0)
        {
            cout<<"\nProduct not found!!\n";
        }
    }
    
        cout<<"You have bought "<<n<<" products\n";
        cout<<"\nHere is your bill :-\n";
        for(int i=0;i<j;i++)
        {
            cout<<item[i].identity<<"\t"<<item[i].producttype<<"\t"<<item[i].productname<<"\t"<<item[i].quantity<<"\t"<<item[i].productprice<<"\n";
        }
        cout<<"Total amount to paid is : "<<item[a].productamont;
        
}
void del()
{
        int p;
        cout<<"For deleting product enter its id : ";
        cin>>p;
        node *cn,*temp;
        cn=hn;
        while(cn!=NULL&&cn->id!=p)
        {   
            
            temp=cn;
            cn=cn->next;
        }
        temp->next=cn->next;
        delete cn;
        
}
void modify()
{
    /*int k;
    cout<<"\nModify by:\n1.Product ID\n2.Name\n3.Type\n4.Rate\n5.Stock\n";
    cin>>k;
    switch(k)
    */
    int p,flag=0;
        cout<<"For modifying product enter its id : ";
        cin>>p;
        node *cn=hn;
        while(cn!=NULL)
        {   
                if(cn->id==p)
                {
                    
                flag=1;
                cout<<"\nEnter new product ID : ";
                cin>>cn->id;
                cout<<"Enter new product type : ";
        cin>>cn->type;
        cout<<"\nEnter new product name : ";
        cin>>cn->proname;
        cout<<"\nEnter new product rate : ";
        cin>>cn->price;
        cout<<"\nEnter new product stock : ";
        cin>>cn->quant;
                }
                cn=cn->next;
        }
                if(flag==0)
                cout<<"\nProduct not found!!!\n";
                
}
};
int main()
{
    supermarket s;
    s.create();
    s.display();
    s.buy();
    s.del();
    s.display();
    s.modify();
    return 0;
}


