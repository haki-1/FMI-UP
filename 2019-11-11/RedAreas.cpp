#include <iostream>
#include <cmath>
using namespace std;

struct dot {
    int x;
    int y;

    void print();
};


int main() {

    int maxDotsN = 5;
    dot tochki[maxDotsN];

    dot centurNaPokebola;
    centurNaPokebola.x = -9;
    centurNaPokebola.y = 0;

    int brTriag = 0, brPokebal = 0;



    for(int i = 0; i < maxDotsN; i++) {
        cin >> tochki[i].x;
        cin >> tochki[i].y;
    }

    for(int i = 0; i < maxDotsN; i++) {
        bool triag = false, pokebal = false;

        int xOtCenturaNaPok = abs(tochki[i].x - centurNaPokebola.x);
        int yOtCenturaNaPok = abs(tochki[i].y - centurNaPokebola.y);
        double razstoqnie = sqrt(xOtCenturaNaPok * xOtCenturaNaPok + yOtCenturaNaPok * yOtCenturaNaPok);
        
        if(tochki[i].x >= 2 && tochki[i].x <= 5
        && tochki[i].y >= 2 && tochki[i].y <= 5
        && tochki[i].x + tochki[i].y <= 7) {
            triag = true;
            brTriag++;
        }
        else if(tochki[i].x >= -12 && tochki[i].x <= -6
             && tochki[i].y >= 0   && tochki[i].y <= 4
             && razstoqnie >= 1 && razstoqnie <= 3) {
                 pokebal = true;
                 brPokebal++;
             }


        tochki[i].print();
        if(triag) {
            cout << "in Triangle (" << brTriag << " poreden), ";
        }
        else {
            cout << "out Triangle, ";
        }
        if(pokebal) {
            cout << "in Pokeball(" << brPokebal << " poreden)." << endl;
        }
        else {
            cout << "out Pokeball." << endl;
        }




    }


    int neSaNikude = maxDotsN - (brPokebal + brTriag);
    
    return 0;
}


void dot::print() {
    cout << "<" <<this->x << ", " << this->y << ">: ";
}
