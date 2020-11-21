#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include "normal.h"
#include "creative.h"

using namespace std;

int main(){
    cout<<"Welcome to the Yahtzee, players!"<<endl<<"We have prepared two gamemodes for you!!!"<<endl<<"To enjoy normal mode, please enter 'n' as gamemode afterward."<<endl<<"To enjoy creative mode, please enter 'c' as gamemode afterward."<<endl<<"Please choose the gamemode (n/c): ";
    string mode;
    int total_player_one=0;
    int total_player_two=0;
    int score;
    
    cin>>mode;
    if(mode=="c"){
        for(int i=0;i<13;i++){
            for (int j=0;j<2;j++){
                score=creative();
                if(j==0){
                    total_player_one+=score;
                } else{
                    total_player_two+=score;
                }
            }
        }
    } else if(mode=="n"){
        for(int k=0;k<13;k++){
            for (int l=0;l<2;l++){
                score=normal();
                if(l==0){
                    total_player_one+=score;
                } else{
                    total_player_two+=score;
                }
            }
        }
    }
    if(total_player_one>total_player_two){
        cout<<"Player ONE wins!!!";
    }else if (total_player_two>total_player_one){
        cout<<"Player TWO wins!!!";
    }else{
        cout<<"DRAW!!";
    }
}    
