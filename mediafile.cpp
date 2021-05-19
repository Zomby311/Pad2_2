//
// Created by Admin on 15.05.2021.
//

#include "iostream"
#include "mediafile.h"

using namespace std;

int MediaFile::lastpostion = 0;

MediaFile::MediaFile() {}

MediaFile::MediaFile(string ptitle, int plength, vector<int> plist, double paverage, string pgenre) {
    title = ptitle;
    length = plength;
    list = plist;
    average = paverage;
    genre = pgenre;
    postion = lastpostion+1;
    lastpostion++;
}

void MediaFile::print() {
    cout << "----------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Laenge: " << length << endl;
    cout << "Durchschnittsbewertung: " << average << endl;
    cout << "Genre: " << genre << endl;
    cout << "----------------" << endl;
}

void MediaFile::addRating(int prating) {
    list.push_back(prating);

    average = 0;
    int averagecounter = 0;
    for (int i : list) {
        averagecounter++;
        average += i;
    }
    average /= averagecounter;
}

void MediaFile::play() {
    cout << "Das Mediafile " << title << " wird abgespielt." << endl;
}

string MediaFile::getTitle() const {
    return title;
}

double MediaFile::getLength() const {
    return length;
}

double MediaFile::getAverage() const {
    return average;
}

string MediaFile::getGenre() const {
    return genre;
}

vector<int> MediaFile::getList() const {
    return list;
}

int MediaFile::getPosition() const {
    return postion;
}



