#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

string first_combination[6]={"Aces","Twos","Threes","Fours","Fives","Sixes"};
string second_combination[7]={"3 of a Kind","4 of a Kind","Full House","Small Straight","Large Straight","YAHTZEE"," Chance"};
int player_turn_count=0;
int dice_count=0;
int player_one_dice[5]={0,0,0,0,0};
int player_two_dice[5]={0,0,0,0,0};
int sample[5]={0,1,2,3,4};
int main(){
    cout<<"Welcome to the Yahtzee, players!"<<endl<<"We have prepared two gamemodes for you!!!"<<endl<<"To enjoy normal mode, please enter 'n' as gamemode afterward."<<endl<<"To enjoy creative mode, please enter 'c' as gamemode afterward."<<endl<<"Please choose the gamemode (n/c): ";
    char mode;
    string dice;
    int dice_num;
    cin>>mode;
    
    //game start functions//
    cout<<"The game starts now."<<endl;
        //dice rolling//
        
    srand( time(0) );
    cout<<"It's player "<<player_turn_count+1<<"'s turn"<<endl;
    if(dice_count==0){
        cout<<"please roll the dices by inputing 'roll': ";
        string input_one;
        cin>>input_one;
        if(input_one== "roll"){
            if(player_turn_count==0){
                for (int i=0;i<5;++i){
                    player_one_dice[i] = (int) (1+rand()%6);
                    cout<<"Dice "<<i+1<<" is: "<<player_one_dice[i]<<endl;
                }
            }else if (player_turn_count==1){
                for (int d=0;d<5;++d){
                    player_two_dice[d] = (int) (1+rand()%6);
                    cout<<"Dice "<<d+1<<" is: "<<player_one_dice[d]<<endl;
                }
            }
        }
        dice_count++;
    }
    if(dice_count==1){
        cout<<"Do you want to reroll the dice? You have "<<3-dice_count<<" chances left! (yes/no): ";
        string input_two;
        cin>>input_two;
        if(input_two=="yes"){
            cout<<"Please input the order of the dice to be rerolled with space separated: ";
            cin.ignore();
            getline(cin, dice);
            for (int f=0;f<dice.length();f=f+2){
                dice_num=(int)dice[f]- 48;
                dice_num=dice_num-1;
                if(player_turn_count==0){
                    player_one_dice[dice_num]=(int) (1+rand()%6);
                    
                } else if (player_turn_count==1){
                    player_two_dice[dice_num]=(int) (1+rand()%6);
                }
            }
            for (int g=0;g<5;g++){
                if(player_turn_count==0){
                    cout<<"Dice "<<g+1<<" is: "<<player_one_dice[g]<<endl;
                } else if (player_turn_count==1){
                    cout<<"Dice "<<g+1<<" is: "<<player_two_dice[g]<<endl;
                }
            }
            dice_count++;
        } else if(input_two=="no"){
            if(player_turn_count==0){ 
                player_turn_count++;
                dice_count=0;
            } else {
                player_turn_count=0;
                dice_count=0;
            }
        }
    }
    if(dice_count==2){
        cout<<"Do you want to reroll the dice? You have the last chance! (yes/no): ";
        string input_three;
        cin>>input_three;
        if(input_three=="yes"){
            cout<<"Please input the order of the dice to be rerolled with space separated: ";
            cin.ignore();
            getline(cin, dice);
            for (int h=0;h<dice.length();h=h+2){
                dice_num=(int)dice[h]- 48;
                dice_num=dice_num-1;
                if(player_turn_count==0){
                    player_one_dice[dice_num]=(int) (1+rand()%6);
                    
                } else if (player_turn_count==1){
                    player_two_dice[dice_num]=(int) (1+rand()%6);
                }
            }
            for (int j=0;j<5;j++){
                if(player_turn_count==0){
                    cout<<"Dice "<<j+1<<" is: "<<player_one_dice[j]<<endl;
                } else if (player_turn_count==1){
                    cout<<"Dice "<<j+1<<" is: "<<player_two_dice[j]<<endl;
                }
            }
            dice_count=0;
        } else if(input_three=="no"){
            if(player_turn_count==0){ 
                player_turn_count++;
                dice_count=0;
            } else {
                player_turn_count=0;
                dice_count=0;
            }
        }
    }
    //count score function//
    
    //winner//
    
}
