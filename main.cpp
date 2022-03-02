
#include <FEHLCD.h>
#include <FEHServo.h>
#include <FEHMotor.h>
#include <FEHUtility.h>
#include <FEHIO.h>

FEHServo servo(FEHServo::Servo7);

// servo Min: 500. max: 2451


//Declare 2 igwan motors to motor ports
FEHMotor left_motor(FEHMotor::Motor0,9.0);  
FEHMotor right_motor(FEHMotor::Motor1,9.0);  
DigitalEncoder right_encoder(FEHIO::P1_0);
DigitalEncoder left_encoder(FEHIO::P1_1);

//Function that calculates average voltage value of CDS cell 0-3.3 V
float lightValue()
{
    //Declare input to cds cell
    AnalogInputPin cds(FEHIO::P2_0);
    int i = 0;
    float sum = 0;
    float a = 0;
    float average = 0;
    //Loop runs through 10 times to measure cds cell output
    while(i < 10)
    {
        //Find value and add it to running sum
        a = cds.Value();
        sum = sum + a;
        i++;

        //Sleep 10 ms
        Sleep(10);
    }

    //calculate average value and return said value
    average = sum/10;
    return average;

}

void forward()
{
   left_motor.SetPercent(-25);
   right_motor.SetPercent(25);
}

void turnLeft()
{ 
   left_motor.SetPercent(0);
   right_motor.SetPercent(25);
}

void turnRight()
{
   left_motor.SetPercent(-25);
   right_motor.SetPercent(0);
}

void move_forward(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    right_motor.SetPercent(percent);
    left_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void move_forward_ramp(int percent1, int percent2, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    right_motor.SetPercent(percent1);
    left_motor.SetPercent(-percent2);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void move_backward(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    right_motor.SetPercent(-percent);
    left_motor.SetPercent(percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void move_backward_ramp(int percent1, int percent2, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    right_motor.SetPercent(-percent1);
    left_motor.SetPercent(percent2);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void turn_left(int percent, int counts)
{
     //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    right_motor.SetPercent(percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while(right_encoder.Counts() < counts);

    //Turn off motors
    right_motor.Stop();
}

void turn_right(int percent, int counts)
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while(left_encoder.Counts() < counts);

    //Turn off motors
    left_motor.Stop();
}

void reverse_after_red(int percent)
{
     //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(percent);
    right_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts())/2 < 200);

    //Turn off motors
    left_motor.Stop();
    right_motor.Stop();

    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while(left_encoder.Counts() < 300);

    //Turn off motors
    left_motor.Stop();
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(percent);
    right_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts())/2 < 200);

    //Turn off motors
    left_motor.Stop();
    right_motor.Stop();

    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while(left_encoder.Counts() < 185);

    //Turn off motors
    left_motor.Stop();

}
void reverse_after_blue(int percent)
{
     //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(percent);
    right_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts())/2 < 200);

    //Turn off motors
    left_motor.Stop();
    right_motor.Stop();

    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while(left_encoder.Counts() < 300);

    //Turn off motors
    left_motor.Stop();
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(percent);
    right_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts())/2 < 200);

    //Turn off motors
    left_motor.Stop();
    right_motor.Stop();

    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(-percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while(left_encoder.Counts() < 180);

    //Turn off motors
    left_motor.Stop();
}


int main(void)
{
    /*
    float a;
    while (true)
    {
        a = lightValue();
        LCD.WriteLine(a);        
    }
    */

    /* conversion between inches traveled and number of transitions for shaft encoder:

    n = (inches*318)/(2*pi*r)

    (put the "n" value into the code)

    */

    move_forward(25,850);
    Sleep(0.5);
    turn_left(25,723);
    Sleep(0.5);
    move_backward(25,132);
    Sleep(0.5);

    float a = lightValue();
    LCD.WriteLine(a);
    move_forward(25,240);
    Sleep(0.5);

    if (a >= .150 && a <= .350)
    {
        turn_left(25,35);
        LCD.WriteLine("Red");
        Sleep(0.5);
        move_forward(35,55);
        reverse_after_red(25);
    }

    else if (a >= .380 && a <= .860)
    {
        turn_right(25,35);
        LCD.WriteLine("Blue");
        Sleep(0.5);
        move_forward(35,55);
        reverse_after_blue(25);
    }

    move_backward(25,500);
    turn_right(25,485);
    move_forward_ramp(40,45,1134);
    move_backward_ramp(20,22,1134);
}
