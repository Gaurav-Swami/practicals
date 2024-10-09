#include<iostream>
#include<conio.h>

using namespace std;

class calander{
    int date, month, year;
    public:
    /*calander(){
        cout<<"Enter the date : ";
        cin>>date;
        cout<<"Enter the mpnth : ";
        cin>>month;
        cout<<"Enter the year : ";
        cin>>year;
    }*/
    
    calander(int dd,int mm,int yy){
        date = dd;
        month = mm;
        year = yy;
    }
    
    void display(){
        cout<<date<<"/"<<month<<"/"<<year<<endl;
    }
    
    void add_days(){
        int n;
        int m[13]={0,30,28,31,30,31,30,31,30,31,30,31};

        cout<<"Enter the days : ";
        cin>>n;
        
        date=date+n;
        while(date>m[month]){
            date=date-m[month];
            month++;
            
            if(month>12){
                month=month-12;
                year++;
            }
            
            if((year%4==0) && (year%100==0)){
                m[2]=29;
            }
            else{
                m[2]=28;
            }
        }
    }
};

int main(){
    int dd,mm,yy;
    
    cout<<"Enter the date : ";
    cin>>dd;
    cout<<"Enter the month : ";
    cin>>mm;
    cout<<"Enter the year : ";
    cin>>yy;
    
    calander c1(dd,mm,yy);
    c1.add_days();
    c1.display();
    getch();
    return 0;
}