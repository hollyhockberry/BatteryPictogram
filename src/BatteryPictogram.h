// Copyright (c) 2021 Inaba.

#ifndef BATTERYPICTOGRAM_H_
#define BATTERYPICTOGRAM_H_

#include <Adafruit_GFX.h>

class BatteryPictogram {
 public:
  BatteryPictogram(int width, int height, int on, int off);

  void locate(int x, int y);
  void draw(int x, int y, int level, Adafruit_GFX* gfx);
  void draw(int level, Adafruit_GFX* gfx);
 private:
  const int width_, height_, on_, off_;
  int x_, y_, bar_;
};

#endif  // BATTERYPICTOGRAM_H_
