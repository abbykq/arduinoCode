void setup() {
  

};

void loop() {
  // put your main code here, to run repeatedly:

};

class Command{
  private:
    int portNumber;
    int value;
    String commandType;
    
  public:
    void execute(){
    //TODO: wright code to handle command execution.
    }
  
    Command(int portNumberIn, int valueIn, String commandTypeIn){
        portNumberIn = portNumber;
        valueIn = value;
        commandTypeIn = commandType;
    }
    
    int getPN(){return portNumber;};
    
    void setPN(int input){portNumber = input;};
    
    int getValue(){return value;};
    
    void setValue(int input){value = input;};
    
    String getCommand(){return commandType;};
    
    void setCommand(String input){commandType = input;};
    
};

class Engine{
  private:
    int value;
    int pin;
    Command command;
    
  public:
   int getValue(){return value;};

   int getPin(){return pin;};

   void setPin(int val){pin = val;};
   
   Command getCommand(){return command;};
   
   void setCommand(Command val){command = val;};
   
   int setValue(int val){value = val;};
};
