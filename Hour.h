#include <iostream>

using namespace std;

class Hour{
    public:
        Hour();
        Hour(int hr, int min);

        void setHour(int hr);
        void setMinute(int min);

        int getHour();
        int getMinute();

        void show();

    private:
        int hour;
        int minute;
};

//Constructores
Hour::Hour(){
    hour = 0;
    minute = 0;
}
Hour::Hour(int hr, int min){
    hour = hr;
    minute = min;
}

//Métodos de Modificación
void Hour::setHour(int hr){
    hour = hr;
}
void Hour::setMinute(int min){
    minute = min;
}

//Métodos de Acceso
int Hour::getHour(){
    return hour;
}
int Hour::getMinute(){
    return minute;
}

//Métodos
void Hour::show(){
    cout<<hour<<":"<<minute;
}