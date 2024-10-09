#include<iostream>
#include <conio.h>


using namespace std;

class paisa;
class rupee{
public:
    float r;
    rupee(){
        cout<<"Enter Rupees : ";
        cin>>r;
    }
    void display(){
        cout<<"The amount in rupee= RS. "<<r<<endl;
    }
    rupee(paisa &p2);
};

class paisa{
    public:
        int p;
        paisa(){
            cout<<"Enter Paisa : ";
            cin>>p;
        }
        void display(){
            cout<<"The amount in paisa= p. "<<p<<endl;
        }
        paisa(rupee &r1){
            p=r1.r*100;
        }
};

rupee::rupee(paisa &p2){
    r=p2.p/100.0;
}

int main(){
    rupee r1;
    r1.display();
    paisa p1=r1;
    cout<<"Conversion from rupees to paisa\n";
    p1.display();
    paisa p2;
    rupee r2=p2;
    cout<<"Conversion from paisa to rupees \n";
    r2.display();
    
   
    return 0;
}