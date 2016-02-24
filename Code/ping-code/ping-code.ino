int Ping1 = 10;
int Ping2 = 11;
int Ping3 = 12;
long duration1, duration2, duration3 ,inches_left, inches_right, inches_up, cm_left, cm_right, cm_up;

void Setup()
{

}

void Loop()
{
	Octagon();
}

void Octagon()
	{
		ReadPings();


		if(inches_left <= 5)
		{
			Keyboard.write('a');
			while(inches_left <= 5)
			{
				ReadPings();
			}

		}

		if(inches_right <= 5)
		{
			Keyboard.write('d');
			while(inches_right <= 5)
			{
				ReadPings();
			}
		}

		if(inches_up <= 2)
		{
			Keyboard.write('w');
			while(inches_up <= 2)
			{
				ReadPings();
			}
		}
	}

	void ReadPings()
	{
		pinMode(Ping1, OUTPUT);
		digitalWrite(Ping1, LOW);
		delayMicroseconds(2);
		digitalWrite(Ping1, HIGH);
		delayMicroseconds(5);
		digitalWrite(Ping1, LOW);
		pinMode(Ping1, INPUT);
		duration1 = pulseIn(Ping1, HIGH);
		inches_left = microsecondsToInches(duration1);
		cm_left = microsecondsToCentimeters(duration1);

		delay(10);

		pinMode(Ping2, OUTPUT);
		digitalWrite(Ping2, LOW);
		delayMicroseconds(2);
		digitalWrite(Ping2, HIGH);
		delayMicroseconds(5);
		digitalWrite(Ping2, LOW);
		pinMode(Ping2, INPUT);
		duration2 = pulseIn(Ping2, HIGH);
		inches_right = microsecondsToInches(duration2);
		cm_right = microsecondsToCentimeters(duration2);

		delay(10);

		pinMode(Ping3, OUTPUT);
		digitalWrite(Ping3, LOW);
		delayMicroseconds(2);
		digitalWrite(Ping3, HIGH);
		delayMicroseconds(5);
		digitalWrite(Ping3, LOW);
		pinMode(Ping3, INPUT);
		duration3 = pulseIn(Ping3, HIGH);
		inches_up = microsecondsToInches(duration3);
		cm_up = microsecondsToCentimeters(duration3);

		delay(10);


	}
	long microsecondsToInches(long microseconds)
	{
		return microseconds / 74 / 2;
	}

	long microsecondsToCentimeters(long microseconds)
	{
		return microseconds / 29 / 2;
	}