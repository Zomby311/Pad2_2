//
// Created by Admin on 15.05.2021.
//

#include "options.h"
#include "database.h"
#include "movie.h"

#include "iostream";
#include "fstream"
#include "string"
#include "time.h"

int counter = 0;

void option1() {
    Database::sort();
    Database::printDatabase();
}

void option2() {
    int filmnumber;
    cout << "Bitte gebe eine Filmnummer an." << endl;
    cin >> filmnumber;

    if (!cin.good()) {
        throw invalid_argument("Falsche Eingabe");
    }

    for(MediaFile *mediafile : *Database::getDatabase()){
        if(mediafile->getPosition() == filmnumber){
            mediafile->play();
        }
    }
}

void option3() {
    int filmnumber, rating;
    cout << "Bitte geben sie eine Filmnummer an." << endl;
    cin >> filmnumber;
    cout << "Bitte geben sie eine Bewertung an." << endl;
    cin >> rating;

    if (!cin.good()) {
        throw invalid_argument("Falsche Eingabe");
    }

//    for(int i = 0;i<Database::getDatabase()->size();i++){
//        if(Database::getDatabase()->at(i).getNumber() == filmnumber){
//            Database::getDatabase()->at(i).addRating(rating);
//        }
//    }

}

void option4(string readdefaultpath) {
    string path;
    cout << "Bitte geben sie einen Dateipfad ein." << endl;
    cin >> path;

    ifstream quelle;
    string quelldateiname = path;
    quelle.open(quelldateiname.c_str(), ios::in);


    if (!quelle) {
        counter++;
        if (counter != 3) {
            throw invalid_argument("Falscher Dateipfad");
        }
        counter = 0;
        quelle.open(readdefaultpath.c_str(), ios::in);
        cout << "Standard Dateipfad wurde gewählt." << endl;
    }

    string tmp;

    string title, genre, tmpaverage;
    int length, averagecounter = 0;
    double average;
    vector<int> list;

    Database::getDatabase()->clear();

    while (getline(quelle, tmp)) {
        if (tmp.find("Titel") != string::npos) {
            title = tmp.substr(tmp.find(':') + 2);
        }
        if (tmp.find("Laenge") != string::npos) {
            length = stoi(tmp.substr(tmp.find(':') + 2));
        }
        if (tmp.find("Bewertungen") != string::npos) {
            tmpaverage = tmp.substr(tmp.find(':') + 2);
            average = 0;
            averagecounter = 0;
            list.clear();
            for (char c : tmpaverage) {
                if (isdigit(c)) {
                    averagecounter++;
                    list.push_back(c - 48);
                    average += int(c) - 48;
                }
            }
            average /= averagecounter;
        }
        if (tmp.find("Genre") != string::npos) {
            genre = tmp.substr(tmp.find(':') + 2);
            srand(time(NULL));
            int randomyear = (rand() % 20) + 2000;

            Movie movie = Movie(title, length, list, average, genre,randomyear);
            Database::getDatabase()->push_back(&movie);
        }
    }
    quelle.close();
    cout << "Datenbank wurde geladen." << endl;
}

void option5(string writedefaultpath) {
    string path;
    cout << "Bitte geben sie einen Dateipfad ein." << endl;
    cin >> path;

    ofstream ziel;
    string zieldateiname = path;
    ziel.open(zieldateiname.c_str(), ios::out);


    if (!ziel) {
        counter++;
        if (counter != 3) {
            throw invalid_argument("Falscher Dateipfad");
        }
        counter = 0;
        cout << writedefaultpath << endl;
        ziel.open(writedefaultpath.c_str(), ios::out);
        ziel.put('l');
        cout << "Standard Dateipfad wurde gewaehlt." << endl;
    }


    for(MediaFile *movie : *Database::getDatabase()){
        for(int i = 0;i<movie->getTitle().size();i++){
            ziel.put(movie->getTitle()[i]);
        }
        ziel.put('\n');
        for(int i = 0;i<to_string(movie->getLength()).size();i++){
            ziel.put(to_string(movie->getLength())[i]);
        }
        ziel.put('\n');
        for(int i = 0;i<movie->getList().size();i++){
            ziel.put(to_string(movie->getList().at(i))[0]);
            ziel.put(':');
        }
        ziel.put('\n');
        for(int i = 0;i<4;i++){
            ziel.put(to_string(movie->getAverage())[i]);
        }
        ziel.put('\n');
        for(int i = 0;i<movie->getGenre().size();i++){
            ziel.put(movie->getGenre()[i]);
        }
        ziel.put('\n');
        ziel.put('-');
        ziel.put('\n');
    }
    cout << "Datenbank wurde gespeichert." << endl;
}