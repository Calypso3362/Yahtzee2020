# Yahtzee2020 #
  Yahtzee is an old game found in 1956 which only needs dices, papers and pens to play with. In Yahtzee2020, a new creative mode is added for fun.
# Identification of team members 
Kwong Yiu Tung (3035694604): 
  - Username: Calypso3362

Chan King Lai (3035692967): 
  - Username: thomaschan123

# Game decription

Basic rules:
-	Number of players: 2
-	Players take turns to roll 5 dice with a total of 13 turns
-	For each turn, player will roll the 5 dice, and then select any number of unwanted dice and reroll for a maximum of 2 times 
-	According to the final result, player choose one of the 13 combinations and count the score into a list
-	If the result cannot match with any of the combinations, 0 score will be marked
-	There will be two parts of the game, with different combinations but a total number of 13(excluding some special combination)
-	The player with highest score wins

New 2020 rules:
- A new mode will be added (named Creative mode), as special rules and play styles are included while players can choose to play in normal mode or creative mode before the game start.
    - The basic Yahtzee rules still apply but there will be a role system added.
    - 6 roles are available include Alchemist, Druid, Gambler, GM, Saint, and Paladin, each with a unique skill to affect the game.
    - Players will get a random role by rolling a dice at the start of the game.

Combinations: 
*First half:*
1. Aces
   - Number of one in five dices
   - For every number one, each will count as one point (Maximum 5 points)
2. Twos	
   - Number of two in five dices
   - For every number two, each will count as two points (Maximum 10 points)
3. Threes
   - Number of three in five dices
   - For every number three, each will count as three points (Maximum 15 points)
4. Fours
   - Number of four in five dices
   - For every number four, each will count as four points (Maximum 20 points)
5. Fives	
   - Number of five in five dices
   - For every number five, each will count as five points (Maximum 25 points)
6. Sixes	
   - Number of six in five dices
   - For every number six, each will count as six points. (Maximum 30 points)
7. Bonus(63+)
   - If the first six section’s score in the first half is 63 or above, a bonus score will be rewarded
   - Gain a bonus of 35 points (The maximum score of first half is 140)


*Second half:*  
8. 3 of a Kind
   - When three of the dices are the same within all five dices
   - Gained number of points  as the summation of all five dices (Maximum 30 points)
9. 4 of a Kind	
   - When four of the dices are the same within all five dices
   - Gained number of points  as the summation of all five dices (Maximum 30 points)
10. Full House
   - When three of the dices are the same while the rest are the same with each other	
   - 25 score will be gained
11. Small Straight
   - When the number of four dices are consecutive
   - 30 score will be gained
12. Large Straight	
   - When the number of five dices are consecutive
   - 40 score will be gained
13. YAHTZEE	
   - When all the number of the dices are the same
   - 50 score will be gained
14. Chance
   - Any combination of five dices
   - Gained number of points  as the summation of all five dices. (Maximum 30 points)
15. YAHTZEE BONUS	
   - After having YAHTZEE, if the next round is also YAHTZEE, the gained score can be marked as any combination while having a bonus	
   - A bonus of 100 will be gained. (The maximum score in the second half excluding bonus will be 235)

***7 and 15 are special combinations.***

# Implement features

1. Generation of random game sets or events 
- The result after rolling the dice will be random
- There is a random chance in getting a role.

2. Data structures for storing game status
- Every turn’s score will be stored into each player’s storage unit of an array
- Players can input the wanted combination and the resultant score will be saved after the comparison with the result

3. Dynamic memory management
- Dynamic variables like vectors may be used for unknown number of varibales (in the GM skill)
- pointers may be used to allocate the dynamic variables

4. File input/output (e.g., for loading/saving game status)
- Input different program codes from different files when choosing different modes
- Players can input their choice with keyboard and result will be shown on screen

5. Program codes in multiple files
- Different modes will have multiple files for program codes
- Set up functions in different files, such as score checking function.
- Makefile with be used to compile the files


                  
# Compilation and execution instructions
- Use the 'make' command of the makefile
- Run the program
