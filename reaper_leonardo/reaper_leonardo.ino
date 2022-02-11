
#include <Keyboard.h>

#define KEY_KP_1          0xE1
#define KEY_KP_2          0xE2
#define KEY_KP_3          0xE3
#define KEY_KP_4          0xE4
#define KEY_KP_5          0xE5
#define KEY_KP_6          0xE6
#define KEY_KP_7          0xE7
#define KEY_KP_8          0xE8
#define KEY_KP_9          0xE9
#define KEY_KP_0          0xEA
#define KEY_KP_DOT        0xEB

#define S_1 2
#define S_2 3
#define S_3 4
#define S_4 5
#define S_5 6
#define S_6 7

typedef struct {
  int pin;
  const char *keystroke;
} SwitchMap;

SwitchMap switch_pins[6] = {
  {S_1, "\xE1"},
  {S_2, "\xE2"},
  {S_3, "\xE3"},
  {S_4, "\xE4"},
  {S_5, "\xE5"},
  {S_6, "\xE6"}
};

int cur_switch = -1;

void setup() {
  // put your setup code here, to run once:

  Keyboard.begin();

  for (int i = 0; i < sizeof(switch_pins) / sizeof(SwitchMap); i++) {
    pinMode(switch_pins[i].pin, INPUT);
  }

  Serial.begin(9600);
}

void loop() {
  delay(0);
  for (int i = 0; i < 6; i++) {
    int state = digitalRead(switch_pins[i].pin);
    if (!state) continue;

    if (switch_pins[i].pin == cur_switch) continue;

    cur_switch = switch_pins[i].pin;
    Keyboard.print(switch_pins[i].keystroke);
    
  }
}
