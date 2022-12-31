// C++ code
//long variables that will hold dice roll values for each unit
long attacker1Number;
long attacker2Number;
long attacker3Number;
long defender1Number;
long defender2Number;
//long variables that will hold the highest and lowets dice rolls for the defenders & attackers
long highAttackRoll;
long lowAttackRoll;
long highDefenseRoll;
long lowDefenseRoll;
//ints that represent each attacker LED & defender LED and which pin they're connected to on the UNO
const int attacker1 = 10;
const int attacker2 = 9;
const int attacker3 = 8;
const int defender1 = 12;
const int defender2 = 13;
//ints that represent the three buttons on the breadboard and which pin they're connected to on the UNO
const int defenderButton = 6;
const int attackerButton = 7;
const int fightButton =5;
//ints that represent the state of each button. 0 is unpressed, 1 is pressed
int attackerButtonState = 0;
int defenderButtonState = 0;
int fightButtonState = 0;
//two counter ints that will be used to store the total number of times the attacker button and defender button were pressed
int attackerCounter = 0;
int defenderCounter = 0;

void setup()
{
  Serial.begin(9600);
  //initializes random number generator using value of unconnected A0 pin
  randomSeed(analogRead(0));
  //sets the pinModes for the LEDs to OUTPUT
  pinMode(attacker1,OUTPUT);
  pinMode(attacker2,OUTPUT);
  pinMode(attacker3,OUTPUT);
  pinMode(defender1,OUTPUT);
  pinMode(defender2,OUTPUT);
  //sets the pinModes for the buttons to OUTPUT
  pinMode(attackerButton,INPUT);
  pinMode(defenderButton,INPUT);
  pinMode(fightButton,INPUT);
  //turns all the LEDs off by default
  digitalWrite(attacker1,LOW);
  digitalWrite(attacker2,LOW);
  digitalWrite(attacker3,LOW);
  digitalWrite(defender1,LOW);
  digitalWrite(defender2,LOW);
}

