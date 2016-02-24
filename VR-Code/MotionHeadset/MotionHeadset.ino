#include <Wire.h>
#include <L3G.h>
#include <LSM303.h>
#include <Servo.h>
int Ping1 = 10;
int Ping2 = 11;
int Ping3 = 12;
long duration1, duration2, duration3 ,inches_left, inches_right, inches_up, cm_left, cm_right, cm_up;
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
	
	// void Octagon()
	// {
	// 	ReadPings();


	// 	if(inches_left <= 5)
	// 	{
	// 		Keyboard.write('a');
	// 		while(inches_left <= 5)
	// 		{
	// 			ReadPings();
	// 		}

	// 	}

	// 	if(inches_right <= 5)
	// 	{
	// 		Keyboard.write('d');
	// 		while(inches_right <= 5)
	// 		{
	// 			ReadPings();
	// 		}
	// 	}

	// 	if(inches_up <= 2)
	// 	{
	// 		Keyboard.write('w');
	// 		while(inches_up <= 2)
	// 		{
	// 			ReadPings();
	// 		}
	// 	}
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

	// void ReadPings()
	// {
	// 	pinMode(Ping1, OUTPUT);
	// 	digitalWrite(Ping1, LOW);
	// 	delayMicroseconds(2);
	// 	digitalWrite(Ping1, HIGH);
	// 	delayMicroseconds(5);
	// 	digitalWrite(Ping1, LOW);
	// 	pinMode(Ping1, INPUT);
	// 	duration1 = pulseIn(Ping1, HIGH);
	// 	inches_left = microsecondsToInches(duration1);
	// 	cm_left = microsecondsToCentimeters(duration1);

	// 	delay(10);

	// 	pinMode(Ping2, OUTPUT);
	// 	digitalWrite(Ping2, LOW);
	// 	delayMicroseconds(2);
	// 	digitalWrite(Ping2, HIGH);
	// 	delayMicroseconds(5);
	// 	digitalWrite(Ping2, LOW);
	// 	pinMode(Ping2, INPUT);
	// 	duration2 = pulseIn(Ping2, HIGH);
	// 	inches_right = microsecondsToInches(duration2);
	// 	cm_right = microsecondsToCentimeters(duration2);

	// 	delay(10);

	// 	pinMode(Ping3, OUTPUT);
	// 	digitalWrite(Ping3, LOW);
	// 	delayMicroseconds(2);
	// 	digitalWrite(Ping3, HIGH);
	// 	delayMicroseconds(5);
	// 	digitalWrite(Ping3, LOW);
	// 	pinMode(Ping3, INPUT);
	// 	duration3 = pulseIn(Ping3, HIGH);
	// 	inches_up = microsecondsToInches(duration3);
	// 	cm_up = microsecondsToCentimeters(duration3);

	// 	delay(10);


	// }
	// long microsecondsToInches(long microseconds)
	// {
	// 	return microseconds / 74 / 2;
	// }

	// long microsecondsToCentimeters(long microseconds)
	// {
	// 	return microseconds / 29 / 2;
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

