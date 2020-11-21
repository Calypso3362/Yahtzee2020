#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

//functions for checking//

int is_aces(int array[5]){
    int sum = 0;
    for(int i=0; i<5; i++){
        if (array[i]==1){
            sum+=1;
        }
    }
    return sum;
}

int is_twos(int array[5]){
    int sum = 0;
    for(int i=0; i<5; i++){
        if (array[i]==2){
            sum+=2;
        }
    }
    return sum;
}

int is_threes(int array[5]){
    int sum = 0;
    for(int i=0; i<5; i++){
        if (array[i]==3){
            sum+=3;
        }
    }
    return sum;
}

int is_fours(int array[5]){
    int sum = 0;
    for(int i=0; i<5; i++){
        if (array[i]==1){
            sum+=4;
        }
    }
    return sum;
}

int is_fives(int array[5]){
    int sum = 0;
    for(int i=0; i<5; i++){
        if (array[i]==5){
            sum+=5;
        }
    }
    return sum;
}

int is_sixes(int array[5]){
    int sum = 0;
    for(int i=0; i<5; i++){
        if (array[i]==6){
            sum+=6;
        }
    }
    return sum;
}

int is_threeofakind(int array[5]){
    int sum = 0;
    bool threeofakind=false;

    for(int i=1;i<=6;i++){
        int Count = 0;
        for(int j=0;j<5;j++){
            if (array[j]== i)
                Count++;
            }
            if (Count>2)
                threeofakind = true;
        }



        if (threeofakind){
            for(int k = 0;k<5; k++)
            sum += array[k];
        }
        return sum;

}

    int is_fourofakind(int array[5]){
         int sum = 0;
         bool fourofakind=false;

         for(int i=1;i<=6;i++){
             int Count = 0;
             for(int j=0;j<5;j++){
                 if (array[j]== i)
                     Count++;
             }
             if (Count>3)
                 fourofakind = true;

         }


         if (fourofakind){
             for(int k = 0;k<5; k++)
             sum += array[k];
         }
         return sum;

     }

     int is_yahtzee(int array[5]){
         int res = 0;
         bool yahtzee=false;

         for(int i=1;i<=6;i++){
             int Count = 0;
             for(int j=0;j<5;j++){
                 if (array[j]== i)
                     Count++;
             }
             if (Count>4)
                 yahtzee = true;

         }


         if (yahtzee){
             res = 50;
         }
         return res;

     }

     int is_chance(int array[5]){
         int sum = 0;
         for(int i=0;i<5;i++){
             sum+=array[i];
         }
         return sum;
     }

     int is_fullhouse(int array[5]){
         int sum = 0;
         int i[5];
         int n = sizeof(i) / sizeof(i[0]);

         i[0]=array[0];
         i[1]=array[1];
         i[2]=array[2];
         i[3]=array[3];
         i[4]=array[4];

         sort(i, i + n);

         if( (((i[0] == i[1]) && (i[1] == i[2])) &&(i[3] == i[4])) ||
         ((i[0] == i[1]) &&((i[2] == i[3]) && (i[3] == i[4]))) )
         {
             sum = 25;
         }
         return sum;

     }

     int is_largestraight(int array[5]){
         int sum = 0;
         int i[5];
         int n = sizeof(i) / sizeof(i[0]);

         i[0]=array[0];
         i[1]=array[1];
         i[2]=array[2];
         i[3]=array[3];
         i[4]=array[4];

         sort(i, i + n);

         if( ((i[0] == 1) &&
        (i[1] == 2) &&
        (i[2] == 3) &&
        (i[3] == 4) &&
        (i[4] == 5)) ||
       ((i[0] == 2) &&
        (i[1] == 3) &&
        (i[2] == 4) &&
        (i[3] == 5) &&
        (i[4] == 6)) )
     {
         sum = 40;
     }
         return sum;

     }

     int is_smallstraight(int array[5]){
         int sum = 0;
         int i[5];
         int n = sizeof(i) / sizeof(i[0]);

         i[0]=array[0];
         i[1]=array[1];
         i[2]=array[2];
         i[3]=array[3];
         i[4]=array[4];

         sort(i, i + n);

         for( int j = 0; j < 4; j++ )
         {
         int temp = 0;
         if( i[j] == i[j+1] )
         {
         temp = i[j];

         for( int k = j; k < 4; k++ )
         {
             i[k] = i[k+1];
         }

         i[4] = temp;
         }
     }

      if( ((i[0] == 1) && (i[1] == 2) && (i[2] == 3) && (i[3] == 4)) ||
         ((i[0] == 2) && (i[1] == 3) && (i[2] == 4) && (i[3] == 5)) ||
         ((i[0] == 3) && (i[1] == 4) && (i[2] == 5) && (i[3] == 6)) ||
         ((i[1] == 1) && (i[2] == 2) && (i[3] == 3) && (i[4] == 4)) ||
         ((i[1] == 2) && (i[2] == 3) && (i[3] == 4) && (i[4] == 5)) ||
         ((i[1] == 3) && (i[2] == 4) && (i[3] == 5) && (i[4] == 6)) )
     {
         sum = 30;
     }

     return sum;
 }
