

#include <VirtualWire.h>
#include <UTFT.h>
#include <URTouch.h>

UTFT    myGLCD(ILI9341_16, 38, 39, 40, 41);
URTouch  myTouch( 6, 5, 4, 3, 2);
#include <SoftwareSerial.h>
SoftwareSerial espSerial =  SoftwareSerial(0, 1);



//#include <DHT.h>d

#define DHTPIN 2
//#define DHTTYPE DHT11
//DHT dht(DHTPIN, DHTTYPE);
#define rows 6


extern uint8_t BigFont[];

int color = 0;
word colorlist[] = {VGA_WHITE, VGA_BLACK, VGA_RED, VGA_BLUE, VGA_GREEN, VGA_FUCHSIA, VGA_YELLOW, VGA_AQUA};
int  bsize = 4;

void send(char signal[])
{
  vw_send((byte *)signal, sizeof(signal));// gửi tín hiệu đi
  vw_wait_tx();
}
void Clear()
{

  myGLCD.setColor(colorlist[1]);
  myGLCD.fillRect(221, 121, 259, 159);
  myGLCD.fillRect(199, 121, 161, 159);
  myGLCD.fillRect(79, 119, 41, 81);
  myGLCD.fillRect(41, 141, 79, 179);
  //         myGLCD.fillRect(200,0,310,110);
  myGLCD.fillRect(260, 200, 300, 240);

  //speaker
  myGLCD.fillRect(221, 21, 259, 59 );
  myGLCD.drawLine(290, 20, 310, 10);
  myGLCD.drawLine(290, 40, 310, 40);
  myGLCD.drawLine(290, 60, 310, 70);
}

void carSetup() {
  //right
  myGLCD.drawLine(220, 120, 260, 120);
  myGLCD.drawLine(260, 120, 260, 100);
  myGLCD.drawLine(260, 100, 320, 140);
  myGLCD.drawLine(320, 140, 260, 180);
  myGLCD.drawLine(260, 180, 260, 160);
  myGLCD.drawLine(260, 160, 220, 160);
  myGLCD.drawLine(220, 160, 220, 120);

  //  left
  myGLCD.drawLine(200, 120, 160, 120);
  myGLCD.drawLine(160, 120, 160, 100);
  myGLCD.drawLine(160, 100, 100, 140);
  myGLCD.drawLine(100, 140, 160, 180);
  myGLCD.drawLine(160, 180, 160, 160);
  myGLCD.drawLine(160, 160, 200, 160);
  myGLCD.drawLine(200, 160, 200, 120);

  //up

  myGLCD.drawLine(60, 20, 20, 80);
  myGLCD.drawLine(20, 80, 40, 80);
  myGLCD.drawLine(40, 80, 40, 120);
  myGLCD.drawLine(40, 120, 80, 120);
  myGLCD.drawLine(80, 120, 80, 80);
  myGLCD.drawLine(80, 80, 100, 80);
  myGLCD.drawLine(100, 80, 60, 20);
  //down
  myGLCD.drawLine(60, 240, 20, 180);
  myGLCD.drawLine(20, 180, 40, 180);
  myGLCD.drawLine(40, 180, 40, 140);
  myGLCD.drawLine(40, 140, 80, 140);
  myGLCD.drawLine(80, 140, 80, 180);
  myGLCD.drawLine(80, 180, 100, 180);
  myGLCD.drawLine(100, 180, 60, 240);


  ///speaker
  myGLCD.drawLine(220, 20, 220, 60);
  myGLCD.drawLine(220, 60, 260, 60);
  myGLCD.drawLine(260, 60, 280, 80);
  myGLCD.drawLine(280, 80, 280, 00);
  myGLCD.drawLine(220, 20, 260, 20);
  myGLCD.drawLine(260, 20, 280, 00);

  //
  myGLCD.setColor(colorlist[2]);
  myGLCD.print("X", 0, 0);
}

