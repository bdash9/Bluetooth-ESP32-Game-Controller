#include <Arduino.h>
#include <BleGamepad.h>

#define BUTTON_PIN_1 9  // Pin button 1 is attached to
#define BUTTON_PIN_2 8  // Pin button 2 is attached to
#define BUTTON_PIN_3 2  // Pin button 3 is attached to

BleGamepad bleGamepad;

int previousButton1State = HIGH;
int previousButton2State = HIGH;
int previousButton3State = HIGH;

void setup()
{
    pinMode(BUTTON_PIN_1, INPUT_PULLUP);
    pinMode(BUTTON_PIN_2, INPUT_PULLUP);
    pinMode(BUTTON_PIN_3, INPUT_PULLUP);
    bleGamepad.begin();
}

void loop()
{
    if (bleGamepad.isConnected())
    {
        int currentButton1State = digitalRead(BUTTON_PIN_1);
        int currentButton2State = digitalRead(BUTTON_PIN_2);
        int currentButton3State = digitalRead(BUTTON_PIN_3);

        if (currentButton1State != previousButton1State)
        {
            if (currentButton1State == LOW)
            {
                bleGamepad.press(BUTTON_1);
            }
            else
            {
                bleGamepad.release(BUTTON_1);
            }
        }

        if (currentButton2State != previousButton2State)
        {
            if (currentButton2State == LOW)
            {
                bleGamepad.press(BUTTON_2);
            }
            else
            {
                bleGamepad.release(BUTTON_2);
            }
        }

        if (currentButton3State != previousButton3State)
        {
            if (currentButton3State == LOW)
            {
                bleGamepad.press(BUTTON_3);
            }
            else
            {
                bleGamepad.release(BUTTON_3);
            }
        }

        previousButton1State = currentButton1State;
        previousButton2State = currentButton2State;
        previousButton3State = currentButton3State;
    }
}
