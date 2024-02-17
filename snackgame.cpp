#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <string.h>
using namespace std ;
//--------------------------------------------------------------------------------------- variables
int score_player1 = 0, score_player2 = 0 ;
int const width = 30 , height = 30 ;
bool gameover ;
bool restartb ;
int restarti ;
string name1 , name2 ;

string name[100];
int score[100];

int speed ;
int speed_time ;
struct point {
int x,y;
};

enum direction{
    STOP = 0 , UP, DOWN , LEFT , RIGHT 
};
direction dir1 , dir2 ;
point player1, player2, fruit , boomb ;
point tail1[900];
point tail2[900];
int size_tail1 , size_tail2 ;
int chandom=0 ;
//---------------------------------------------------------------------------------- first function
void setup(){//meghdar haye avaliye
player1.x = 8;
player1.y = 8; 
size_tail1 = 3;
size_tail2 = 3;
tail1[0].x = 8 ;
tail1[0].y = 8 ;
tail1[1].x = 8 ;
tail1[1].y = 8 ;
tail1[2].x = 8 ;
tail1[2].y = 8 ;


player2.x = width-10;
player2.y = height-10;
tail1[0].x = width-10 ;
tail1[0].y = height-10 ;
tail1[1].x = width-10 ;
tail1[1].y = height-10 ;
tail1[2].x = width-10 ;
tail1[2].y = height-10 ;


fruit.x = rand() %( width - 3) +1;
fruit.y = rand() % (height - 3) +1;

boomb.x = rand() %( width - 3) +1;
boomb.y = rand() % (height - 3) +1;

for(int r=0 ; r<10 ; r++){//in halghe baraye mohkam kary hast 
if((boomb.x == fruit.x && boomb.y == fruit.y)||
(boomb.x == player1.x && boomb.y == player1.y)||
(boomb.x == player2.x && boomb.y == player2.y)){
boomb.x = rand() %( width - 3) +1;
boomb.y = rand() % (height - 3) +1;  
}}
for(int e=0 ; e<10 ; e++){//in halghe baraye mohkam kary hast 
if((boomb.x == fruit.x && boomb.y == fruit.y)||
(fruit.x == player1.x && fruit.y == player1.y)||
(fruit.x == player2.x && fruit.y == player2.y)){
boomb.x = rand() %( width - 3) +1;
boomb.y = rand() % (height - 3) +1;  
}}

gameover = false ;
restartb = true ;
score_player1 = 0 ;
score_player2 = 0 ;

dir1 = STOP ;
dir2 = STOP ;

cout<<"esm bazikon aval ra vared konid : "<<endl;
cin>>name1;
//name[chandom]=name1;
cout<<"esm bazikon dovom ra vared konid : "<<endl;
cin>>name2;
//name[chandom+1]=name2;
cout<<"sorat bazi cheghadr bashad ?? (guidance :: 1.slow , 2.medium , 3.fast )"<<endl;
cin>>speed ;
if(speed == 1)
speed_time = 150 ;
else if(speed == 2)
speed_time = 100;
else if(speed == 3)
speed_time = 75 ;

}
//----------------------------------------------------------------------------------second function
void draw(){//rasm bazi 
system("cls");//pak kardan freim ghabli
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // دریافت دستگاه کنترل کننده خروجی

for(int i = 0 ; i < height  ; i++){
    for(int j = 0 ; j < width  ; j++){

        if(i==0 || j==0)
            cout<<"+ ";
        else if (i==height-1 || j==width-1)
            cout<<"+ ";
        else if (i==fruit.y && j==fruit.x){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // rangesho sabz mikone
            cout<<"@ ";   
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); }//rango be halat adi barmigardone

        else if (i==boomb.y && j==boomb.x){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //  rangesho abi mikone
            cout<<"# ";     
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); }// rango be halat adi barmigardone
        else if (i==player1.y && j==player1.x){
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); //  rangesho abi mikone
            cout<<"$ ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); }// rango be halat adi barmigardone
        else if (i==player2.y && j==player2.x){
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); //  rangesho abi mikone
            cout<<"O ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); }// rango be halat adi barmigardone
        
        else {
            bool dom_hast = false ;
            for(int k = 0 ; k < size_tail1 ; k++){
                if(i == tail1[k].y  &&  j== tail1[k].x){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); //  rangesho abi mikone
                    cout<<"& ";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // rango be halat adi barmigardone
                    dom_hast = true ;}}
            for(int h = 0 ; h < size_tail2 ; h++){
                if(i == tail2[h].y  &&  j== tail2[h].x){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); //  rangesho abi mikone
                    cout<<"o ";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // rango be halat adi barmigardone
                    dom_hast = true ;}}
            if(!dom_hast )
                cout<<"  ";
                
            }
        
    }
    cout<<endl;

}

