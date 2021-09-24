#include <iostream>
#include <string>

using namespace std;

class Actor{
    public:
        /*Constructors*/
        Actor();
        Actor(int id, string nm);

        /*Modifiaction methods*/
        void setID(int id);
        void setName(string nm);

        /*Access methods*/
        int getID();
        string getName();

        /*Methods*/
        void show();

    private:
        int ID;
        string name;
};

/*Constructors*/
Actor::Actor(){
    ID = 0;
    name = "";
}
Actor::Actor(int id, string nm){
    ID = id;
    name = nm;
}

/*Modifiaction methods*/
void Actor::setID(int id){
    ID = id;
}
void Actor::setName(string nm){
    name = nm;
}

/*Access methods*/
int Actor::getID(){
    return ID;
}
string Actor::getName(){
    return name;
}

/*Methods*/
void Actor::show(){
    cout<<ID<<" "<<name;
}