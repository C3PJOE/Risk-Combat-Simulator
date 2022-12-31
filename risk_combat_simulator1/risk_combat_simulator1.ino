// C++ code
long attacker1Number;
long attacker2Number;
long attacker3Number;
long defender1Number;
long defender2Number;

long highAttackRoll;
long lowAttackRoll;
long highDefenseRoll;
long lowDefenseRoll;

const int attacker1 = 10;
const int attacker2 = 9;
const int attacker3 = 8;
const int defender1 = 12;
const int defender2 = 13;

const int button2 = 6;
const int button = 7;
const int offButton =5;
int buttonState = 0;
int button2State = 0;
int offButtonState = 0;
int pressCounter = 0;
int pressCounter2 = 0;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  pinMode(attacker1,OUTPUT);
  pinMode(attacker2,OUTPUT);
  pinMode(attacker3,OUTPUT);
  pinMode(defender1,OUTPUT);
  pinMode(defender2,OUTPUT);
  
  pinMode(button,INPUT);
  pinMode(button2,INPUT);
  pinMode(offButton,INPUT);
  
  digitalWrite(attacker1,LOW);
  digitalWrite(attacker2,LOW);
  digitalWrite(attacker3,LOW);
  digitalWrite(defender1,LOW);
  digitalWrite(defender2,LOW);
}

void loop()
{
  offButtonState = digitalRead(offButton);
  buttonState = digitalRead(button);
  button2State = digitalRead(button2);
  
  if(offButtonState == HIGH)
  {
    combatDriver(pressCounter,pressCounter2);
    exit(1);
  } 
  if(button2State ==HIGH)
  {
    pressCounter2++;
    delay(300);
    Serial.println("Defender Count:");
    Serial.print(pressCounter2);
    Serial.println("");
    
  }
  if(buttonState == HIGH)
  {
    pressCounter++;
    delay(300);
    Serial.println("Attacker Count:");
    Serial.print(pressCounter);
    Serial.println("");
    
  }	
}
//function that checks and determines combat outcomes
void combatDriver(int attackers,int defenders)
{
  //this lets players just click the offbutton instead of having to click all three, if it's just going to be a 1v1 anyway
  if(attackers<1 && defenders <1)
  {
    attackers =1;
    defenders = 1;
  }
  if(attackers>3)
  {
    attackers =3;
  }
  if(defenders >2)
  {
    defenders =2;
  }
  //1 attacker, 1 defender
  if(attackers == 1 && defenders == 1)
  {
    enable(attacker1);
    delay(200);
    enable(defender1);
    delay(200);
    blink(attacker1);
    blink(defender1);
    
    attacker1Number = random(1,7);
    defender1Number = random(1,7);

    if(attacker1Number>defender1Number)
    {
      digitalWrite(attacker1,HIGH);
      digitalWrite(defender1,LOW);
    }
    else if(attacker1Number < defender1Number)
    {
      digitalWrite(defender1,HIGH);
      digitalWrite(attacker1,LOW);
    }
    else
    {
      digitalWrite(defender1,HIGH);
      digitalWrite(attacker1,LOW);
    }
  }
  //2 attackers, 1 defender
  else if(attackers ==2 && defenders ==1)
  {
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
    
    attacker1Number = random(1,7);
    attacker2Number = random(1,7);
    defender1Number = random(1,7);
    
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
    
    attacker1Number = random(1,7);
    attacker2Number = random(1,7);
    attacker3Number = random(1,7);
    defender1Number = random(1,7);
    
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
    
    attacker1Number = random(1,7);
    defender1Number = random(1,7);
    defender2Number = random(1,7);
    if(attacker1Number > defender1Number)
    {
      if(attacker1Number>defender2Number)
      {
        digitalWrite(attacker1,HIGH);
        digitalWrite(defender1,LOW);
        digitalWrite(defender2,HIGH);
      }
      else
      {
        digitalWrite(attacker1,LOW);
        digitalWrite(defender1,HIGH);
        digitalWrite(defender2,HIGH);
      }
    }
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
    
    attacker1Number = random(1,7);
    attacker2Number = random(1,7);
    defender1Number = random(1,7);
    defender2Number = random(1,7);
    
    sortDiceRolls(attacker1Number,defender1Number,attacker2Number,defender2Number,0);
    
    if(highAttackRoll>highDefenseRoll)
    {
      if(lowAttackRoll>lowDefenseRoll)
      {
        digitalWrite(attacker1,HIGH);
        digitalWrite(attacker2,HIGH);
        digitalWrite(defender1,LOW);
        digitalWrite(defender2,LOW);
      }
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
      if(lowAttackRoll>lowDefenseRoll)
      {
        digitalWrite(attacker1,LOW);
        digitalWrite(defender1,HIGH);
        digitalWrite(attacker2,HIGH);
        digitalWrite(defender2,LOW);
      }
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
    
    attacker1Number = random(1,7);
    attacker2Number = random(1,7);
    attacker3Number = random(1,7);
    defender1Number = random(1,7);
    defender2Number = random(1,7);
    
    sortDiceRolls(attacker1Number,defender1Number,attacker2Number,defender2Number,attacker3Number);
    
    if(highAttackRoll>highDefenseRoll)
    {
      if(lowAttackRoll>lowDefenseRoll)
      {
        digitalWrite(attacker1,HIGH);
        digitalWrite(attacker2,HIGH);
        digitalWrite(attacker3,HIGH);
        digitalWrite(defender1,LOW);
        digitalWrite(defender2,LOW);
      }
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
      if(lowAttackRoll>lowDefenseRoll)
      {
        digitalWrite(attacker1,LOW);
        digitalWrite(defender1,HIGH);
        digitalWrite(attacker2,HIGH);
        digitalWrite(defender2,LOW);
        digitalWrite(attacker3,HIGH);
      }
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
  else
  {
    //big if statements sort the attack rolls into highest and lowest dice
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


