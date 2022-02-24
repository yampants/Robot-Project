#include <FEHLCD.h>
#include <FEHServo.h>
#include <FEHMotor.h>
#include <FEHUtility.h>
#include <FEHIO.h>
//Declare 2 igwan motors to motor ports
FEHMotor left_motor(FEHMotor::Motor0,9.0);  
FEHMotor right_motor(FEHMotor::Motor1,9.0);  
DigitalEncoder right_encoder(FEHIO::P1_0);
DigitalEncoder left_encoder(FEHIO::P1_1);
int main(void)
{
move_forward(25,405);
turn_left(25,);
}

//Function that calculates average voltage value of CDS cell 0-3.3 V
int lightValue(){
    //Declare input to cds cell
AnalogInputPin cds(FEHIO::P0_0);
int i=0;
float sum=0;
float a=0;
float average=0;
//Loop runs through 10 times to measure cds cell output
while(i<10){
    //Find value and add it to running sum
     a= cds.Value();
     sum=sum+a;
     i++;
     //Sleep 10 ms
     Sleep(10);
  


}
//calculate average value and return said value

average=sum/10;
return average;

}

void forward(){ 
    
   left_motor.SetPercent(25);
   right_motor.SetPercent(25);


}
void turnLeft(){ 
    
   left_motor.SetPercent(0);
   right_motor.SetPercent(25);


}
void turnRight(){ 
    
   left_motor.SetPercent(25);
   right_motor.SetPercent(0);


}
void move_forward(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    right_motor.SetPercent(percent);
    left_motor.SetPercent(percent);

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
    left_motor.SetPercent(percent);
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while(left_encoder.Counts() < counts);

    //Turn off motors
    left_motor.Stop();

}
