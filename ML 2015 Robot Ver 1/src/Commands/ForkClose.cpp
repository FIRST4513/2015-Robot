// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ForkClose.h"
#include "../Robot.h"

ForkClose::ForkClose() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::fork);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void ForkClose::Initialize() {
	SetTimeout(4);				// If does not reach destination in time then stop
}

// Called repeatedly when this Command is scheduled to run
void ForkClose::Execute() {
	Robot::fork->close();		// Start Motor Moving in
}

// Make this return true when this Command no longer needs to run execute()
bool ForkClose::IsFinished() {
//  ------- orig working code ---------------
//	if 	(IsTimedOut() ||
//		(Robot::fork->getInsideLmtSw() == Robot::fork->kLmtSwPressed) ||
//		(Robot::fork->getcontactLRLmtSw() == Robot::fork->kLmtSwPressed))
//			return true;	// We hit the end done
//	else
//		return false;
	if 	(IsTimedOut())
		return true;

	if 	((Robot::fork->getInsideLmtSw() == Robot::fork->kLmtSwPressed) ||
		(Robot::fork->getContactLeftLmtSw() == Robot::fork->kLmtSwPressed) ||
		(Robot::fork->getContactRightLmtSw()  == Robot::fork->kLmtSwPressed))
			return true;	// We hit the end done
	else
		return false;
}

// Called once after isFinished returns true
void ForkClose::End() {
	Robot::fork->stop();		// Stop the Motor now !
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkClose::Interrupted() {
	End();
}
