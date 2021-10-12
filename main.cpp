#include <iostream>
#include <string>
#include <fstream>

#include "Function.h"
#include "Actor.h"
#include "Movie.h"

using namespace std;

int main(){

    int limit = 20;
    Actor actors[limit];
    Function functions[limit];
    Movie movies[limit];

    ifstream act;
    act.open("Actores.txt");
    ifstream pelis;
    pelis.open("Peliculas.txt");
    
    //Filling of the actors' array
    string line, name, id;
    int countActors = 0;
    while(getline(act, line)){

        id = line.substr(0, line.find(" "));
        name = line.substr(line.find(" ")+1);
        
        actors[countActors] = Actor(stoi(id), name);
        countActors++;
    }

    //Filling of the movies' array
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

    //Filling of the functions' array
    string cveFunction;
    char ans;
    int idMov, hour = -1, min = -1, roomNum, countFunctions = 0;
    bool active = true, existingMovie = false;
    while(active){
        cout<<"Enter the function's number: ";cin>>cveFunction;
        while(hour<0||hour>23){
            cout<<"Enter the start hour: ";cin>>hour;
        }
        while(min<0||min>59){
            cout<<"Enter the start minute: ";cin>>min;
        }
        while(existingMovie == false){
            cout<<"Enter the movie's id: ";cin>>idMov;
            for(int i=0; i<limit;i++){
                if(idMov==movies[i].getMovieNum()){
                    existingMovie = true;
                    break;
                }
            }
        }
        cout<<"Enter the room's number: ";cin>>roomNum;

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
        min = -1;
        hour = -1;
        existingMovie = false;
        countFunctions++;
    }

    active = true;
    ans = 'X';
    while(active){
        cout<<"1) Consult Actor's Data Base"<<endl;
        cout<<"2) Consult Movie's Data Base"<<endl;
        cout<<"3) Consult Funciton's Data Base"<<endl;
        cout<<"4) Consult Functions per hour"<<endl;
        cout<<"5) Funtion Search"<<endl;
        cout<<"6) Consult Movies per Actor"<<endl;
        cout<<"7) Leave"<<endl;
        cin>>ans;

        switch(ans){
            case '1':
                for(int i=0;i<limit;i++){
                    cout<<actors[i].getID()<<" "<<actors[i].getName()<<endl;
                }
                break;
            case '2':
                for(int i=0;i<limit;i++){
                    cout<<movies[i].getYear()<<" "<<movies[i].getTitle()<<" - "<<movies[i].getGenre()<<" ("<<movies[i].getDuration()<<" min)"<<endl;
                    for(int j=0;j<movies[i].getActorsNum();j++){
                        int currentActor = movies[i].getActorID(j);
                        for(int k=0;k<limit;k++){
                            if(currentActor == actors[k].getID()){
                                cout<<"\t"<<actors[k].getID()<<" "<<actors[k].getName()<<endl;
                                break;
                            }
                        }
                    }
                }
                break;
            case '3':
                for(int i=0;i<limit;i++){
                    if(functions[i].getCveFunction() == "A0"){
                        break;
                    }
                    cout<<functions[i].getCveFunction()<<" ";
                    for(int j=0;j<limit;j++){
                        if(functions[i].getMovieNum() == movies[j].getMovieNum()){
                            cout<<movies[j].getTitle()<<" in room ";
                        }
                    }
                    cout<<functions[i].getRoom()<<" at ";
                    Hour funcHr = functions[i].getHour();
                    cout<<funcHr.getHour()<<":"<<funcHr.getMinute()<<endl;
                }
                break;
            case '4':
                {
                    hour = -1;
                    min = -1;
                    while(hour<0||hour>23){
                        cout<<"Enter the start hour: ";cin>>hour;
                    }
                    while(min<0||min>59){
                        cout<<"Enter the start minute: ";cin>>min;
                    }
                    Hour currentHour = Hour(hour, min);

                    cout<<"Showing funtions that start at ";
                    currentHour.show();
                    cout<<endl;

                    Movie currentMovie;

                    for(int i=0;i<limit;i++){
                        if(functions[i].getCveFunction() == "A0"){
                            break;
                        }
                        if(functions[i].getHour().getHour()==hour && functions[i].getHour().getMinute() == min){
                            for(int j=0;j<limit;j++){
                                if(functions[i].getMovieNum() == movies[j].getMovieNum()){
                                    currentMovie = movies[j];
                                }
                            }
                            cout<<"\t"<<functions[i].getCveFunction()<<" "<<currentMovie.getTitle()<<" Room: "<<functions[i].getRoom()<<endl;
                        }
                    }
                }
                break;
            case '5':
                {       
                string clave;
                Function currentFunction;

                Movie currentMovie;
                cout<<"Enter de Function's number: ";cin>>clave;
                for(int i=0;i<limit;i++){
                    if(functions[i].getCveFunction() == clave){
                        currentFunction = functions[i];
                        for(int j=0;j<limit;j++){
                            if(currentFunction.getMovieNum() == movies[j].getMovieNum()){
                                currentMovie = movies[j];
                            }
                        }
                        break;
                    }
                }
                if(currentFunction.getCveFunction() == "A0"){
                    cout<<"There is no function with that number, try again later."<<endl;
                    break;
                }

                cout<<"Function: "<<clave<<endl;
                cout<<"Title: "<<currentMovie.getTitle()<<endl;
                cout<<"Duration: "<<currentMovie.getDuration()<<" min"<<endl;
                cout<<"Room: "<<currentFunction.getRoom()<<endl;
                cout<<"Hour: ";
                currentFunction.getHour().show();
                cout<<endl;
                cout<<"Genre: "<<currentMovie.getGenre()<<endl;
                cout<<"Actors: "<<endl;
                for(int i=0;i<currentMovie.getActorsNum();i++){
                    int act = currentMovie.getActorID(i);
                    for(int j=0;j<limit;j++){
                        if(act == actors[j].getID()){
                            cout<<"\t"<<actors[j].getName()<<endl;
                        }
                    }
                }
                }
                break;
            case '6':
                {   
                    int reqID;
                    Actor currentActor;
                    cout<<"Ingrese el ID del actor: ";cin>>reqID;
                    for(int i=0;i<=limit;i++){
                        if(actors[i].getID() == reqID){
                            currentActor = actors[i];
                            break;
                        }
                    }

                    if(currentActor.getID() == 0){
                        cout<<"The actor doesn't exists"<<endl;
                        break;
                    }

                    cout<<"Showing movies where this actor participates: "<<endl;
                    //Checking movies
                    for(int i=0; i<limit; i++){
                        //Checking actors in movies
                        for(int j=0; j<movies[i].getActorsNum(); j++){
                            if(movies[i].getActorID(j) == reqID){
                                cout<<"\t"<<movies[i].getTitle()<<endl;
                            }
                        }
                    }

                }
                break;
            case '7':
                cout<<"Thanks for coming!"<<endl;
                active = false;
                break;
            default:
                cout<<"Please enter a valid character"<<endl;
                break;
        }
    }

    return 0;
}