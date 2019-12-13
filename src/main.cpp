#include "Controls.cc"
#include "Display.cc"
#include "Streaming.h"
#include <VL53L0X.h>

Controls controls = Controls();
Display display	  = Display();
VL53L0X tof;

/**
 * Declarations
 */
void joystick_callback(int8_t x, int8_t y);
void button_callback(FJBUTTON* buttons, uint8_t count);

/**
 * Declarations
 */
void setup() {
	Serial.begin(115200);
	display.begin();
    display.clear();
	// controls.begin().register_button_callback(button_callback).register_joystick_callback(joystick_callback);

	tof.setTimeout(500);
	tof.init();
	tof.startContinuous();
}

void loop() {
    display
        .clearln1()
        .println1(tof.readRangeContinuousMillimeters())
        .update();

	if (tof.timeoutOccurred()) {
        display.clearln2().println2("Timed out");
    }
}

void left_button_pressed() {
}

void right_button_pressed() {
}

void up_button_pressed() {
}

void down_button_pressed() {
}

void select_button_pressed() {
}

void joystick_callback(int8_t x, int8_t y) {
}

void button_callback(FJBUTTON* buttons, uint8_t count) {
	for (int i = 0; i < count; i++) {
		if (buttons[i].hasChanged && buttons[i].pressed) {
			switch (buttons[i].pinId) {
				case BUTTON_RIGHT:
					right_button_pressed();
					break;
				case BUTTON_DOWN:
					down_button_pressed();
					break;
				case BUTTON_LEFT:
					left_button_pressed();
					break;
				case BUTTON_UP:
					up_button_pressed();
					break;
				case BUTTON_SEL:
					select_button_pressed();
					break;
			}
		}
	}
}
