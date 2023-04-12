// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//the extra feature I added was audio, I have both a sf::Music object and two sound effects using sf::SoundBuffer to load and sf::Sound to play them


#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
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
    //variable declarations
    int moveCount = 0;
    Font font;
    Text startText;
    int hitCount = 0;
    int numTargets = 3;

    srand(time(NULL));

    Music mainSoundTrack;
    bool mainSoundTrackPlaying = false;

    bool hitTarget = false;
    bool playGame = false;
   

    SoundBuffer winSfx;
    bool winSfxPlaying = false;
    SoundBuffer targetHitSfx;

    Sound playSound;
    

    //loading font and sound from files
    if (!font.loadFromFile("AGENCYR.ttf")) {
        cout << "Error";
    }
    if (!mainSoundTrack.openFromFile("mainMusic.ogg")) {
        cout << "Error";
    }
    if(!winSfx.loadFromFile("winSFX.wav"))
    {
        cout << "Error";
    }
    if (!targetHitSfx.loadFromFile("targetHitSFX.wav"))
    {
        cout << "Error";
    }
    /*
    Text debugText;
    Text targetText;
    debugText.setFont(font);
    targetText.setFont(font);
    */
    //reduces the volume on music to not overwhelm the sound effects
    mainSoundTrack.setVolume(50);

    //seting up text objects
    Text remainingText;
    remainingText.setFont(font);
    remainingText.setString("Targets Remaining: " + to_string(numTargets - hitCount));

    startText.setFont(font);
    startText.setString("Use WASD to move, hit the target in as few moves as possible\nHit "+ to_string(numTargets) + " targets to win\nPress enter to start the game");
    startText.setCharacterSize(24); // in pixels, not points!

    // set the color
    startText.setFillColor(Color::Red);

    // set the text style
    startText.setStyle(Text::Bold);

    Text winText;
    winText.setFont(font);
    winText.setString("You win!\nTotal moves: " + moveCount);
    winText.setCharacterSize(24);
    winText.setFillColor(Color::Red);
    winText.setStyle(Text::Bold);

    //creates window
    RenderWindow window(sf::VideoMode(800, 600), "My window");

    
   
    //out << "Use WASD to move, get with 0.75 units of the target in as few moves as possible" << endl;
    //cout << "Hit 2 targets to win" << endl;

    b2Vec2 target(randomRange(9, -9), randomRange(9, -9));

    //cout << "Target Location: X - " << target.x << " " << "Y - " << target.y << endl;;

    b2Vec2 gravity(0.0f, 0.0f);

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
    
    RectangleShape playerImage(Vector2f(10,10));
    playerImage.setOrigin(5, 5);
    playerImage.setFillColor(Color::Red);

    //creates deltaTime using SFML library
    Clock deltaClock;
    Time dt;


    //creating sfml objects from target and all four walls 
    RectangleShape targetShape(Vector2f(50,36));
    targetShape.setOrigin(25, 18);
    targetShape.setPosition(returnX(target.x), returnY(target.y));
    targetShape.setFillColor(Color::Green);


    RectangleShape floor(Vector2f(800, 80));
    floor.setFillColor(Color::Blue);
    
    floor.setPosition(returnX(0.0f), returnY(-11.0f)); 
    floor.setOrigin(Vector2f(400, 40));
    

    RectangleShape ceiling(Vector2f(800, 80));
    ceiling.setFillColor(Color::Blue);
    ceiling.setOrigin(Vector2f(400, 40));
    ceiling.setPosition(returnX(0), returnY(10.84));
    
    RectangleShape leftWall(Vector2f(80, 800));
    leftWall.setFillColor(Color::Blue);
    leftWall.setOrigin(Vector2f(40, 400));
    leftWall.setPosition(returnX(-10.50), returnY(0));

    RectangleShape rightWall(Vector2f(80, 800));
    rightWall.setFillColor(Color::Blue);
    rightWall.setOrigin(Vector2f(40, 400));
    rightWall.setPosition(returnX(10.60), returnY(0));

    //stops the code from starting the game loop before the player is ready
    //cout << "Press any letter and then enter to begin: ";
    //char test;
    //cin >> test;

    //variables used to display the output text once every 0.1 seconds to make the speed that the player's position is being printed less overwhelming
    float displayTimer = 0.0f;
    const float TIME_BETWEEN_DISPLAY = 0.1f;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        
        //sound track is played in each game state so it isn't in any of the if statements
        //uses if and bool to only call .play in the first while loop call
        if (!mainSoundTrackPlaying) 
        {
            mainSoundTrack.play();
            mainSoundTrackPlaying = true;
        }
        
        
        
       
        //menu that hold the player until they press enter
        if (!playGame) 
        {
            window.draw(startText);
            if (Keyboard::isKeyPressed(Keyboard::Enter)) 
            {
                playGame = true;
            }
        }
        
        //game loop
       if(hitCount < numTargets && playGame)
       {

            //deltaTime calculation
            displayTimer += dt.asSeconds();
            //stores the player's position in a variable
            b2Vec2 position = playerBody->GetPosition();
            //prints the position of the player and target once every 0.1 seconds
            if (displayTimer > TIME_BETWEEN_DISPLAY)
            {
                displayTimer = 0;
                //display(position.x, position.y, target);
            }

            //tells time passed since previous loop
            dt = deltaClock.getElapsedTime();
            //resets the timer so multiple loops don't get added
            deltaClock.restart();

            world->Step(dt.asSeconds(), 6, 2);

            applyForces(playerBody, &moveCount, dt.asSeconds());
            playerImage.setPosition(returnX(position.x), returnY(position.y));

            
            //drawing objects
            window.draw(playerImage);
            window.draw(floor);
            window.draw(ceiling);
            window.draw(leftWall);
            window.draw(rightWall);
            window.draw(targetShape);
            window.draw(remainingText);
           


            //player wins when they are within 0.75 units from the target
            if (target.x - position.x <= 0.75f && target.x - position.x >= -0.75f && target.y - position.y <= 0.75f && target.y - position.y >= -0.75f) {
                
                hitCount++;
                //repositions target
                target.x = randomRange(9, -9);
                target.y = randomRange(9, -9);
                //respositions smfl target object
                targetShape.setPosition(returnX(target.x), returnY(target.y));
                remainingText.setString("Targets Remaining: " + to_string(numTargets - hitCount));
                
                //plays target hit sound
                playSound.setBuffer(targetHitSfx);
                playSound.play();
            }

       }
       //can't use else because that would be true before the player starts the game, uses else if rather than if to avoid the condition being checked every frame
       else if(hitCount >= numTargets){
           //uses if and bool to only call .play in the first while loop call
           if (!winSfxPlaying) {
               //resets the sound player to use the correct sound effect
               playSound.setBuffer(winSfx);
               //plays the win sound effect
               playSound.play();
               winSfxPlaying = true;
           }

           winText.setString("Total moves: " + to_string(moveCount));
           window.draw(winText);
       }

       // end the current frame
       window.display();
    }
   
    //deletes world, the only object created using the new keyword
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
