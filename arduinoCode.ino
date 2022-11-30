#include <TimeLib.h>
#include <SoftwareSerial.h>
#define bluetooth A0

SoftwareSerial BTSerial(10, 11); // RX | TX


void setup() {
  Serial.begin(9600);
  pinMode(bluetooth, INPUT);
  BTSerial.begin(9600);
  BTSerial.listen();
  pinMode(0, INPUT);    
};

void loop() {
  int x = digitalRead(10) ;
  if(x!=1) Serial.println(digitalRead(10));
  if (BTSerial.available()) { // read from HC-05 and send to Arduino Serial Monitor
    char BTInput;
    BTInput = BTSerial.read();
    Serial.print(BTSerial.read());
  }

  if (Serial.available())     // Keep reading from Arduino Serial Monitor and send to HC-05
    BTSerial.write(Serial.read());;
};

void writeEngine(int input);
void writeServo(int input);

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

    // Takes in command, which is a pointer to a Command object
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

class ServoClass: public Component {
  public:
    int angle;
};

void writeEngine(int input) {
  //TODO: Write code to handle changes to engines
};

void writeServo(int input) {
  //TODO: Write code to handle changes to servos
};
