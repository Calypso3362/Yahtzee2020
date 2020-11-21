#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

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
