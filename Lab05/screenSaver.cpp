#include "screenSaver.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>

//Self-explanatory
ScreenSaver::ScreenSaver() {
  shape = sf::CircleShape(10.f);
  velocity = sf::Vector2f(0.0f, 0.0f);
  shape.setFillColor(sf::Color::White);
}

//Self-explanatory
ScreenSaver::ScreenSaver(float radius, sf::Vector2f cVelocity, sf::Color color) {
  shape = sf::CircleShape(radius);
  velocity = cVelocity;
  shape.setFillColor(color);
}

//We have to return shape as a reference!
sf::CircleShape &ScreenSaver::getShape() { return shape; }

//this will draw the sf::CircleShape member of ScreenSaver to the screen
//this will be inherited by all derived class, and shouldn't have to be overriden
void ScreenSaver::draw(sf::RenderWindow &window) { window.draw(getShape()); }

/*Here's some nifty code to resolve any collsions with a wall, by reversing
the velocity of the object to mimic bouncing, you can call this function
in your update functions to make sure your ScreenSaver doesn't wander off-screen*/
void ScreenSaver::checkWallCollision(int screenWidth, int screenHeight){
  
    sf::Vector2f position = getShape().getPosition();
  float diameter = getShape().getRadius() * 2;

  // Check if the circle hits the right wall
  if (position.x + diameter > screenWidth)
  {
    getShape().setPosition(screenWidth - diameter, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the left wall
  if (position.x < 0)
  {
    getShape().setPosition(0, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the top wall
  if (position.y < 0)
  {
    getShape().setPosition(position.x, 0);
    velocity.y *= -1.f;
  }

  // Check if the circle hits the bottom wall
  if (position.y + diameter > screenHeight)
  {
    getShape().setPosition(position.x, screenHeight - diameter);
    velocity.y *= -1.f;
  }
}

ClassicSaver::ClassicSaver(float radius, sf::Vector2f cVelocity, sf::Color color) {
    shape = sf::CircleShape(radius);
    velocity = cVelocity;
    shape.setFillColor(color);
}
void ClassicSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    shape.move(velocity.x * deltaTime, velocity.y * deltaTime);
    checkWallCollision(screenWidth, screenHeight);
}

ColorChangingSaver::ColorChangingSaver(float radius, sf::Vector2f cVelocity, float cColorSpeed) {
    shape = sf::CircleShape(radius);
    velocity = cVelocity;
    shape.setFillColor(sf::Color::Red);
    colorSpeed = cColorSpeed;
}
void ColorChangingSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    shape.move(velocity.x * deltaTime, velocity.y * deltaTime);
    sf::Color current = shape.getFillColor();
    if(current.r >= current.b) {
        current.b += colorSpeed * deltaTime;
        current.r -= colorSpeed * deltaTime;
    } else {
        current.b -= colorSpeed * deltaTime;
        current.r += colorSpeed * deltaTime;
    }
    shape.setFillColor(current);
    checkWallCollision(screenWidth, screenHeight);
}

CustomSaver::CustomSaver(float sideLength, sf::Vector2f cVelocity, float cSpinSpeed) {
    shape = sf::RectangleShape(sf::Vector2f(sideLength, sideLength));
    velocity = cVelocity;
    shape.setFillColor(sf::Color::Blue);
    spinSpeed = cSpinSpeed;
}
void CustomSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    shape.move(velocity.x * deltaTime, velocity.y * deltaTime);
    shape.rotate(spinSpeed * deltaTime);
    checkWallCollision(screenWidth, screenHeight);
}



//TODO Define all necessary member functions for ClassicSaver, ColorChangingSaver, and CustomSaver Here
