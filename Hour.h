#include <iostream>

using namespace std;

class Hour{
    public:
        /*Constructors*/
        Hour();
        Hour(int hr, int min);

        /*Modifiaction methods*/
        void setHour(int hr);
        void setMinute(int min);

        /*Access methods*/
        int getHour();
        int getMinute();

        /*Methods*/
        void show();

    private:
        int hour;
        int minute;
};

/*Constructors*/
Hour::Hour(){
    hour = 0;
    minute = 0;
}
Hour::Hour(int hr, int min){
    hour = hr;
    minute = min;
}

/*Modifiaction methods*/
void Hour::setHour(int hr){
    hour = hr;
}
void Hour::setMinute(int min){
    minute = min;
}

/*Access methods*/
int Hour::getHour(){
    return hour;
}
int Hour::getMinute(){
    return minute;
}

/*Methods*/
void Hour::show(){
    if(hour<10){
        cout<<"0";
    }
    cout<<hour<<":";
    if(minute<10){
        cout<<"0";
    }
    cout<<minute;
}