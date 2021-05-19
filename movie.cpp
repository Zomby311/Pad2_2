//
// Created by Admin on 17.05.2021.
//

#include "iostream"

#include "movie.h"

Movie::Movie() {}

Movie::Movie(string ptitle, int plength, vector<int> plist, double paverage, string pgenre, int pyear) {
    title = ptitle;
    length = plength;
    list = plist;
    average = paverage;
    genre = pgenre;
    postion = lastpostion+1;
    lastpostion++;
    year = pyear;

}

void Movie::setYear(int year) {
    this->year;
}

int Movie::getYear() {
    return year;
}

void Movie::play() {
    cout << "Der Film " << title << " wird abgespielt." << endl;
}

void Movie::compare(Movie &movie) {
    if(year < movie.getYear()){
        cout << "Der Film " << title << "ist juenger als " << movie.getTitle() << endl;
    }
    if(year > movie.getYear()){
        cout << "Der Film " << title << "ist aelter als " << movie.getTitle() << endl;
    }
    if(year == movie.getYear()){
        cout << "Der Film " << title << "ist gleich Alt wie " << movie.getTitle() << endl;
    }
}



