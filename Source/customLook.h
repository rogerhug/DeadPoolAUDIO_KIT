/*
  ==============================================================================

    customLook.h
    Created: 17 May 2021 1:56:01pm
    Author:  Roger Hug

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>

struct CustomLookAndFeel : public juce::LookAndFeel_V2
{
 void drawComboBox(Graphics& g, int width, int height, const bool /*isMouseButtonDown*/,
        int buttonX, int buttonY, int buttonW, int buttonH, ComboBox& box)
    {
        g.fillAll(box.findColour(ComboBox::backgroundColourId));

        if (box.isEnabled() && box.hasKeyboardFocus(false))
        {
            g.setColour(box.findColour(ComboBox::focusedOutlineColourId));
            g.drawRect(0, 0, width, height, 2);
        }
        else
        {
            g.setColour(box.findColour(ComboBox::outlineColourId));
            g.drawRect(0, 0, width, height);
        }

        const float arrowX = 0.3f;
        const float arrowH = 0.2f;

        const auto x = (float)buttonX;
        const auto y = (float)buttonY;
        const auto w = (float)buttonW;
        const auto h = (float)buttonH;

        Path p;
        p.addTriangle(x + w * 0.5f, y + h * (0.45f - arrowH),
            x + w * (1.0f - arrowX), y + h * 0.45f,
            x + w * arrowX, y + h * 0.45f);

        p.addTriangle(x + w * 0.5f, y + h * (0.55f + arrowH),
            x + w * (1.0f - arrowX), y + h * 0.55f,
            x + w * arrowX, y + h * 0.55f);

        g.setColour(box.findColour(ComboBox::arrowColourId).withMultipliedAlpha(box.isEnabled() ? 1.0f : 0.3f));
        g.fillPath(p);
    }

    void LookAndFeel_layoutFilenameComponent(FilenameComponent& filenameComp,
        ComboBox* filenameBox, Button* browseButton)
    {
        if (browseButton == nullptr || filenameBox == nullptr)
            return;

        browseButton->setSize(80, 40);

        if (auto* tb = dynamic_cast<TextButton*> (browseButton))
            tb->changeWidthToFitText();
        browseButton->setButtonText("Drop or load .wav");

        browseButton->setTopRightPosition(filenameComp.getWidth(), 0);

        browseButton->setBounds(0, 0, 10, 40);
        filenameBox->setBounds(0, 0, 3, 2);
    }
   
};