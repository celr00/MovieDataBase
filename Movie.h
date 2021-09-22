#include <iostream>
#include <string>

using namespace std;

class Movie{
    public:
        Movie();

        void setMovieNum(int mnum);
        void setTitle(string title);
        void setYear(int yr);
        void setDuration(int dur);
        void setGenre(string gnr);

        int getMovieNum();
        string getTitle();
        int getYear();
        int getDuration();
        string getGenre();
        int getActorsNum();
        int getActorID(int idx);

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