/**
 //GRID IS 20X20 // Element is Element[X][Y]
//Move types
    //Random Move (move fail if position taken) ANT
    //Eat Move: Find Ant otherwise Random Move DOODLEBUG
    //Breed Move: Find empty (nullptr) cell otherwise breed fail ANT & DOODLE
 //Only Ants
 //Only Doodlebugs
 **/

//LIBRARIES
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

using namespace std;


//CONSTANTS
const int BOARD_SIZE=20;
const int ANT_BIRTH_READY=3;
const char ANT_SPRITE='o';
const char DOODLEBUG_SPRITE='X';
const char SPACE='-';
const char DOODLEBUG_ID='D';
const char ANT_ID='A';


enum move{ UP, RIGHT, DOWN, LEFT
};

//CLASSES
class Board;

class Organism{
public:
    virtual void moveFunction(Board& game_board) =0;
    virtual char getSprite () const;
    virtual void printSprite() const;
    virtual char getType() const = 0;
    Organism();
    Organism(int x, int y, bool breedStatus, int days);
    pair<int,int> getPositions();
    void setPosition(int x, int y);
    bool getMovedStatus() const;
    void markAsMoved();
    void resetMovedStatus();
    virtual void breedFunction(Board& game_board)=0;
    virtual int getDaysPregnant() const=0;
private:
    char sprite;
    bool moved;
    int positionX;
    int positionY;
    bool canBreed;
    int daysWithoutFood;
};

class Board{
public:
    Board();
    ~Board();
    void printBoard();
    int getElapsedTime() const;
    void setElapsedTime();
    void seedOrganism(int x, int y, Organism* seed);
    void turnSequence();
    pair<int, int> findBreedingSpace(const int x, const int y);
    bool isCellEmpty(int x, int y);
    void swapPlaces(int x, int y, int newX, int newY);
private:
    Organism* gameBoard[BOARD_SIZE][BOARD_SIZE];

};


class Ant: public Organism{
public:
    virtual void moveFunction(Board& game_board);
    virtual char getSprite () const;
    virtual void printSprite() const;
    virtual char getType() const;
    virtual int getDaysPregnant() const;
    virtual void breedFunction(Board& game_board);
    void resetDaysPregnant();
    Ant();
    Ant(int x, int y);
private:
    char sprite=ANT_SPRITE;
    int daysPregnant;
};

class Doodlebug: public Organism{
public:
    Doodlebug();
    virtual void moveFunction(Board& game_board);
    virtual char getSprite () const;
    virtual void printSprite() const;
    virtual char getType() const;
    int getDaysPregnant() const;
    virtual void breedFunction(Board& game_board);
private:
    char sprite=DOODLEBUG_SPRITE;
    int daysPregnant;
};


int main(){
    srand(time(0));
    int step=0;
    Board currBoard;
    while (true){
        cout<<"World at time: "<<step <<endl;
        currBoard.printBoard();
        cout << endl << "Press enter for next step \n";
        cin.get();
        currBoard.turnSequence();
        step++;
    }

return 0;
}
//ORGANISM FNs
Organism::Organism(){
    moved=false;
    positionX=-1;
    positionY=-1;
    canBreed=false;
    daysWithoutFood=0;
}


Organism::Organism(int x, int y, bool breedStatus, int days){
    positionX=x;
    positionY=y;
    canBreed=breedStatus;
    daysWithoutFood=days;
}

char Organism::getSprite() const {
    return sprite;
}

void Organism::printSprite() const {
    cout<<"should not be printing if working correctly"<<endl;
}

pair<int,int> Organism::getPositions() {
    pair<int,int>  positions = {positionX, positionY};
    return positions;
}

void Organism::setPosition(int x, int y) {
    this->positionX =x;
    this->positionY =y;
}

bool Organism::getMovedStatus() const {
    return moved;
}

void Organism::markAsMoved() {
    moved = true;
}
void Organism::resetMovedStatus() {
    moved = false;
}
//ANT FNS
Ant::Ant(): Organism(), sprite(ANT_SPRITE), daysPregnant(0){};

void Ant::printSprite() const {
    cout<<sprite;
}

char Ant::getSprite() const {
    return sprite;
}

char Ant::getType() const {
    return ANT_ID;
}

int Ant::getDaysPregnant() const {
    return daysPregnant;
}

void Ant::resetDaysPregnant() {
    daysPregnant=0;
}

void Ant::breedFunction(Board &game_board) {
    if (daysPregnant <ANT_BIRTH_READY){
        return;
    }
    pair<int,int> currPosition = this->getPositions();
    pair<int,int> potentialBreedingSpace = game_board.findBreedingSpace(currPosition.first, currPosition.second);

    if (potentialBreedingSpace.first !=-1){
        Organism* ptrSeed = new Ant;
        game_board.seedOrganism(potentialBreedingSpace.first, potentialBreedingSpace.second, ptrSeed);
        this->resetDaysPregnant();
    }
}

void Ant::moveFunction(Board& game_board){
    int xCord = getPositions().first;
    int yCord = getPositions().second;
    int newXCord=xCord, newYCord=yCord;
    int randomDirection = rand() % 4;

    if (randomDirection==0){
        newYCord++;
    }else if (randomDirection==1){
        newYCord--;
    }else if (randomDirection==2){
        newXCord--;
    } else {
        newXCord++;
    }


    if (game_board.isCellEmpty(newXCord, newYCord)) {
        game_board.swapPlaces(newXCord, newYCord, xCord, yCord);
    }
    this->daysPregnant++;
    this->markAsMoved();
}

