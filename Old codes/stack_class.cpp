#include<iostream>

#define UNDERFLOW -400000
#define OVERFLOW 400000
#define SUCCESS 1
using namespace std;
class stack{
    //public:    
        long max;
        int *arr;
        int curi;
    public:
    stack(long size=10000){
        max=size;
        arr=new int[max];
        curi=-1;
    }

    
        bool empty(){
            if (curi==-1)
                return 1;
            else return 0;
        }
        bool full(){
            if(curi==max-1)
                return 1;
            else return 0;
        }
        int push(int p){
            if(this->full()) return OVERFLOW;
            curi++;
            arr[curi]=p;
            return SUCCESS;
            }
        int pop(){
            if(this->empty()) return UNDERFLOW;
            int ret=this->top();
            curi--;
            return ret;
        }
        int top(){
            if(this->empty()) return UNDERFLOW;
            return arr[curi];
        }
        void display(){
            if(this->empty()) {cout<<"stack empty";return;}
            cout<<"displaying stack: ";
            int i;
            for(i=0;i<=curi;i++)
                cout<<arr[i]<<' ';
        } 
};
int main(){
    int choice;
    cout<<"enter size of stack";
    int size;
    cin>>size;
    stack s(size);
    cout<<"1.push\n2.pop\n3.display\n0.exit\n";
    cin>>choice;
    int val;
    while(choice){
        switch(choice){
            case 1:
                cin>>val;
                if(s.push(val)==OVERFLOW) cout<<"overflow\n";
                else cout<<"success\n";
		        break;
            case 2:
                int k;
		        if((k=s.pop())==UNDERFLOW) cout<<"underflow\n";
                else cout<<k<<" popped\n";
	           	break;
            case 3:
                s.display();
                cout<<endl;
                break;
            }
        cin>>choice;
    }
    cout<<"exiting..."<<endl;       
    return 0;
}