//end of functions for checking//
//////
//////
//////
/////
///////
///////

string main_combination[13]={"Aces","Twos","Threes","Fours","Fives","Sixes","Three of a Kind","Four of a Kind","Full House","Small Straight","Large Straight","YAHTZEE","Chances"};
int player_turn_count=0;
int dice_count=0;
int player_one_dice[5]={0,0,0,0,0};
int player_two_dice[5]={0,0,0,0,0};
int player_one_expected_score[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
int player_two_expected_score[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
int player_one_upper_total=0;
int player_two_upper_total=0;
int player_one_score=0;
int player_two_score=0;
int player_one_check_list[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
int player_two_check_list[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
int main(){
    cout<<"Welcome to the Yahtzee, players!"<<endl<<"We have prepared two gamemodes for you!!!"<<endl<<"To enjoy normal mode, please enter 'n' as gamemode afterward."<<endl<<"To enjoy creative mode, please enter 'c' as gamemode afterward."<<endl<<"Please choose the gamemode (n/c): ";
    char mode;
    string dice;
    int dice_num;
    int com_num;
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
        //providing expected score//
       if(player_turn_count==0){
                player_one_expected_score[0]=is_aces(player_one_dice);
                player_one_expected_score[1]=is_twos(player_one_dice);
                player_one_expected_score[2]=is_threes(player_one_dice);
                player_one_expected_score[3]=is_fours(player_one_dice);
                player_one_expected_score[4]=is_fives(player_one_dice);
                player_one_expected_score[5]=is_sixes(player_one_dice);
                player_one_expected_score[6]=is_threeofakind(player_one_dice);
                player_one_expected_score[7]=is_fourofakind(player_one_dice);
                player_one_expected_score[8]=is_fullhouse(player_one_dice);
                player_one_expected_score[9]=is_smallstraight(player_one_dice);
                player_one_expected_score[10]=is_largestraight(player_one_dice);
                player_one_expected_score[11]=is_yahtzee(player_one_dice);
                player_one_expected_score[12]=is_chance(player_one_dice);
                cout<<"Here are the expected score of the combinations:"<<endl;
                cout<<"1. Aces: "<<player_one_expected_score[0]<<endl;
                cout<<"2. Twos: "<<player_one_expected_score[1]<<endl;
                cout<<"3. Threes: "<<player_one_expected_score[2]<<endl;
                cout<<"4. Fours: "<<player_one_expected_score[3]<<endl;
                cout<<"5. Fives: "<<player_one_expected_score[4]<<endl;
                cout<<"6. Sixes: "<<player_one_expected_score[5]<<endl;
                cout<<"7. Three of a kind: "<<player_one_expected_score[6]<<endl;
                cout<<"8. Four of a kind: "<<player_one_expected_score[7]<<endl;
                cout<<"9. Full house: "<<player_one_expected_score[8]<<endl;
                cout<<"10. Small straight: "<<player_one_expected_score[9]<<endl;
                cout<<"11. Large straight: "<<player_one_expected_score[10]<<endl;
                cout<<"12. Yahtzee: "<<player_one_expected_score[11]<<endl;
                cout<<"13. Chances: "<<player_one_expected_score[12]<<endl;
        } else if(player_turn_count==1){
                player_two_expected_score[0]=is_aces(player_two_dice);
                player_two_expected_score[1]=is_twos(player_two_dice);
                player_two_expected_score[2]=is_threes(player_two_dice);
                player_two_expected_score[3]=is_fours(player_two_dice);
                player_two_expected_score[4]=is_fives(player_two_dice);
                player_two_expected_score[5]=is_sixes(player_two_dice);
                player_two_expected_score[6]=is_threeofakind(player_two_dice);
                player_two_expected_score[7]=is_fourofakind(player_two_dice);
                player_two_expected_score[8]=is_fullhouse(player_two_dice);
                player_two_expected_score[9]=is_smallstraight(player_two_dice);
                player_two_expected_score[10]=is_largestraight(player_two_dice);
                player_two_expected_score[11]=is_yahtzee(player_two_dice);
                player_two_expected_score[12]=is_chance(player_two_dice);
                cout<<"Here are the expected score of the combinations:"<<endl;
                cout<<"1. Aces: "<<player_two_expected_score[0]<<endl;
                cout<<"2. Twos: "<<player_two_expected_score[1]<<endl;
                cout<<"3. Threes: "<<player_two_expected_score[2]<<endl;
                cout<<"4. Fours: "<<player_two_expected_score[3]<<endl;
                cout<<"5. Fives: "<<player_two_expected_score[4]<<endl;
                cout<<"6. Sixes: "<<player_two_expected_score[5]<<endl;
                cout<<"7. Three of a kind: "<<player_two_expected_score[6]<<endl;
                cout<<"8. Four of a kind: "<<player_two_expected_score[7]<<endl;
                cout<<"9. Full house: "<<player_two_expected_score[8]<<endl;
                cout<<"10. Small straight: "<<player_two_expected_score[9]<<endl;
                cout<<"11. Large straight: "<<player_two_expected_score[10]<<endl;
                cout<<"12. Yahtzee: "<<player_two_expected_score[11]<<endl;
                cout<<"13. Chances: "<<player_two_expected_score[12]<<endl;
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
            //providing expected score//
            if(player_turn_count==0){
                player_one_expected_score[0]=is_aces(player_one_dice);
                player_one_expected_score[1]=is_twos(player_one_dice);
                player_one_expected_score[2]=is_threes(player_one_dice);
                player_one_expected_score[3]=is_fours(player_one_dice);
                player_one_expected_score[4]=is_fives(player_one_dice);
                player_one_expected_score[5]=is_sixes(player_one_dice);
                player_one_expected_score[6]=is_threeofakind(player_one_dice);
                player_one_expected_score[7]=is_fourofakind(player_one_dice);
                player_one_expected_score[8]=is_fullhouse(player_one_dice);
                player_one_expected_score[9]=is_smallstraight(player_one_dice);
                player_one_expected_score[10]=is_largestraight(player_one_dice);
                player_one_expected_score[11]=is_yahtzee(player_one_dice);
                player_one_expected_score[12]=is_chance(player_one_dice);
                cout<<"Here are the expected score of the combinations:"<<endl;
                cout<<"1. Aces: "<<player_one_expected_score[0]<<endl;
                cout<<"2. Twos: "<<player_one_expected_score[1]<<endl;
                cout<<"3. Threes: "<<player_one_expected_score[2]<<endl;
                cout<<"4. Fours: "<<player_one_expected_score[3]<<endl;
                cout<<"5. Fives: "<<player_one_expected_score[4]<<endl;
                cout<<"6. Sixes: "<<player_one_expected_score[5]<<endl;
                cout<<"7. Three of a kind: "<<player_one_expected_score[6]<<endl;
                cout<<"8. Four of a kind: "<<player_one_expected_score[7]<<endl;
                cout<<"9. Full house: "<<player_one_expected_score[8]<<endl;
                cout<<"10. Small straight: "<<player_one_expected_score[9]<<endl;
                cout<<"11. Large straight: "<<player_one_expected_score[10]<<endl;
                cout<<"12. Yahtzee: "<<player_one_expected_score[11]<<endl;
                cout<<"13. Chances: "<<player_one_expected_score[12]<<endl;
            } else if(player_turn_count==1){
                player_two_expected_score[0]=is_aces(player_two_dice);
                player_two_expected_score[1]=is_twos(player_two_dice);
                player_two_expected_score[2]=is_threes(player_two_dice);
                player_two_expected_score[3]=is_fours(player_two_dice);
                player_two_expected_score[4]=is_fives(player_two_dice);
                player_two_expected_score[5]=is_sixes(player_two_dice);
                player_two_expected_score[6]=is_threeofakind(player_two_dice);
                player_two_expected_score[7]=is_fourofakind(player_two_dice);
                player_two_expected_score[8]=is_fullhouse(player_two_dice);
                player_two_expected_score[9]=is_smallstraight(player_two_dice);
                player_two_expected_score[10]=is_largestraight(player_two_dice);
                player_two_expected_score[11]=is_yahtzee(player_two_dice);
                player_two_expected_score[12]=is_chance(player_two_dice);
                cout<<"Here are the expected score of the combinations:"<<endl;
                cout<<"1. Aces: "<<player_two_expected_score[0]<<endl;
                cout<<"2. Twos: "<<player_two_expected_score[1]<<endl;
                cout<<"3. Threes: "<<player_two_expected_score[2]<<endl;
                cout<<"4. Fours: "<<player_two_expected_score[3]<<endl;
                cout<<"5. Fives: "<<player_two_expected_score[4]<<endl;
                cout<<"6. Sixes: "<<player_two_expected_score[5]<<endl;
                cout<<"7. Three of a kind: "<<player_two_expected_score[6]<<endl;
                cout<<"8. Four of a kind: "<<player_two_expected_score[7]<<endl;
                cout<<"9. Full house: "<<player_two_expected_score[8]<<endl;
                cout<<"10. Small straight: "<<player_two_expected_score[9]<<endl;
                cout<<"11. Large straight: "<<player_two_expected_score[10]<<endl;
                cout<<"12. Yahtzee: "<<player_two_expected_score[11]<<endl;
                cout<<"13. Chances: "<<player_two_expected_score[12]<<endl;
            }
            dice_count++;
        } else if(input_two=="no"){
            dice_count=0;
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
            //providing expected score//
            if(player_turn_count==0){
                player_one_expected_score[0]=is_aces(player_one_dice);
                player_one_expected_score[1]=is_twos(player_one_dice);
                player_one_expected_score[2]=is_threes(player_one_dice);
                player_one_expected_score[3]=is_fours(player_one_dice);
                player_one_expected_score[4]=is_fives(player_one_dice);
                player_one_expected_score[5]=is_sixes(player_one_dice);
                player_one_expected_score[6]=is_threeofakind(player_one_dice);
                player_one_expected_score[7]=is_fourofakind(player_one_dice);
                player_one_expected_score[8]=is_fullhouse(player_one_dice);
                player_one_expected_score[9]=is_smallstraight(player_one_dice);
                player_one_expected_score[10]=is_largestraight(player_one_dice);
                player_one_expected_score[11]=is_yahtzee(player_one_dice);
                player_one_expected_score[12]=is_chance(player_one_dice);
                cout<<"Here are the expected score of the combinations:"<<endl;
                cout<<"1. Aces: "<<player_one_expected_score[0]<<endl;
                cout<<"2. Twos: "<<player_one_expected_score[1]<<endl;
                cout<<"3. Threes: "<<player_one_expected_score[2]<<endl;
                cout<<"4. Fours: "<<player_one_expected_score[3]<<endl;
                cout<<"5. Fives: "<<player_one_expected_score[4]<<endl;
                cout<<"6. Sixes: "<<player_one_expected_score[5]<<endl;
                cout<<"7. Three of a kind: "<<player_one_expected_score[6]<<endl;
                cout<<"8. Four of a kind: "<<player_one_expected_score[7]<<endl;
                cout<<"9. Full house: "<<player_one_expected_score[8]<<endl;
                cout<<"10. Small straight: "<<player_one_expected_score[9]<<endl;
                cout<<"11. Large straight: "<<player_one_expected_score[10]<<endl;
                cout<<"12. Yahtzee: "<<player_one_expected_score[11]<<endl;
                cout<<"13. Chances: "<<player_one_expected_score[12]<<endl;
            } else if(player_turn_count==1){
                player_two_expected_score[0]=is_aces(player_two_dice);
                player_two_expected_score[1]=is_twos(player_two_dice);
                player_two_expected_score[2]=is_threes(player_two_dice);
                player_two_expected_score[3]=is_fours(player_two_dice);
                player_two_expected_score[4]=is_fives(player_two_dice);
                player_two_expected_score[5]=is_sixes(player_two_dice);
                player_two_expected_score[6]=is_threeofakind(player_two_dice);
                player_two_expected_score[7]=is_fourofakind(player_two_dice);
                player_two_expected_score[8]=is_fullhouse(player_two_dice);
                player_two_expected_score[9]=is_smallstraight(player_two_dice);
                player_two_expected_score[10]=is_largestraight(player_two_dice);
                player_two_expected_score[11]=is_yahtzee(player_two_dice);
                player_two_expected_score[12]=is_chance(player_two_dice);
                cout<<"Here are the expected score of the combinations:"<<endl;
                cout<<"1. Aces: "<<player_two_expected_score[0]<<endl;
                cout<<"2. Twos: "<<player_two_expected_score[1]<<endl;
                cout<<"3. Threes: "<<player_two_expected_score[2]<<endl;
                cout<<"4. Fours: "<<player_two_expected_score[3]<<endl;
                cout<<"5. Fives: "<<player_two_expected_score[4]<<endl;
                cout<<"6. Sixes: "<<player_two_expected_score[5]<<endl;
                cout<<"7. Three of a kind: "<<player_two_expected_score[6]<<endl;
                cout<<"8. Four of a kind: "<<player_two_expected_score[7]<<endl;
                cout<<"9. Full house: "<<player_two_expected_score[8]<<endl;
                cout<<"10. Small straight: "<<player_two_expected_score[9]<<endl;
                cout<<"11. Large straight: "<<player_two_expected_score[10]<<endl;
                cout<<"12. Yahtzee: "<<player_two_expected_score[11]<<endl;
                cout<<"13. Chances: "<<player_two_expected_score[12]<<endl;
            }
            dice_count=0;
        } else if(input_three=="no"){
            dice_count=0;
        }
    }
    //choose combinations//
    while(true){
        cout<<"Which combinations do you want to choose? Type in the represented number: ";
        cin>>com_num;
        com_num=com_num-1;
        string input_four;
        if (player_turn_count==0){
            cout<<"You have choosen "<<main_combination[com_num]<<" with score of "<<player_one_expected_score[com_num]<<". Are you sure? (yes/no): ";
            cin>>input_four;
            if(input_four=="yes"){
                if(player_one_check_list[com_num]!=1){
                    if(com_num==0||com_num==1||com_num==2||com_num==3||com_num==4||com_num==5){
                        player_one_upper_total+=player_one_expected_score[com_num];
                    }
                    player_one_score=player_one_score+player_one_expected_score[com_num];
                    player_one_check_list[com_num]=1;
                    player_turn_count++;
                    break;
                } else{
                    cout<<"This combinations has been occupied! Please choose again! ";
                    continue;
                }
            } else if (input_four=="no"){
                continue;
            }
            
            
        } else if (player_turn_count==1){
            cout<<"You have choosen "<<main_combination[com_num]<<" with score of "<<player_two_expected_score[com_num]<<". Are you sure? (yes/no): ";
            cin>>input_four;
            if(input_four=="yes"){
                if(player_two_check_list[com_num]!=1){
                    if(com_num==0||com_num==1||com_num==2||com_num==3||com_num==4||com_num==5){
                        player_two_upper_total+=player_two_expected_score[com_num];
                    }
                    player_two_score=player_two_score+player_two_expected_score[com_num];
                    player_two_check_list[com_num]=1;
                    player_turn_count=0;
                    break;
                } else{
                    cout<<"This combinations has been occupied! Please choose again! ";
                    continue;
                }
            } else if (input_four=="no"){
                continue;
            }
        } 
    }
    if (player_one_upper_total>=63){
        player_one_score+=35;
    }
    if (player_two_upper_total>=63){
        player_two_score+=35;
    }
}
