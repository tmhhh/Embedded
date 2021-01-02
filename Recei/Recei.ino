#include <VirtualWire.h>

int Speaker = 9;
int Sensors1 = 13;
int Sensors2 = 11;
int Sensors3 = 7;
byte msg[VW_MAX_MESSAGE_LEN];
byte msgLen = VW_MAX_MESSAGE_LEN;

void setup()
{
  Serial.begin(9600);
  Serial.println("READY..........");
  vw_setup(1024);                             // cài đặt tốc độ truyền tín hiệu
  vw_set_rx_pin(8);                           // cài đặt chân digital để nhận tín hiệu
  vw_rx_start();                              // bắt đầu nhận tín hiệu

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(Speaker, OUTPUT);

}
void rotateLeft()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
}
void rotateRight()
{
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
}
void moveForward()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
}
void moveDown()
{
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
}
void moveLeft()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}
void moveRight()
{
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
}
void Stop()
{
  digitalWrite(9, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}
void SpeakerAction()
{
  digitalWrite(Speaker, HIGH);

}
void Auto()
{
  bool A = false;
  while (true)
  {
    int ScanForward = digitalRead(Sensors1);
    int ScanLeft = digitalRead(Sensors2);
    int ScanRight = digitalRead(Sensors3);


    int rd;
    while (ScanForward == 0 && ScanLeft == 0 && ScanRight == 0)
    {
      moveForward();
      Serial.println("move forward");
      ScanForward = digitalRead(Sensors1);
      ScanLeft = digitalRead(Sensors2);
      ScanRight = digitalRead(Sensors3);


      if (vw_get_message(msg, &msgLen))
      {
        if (msg[0] == '7')
        {
          Serial.println("got:7");
          Serial.println("quit");
          Stop();
          A = true;
          break;
        }
      }
    }
    if (A)
    {
      Stop();
      break;
    }
  
  rd = random(0, 2);
  if (rd == 0)
  {
    moveDown();
    delay(500);

    Serial.println("rotateLeft");
    rotateLeft();
    delay(500);

    Stop();
  }
  else
  {
    Serial.println("rotateRight");
    moveDown();
    delay(500);
    rotateRight();
    delay(500);
    Stop();


  }

}

}
void Executed(char msg)
{
  Serial.print("got: ");
    Serial.println(msg);

  if (msg == '1')
  {
    rotateLeft();
  }
  else if (msg == '2')
  {
    rotateRight();
  }
  else if (msg == '3')
  {
    moveForward();
  }
  else if (msg == '4')
  {
    moveDown();
  }
  else if (msg == '5')
  {
    SpeakerAction();
  }
  else if (msg == '6')
  {
    Auto();
  }
  else if(msg=='0')
  {
  Stop();   
  }
//  delay(1000);  
 
}

void loop()
{
  if (vw_get_message(msg, &msgLen))            // nếu có tín hiệu được truyền đến
  {
   char signal = msg[0];
//   Serial.println(signal);
//  signal=msg[1];
//   Serial.println(signal);
    Executed(signal);
delay(100);
  }
  


}
