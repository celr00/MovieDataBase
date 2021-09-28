#include <iostream>
#include <string>
#include <fstream>

#include "Function.h"
#include "Actor.h"
#include "Movie.h"

using namespace std;

int main(){

    Actor actors[20];
    Function functions[20];
    Movie movies[20];

    ifstream act;
    act.open("Actores.txt");
    ifstream pelis;
    pelis.open("Peliculas.txt");
    
    string line, name, id;
    int countActors = 0;
    while(getline(act, line)){

        id = line.substr(0, line.find(" "));
        name = line.substr(line.find(" ")+1);
        
        actors[countActors] = Actor(stoi(id), name);
    }

    int countMovies = 0, idActor;
    string movId, year, dur, gen, movName;
    int numActs;
    while(getline(pelis, line)){
        movId = line.substr(0, line.find(" "));
        line = line.substr(line.find(" ")+1);
        movies[countMovies].setMovieNum(stoi(movId));

        year = line.substr(0, line.find(" "));
        line = line.substr(line.find(" ")+1);
        movies[countMovies].setYear(stoi(year));

        dur = line.substr(0, line.find(" "));
        line = line.substr(line.find(" ")+1);
        movies[countMovies].setDuration(stoi(dur));

        gen = line.substr(0, line.find(" "));
        line = line.substr(line.find(" ")+1);
        movies[countMovies].setGenre(gen);

        numActs = stoi(line.substr(0, line.find(" ")));
        line = line.substr(line.find(" ")+1);

        for(int i=0;i<numActs;i++){
            idActor = stoi(line.substr(0, line.find(" ")));
            line = line.substr(line.find(" ")+1);
            movies[countMovies].addActor(idActor);
        }

        movies[countMovies].setTitle(line);

        countMovies++;
    }

    string cveFunction;
    char ans;
    int idMov, hour, min, roomNum, countFunctions = 0;
    bool active = true;
    while(active){
        cout<<"Enter the function's number: ";cin>>cveFunction;
        cout<<"Enter the start hour: ";cin>>hour;
        cout<<"Enter the start minute: ";cin>>min;
        cout<<"Enter the movie's id: ";cin>>idMov;
        cout<<"Enter the room's numner: ";cin>>roomNum;

        functions[countFunctions] = Function(cveFunction, idMov, Hour(hour, min), roomNum);
        
        if(countFunctions==19){
            cout<<"Thanks! You've reached the limit of functions in a day."<<endl;
            break;
        }
        while(ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n'){
            cin.ignore();
            cout<<"Do you want to add another function? (Y/N): ";cin>>ans;
            if(ans == 'N' || ans == 'n'){
                active = false;
            }
        }
        ans = 'X';
        countFunctions++;
    }

    return 0;
}