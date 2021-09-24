#include <iostream>
#include <string>

using namespace std;

class Actor{
    public:
        Actor();
        Actor(int id, string nm);

        void setID(int id);
        void setName(string nm);

        int getID();
        string getName();

        void show();

    private:
        int ID;
        string name;
};

//Constructores
Actor::Actor(){
    ID = 0;
    name = "";
}
Actor::Actor(int id, string nm){
    ID = id;
    name = nm;
}

//Métodos de modificación
void Actor::setID(int id){
    ID = id;
}
void Actor::setName(string nm){
    name = nm;
}

//Métodos de acceso
int Actor::getID(){
    return ID;
}
string Actor::getName(){
    return name;
}

//Métodos
void Actor::show(){
    cout<<ID<<" "<<name;
}