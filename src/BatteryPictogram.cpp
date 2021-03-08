// Copyright (c) 2021 Inaba.

#include "BatteryPictogram.h"

BatteryPictogram::BatteryPictogram(int width, int height, int on, int off)
: width_(width), height_(height), on_(on), off_(off),
  x_(), y_(), bar_(-1) {
}

void BatteryPictogram::locate(int x, int y) {
  x_ = x;
  y_ = y;
}

void BatteryPictogram::draw(int x, int y, int level, Adafruit_GFX* gfx) {
  locate(x, y);
  draw(level, gfx);
}

void BatteryPictogram::draw(int level, Adafruit_GFX* gfx) {
  const int frame = 1;  // frame weight
  const int twidth = 2, theight = 4;  // terminal size
  const int max = width_ - twidth - frame * 2;

  if (level > 100) level = 100;
  if (level < 0) level = 0;
  int bar = max * level / 100;
  if (bar_ == bar || gfx == nullptr) return;

  bar_ = bar;
  // +terminal
  gfx->fillRect(x_, y_ + (height_ - theight) / 2, twidth, theight, on_);
  // body
  gfx->fillRect(x_ + twidth, y_, width_ - frame * 2, height_, on_);
  // used
  bar = (max - bar) % max;
  gfx->fillRect(x_ + twidth + frame, y_ + frame,
                bar, height_ - frame * 2, off_);
}