//DOODLEBUG FNS
Doodlebug::Doodlebug(): Organism(), sprite(DOODLEBUG_SPRITE),daysPregnant(0) {};

void Doodlebug::moveFunction(Board& game_board) {
    cout<<"doodle move fn"<<endl;
}

 void Doodlebug::breedFunction(Board &game_board) {
     cout<<"doodle breed"<<endl;
}
void Doodlebug::printSprite() const {
    cout<<sprite;
}

char Doodlebug::getSprite() const {
    return sprite;
}

char Doodlebug::getType() const {
    return DOODLEBUG_ID;
}
int Doodlebug::getDaysPregnant() const {
    return daysPregnant;
}

///BOARD fns
Board::~Board() {
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            if (gameBoard[x][y] != nullptr) {
                delete gameBoard[x][y];
            }
        }
    }
}
Board::Board() {
    const int ANT_START = 100;
    const int DOODLEBUG_START = 5;

    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            gameBoard[x][y] = nullptr;
        }
    }
    for (int i = 0; i < DOODLEBUG_START; i++) {
        int rand_row = rand() % BOARD_SIZE;
        int rand_col = rand() % BOARD_SIZE;

        while (gameBoard[rand_row][rand_col] != nullptr) {
            rand_row = rand() % BOARD_SIZE;
            rand_col = rand() % BOARD_SIZE;
        }

        gameBoard[rand_row][rand_col] = new Doodlebug();
        gameBoard[rand_row][rand_col]->setPosition(rand_row, rand_col);
    }

    for (int i = 0; i < ANT_START; i++) {
        int rand_row = rand() % BOARD_SIZE;
        int rand_col = rand() % BOARD_SIZE;

        while (gameBoard[rand_row][rand_col] != nullptr) {
            rand_row = rand() % BOARD_SIZE;
            rand_col = rand() % BOARD_SIZE;
        }

        gameBoard[rand_row][rand_col] = new Ant();
        gameBoard[rand_row][rand_col]->setPosition(rand_row, rand_col);
    }
}

void Board::printBoard(){
//    int count =0;
    for (int x=0; x < BOARD_SIZE; x++){
        for (int y=0; y<BOARD_SIZE; y++) {
            if (gameBoard[x][y]!= nullptr){
                gameBoard[x][y]->printSprite();
            }else {
                cout<<SPACE;
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

void Board::turnSequence(){
    for (int x=0; x < BOARD_SIZE; x++){
        for (int y=0; y<BOARD_SIZE; y++) {
            if (gameBoard[x][y]!=nullptr && gameBoard[x][y]->getType()=='A' && !gameBoard[x][y]->getMovedStatus()){
                gameBoard[x][y]->moveFunction(*this);
            }
        }
    }

    for (int x=0; x < BOARD_SIZE; x++){
        for (int y=0; y<BOARD_SIZE; y++) {
            if (gameBoard[x][y]!=nullptr && gameBoard[x][y]->getType()=='A'){
                gameBoard[x][y]->breedFunction(*this);
            }
        }
    }

    for (int x=0; x < BOARD_SIZE; x++){
        for (int y=0; y<BOARD_SIZE; y++) {
            if (gameBoard[x][y]!=nullptr && gameBoard[x][y]->getType()=='A'){
                gameBoard[x][y]->resetMovedStatus();
            }
        }
    }

    //Doodle Turn (Eat Ant or Move)
    //Ant Turn (Move)
    //Doodle Die
    //Doodle Breed
    //Ant Breed
}

bool Board::isCellEmpty(int x, int y){
    if (gameBoard[x][y] == nullptr && (0<= x) && (x< BOARD_SIZE) && (0<=y) && (y <BOARD_SIZE))
        return true;
    else {
        return false;
    }
}

pair<int, int> Board::findBreedingSpace(const int x, const int y){
    pair<int,int> originalCords = {x, y};
    vector <pair<int, int>> emptyCoords;
    if (gameBoard[x][y-1]==nullptr && y>0){
        pair<int, int> temp = {x, y-1};
        emptyCoords.push_back(temp);
    }
    if (gameBoard[x][y+1]==nullptr && y<18){
        pair<int, int> temp = {x, y+1};
        emptyCoords.push_back(temp);
    }
    if (gameBoard[x-1][y]==nullptr && x>0){
        pair<int, int> temp = {x-1, y};
        emptyCoords.push_back(temp);
    }
    if (gameBoard[x+1][y]==nullptr && x < 18){
        pair<int, int> temp = {x+1, y};
        emptyCoords.push_back(temp);
    }

    if (emptyCoords.empty()){
        pair<int, int> negReturn ={-1,-1};
        return negReturn;
    } else {
        int randomlyChosenCord = rand() % emptyCoords.size();
        return emptyCoords[randomlyChosenCord];
    }
}

void searchNearbyEmpty(){

}

void Board::seedOrganism(int x, int y, Organism* seed){
    gameBoard[x][y] = seed;
    gameBoard[x][y]->setPosition(x,y);
}

void Board::swapPlaces(int newX, int newY, int x, int y) {
    gameBoard[newX][newY]= gameBoard[x][y];
    gameBoard[newX][newY]->setPosition(newX, newY);
    gameBoard[x][y]=nullptr;
}