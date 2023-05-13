We use two Audrinos.

one for the Linefollower and Winch (ROCKRadioLineFollowerEncoder)
and the other for the robotic arm. (ROCK_DOD_Challenge)


ROBOTIC ARM:
For the arm you have to use the "LAFVIN_Robot_arm_9_4_15.apk" as an app on an Android Phone. (apple is not compatible.)
you then use the "Lesson_8_Bluetooth_Controlling_Arm" code. For further opertational instruction seek LAFVIN's Lesson 8 tutorial.

Looking at the top of the robot (winch side towards you) the servos go into these spots on the audrino

left bottom servo = 5
right bottom servo = 3
servo connecting to the claw = 6**
servo that controls the claw = 9

**(Up and down controls are reversed.)


LINE FOLLOWER:
To use the Linefollower the code is "ROCKRadioLineFollowEncoder.ino"
Then, to turn on the robot's line follower, flip the left long switch all the way up on the Controller. Then flip the left small switch after alining the sensors on the robot (which is on the bottom front end of the robot) to the black line. It should follow the line.

(The Line Following Code is also a part of the Winch Code.)


WINCH:
Flip the left long switch to the middle and then flip the left small switch to activate the winch. use the left Joystick to controll the up and down motion of the winch. Left makes it go Up and Right makes it go Down.

There are indicators on the robot that changes color based on what mode you are in.

Green = Radio (the robot is in drive mode)

Orange + Winch (the robot is in Winch mode)

Red = Line Follower (the robot is in line following mode)


FINAL BUILD - CAD:
 - ARM:
	- Primary:
		- Base Piece
		- Claw Attachment
		- Claw Part
		- End Piece
		- Main Section
	- Spacers:
		- Axle Spacer
		- Base Spacer
		- Claw Mount Spacer
 - MISC.:
	- MindsEye Bracket
	- Servo Mount Bracketconnects
There are five PRIMARY components to the arm (and their affiliated spacers). The "Base Piece" connects via four pins to the main base of the robot, which supports the rest of the arm. The "End Piece" is the first
free-rotating section of the arm (features the RoCK logo), supported by two servos. The "Main Section" features 15 hexagonal holes, allowing for a convenient way to fasten zip-ties to secure rogue wires. The "Main Section"
also attaches itself to the "End Piece", increasing the length of the arm. The "Claw Attachment" is the next free-rotating section of the arm, supported by one servo on the "Main Section". With this component, two "Claw Part" 
units move symmetrically with one servo on the "Claw Attachment".