void carController() {
  long x, y;
  char signal[20] = "";

  while (myTouch.dataAvailable() == true || true )
  {
    myTouch.read();
    x = myTouch.getX();
    y = myTouch.getY();
    if ((x != -1) and (y != -1))
    {
      if ( x >= 220 && x <= 320)
      {
        if (y >= 100 && y <= 180)
        {
          myGLCD.setColor(colorlist[2]);
          myGLCD.fillRect(221, 121, 259, 159);

          //          myGLCD.fillTriangle(260,100,320, 140, 260, 180,colorlist[2]);

          signal[0] = '1';
          send(signal);

        }
        else if (y >= 0 && y <= 60)
        {
          //  myGLCD.setColor(colorlist[2]);
          // un        myGLCD.fillRect(260,200,300,240);
          //  myGLCD.drawLine(285,10,310,15);
          //  myGLCD.drawLine(285,25,310,25);
          //  myGLCD.drawLine(285,400,310,35);
          signal[0] = '5';
          send(signal);
        }
      }
      else if (x >= 120 && x <= 200)
      {
        if (y >= 100 && y <= 180)
        {
          myGLCD.setColor(colorlist[2]);
          myGLCD.fillRect(199, 121, 161, 159);
          signal[0] = '2';
          send(signal);
        }
      }
      else if (x >= 20 && x <= 120)
      {
        if (y >= 50 && y <= 130)
        {
          myGLCD.setColor(colorlist[2]);
          myGLCD.fillRect(79, 119, 41, 81);
          signal[0] = '3';
          send(signal);
          //     myGLCD.print("Warning",200,20);

        }
        else if (y >= 140 && y <= 240)
        {
          myGLCD.setColor(colorlist[2]);
          myGLCD.fillRect(41, 141, 79, 179);
          signal[0] = '4';
          send(signal);
        }

      }
      if ( x >= 220 && x <= 280 && y >= 20 && y <= 60) {
        myGLCD.setColor(colorlist[2]);
        myGLCD.fillRect(221, 21, 259, 59 );
        myGLCD.drawLine(290, 20, 310, 10);
        myGLCD.drawLine(290, 40, 310, 40);
        myGLCD.drawLine(290, 60, 310, 70);
        signal[0] = '5';
        send(signal);


      }
      else if (x >= 0 && x <= 10 && y >= 0 && y <= 20)
      {
        myGLCD.clrScr();
        break;
      }
      Serial.print("sent: ");
      Serial.println(signal);
      signal[0] = '0';
      send(signal);
      delay(100);

      Clear();
    }
  }
}
void autoScreen()
{
  myGLCD.setColor(colorlist[2]);
  myGLCD.print("x", 0, 0);
  myGLCD.setColor(colorlist[0]);
  myGLCD.print("Performing", 70, 120);
  while (true)
  {

    myTouch.read();
    long x = myTouch.getX();
    long y = myTouch.getY();
    if (x >= 0 && x <= 10 && y >= 0 && y <= 20)
    {
      myGLCD.clrScr();
      break;
    }
  }


}
void drawScreen()
{
  float width = 320 / rows;
  float height = 240 / rows;
  for (int i = 1; i < rows; i++)
  {
    myGLCD.setColor(colorlist[3]);
    myGLCD.drawLine(5, height * i, 315, height * i);
    myGLCD.drawLine(width * i, 0, width * i, 240);
  }
  myGLCD.setColor(colorlist[2]);
  myGLCD.print("x", 0, 0);
  while (myTouch.dataAvailable() == true || true)
  {
    myTouch.read();
    long x = myTouch.getX();
    long y = myTouch.getY();
    Serial.print("BeginX: ");
    Serial.println(x);
    Serial.print("BeginY: ");
    Serial.println(y);
    if (x != -1 && y != -1)
    {
      if (x >= 0 && x <= 10 && y >= 0 && y <= 20)
      {
        myGLCD.clrScr();
        send('7');
        Serial.println("send: 7");
        break;
      }

      myGLCD.setColor(colorlist[4]);
      myGLCD.fillCircle(x, y, 2);
      long firstX = x;
      long firstY = y;
      long secondX = -1;
      long secondY = -1;
      delay(1000);
      secondX = myTouch.getX();
      secondY = myTouch.getY();

      if(secondX!=-1 && secondY!=-1)
      {
        Serial.print("FirstX: ");
      Serial.println(firstX);
      Serial.print("FirstY: ");
      Serial.println(firstY);
      Serial.print("secondX: ");
      Serial.println(secondX);
      Serial.print("secondY: ");
      Serial.println(secondY);
      myGLCD.fillCircle(secondX, secondY, 2);
      myGLCD.drawLine(firstX, firstY, secondX, secondY);
      delay(3000);
      }
      
    }



  }
}
void homeScreen()
{

  while (myTouch.dataAvailable() == true || true )
  {
    myGLCD.setColor(colorlist[0]);
    myGLCD.print("Tu chay", 70, 20);
    myGLCD.print("Dieu khien", 70, 70);
    myGLCD.print("Chay theo net ve", 40, 120);
    long x, y;
    myTouch.read();
    x = myTouch.getX();
    y = myTouch.getY();
    if (x >= 70 && y >= 70 && y <= 110)
    {
      Serial.print("vo");
      myGLCD.clrScr();
      carSetup();
      carController();

    }
    else if (x >= 70 && y >= 20 && y <= 60)
    {
      myGLCD.clrScr();
      autoScreen();
    }
    else if ( x >= 40 && y >= 120 && y <= 150)
    {
      myGLCD.clrScr();
      drawScreen();
    }
  }
}

void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_HI);

  Serial.begin(9600);
  Serial.println("Ready.........");
  vw_set_ptt_inverted(true);
  vw_setup(1024);
  vw_set_tx_pin(8);

}
void loop()
{
  homeScreen();


}
