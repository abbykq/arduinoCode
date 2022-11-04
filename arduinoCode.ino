#include <TimeLib.h>
#include <Servo.h>

void setup() {
//  Serial.begin(9600);
//  IrReceiver.begin(inputPin);
};

void loop() {
  // put your main code here, to run repeatedly:

};

class Command {
  private:
    int portNumber;
    int value;
    int type;
    time_t timeStamp;

  public:

    Command(int portNumberIn, int valueIn, String commandTypeIn) {
      portNumberIn = portNumber;
      valueIn = value;
      commandTypeIn = type;
      timeStamp = now();
    }

    int getPN() {
      return portNumber;
    };

    void setPN(int input) {
      portNumber = input;
    };

    int getValue() {
      return value;
    };

    void setValue(int input) {
      value = input;
    };

    time_t getTimeStamp() {
      return timeStamp;
    };

    int getType() {
      return type;
    };

    void setType(int input) {
      type = input;
    };
};

class Component {
  private:
    int value;
    int pin;
    bool active;

  public:
    int getValue() {
      return value;
    };
    int setValue(int val) {
      value = val;
    };
    int getPin() {
      return pin;
    };

    void setPin(int val) {
      pin = val;
    };

    void execute(Command* command) {
      switch (command->getType()) {

        case 1: writeEngine(command->getValue());//engine speed command
          break;

        case 2: writeServo(command->getType()); // Servo angle control
          break;

      }
    };
};

class Engine: public Component {
  public:
    int angle;
    int enginePosition;
};
