$fn=350;

/////Units\\\\\
ft = 304.8;
in = 25.4;
cm = 10;
mm = 1;

/////Measurments\\\\\

Width = 46;
Hieght = 28;
Depth = 27;
Thickness = 2;

SensorEye = 17;
SensorEyeDistance = 25/2;

module Box()
{
difference()
{

	cube([Width + Thickness*2, Depth+Thickness*2, Hieght+Thickness]);  //Box
	translate([Thickness, Thickness, Thickness])
	cube([Width,Depth,Hieght+2]);  // cut out
	translate([Width + Thickness*2-SensorEyeDistance,0,0])
	Eye();
	translate([SensorEyeDistance,0,0])
	Eye();
	translate([(Width/2)-7,(Thickness-2)+Depth,Thickness])
	cube([14,Thickness+4,7]);
}
}
module Eye()
{
translate([0,Thickness+2,Thickness+Hieght-2.6-(SensorEye/2)])
rotate([90,0,0])
cylinder(r = SensorEye/2, h = Thickness+4);
}

Box();
