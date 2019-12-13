#include "Adafruit_VL53L0X.h"
#include "Controls.cc"
#include "Display.cc"
#include "Streaming.h"

Controls controls	 = Controls();
Display display		 = Display();
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

/**
 * Declarations
 */
void joystick_callback(int8_t x, int8_t y);
void button_callback(FJBUTTON* buttons, uint8_t count);

/**
 * Declarations
 */
void setup() {
	// Serial.begin(115200);
	display.begin();
	controls.begin().register_button_callback(button_callback).register_joystick_callback(joystick_callback);

	if (!lox.begin()) {
        display.clear().println1("Failed to boot VL53L0X").update();
		while (1)
			;
	}
}

void loop() {
	// controls.update();
	// display.invert(stepper.isRunning())
	//   .clear()
	//   .println1("Curr ")
	//   .println1(stepper.currentPosition())
	//   .println1(", Targ ")
	//   .println1(stepper.targetPosition())
	//   .println2(stepper.speed())
	//   .println2(" s/s ")
	//   .println2(stepper_accel)
	//   .println2(" s/s/s ")
	//   .println3(!digitalRead(STEPPER_EN_PIN) ? "Enabled" : "Disabled")
	//   .update();
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
