// The code is based on the BleGamepad.h library https://github.com/lemmingDev/ESP32-BLE-Gamepad and the code example in Arduino IDE (File > Example > ESP32-BLE-Gamepad > SingleButton)
#include <Arduino.h>
#include <BleGamepad.h>

#define BUTTON_PIN 9  // Pin for the button
#define JOYSTICK_LEFT_PIN 8  // Pin for the left direction of the joystick
#define JOYSTICK_RIGHT_PIN 2  // Pin for the right direction of the joystick

BleGamepad bleGamepad;

int previousButtonState = HIGH;
int previousJoystickState = HIGH;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(JOYSTICK_LEFT_PIN, INPUT_PULLUP);
    pinMode(JOYSTICK_RIGHT_PIN, INPUT_PULLUP);
    bleGamepad.begin();
}

void loop() {
    if (bleGamepad.isConnected()) {
        int currentButtonState = digitalRead(BUTTON_PIN);
        int currentJoystickLeftState = digitalRead(JOYSTICK_LEFT_PIN);
        int currentJoystickRightState = digitalRead(JOYSTICK_RIGHT_PIN);

        // Check the joystick for left and right movement
        if (currentJoystickLeftState == LOW) {
            bleGamepad.press(BUTTON_1);  // Press Button 1 for left
            bleGamepad.release(BUTTON_2);  // Release Button 2 (right)
        } else if (currentJoystickRightState == LOW) {
            bleGamepad.press(BUTTON_2);  // Press Button 2 for right
            bleGamepad.release(BUTTON_1);  // Release Button 1 (left)
        } else {
            bleGamepad.release(BUTTON_1);
            bleGamepad.release(BUTTON_2);
        }

        // Check the button
        if (currentButtonState == LOW) {
            bleGamepad.press(BUTTON_3);  // Press Button 3 for the separate button
        } else {
            bleGamepad.release(BUTTON_3);
        }

        previousButtonState = currentButtonState;
        previousJoystickState = currentJoystickLeftState;
    }
}
