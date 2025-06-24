package pkgs;

class Tv {
	String color;
	String name;
	boolean power;
	int channel;

	void power()		{ power = !power; }
	void channelUp()	{ channel++; }
	void channelDown()	{ channel--; }
}
