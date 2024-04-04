/**
 * file:            Artillery.cpp
 * author:          Eva Ulrichsen
 * date modified:   11/01/23
 * description:     This program is a version of
 *                  "Tank Battle." In order to win,
 *                  you must hit the enemy tank
 *                  before they hit you.
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    // declare variables
    double tankPos, playerPos, pAngle, pVelocity;
    int roundNumber = 1;
    bool gameOver = false;
    string difficulty, angle, velocity;



    string banner;
    banner += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    banner += "  _______          _      ____        _   _   _       \n";
    banner += " |__   __|        | |    |  _ \\      | | | | | |      \n";
    banner += "    | | __ _ _ __ | | __ | |_) | __ _| |_| |_| | ___  \n";
    banner += "    | |/ _` | '_ \\| |/ / |  _ < / _` | __| __| |/ _ \\ \n";
    banner += "    | | (_| | | | |   <  | |_) | (_| | |_| |_| |  __/ \n";
    banner += "    |_|\\__,_|_| |_|_|\\_\\ |____/ \\__,_|\\__|\\__|_|\\___| \n";
    banner += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << banner << endl << endl;
    // random number seed
    srand(time(NULL));
    // Player menu
    cout <<"Pick a difficulty: [easy, medium, hard]" << endl;
    getline(cin, difficulty);
    // determine tank position
    tankPos =  rand() % 100 + 101;

    // make a loop that ends after the third round OR the game is won
    while(roundNumber <= 3 && !gameOver) {

        //Round banner
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Round #" << roundNumber << ", Difficulty: [" << difficulty << "]\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        // User inputs angle
        cout <<"Enter the angle of your shot in degrees: ";
        getline(cin, angle);
        cout << endl;
        pAngle = stoi(angle);
        pAngle *= M_PI/180;

        // User inputs velocity
        cout <<"Enter the velocity of your shot: ";
        getline(cin, velocity);
        cout << endl;
        pVelocity = stoi(velocity);

        // Convert angle to radians
        // Calculate where shot landed
        playerPos = pVelocity * cos(pAngle);
        // Print up to decimal places
        printf("Your shot landed at x = %.2f\n", playerPos);


        // Based on difficulty, determine if player hit the tank based on if the shot landed within a certain range
        if((difficulty == "easy" || difficulty == "Easy") && ((playerPos >= (tankPos - 20) && playerPos <= (tankPos + 20)))) {
            gameOver = true;
        } else if((difficulty == "medium" || difficulty == "Medium") && ((playerPos >= (tankPos - 10) && playerPos <= (tankPos + 10)))) {
            gameOver = true;
        } else if((difficulty == "hard" || difficulty == "Hard") && ((playerPos >= (tankPos - 5) && playerPos <= (tankPos + 5)))) {
            gameOver = true;
        } else {
            // Player missed the tank, was their shot long or short?
            if(playerPos < tankPos){
                cout <<"You missed the tank -- your shot was too short...\n\n";
            } else {
                cout <<"You missed the tank -- your shot was too long...\n\n";
            }
        }
        // increase round number
        roundNumber++;
    }
    // Player won the game
    if(gameOver) {
        cout << "You hit the tank! Enemy located at x = " << tankPos << endl;
        cout << "* * * Congratulations! Winner Winner Chicken Dinner!! * * *\n";}
        // Player lost the game and the game ends
    else {cout << "You missed the tank :( Enemy located at x = " << tankPos << endl;
        cout << "Boo You Smell Bad Loser!\n";}

    return 0;
}