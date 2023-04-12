// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>;
#include "snake.h"
#include <conio.h>
using namespace std;
using namespace sf;

void wrapper();

int main()
{
    //scopes out anything on the stack to avoid them showing uo as memory leaks
    wrapper();

    //checks for memory leaks
    if (_CrtDumpMemoryLeaks()) {
        cout << "Leak" << endl;
    }

    
}

void wrapper() {
    int moveCount = 0;
    int hitCount = 0;
    srand(time(NULL));

    bool hitTarget = false;

    cout << "Use WASD to move, get with 0.75 units of the target in as few moves as possible" << endl;
    cout << "Hit 2 targets to win" << endl;

    b2Vec2 target(randomRange(10, -10), randomRange(10, -10));

    cout << "Target Location: X - " << target.x << " " << "Y - " << target.y << endl;;

    b2Vec2 gravity(0.0f, -10.0f);

    b2World* world = new b2World(gravity);

    //positioned 10 below the origin
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -11.0f);
    //instantiates the body in the world based on it's definition
    b2Body* groundBody = world->CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    //sets x distance from center to edge as 50 and y distance as 1
    groundBox.SetAsBox(50.0f, 1.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    b2BodyDef leftWallBodyDef;
    leftWallBodyDef.position.Set(-11.0f, 0.0f);

    b2Body* leftWallBody = world->CreateBody(&leftWallBodyDef);

    b2PolygonShape leftWallBox;
    leftWallBox.SetAsBox(1.0f, 50.0f);
    leftWallBody->CreateFixture(&leftWallBox, 0.0f);


    b2BodyDef rightWallBodyDef;
    rightWallBodyDef.position.Set(11.0f, 0.0f);

    b2Body* rightWallBody = world->CreateBody(&rightWallBodyDef);

    b2PolygonShape rightWallBox;
    rightWallBox.SetAsBox(1.0, 50.0f);
    rightWallBody->CreateFixture(&rightWallBox, 0.0f);


    b2BodyDef topBodyDef;
    topBodyDef.position.Set(0.0f, 11.0f);
    //instantiates the body in the world based on it's definition
    b2Body* topBody = world->CreateBody(&topBodyDef);

    b2PolygonShape topBox;
    //sets x distance from center to edge as 50 and y distance as 10 so the whole box would be 100x20
    topBox.SetAsBox(50.0f, 1.0f);
    topBody->CreateFixture(&topBox, 0.0f);

    b2BodyDef playerBodyDef;
    //tells the phsyics engine player is effected by forces
    playerBodyDef.type = b2_dynamicBody;
    playerBodyDef.position.Set(0.0f, 1.0f);

    b2Body* playerBody = world->CreateBody(&playerBodyDef);

    b2PolygonShape playerBox;
    playerBox.SetAsBox(0.5f, 0.5f);

    b2FixtureDef playerFix;
    playerFix.shape = &playerBox;
    playerFix.density = 1.0f;
    playerFix.friction = 0.3f;
    playerBody->CreateFixture(&playerFix);

    //creates deltaTime using SFML library
    Clock deltaClock;
    Time dt;

    //stops the code from starting the game loop before the player is ready
    cout << "Press any letter and then enter to begin: ";
    char test;
    cin >> test;

    //variables used to display the output text once every 0.1 seconds to make the speed that the player's position is being printed less overwhelming
    float displayTimer = 0.0f;
    const float TIME_BETWEEN_DISPLAY = 0.1f;

    while (hitCount < 2)
    {

        //deltaTime calculation
        displayTimer += dt.asSeconds();
        //stores the player's position in a variable
        b2Vec2 position = playerBody->GetPosition();
        //prints the position of the player and target once every 0.1 seconds
        if (displayTimer > TIME_BETWEEN_DISPLAY)
        {
            displayTimer = 0;
            display(position.x, position.y, target);
        }

        //tells time passed since previous loop
        dt = deltaClock.getElapsedTime();
        //resets the timer so multiple loops don't get added
        deltaClock.restart();

        world->Step(dt.asSeconds(), 6, 2);
        
        applyForces(playerBody, &moveCount, dt.asSeconds());


        //player wins when they are within 0.75 units from the target
        if (target.x - position.x <= 0.75f && target.x - position.x >= -0.75f && target.y - position.y <= 0.75f && target.y - position.y >= -0.75f) {
            cout << "target hit" << endl;
            hitCount++;
            target.x = randomRange(10, -10);
            target.y = randomRange(10, -10);
        }

    }
    //informs the player when they have won
    cout << "You win" << endl;;
    cout << "Total Moves: " << moveCount;
    delete world;
    world = nullptr;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
