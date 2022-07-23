#include <iostream>
#include <string>

using namespace std;

void playreMove(int x = 0 , int y = 0);
void attack();
void status();
void maplord();

int old_coordinate[2] = {0 , 0};

int map[5][5] = {

    {1 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0}

};

int hp = 0;
int score = 0;
int playInputX = 0;
int playInputY = 0;

int main() { 
    
    cout << "y : ";
    cin >> playInputY;
    cout << "x : ";
    cin >> playInputX;
    playreMove(playInputY , playInputX);
    maplord();
    
} 

void maplord() {
    
    cout << endl;

    for(int i = 0; i < 5 ; i++){

	for(int j = 0; j < 5 ; j++){

	    cout << " " << map[i][j];

	}

	cout << endl;

    } 
    cout << endl;
}

void playreMove(int x , int y) {
    
    map[old_coordinate[0]][old_coordinate[1]] = 0;

    map[x][y] = 1;

    old_coordinate[0] = x;
    old_coordinate[1] = y;

}

