#include <iostream>
#include <string>

using namespace std;

class Movie{
    public:
        /*Constructors*/
        Movie();
        
        /*Modifiaction methods*/
        void setMovieNum(int mnum);
        void setTitle(string titl);
        void setYear(int yr);
        void setDuration(int dur);
        void setGenre(string gnr);

        /*Access methods*/
        int getMovieNum();
        string getTitle();
        int getYear();
        int getDuration();
        string getGenre();
        int getActorsNum();
        int getActorID(int idx);

        /*Methods*/
        //adds id to array and increases the number of actors in movie.
        //return true if it was added
        //return false if array is full or if that actor was already there
        bool addActor(int actorId);

    private:
        int movieNum;
        string title;
        int year;
        int duration;
        string genre;
        int actorsNum;
        int actorList [10];
};

/*Constructors*/
Movie::Movie(){
    movieNum = 0;
    title = "";
    year = 0;
    duration = 0;
    genre = "";
    actorsNum = 0;
}

/*Modifiaction Methods*/
void Movie::setMovieNum(int mnum){
    movieNum = mnum;
}
void Movie::setTitle(string titl){
    title = titl;
}
void Movie::setYear(int yr){
    year = yr;
}
void Movie::setDuration(int dur){
    duration = dur;
}
void Movie::setGenre(string gnr){
    genre = gnr;
}

/*Access Methods*/
int Movie::getMovieNum(){
    return movieNum;
}
string Movie::getTitle(){
    return title;
}
int Movie::getYear(){
    return year;
}
int Movie::getDuration(){
    return duration;
}
string Movie::getGenre(){
    return genre;
}
int Movie::getActorsNum(){
    return actorsNum
}
int Movie::getActorID(int idx){
    return actorList[idx];
}

/*Methods*/

bool Movie::addActor(int actorId){
    if(actorsNum == 10){
        return false;
    }
    for(int i=0;i<actorsNum;i++){
        if(actorList[i] == actorId){
            return false;
        }
    }
    actorList[actorsNum] = actorId;
    actorsNum++;
    return true;
}