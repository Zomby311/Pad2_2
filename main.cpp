#include <iostream>

#include "options.h"
#include "mediafile.h"
#include "database.h"

#include "series.h"
#include "movie.h"


int main(int argc, char *argv[]) {

    string readdefaultpath = argv[1];
    string writedefaultpath = argv[2];

    Database::init();

    Database::getDatabase()->push_back(new Series("Blacklist",{1,2,3,4,5},1.2,"Action",5));
    Database::getDatabase()->push_back(new Series("Prison Break",{1,2,3,4,5},2.5,"Action",7));
    Database::getDatabase()->push_back(new Series("Walking Dead",{1,2,3,4,5},3.5,"Action",9));
    Database::getDatabase()->push_back(new Series("Breaking Bad",{1,2,3,4,5},4.5,"Action",4));
    Database::getDatabase()->push_back(new Series("Game of Thrones",{1,2,3,4,5},5,"Action",10));

    Movie *movie = new Movie("Titanic", 200, {1,2,3,4,5}, 4, "Drama",2007);

    Movie *movie1 = dynamic_cast<Movie *>(Database::getDatabase()->at(0));
    movie1->compare(*movie);












    while (true) {
        cout << "Bitte waehle eine Option aus." << endl;
        int eingabe;
        cin >> eingabe;


        switch (eingabe) {
            case 1:
                try {
                    option1(); // Ausgeben aller Videos
                } catch (invalid_argument &e) {
                    cout << e.what() << endl;
                }
                break;
            case 2:
                try {
                    option2(); // Abspielen eines Videos
                } catch (invalid_argument &e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                option3(); // Bewertung hinzufügen
                break;
            case 4:
                try {
                    option4(readdefaultpath); // Datenbank laden
                } catch (invalid_argument &e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                try {
                    option5(writedefaultpath); // Dazenbank speichern
                } catch (invalid_argument &e) {
                    cout << e.what() << endl;
                }
                break;
            case 6:
                exit(0); // Beenden
            default:;
        }
    }
}
