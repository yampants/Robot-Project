
#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHAccel.h>
#include <FEHBattery.h>
#include <FEHBuzzer.h>
#include <FEHRPS.h>
#include <FEHSD.h>
#include <string.h>
#include <stdio.h>

#define LEFTFORWARD -25
#define LEFTBACKWARD 25
#define RIGHTFORWARD 25
#define RIGHTBACKWARD -25

FEHMotor LeftIGWAN(FEHMotor::Motor1, 9);
FEHMotor RightIGWAN(FEHMotor::Motor0, 9);

AnalogInputPin cds(FEHIO::P2_0);

void forward();

void backward();

void left();

void right();

void stop();

void forward()
{
    LeftIGWAN.SetPercent(LEFTFORWARD);
    RightIGWAN.SetPercent(RIGHTFORWARD);
}

void backward()
{
    LeftIGWAN.SetPercent(LEFTBACKWARD);
    RightIGWAN.SetPercent(RIGHTBACKWARD);
}

void right()
{
    LeftIGWAN.SetPercent(LEFTBACKWARD);
    RightIGWAN.SetPercent(RIGHTFORWARD);
}

void left()
{
    LeftIGWAN.SetPercent(LEFTFORWARD);
    RightIGWAN.SetPercent(RIGHTBACKWARD);
}

void stop()
{
    LeftIGWAN.Stop();
    RightIGWAN.Stop();
}

int main(void)
{
    //move forward from welcome mat
    
    forward();

    //stop at turning point

    // **** Shaft Encoder Code ***

    stop();

    Sleep(1.0);

    //turn to face jukebox

    right();

    //stop when facing juke box

    // **** Shaft Encoder Code ***

    stop();

    //move to light

    forward();

    //stop on light

    // **** Shaft Encoder Code ***

    stop();

    //read, interpret, and turn right/left depending on light

    if (cds.Value < )
    {

    }
    else if(cds.Value > )
    {

    }
    else
    {

    }



}
