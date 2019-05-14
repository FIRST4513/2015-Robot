// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 * @author ExampleAuthor
 */
class Drivetrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	float dThrottleAxis, dThrottle;
	float xAxis, xSpeed, yAxis, ySpeed;
	float twistAxis,twistSpeed;
	float topxSpeed, topySpeed;
	int   topPov;
	float deadband = 0.1;
	float gyroLastHdg, gyroHdg, gyroDrift, origCorrection, correction;
	int straightFirstTimeFlag;

	// ******* Constants  **********

	float kDeadband = 0.1;
	float kTwistDeadband = 0.05;

	float kTwistConstant = 2.5;	// This cuts in half the joystick twist rate.. It was toooo fast

	// These gyro correction values may need to be tweaked based on floor type, Speed, Direction ???
	float kGyroCorrectionConstant = 0.018;		// 0.018 seemd good maybe lower than idel??
	float kGyroCorrectionLwrLimit = -0.070;		// -0.035 wasnt experienced at 0.005 correction
	float kGyroCorrectionUpperLimit = 0.070;

	float kTopPovFwdRvsConstant = 3;			// Axis * throttle / 3 seemed a good speed
	float kTopPovLftRtConstant = 2;			// Axis * throttle / 3 was too slow 1.5 seemed too fast
	float kTopPovDiagConstant = 3;				// Axis * throttle / 2 ????
	// drivetrain encoders distance per pulse = 0.017462 (average over 10 ft.)
	float kEncoderConvFwd = 0.017462;			// Distance per pulse
	float kEncoderConvHorizontal = 0.014361;	// Distance per pulse

	void InitVariables();

public:

	bool kLmtSwPressed = true;
	bool kLmtSwNotPressed = false;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SpeedController* lFSpeedCtrlr;
	SpeedController* fRSpeedCtrlr;
	SpeedController* rLSpeedCtrlr;
	SpeedController* rRSpeedCtrlr;
	RobotDrive* robotDrive;
	Encoder* lFQuadratureEncoder;
	Encoder* rFQuadratureEncoder;
	Gyro* gyro;
	DigitalInput* contactLmtSw;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS


	Drivetrain();

	void InitDefaultCommand();

	void Drive(Joystick* joy);					// joystick to drive Mecanum Cartesian style.
	void DriveStraight(float dir, float speed);	// dir 0=left, 1=right, 2=forward, 3=reverse
	void TankDrive(double left, double right);		// Tank Drive (no twist)
	void Stop();								// Stop the Motors

	double GetHeading();						// return The robots heading in degrees.
	void SetFirstTimeFlag(int val);				// Set or clear the first time flag for gyro correction

	void ResetEncoders();						// Reset the robots sensors to the zero states.
	void ResetGyro();							// Reset Gyro to zero state

	double GetDistance();						// return The distance driven (average of lf and rt encoders).
	double GetHorizontalDistance();				// return the distance driven horizontally (average lf & rt)
	double GetLeftEncoder();					// return raw encoder value
	double GetRightEncoder();					// return raw encoder value

	void GetAxisValues(Joystick* joy);			// Calculate speed values from joystck position

	bool GetContact();							// Return if front ctr contact limit switch tripped

	void Log(Joystick* joy);					// log method puts interesting information to the SmartDashboard.
	void CalculateCorrection();					// Print gyroscope values

};

#endif
