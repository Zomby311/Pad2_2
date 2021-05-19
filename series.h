//
// Created by Admin on 17.05.2021.
//

#ifndef PRAKIKUM2_SERIES_H
#define PRAKIKUM2_SERIES_H

#include "mediafile.h"

class Folge{
public:
    Folge();
    Folge(string name,int length);

private:
    string name;
    int length;
};

class Series : public MediaFile {

public:
    Series(string ptitle,vector<int> plist, double average, string pgenre,int amountfolgen);

    void play();


private:
    int amountfolgen;
    Folge folge;
    vector<Folge> listfolgen;
    int number;
};




#endif //PRAKIKUM2_SERIES_H