cout<<"score "<<name1<<" is : "<<score_player1<<"(&&&$)";
cout<<endl;
cout<<"score "<<name2<<" is : "<<score_player2<<"(oooO)";
cout<<endl;
cout<<"time of this game is 60 seconds my friend please hurry up ";
}
//-----------------------------------------------------------------------------------third function
void input(){//daryaft vorodi ha
    if(kbhit()){
        switch (getch())
        {
        case 'w':
        case 'W':
            dir1 = UP;
            break;

        case 'a':
        case 'A':
            dir1 = LEFT;
            break;

        case 's':
        case 'S':
            dir1 = DOWN;
            break;

        case 'd':
        case 'D':
            dir1 = RIGHT;
            break;
//------------------------------------------------------------------//PLAYER2
        // case 'i':
        // case 'I':
        //     dir2 = UP;
        //     break;

        // case 'j':
        // case 'J':
        //     dir2 = LEFT;
        //     break;

        // case 'k':
        // case 'K':
        //     dir2 = DOWN;
        //     break;

        // case 'l':
        // case 'L':
        //     dir2 = RIGHT;
        //     break;   
        // default :
        //     break;
        case 72: // Arrow Up
            dir2 = UP;
            break;
        case 75: // Arrow Left
            dir2 = LEFT;
            break;        
        case 80: // Arrow Down
            dir2 = DOWN;
            break;
        case 77: // Arrow Right
            dir2 = RIGHT;
            break;
        default:
            break;
        }
    }


    
}
//----------------------------------------------------------------------------------forth function
void logic(){//barname rizi bazi
    if(size_tail1 != 0){
    for (int q = size_tail1-1; q > 0; q--) {
        tail1[q].x = tail1[q - 1].x;
        tail1[q].y = tail1[q - 1].y;
    }
    tail1[0].x = player1.x;
    tail1[0].y = player1.y;}

    for (int l = size_tail2-1; l > 0; l--) {
        tail2[l].x = tail2[l - 1].x;
        tail2[l].y = tail2[l - 1].y;
    }
    tail2[0].x = player2.x;
    tail2[0].y = player2.y;

switch (dir1)
{
case UP:
    player1.y -=  1 ;
    if(player1.y <= 0)
    gameover = true ;
    break;
case DOWN:
    player1.y +=1 ;
    if(player1.y >= height-1)
    gameover = true ;
    break;
case LEFT:
    player1.x -=1 ;
    if(player1.x <= 0)
    gameover = true ;
    break;
case RIGHT:
    player1.x +=1 ;
    if(player1.x >= width -1)
    gameover = true ;
    break;


}

switch (dir2)
{
case UP:
    player2.y -=  1 ;
    if(player2.y <= 0)
    gameover = true ;
    break;
case DOWN:
    player2.y +=1 ;
    if(player2.y >= height-1)
    gameover = true ;
    break;
case LEFT:
    player2.x -=1 ;
    if(player2.x <= 0)
    gameover = true ;
    break;
case RIGHT:
    player2.x +=1 ;
    if(player2.x >= width -1)
    gameover = true ;
    break;



}
if((player1.x == fruit.x) && (player1.y == fruit.y)){
score_player1 += 10 ;
fruit.x = rand() %( width - 3) +1;
fruit.y = rand() % (height - 3) +1;
size_tail1 +=1;
}

else if((player2.x == fruit.x) && (player2.y == fruit.y)){
score_player2 += 10 ;
fruit.x = rand() %( width - 3) +1;
fruit.y = rand() % (height - 3) +1;
size_tail2 +=1 ;
}
if((player1.x == boomb.x) && (player1.y == boomb.y)){
gameover = true  ;}

else if((player2.x == boomb.x) && (player2.y == boomb.y)){
gameover = true  ;}

for(int p = 3 ; p < size_tail1 ;p++){
    if(tail1[p].x == player1.x  && tail1[p].y == player1.y){
        gameover = true ;
}} 
for(int g = 3 ; g < size_tail2 ;g++){
    if(tail2[g].x == player2.x  && tail2[g].y == player2.y){
        gameover = true ;
}} 




}
//--------------------------------------------------------------------------------------
void sort(){
int tedad_pooch = 0;

    for(int x = 0 ; x < chandom+2 ;x++){
        if( name[x] == name[x+2]){
            score[x]+=score[x+2];
            score[x+2]=0;
            name[x+2]='\0';
            tedad_pooch++ ;
        }
    }    
        for(int p = 0 ; p < chandom+2 ;p++){
        if(name[p] == name[p+3]){
            score[p]+=score[p+3];
            score[p+3]=0;
            name[p+3]='\0';
            tedad_pooch++ ;
        }
    }


        for(int e = 0 ; e < chandom+2 ;e++){
        if(name[e] == name[e+1]){
            score[e]+=score[e+1];
            score[e+1]=0;
            name[e+1]='\0';
            tedad_pooch++ ;
        }
    }
        for(int e = 0 ; e < chandom+2 ;e++){
        if(name[e] == name[e+4]){
            score[e]+=score[e+4];
            score[e+4]=0;
            name[e+4]='\0';
            tedad_pooch++ ;
        }
    }
        for(int e = 0 ; e < chandom+2 ;e++){
        if(name[e] == name[e+5]){
            score[e]+=score[e+5];
            score[e+5]=0;
            name[e+5]='\0';
            tedad_pooch++ ;
        }
    }

for(int y = 0 ; y < chandom+2 ;y++){
    for(int x = 0 ; x < chandom+2 ;x++){
        if(score[x] < score[x+1]){
            swap(name[x],name[x+1]);
            swap(score[x],score[x+1]);
        }
    }    
}




for(int w = 0 ; w < chandom + 2  ; w++){
string abzar = "\0";
if(name[w] != abzar){
cout<<endl;    
cout<<name[w]<<" is : "<<score[w];
cout<<endl;}}



}
//-----------------------------------------------------------------------------------fifth function
void finalshow(){
    name[chandom]=name1;
    name[chandom+1]=name2;
    score[chandom]=score_player1;
    score[chandom+1]=score_player2;

    if(score_player1 > score_player2){
        cout<<" OUR WINNER IS "<<name1<<endl<<" CONGRATULATIONS :)))))"<<endl;
        cout<<"score "<<name1<<" is : "<<score_player1;
        cout<<endl;
        cout<<"score "<<name2<<" is : "<<score_player2;
        cout<<endl;}
    else if(score_player2 > score_player1){
        cout<<" OUR WINNER IS "<<name2<<endl<<"CONGRATULATIONS :)))))"<<endl;
        cout<<"score "<<name1<<" is : "<<score_player1;
        cout<<endl;
        cout<<"score "<<name2<<" is : "<<score_player2;
        cout<<endl;}
    else if(score_player1 == score_player2){
        cout<<" WE DONT HAVE WINNER "<<endl<<"THIS GAME FINISHED WITH RESUALT DRAW ://///"<<endl;
        cout<<"score "<<name1<<" is : "<<score_player1;
        cout<<endl;
        cout<<"score "<<name2<<" is : "<<score_player2;
        cout<<endl;}
    cout<<endl;
    
    sort();

    cout<<"ARE YOU WANT TO PLAY AGAIN ??? "<<endl;
    cout<<"IF YOUR ANSWE IS YES PRESS 1"<<endl;
    cout<<"IF YOUR ANSWE IS NO  PRESS 2"<<endl;
    cin>>restarti ;

    if(restarti == 1)
        restartb = true ;
    else 
        restartb = false ;



}
//----------------------------------------------------------------------------------- main function
int main(){
    srand( time(NULL));//baraye tabe randim


for(restartb = true ;restartb != false;chandom+=2){
        clock_t startTime = clock(); // zaman shoro bazi
    setup();

    while(!gameover){
        draw();

        input();
        logic(); 

                clock_t currentTime = clock();
        double secondsPassed = double(currentTime - startTime) / CLOCKS_PER_SEC;
        if (secondsPassed >= 60) {//andazegiri 60 sanie
            gameover = true;
            cout << "Time's up! Game over!" << endl;
        }
        Sleep(speed_time);//vaghfe beyn har freim
    }
    Sleep(3000);
    system("cls");
    finalshow();

    //getch();
    }
    return 0 ;
} 