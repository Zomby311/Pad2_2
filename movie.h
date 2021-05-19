//
// Created by Admin on 17.05.2021.
//

#ifndef PRAKIKUM2_MOVIE_H
#define PRAKIKUM2_MOVIE_H

#include "mediafile.h"


class Movie : public MediaFile{
public:
    Movie();
    Movie(string ptitle, int length,vector<int> plist, double average, string pgenre,int year);


    void play();
    void compare(Movie &movie);
    void setYear(int year);
    int getYear();

private:
    int year;

};


#endif //PRAKIKUM2_MOVIE_H
