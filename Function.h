#include <iostream>
#include "Hour.h"

using namespace std;

class Function{
    public:
        Function();
        Function(string cve, int num, Hour hr, int rm);

        void setCveFunction(string cve);
        void setMovieNum(int num);
        void setHour(Hour hr);
        void setRoom(int rm);

        string getCveFunction();
        int getMovieNum();
        Hour getHour();
        int getRoom();

        void show();

    private:
        string cveFunction;
        int movieNum;
        Hour hour;
        int room;
};