void loop()
{
  //sets the button state integers to the current value of their respective button using digitalRead function
  fightButtonState = digitalRead(fightButton);
  attackerButtonState = digitalRead(attackerButton);
  defenderButtonState = digitalRead(defenderButton);
  //if the fight button is pressed, combatDriver is called and the dice roll commences
  if(fightButtonState == HIGH)
  {
    //we pass the number of attackers and defenders using the respective counter integers that have been incrementing with each button press
    combatDriver(attackerCounter,defenderCounter);
    exit(1);
  } 
  //if defender button is pressed, increment defenderCounter and write its current value to the serial monitor. Not sure if I'll keep serial output in final version, but it is useful for debugging right now, so it stays.
  if(defenderButtonState ==HIGH)
  {
    defenderCounter++;
    delay(300);
    Serial.println("Defender Count:");
    Serial.print(defenderCounter);
    Serial.println("");
    
  }
  //if attacker button is pressed, increment attackerCounter and write its current value to the serial monitor.
  if(attackerButtonState == HIGH)
  {
    attackerCounter++;
    delay(300);
    Serial.println("Attacker Count:");
    Serial.print(attackerCounter);
    Serial.println("");
    
  }	
}
//function that checks and determines combat outcomes
void combatDriver(int attackers,int defenders)
{
  //if the attacker and defender buttons haven't been pressed and someone presses the fight button, we assume they want a fast 1v1, so attackers and defenders are set to 1
  if(attackers<1 && defenders <1)
  {
    attackers =1;
    defenders = 1;
  }
  //if someone presses the attacker button more than 3 times, we set it back to 3, since there are only 3 attackers maximum per Risk rules
  if(attackers>3)
  {
    attackers =3;
  }
  //if someone presses the defenders button more than 2 times, we set it back to 2, since there are only 2 defenders maximum per Risk rules
  if(defenders >2)
  {
    defenders =2;
  }
  //1 attacker, 1 defender
  if(attackers == 1 && defenders == 1)
  {
    //this block turns on the attacker and defender LEDs with a slight delay, then blinks them to simulate combat while the 'dice' are being rolled. 
    enable(attacker1);
    delay(200);
    enable(defender1);
    delay(200);
    blink(attacker1);
    blink(defender1);

    //calls the random number generator to assign a value between 1 and 6 to the attacker and defender variables.
    attacker1Number = random(1,7);
    defender1Number = random(1,7);
    //if statements that compare our attacker and defender number results and set the LEDs to on or off, depending on the outcome of the comparison
    if(attacker1Number>defender1Number)
    {
      digitalWrite(attacker1,HIGH);
      digitalWrite(defender1,LOW);
    }
    //else statement handles attacker loss case, which includes if the attacker and defender numbers are equal
    else
    {
      digitalWrite(defender1,HIGH);
      digitalWrite(attacker1,LOW);
    }
  }
  //2 attackers, 1 defender
  else if(attackers ==2 && defenders ==1)
  {
    //this block turns on the attacker and defender LEDs with a slight delay, then blinks them to simulate combat while the 'dice' are being rolled. 
    enable(attacker1);
    delay(200);
    enable(attacker2);
    delay(200);
    enable(defender1);
    delay(200);
    blink(attacker1);
    blink(defender1);
    blink(attacker2);
    blink(defender1);

    //calls the random number generator to assign a value between 1 and 6 to the attacker and defender variables.
    attacker1Number = random(1,7);
    attacker2Number = random(1,7);
    defender1Number = random(1,7);

    //if statements that compare our attacker and defender number results and set the LEDs to on or off, depending on the outcome of the comparison
    if(attacker1Number>defender1Number)
    {
      digitalWrite(attacker1,HIGH);
      digitalWrite(attacker2,HIGH);
      digitalWrite(defender1,LOW);
    }
    else if(attacker2Number > defender1Number)
    {
      digitalWrite(attacker1,HIGH);
      digitalWrite(attacker2,HIGH);
      digitalWrite(defender1,LOW);
    }
    //else statement handles attacker loss case, which includes if the attacker and defender numbers are equal
    else
    {
      digitalWrite(defender1,HIGH);
      digitalWrite(attacker1,LOW);
      digitalWrite(attacker2,HIGH);
    }
  }
  //3 attackers, 1 defender
  else if(attackers ==3 && defenders ==1)
  {
    //this block turns on the attacker and defender LEDs with a slight delay, then blinks them to simulate combat while the 'dice' are being rolled. 
    enable(attacker1);
    delay(200);
    enable(attacker2);
    delay(200);
    enable(attacker3);
    delay(200);
    enable(defender1);
    delay(500);
    blink(attacker1);
    blink(defender1);
    blink(attacker2);
    blink(defender1);
    blink(attacker3);
    blink(defender1);

    //calls the random number generator to assign a value between 1 and 6 to the attacker and defender variables.
    attacker1Number = random(1,7);
    attacker2Number = random(1,7);
    attacker3Number = random(1,7);
    defender1Number = random(1,7);

    //if statements that compare our attacker and defender number results and set the LEDs to on or off, depending on the outcome of the comparison
    if(attacker1Number>defender1Number)
    {
      digitalWrite(attacker1,HIGH);
      digitalWrite(attacker2,HIGH);
      digitalWrite(attacker3,HIGH);
      digitalWrite(defender1,LOW);
    }
    else if(attacker2Number > defender1Number)
    {
      digitalWrite(attacker1,HIGH);
      digitalWrite(attacker2,HIGH);
      digitalWrite(attacker3,HIGH);
      digitalWrite(defender1,LOW);
    }
    else if(attacker3Number > defender1Number)
    {
      digitalWrite(attacker1,HIGH);
      digitalWrite(attacker2,HIGH);
      digitalWrite(attacker3,HIGH);
      digitalWrite(defender1,LOW);
    }
    //else statement handles attacker loss case, which includes if the attacker and defender numbers are equal
    else
    {
      digitalWrite(defender1,HIGH);
      digitalWrite(attacker1,LOW);
      digitalWrite(attacker2,HIGH);
      digitalWrite(attacker3,HIGH);
    }
  }
  //two defenders, 1 attacker
  else if(attackers ==1 && defenders ==2)
  {
    //this block turns on the attacker and defender LEDs with a slight delay, then blinks them to simulate combat while the 'dice' are being rolled. 
    enable(attacker1);
    delay(200);
    enable(defender1);
    delay(200);
    enable(defender2);
    delay(500);
    blink(attacker1);
    blink(defender1);
    blink(attacker1);
    blink(defender2);
    blink(attacker1);

    //calls the random number generator to assign a value between 1 and 6 to the attacker and defender variables.
    attacker1Number = random(1,7);
    defender1Number = random(1,7);
    defender2Number = random(1,7);

    //if statements that compare our attacker and defender number results and set the LEDs to on or off, depending on the outcome of the comparison
    if(attacker1Number > defender1Number)
    {
      //once we know that the lone attacker's number is greater than of the defender's numbers, we then compare it to the other defender's number to determine the outcome
      if(attacker1Number>defender2Number)
      {
        digitalWrite(attacker1,HIGH);
        digitalWrite(defender1,LOW);
        digitalWrite(defender2,HIGH);
      }
      //else statement handles attacker loss case, which includes if the attacker and defender numbers are equal
      else
      {
        digitalWrite(attacker1,LOW);
        digitalWrite(defender1,HIGH);
        digitalWrite(defender2,HIGH);
      }
    }
    //else statement handles attacker loss case, which includes if the attacker and defender numbers are equal
    else
    {
      digitalWrite(attacker1,LOW);
      digitalWrite(defender1,HIGH);
      digitalWrite(defender2,HIGH);
    }
  }
  //two defenders, two attackers
  else if(attackers ==2 && defenders ==2)
  {
    //this block turns on the attacker and defender LEDs with a slight delay, then blinks them to simulate combat while the 'dice' are being rolled. 
    enable(attacker1);
    delay(200);
    enable(defender1);
    delay(200);
    enable(attacker2);
    delay(200);
    enable(defender2);
    delay(500);
    blink(attacker1);
    blink(attacker2);
    blink(defender1);
    blink(defender2);
    blink(attacker1);
    blink(attacker2);
    blink(defender2);
    blink(attacker1);
    blink(attacker2);

    //calls the random number generator to assign a value between 1 and 6 to the attacker and defender variables
    attacker1Number = random(1,7);
    attacker2Number = random(1,7);
    defender1Number = random(1,7);
    defender2Number = random(1,7);
    //calls the sortDiceRolls function to determine and order the highest and lowest roll from the defenders and attackers. Out of pure laziness, we pass 0 at the end so I don't have to implement a 
    //a variable argument function. Within sortDiceRolls, we check if that third parameter is 0, and if it is, it sorts for the four 'real' values passed. Otherwise, it sorts all five.
    sortDiceRolls(attacker1Number,defender1Number,attacker2Number,defender2Number,0);

    //if statements that compare our highest attacker and defender numbers and set the LEDs to on or off, depending on the outcome of the comparison
    if(highAttackRoll>highDefenseRoll)
    {
      //attacker loses none,defender loses 2
      if(lowAttackRoll>lowDefenseRoll)
      {
        digitalWrite(attacker1,HIGH);
        digitalWrite(attacker2,HIGH);
        digitalWrite(defender1,LOW);
        digitalWrite(defender2,LOW);
      }
      //attacker loses 1, defender loses 1 
      else
      {
        digitalWrite(attacker1,HIGH);
        digitalWrite(attacker2,LOW);
        digitalWrite(defender1,LOW);
        digitalWrite(defender2,HIGH);
      }
    }
    else
    {
      //attacker loses 1, defender loses 1
      if(lowAttackRoll>lowDefenseRoll)
      {
        digitalWrite(attacker1,LOW);
        digitalWrite(defender1,HIGH);
        digitalWrite(attacker2,HIGH);
        digitalWrite(defender2,LOW);
      }
      //defender loses none,attacker loses 2
      else
      {
        digitalWrite(attacker1,LOW);
        digitalWrite(attacker2,LOW);
        digitalWrite(defender1,HIGH);
        digitalWrite(defender2,HIGH);
      }
    }
  }
    //two defenders, three attackers
  else if(attackers ==3 && defenders ==2)
  {
    //this block turns on the attacker and defender LEDs with a slight delay, then blinks them to simulate combat while the 'dice' are being rolled. 
    enable(attacker1);
    delay(200);
    enable(attacker2);
    delay(200);
    enable(attacker3);
    delay(200);
    enable(defender1);
    delay(200);
    enable(defender2);
    delay(500);
    blink(attacker1);
    blink(attacker2);
    blink(attacker3);
    blink(defender1);
    blink(defender2);
    blink(attacker1);
    blink(attacker2);
    blink(attacker3);
    blink(defender2);
    blink(attacker1);
    blink(attacker2);
    blink(attacker3);

    //calls the random number generator to assign a value between 1 and 6 to the attacker and defender variables
    attacker1Number = random(1,7);
    attacker2Number = random(1,7);
    attacker3Number = random(1,7);
    defender1Number = random(1,7);
    defender2Number = random(1,7);

    //calls the sortDiceRolls function to determine and order the highest and lowest roll from the defenders and attackers.
    sortDiceRolls(attacker1Number,defender1Number,attacker2Number,defender2Number,attacker3Number);

    //if statements that compare our attacker and defender number results and set the LEDs to on or off, depending on the outcome of the comparison
    if(highAttackRoll>highDefenseRoll)
    {
      //attacker loses none, defender loses 2
      if(lowAttackRoll>lowDefenseRoll)
      {
        digitalWrite(attacker1,HIGH);
        digitalWrite(attacker2,HIGH);
        digitalWrite(attacker3,HIGH);
        digitalWrite(defender1,LOW);
        digitalWrite(defender2,LOW);
      }
      //attacker loses 1, defender loses 1
      else
      {
        digitalWrite(attacker1,HIGH);
        digitalWrite(attacker2,HIGH);
        digitalWrite(attacker3,HIGH);
        digitalWrite(defender1,LOW);
        digitalWrite(defender2,HIGH);
      }
    }
    else
    {
      //attacker loses 1, defender loses 1
      if(lowAttackRoll>lowDefenseRoll)
      {
        digitalWrite(attacker1,LOW);
        digitalWrite(defender1,HIGH);
        digitalWrite(attacker2,HIGH);
        digitalWrite(defender2,LOW);
        digitalWrite(attacker3,HIGH);
      }
      //defender loses none, attacker loses 2
      else
      {
        digitalWrite(attacker1,LOW);
        digitalWrite(attacker2,LOW);
        digitalWrite(attacker3,HIGH);
        digitalWrite(defender1,HIGH);
        digitalWrite(defender2,HIGH);
      }
    }
  }
}
//sorts the dice rolls into highest attack roll, highest defense roll,
//lowest attack roll, and lowest defense roll
void sortDiceRolls(int attacker, int defender, int attacker2,int defender2,int attacker3)
{
  //this is the aforementioned lazy if statement that sorts for 4 parameters if attacker 3 is passed as 0, otherwise it sorts for 5 parameters
  //sorts the attacker values into highest and lowest, storing them into respective variables
  if(attacker3 == 0)
  {
    if(attacker >= attacker2)
    {
      highAttackRoll = attacker;
      lowAttackRoll = attacker2;
    }
    else
    {
      highAttackRoll = attacker2;
      lowAttackRoll = attacker;
    }
  }
  //this else statement does the same as above except for 3 attacker values
  else
  {
    //if statements sort the attack rolls into highest and lowest dice. Once the largest value of the 3 is chosen, the second largest will be assigned to lowAttackRoll. the true lowest value will remain unused.
    //i.e if 5,3, and 1 are passed, 5 will be assigned to highAttackRoll, and 3 will be assigned to lowAttackRoll. 1 will not be used.
    if(attacker >= attacker2 && attacker >= attacker3)
    {
      highAttackRoll = attacker;
      if(attacker2>=attacker3)
      {
        lowAttackRoll = attacker2;
      }
      else
      {
        lowAttackRoll = attacker3;
      }
    }
    else if(attacker2 >=attacker &&attacker2 >= attacker3)
    {
      highAttackRoll =attacker2;
      if(attacker >= attacker3)
      {
        lowAttackRoll = attacker;
      }
      else
      {
        lowAttackRoll = attacker3;
      }
    }
    else
    {
      highAttackRoll = attacker3;
      
      if(attacker2 >= attacker)
      {
        lowAttackRoll = attacker2;
      }
      else
      {
        lowAttackRoll = attacker;
      }
    }
  }
  //sorts the defender values into highest and lowest
  if(defender >= defender2)
  {
    highDefenseRoll = defender;
    lowDefenseRoll = defender2;
  }
  else
  {
    highDefenseRoll = defender2;
    lowDefenseRoll = defender;
  }
}
//turns on the specified LED
void enable(int LED)
{
  digitalWrite(LED,HIGH);
}
//blinks the specified LED
void blink(int LED)
{
  	digitalWrite(LED,LOW);
    delay(200);
    digitalWrite(LED,HIGH);
    delay(200);
  	digitalWrite(LED,LOW);
  	delay(200);
  	digitalWrite(LED,HIGH);
}


