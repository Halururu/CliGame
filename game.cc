#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void playreMove(int x = 0 , int y = 0);
void attack();
void status();
void maplord();
void InputMoveTest(int v);

int old_coordinate[2] = {0 , 0};

int map[8][16] = {

    {1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0 , 0 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,

    {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}

};

int hp = 0;
int score = 0;
int playInputX = 0;
int playInputY = 0;

int InputMove = 0;
int coin_coordinate[2] = {7 , 7};
bool getCoin = false;


int main() { 
    
   // cout << "y : ";
   // cin >> playInputY;
   // cout << "x : ";
   // cin >> playInputX;
   // playreMove(playInputY , playInputX);
   // maplord();
    
    while(getCoin == false){
	if(coin_coordinate[0] == old_coordinate[0] && coin_coordinate[1] == old_coordinate[1]) {

	    cout << "Clear!" << endl;
	    getCoin = true;
	}else {
	    system("reset");
    	    maplord();   
	    cout << endl;
    	    cout << " 1 : left " << endl << " 2 : down" << endl << " 3 : up " << endl << " 4 : right " << endl << endl << "> ";
    	    cin >> InputMove;
    	    InputMoveTest(InputMove);
	    
	}
	
    }
    
} 

//map配列を描画する関数
void maplord() {
    
    cout << endl;

    for(int i = 0; i < 8 ; i++){
	
	cout << "\x1b[42m";

	for(int j = 0; j < 16 ; j++){
	    
	    if(map[i][j] == 0){
		cout << " w";
	    }else if (map[i][j] == 1){

		cout << "\x1b[31m" << " p" << "\x1b[39m";

	    }else if(map[i][j] == 2) {
		coin_coordinate[0] = i;
		coin_coordinate[1] = j;

	    	cout << "\x1b[33m" << " O" << "\x1b[39m";


	    }

	    //cout << " " << map[i][j];

	}

	cout << " " << "\x1b[49m" << endl;

    } 
    cout << endl;
}

//引数として取得した座標に1(playre)を代入してその前にいた座標(old_coordinate)に0(空)を代入する
void playreMove(int y , int x) {
    
    map[old_coordinate[0]][old_coordinate[1]] = 0;

    map[y][x] = 1;

    old_coordinate[0] = y;
    old_coordinate[1] = x;

}

void InputMoveTest(int v){

    if(v == 1){
	
	playreMove(old_coordinate[0] , old_coordinate[1] -1);

    }else if(v == 2) {

	playreMove(old_coordinate[0] + 1 , old_coordinate[1]);

    }else if(v == 3) {

	playreMove(old_coordinate[0] - 1 , old_coordinate[1]);

    }else if(v == 4) {

	playreMove(old_coordinate[0] , old_coordinate[1] + 1);

    }



}
