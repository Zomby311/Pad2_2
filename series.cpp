//
// Created by Admin on 17.05.2021.
//
#include "iostream";
#include "series.h"
#include "time.h"

Folge::Folge() {}

Folge::Folge(string pname, int plength) {
    name = pname;
    length = plength;
}


Series::Series(string ptitle, vector<int> plist, double paverage, string pgenre, int pamountfolgen) {
    title = ptitle;
    list = plist;
    average = paverage;
    genre = pgenre;
    amountfolgen = pamountfolgen;
    number = 1;
    postion = lastpostion+1;
    lastpostion++;


    srand(time(NULL));
    for (int i = 1; i < amountfolgen + 1; i++) {
        int randomlength = (rand() & 60) + 30;
        Folge folge = Folge(to_string(i), randomlength);
        listfolgen.push_back(folge);
        length += randomlength;
    }
    length /= amountfolgen;
    folge = listfolgen.at(0);


}

void Series::play() {
    cout << "Folge " << number << " von der Serie " << title << " wird abgespielt." << endl;
    if (number == amountfolgen) {
        number = 1;
        folge = listfolgen.at(0);
        return;
    }
    number++;
    folge = listfolgen.at(number - 1);
}
