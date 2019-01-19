/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/ArmMotor.h"

ArmMotor::ArmMotor() : Subsystem("ArmMotor"), armMotor(new TalonSRX(5)), minPosition(-84),
maxPosition(minPosition + 370)
{
	//armEncoder->Reset();
	armMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::Analog, 0, 10);
		// left->ConfigEncoderCodesPerRev(360);
	armMotor->SetSelectedSensorPosition(0,0,10);

	lowLimit = new DigitalInput(1);
	counter = new Counter(lowLimit);

	armMotor->SetInverted(false);


}

void ArmMotor::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ArmMotor::move(double power) {
	armMotor->Set(ControlMode::PercentOutput, ArmMotor::Limit(power, 1));
	//armMotor->
	//ControlMode test = armMotor->GetControlMode();


	//if(test == ControlMode::Disabled)
		//armMotor->SetInverted(true);
}

void ArmMotor::reset()
{
	armMotor->SetSelectedSensorPosition(0, 0, 10);
	minPosition = getPosition();
	maxPosition = minPosition + 370;
}

double ArmMotor::getPosition() {
	return armMotor->GetSelectedSensorPosition(0);
}

double ArmMotor::getSpeed() {
	return armMotor->GetSelectedSensorVelocity(0);
}

//Encoder* Arm::getEncoder() {
	//return armEncoder;
//}

TalonSRX* ArmMotor::getArmMotor() {
	return armMotor;
}

double ArmMotor::Limit(double num, double max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}

double ArmMotor::getMin()
{
	return minPosition;
}

double ArmMotor::getMax()
{
	return maxPosition;
}


bool ArmMotor::IsSwitchSet()
{
     return counter->Get() > 0;
}

void ArmMotor::InitializeCounter()
{
     counter->Reset();
}