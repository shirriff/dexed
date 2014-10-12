/**
 *
 * Copyright (c) 2014 Pascal Gauthier.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

#ifndef DXCOMPONENTS_H_INCLUDED
#define DXCOMPONENTS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class EnvDisplay : public Component {
public:
    EnvDisplay();
    char *pvalues;
    char vPos;    
    void paint(Graphics &g);
};

class PitchEnvDisplay : public Component {
    char rvalues[8];
public:
    PitchEnvDisplay();
    char *pvalues;
    char vPos;
    void paint(Graphics &g);
};

class VuMeter: public Component {
    void paint(Graphics &g);
public : 
    float v;
};

class LcdDisplay : public Component, public Timer, public AsyncUpdater {
    void timerCallback();
    void handleAsyncUpdate();
public:
    LcdDisplay();
    void setSystemMsg(String msg);
    String systemMsg;
    String paramMsg;
    void paint(Graphics &g);    
};

class ComboBoxImage : public ComboBox {
    Image items;
    int itemHeight;
    PopupMenu popup;
    bool onPopup;

    int itemPos[4];
public:
    ComboBoxImage();

    virtual void paint(Graphics &g);
    virtual void showPopup() override;
    void setImage(Image image);
    void setImage(Image image, int pos[]);
};

class ProgramSelector : public ComboBox {
    bool isInInit;
public:
    void setInit();
    virtual void paint(Graphics &g) override;
};

#endif  // DXCOMPONENTS_H_INCLUDED
