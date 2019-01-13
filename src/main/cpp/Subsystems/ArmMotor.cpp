/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/ArmMotor.h"

ArmMotor::ArmMotor() : Subsystem("ExampleSubsystem") {}

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	TalonSRX* armMotor;
	//Encoder* armEncoder;
	double maxPosition;
	double minPosition;
	DigitalInput* lowLimit;
	Counter* counter;
public:
	Arm();
	void InitDefaultCommand();
	void move(double power);
	void reset();
	double getPosition();
	double getSpeed();
	double Limit(double num, double max);
	Encoder* getEncoder();
	TalonSRX* getArmMotor();
	double getMin();
	double getMax();

	bool IsSwitchSet();
	void InitializeCounter();

void ArmMotor::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
