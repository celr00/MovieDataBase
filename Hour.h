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