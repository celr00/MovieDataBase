#include <iostream>
#include <string>
#include "Hour.h"

using namespace std;

class Function{
    public:
        /*Constructors*/
        Function();
        Function(string cve, int num, Hour hr, int rm);

        /*Modifiaction methods*/
        void setCveFunction(string cve);
        void setMovieNum(int num);
        void setHour(Hour hr);
        void setRoom(int rm);

        /*Access methods*/
        string getCveFunction();
        int getMovieNum();
        Hour getHour();
        int getRoom();

        /*Methods*/
        void show();

    private:
        string cveFunction;
        int movieNum;
        Hour hour;
        int room;
};

/*Constructors*/
Function::Function(){
    cveFunction = "A0";
    movieNum = 0;
    hour = Hour();
    room = 0;
}
Function::Function(string cve, int num, Hour hr, int rm){
    cveFunction = cve;
    movieNum = num;
    hour = hr;
    room = rm;
}

/*Modifiaction methods*/
void Function::setCveFunction(string cve){
    cveFunction = cve;
}
void Function::setMovieNum(int num){
    movieNum = num;
}
void Function::setHour(Hour hr){
    hour = hr;
}
void Function::setRoom(int rm){
    room = rm;
}

/*Access methods*/
string Function::getCveFunction(){
    return cveFunction;
}
int Function::getMovieNum(){
    return movieNum;
}
Hour Function::getHour(){
    return hour;
}
int Function::getRoom(){
    return room;
}

/*Methods*/
void Function::show(){
    cout<<"Funtion number: "<<cveFunction<<". Movie number: "<<movieNum<<". Start at ";
    hour.show();
    cout<<" in room "<<room<<endl;
}