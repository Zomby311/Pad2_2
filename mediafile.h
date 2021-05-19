//
// Created by Admin on 15.05.2021.
//

#ifndef PRAKIKUM2_movie_H
#define PRAKIKUM2_movie_H

#include "string"
#include "vector"


using namespace std;


class MediaFile {
public:
    MediaFile();
    MediaFile(string ptitle, int length,vector<int> plist, double average, string pgenre);

    void print();
    void addRating(int prating);
    virtual void play();

    string getTitle() const;
    double getLength() const;
    vector<int> getList() const;
    double getAverage() const;
    string getGenre() const;
    int getPosition() const;


protected:
    string title;
    double length;
    vector<int> list;
    double average;
    string genre;
    static int lastpostion;
    int postion;

};


#endif //PRAKIKUM2_MOVIE_H
