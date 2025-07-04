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

class CaptionTv extends Tv {
	boolean caption; // 기본값은 false로 초기화됨.

	void displayCaption(String text) {
		if (caption) {
			System.out.println(text);
		}
	}
}

class VCR {
	boolean power;
	int counter = 0;
	void power() { power = !power; }

	static void play() {}
	static void stop() {}
	static void rew() {}
	static void ff() {}
}

class TVCR extends Tv {
	VCR vcr = new VCR();
	void play() {VCR.play();}
	void stop() {VCR.stop();}
	void rew() {VCR.rew();}
	void ff() {VCR.ff();}
}

