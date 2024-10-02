#include <TFT_eSPI.h>   
#define WIDTH 240
#define HEIGHT 135    

TFT_eSPI tft = TFT_eSPI();  
TFT_eSprite personSprite = TFT_eSprite(&tft);
TFT_eSprite bkg = TFT_eSprite(&tft);

// Include the header files that contain the icons
#include "../headers/person.h"
#include "../headers/note1.h"
#include "../headers/note2.h"
#include "../headers/note3.h"

void setup()
{
  tft.begin();
  tft.setRotation(1);	// landscape
  tft.setSwapBytes(true);
  
  bkg.createSprite(WIDTH, HEIGHT);
  bkg.setSwapBytes(true);
}

double x_pos = 20;
double y_pos = 20;
double x_vel = 0.5;
double y_vel = 0.5;
double angle = 0;

int note1X = 50;
int note1Y = 50;
int note2X = 100;
int note2Y = 50;
int note3X = 150;
int note3Y = 50;
long lastUpdate = 0;
long lastShow = 0;
int showing = 0;

void update_notes(long ms) {
    if(millis() - lastUpdate >= ms) {
      lastUpdate = millis();
      note1X = random(0, tft.width()-note1Width);
      note2X = random(0, tft.width()-note2Width);
      note3X = random(0, tft.width()-note3Width);
      note1Y = random(0, tft.width()-note1Height);
      note2Y = random(0, tft.width()-note2Height);
      note3Y = random(0, tft.width()-note3Height);
    }
}

int show_notes(long ms, long timeToShow) {
    if(millis() - lastShow >= ms) {
      lastShow = millis();
      showing = 1;
      return 1;
    }

    if(showing) {
      if(millis() - lastShow >= timeToShow) {
        showing = 0;
      } else {
        return 1;
      }
    }

    return 0;
}

void loop() {
  personSprite.createSprite(WIDTH, HEIGHT);

  // Draw the icons
  bkg.fillSprite(TFT_BLACK);
  

  personSprite.pushImage(0, 0, personWidth, personHeight, person);
  personSprite.setPivot(x_pos + personWidth/2, y_pos + personHeight/2);
  personSprite.pushRotated(&personSprite, angle);
  personSprite.pushRotated(&bkg, angle, TFT_BLACK);

  update_notes(2500);

  if(show_notes(2500, 500)) {
    personSprite.pushImage(note1X, note1Y, note1Width, note1Height, note1);
    personSprite.pushImage(note2X, note2Y, note2Width, note2Height, note2);
    personSprite.pushImage(note3X, note3Y, note3Width, note3Height, note3);
  }

  personSprite.pushToSprite(&bkg, (int)x_pos, (int)y_pos, TFT_BLACK);

  

  bkg.pushSprite(0, 0);

  x_pos += x_vel;
  y_pos += y_vel;
  angle += 1;
  
  if(x_pos+personWidth > tft.width()) { x_vel = -1 * random(30, 70) / 100.0;}
  else if(x_pos < 0) {x_vel = random(30, 70) / 100.0;}

  if(y_pos+personHeight > tft.height()) {y_vel = -1 * random(30, 70) / 100.0;}
  else if(y_pos < 0) {y_vel = random(30, 70) / 100.0;}

  personSprite.deleteSprite();
}