#include<iostream>
using namespace std;
class CQueue
{
    int q[100],f,r,n;
public:
    CQueue()
    {
        f=r=-1;
        n=5;
    }
    CQueue(int n)
    {
        f=r=-1;
        this->n=n;
    }

    void enqueue(int x)
    {
        if((r==n-1 && f==0) || r==f-1)
        {
            cout<<"queue overflow\n";
            return;
        }
        if(r==n-1)
        {
            r=0;
        }
        else{
            r+=1;
        }
        q[r]=x;
        if(f==-1)
        {
            f=0;
        }
    }

    int dequeue()
    {
        if(f==-1)
        {
            cout<<"queue underflow\n";
            return -1;
        }
        int temp=q[f];
        if(f==n-1)
        {
            f=0;
            return temp;
        }
        if(f==r)
        {
            f=r=-1;
            return temp;
        }
        f+=1;
        return temp;

    }

    void display()
    {
        if(f==-1)
        {
            cout<<"queue underflow\n";
            return;
        }
        if(f<r)
        {
            for(int i=f;i<=r;i++)
            {
                cout<<q[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            for(int i=f;i<=n-1;i++)
            {
                cout<<q[i]<<" ";
            }
            for(int i=0;i<=r;i++)
            {
                cout<<q[i]<<" ";
            }
            cout<<endl;

        }
    }
};



int main()
{
    CQueue q1;
    int s,val,p;
    do
    {
        cout<<"enter 1 for enqueue\n";
        cout<<"enter 2 for dequeue\n";
        cout<<"enter 3 for display\n";
        cout<<"enter 4 for exit\n";
        cout<<"enter your choice : ";
        cin>>s;
        switch(s)
        {
        case 1:
            cout<<"enter element to insert : ";
            cin>>val;
            q1.enqueue(val);
            break;
        case 2:
            cout<<"deleted element is "<<q1.dequeue()<<"\n";
            break;
          case 3:
            q1.display();
            break;
          case 4:
            break;
          default:
            cout<<"Invalid input\n";
            break;

        }
    }while(s!=4);
q1.display();
}
