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
void rotateRight()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
}
void rotateLeft()
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
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}
void SpeakerAction()
{
  digitalWrite(Speaker, HIGH);

}

void Executed(char msg)
{
  Serial.write("In \n");
  Serial.write(msg);                     // in ký tự ra màn hình

  if (msg == '1')
  {
    moveLeft();
  }
  else if (msg == '2')
  {
    moveRight();
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
  else if (msg = '6')
  {
    Auto();
  }

}
void Auto()
{
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
      if(msg[0]=='7')
      {
        Serial.println("quit");
              break;
      }

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
void loop()
{
  if (vw_get_message(msg, &msgLen))            // nếu có tín hiệu được truyền đến
  {
    Serial.print("got: ");
    Serial.write(msg[0]);
    char signal = msg[0];
    Executed(signal);

  }



}
