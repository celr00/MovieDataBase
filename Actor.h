#include <iostream>
#include <string>

using namespace std;

class Actor{
    public:
        Actor();
        Actor(int id, string name);

        void setID(int id);
        void setName(int name);

        int getID();
        string getName();

        void show();

    private:
        int ID;
        string name;
};
