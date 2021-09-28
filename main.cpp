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
    
    

    return 0;
}