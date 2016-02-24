#include <Wire.h>
#include <L3G.h>
#include <LSM303.h>
#include <Servo.h>
double centery= 103;
double centerx= 90;
double r;
Servo xServ;
Servo yServ;
int difference;
int last_difference;
double kp6 = .0001;
LSM303 compass;
L3G gyro;
double ykp = .0018;
double xkp = -.0015;
double xkp2 = -.0005;
double xkps = .00003;
double ykps = .00001;
double kp3 = .000002;
int i;
long  X_DIR;
long  Y_DIR;
double Y_READ;
double X_READ;
void setup() {
	Serial.begin(9600);
	xServ.attach(12);
	yServ.attach(11);
	Wire.begin();
	Keyboard.begin();
	Mouse.begin();
	compass.init();
	compass.enableDefault();
	if (!gyro.init())
	{
		Serial.println("Failed to autodetect gyro type!");
		while (1);
	}
	compass.m_min = (LSM303::vector<int16_t>){ -32767, -32767, -32767 };
	compass.m_max = (LSM303::vector<int16_t>){ +32767, +32767, +32767 };

	gyro.enableDefault();
	compass.read();
	analogWrite(11, 0);
}

void loop() 
{
	FPS();
}

void FPS()
{
	
	gyro.read();
	compass.readAcc();
	 Serial.println(gyro.g.x);
	 while(i <= 50)
	 {
	 	X_READ = (int)gyro.g.z;
	 	X_DIR = X_DIR+X_READ;
	 	i++;
	 }
	 X_DIR = X_DIR/i;
	 i = 0;
	 while(i <= 50)
	 {
	 	Y_READ = (int)gyro.g.y;
	 	Y_DIR = Y_DIR+Y_READ;
	 	i++;
	 }
	 Y_DIR= Y_DIR/i;
	 i = 0;
	 Mouse.move(0, (((Y_DIR*ykp) - 2.32)+X_DIR*kp3), 0);
	 Mouse.move((X_DIR * xkp), 0, 0);
	 X_DIR = 0;
	 Y_DIR = 0;
	}

	// void Flight()
	// {
	// 	gyro.read();
	// 	compass.read();
	// 	float heading = compass.heading();
	// 	Mouse.move(0, (((int)gyro.g.z * -ykp)), 0);
	// 	Mouse.move(((((int)gyro.g.y * xkp2) + 1.23)), 0, 0);
	// }
	

	// void PinBall()
	// {
	// 	ReadPings();
	// 	if(inches_left <= 2)
	// 	{
	// 		while(inches_left <= 2)
	// 		{

	// 			Keyboard.press('a');
	// 			ReadPings();
	// 		}
	// 		Keyboard.releaseAll();

	// 	}
	// 	if(inches_right <= 2)
	// 	{
	// 		while( inches_right <= 2)
	// 		{
	// 			Keyboard.press('d');
	// 			ReadPings();
	// 		}	
	// 		Keyboard.releaseAll();

	// 	}
	// }

	// void BrickBrake()
	// {
	// 	ReadPings();
	// 	difference = cm_left - last_difference;
	// 	Mouse.move((difference*kp6),0,0);
	// 	Serial.println(difference);
	// 	last_difference = difference;
	// }

	
	void Debug()
	{
		gyro.read();
		compass.readAcc();
		Serial.print("X: ");
		Serial.print(compass.a.x);
		Serial.print(" Y: ");
		Serial.print(compass.a.y);
		Serial.print(" Z: ");
		Serial.println(compass.a.z);
	}

