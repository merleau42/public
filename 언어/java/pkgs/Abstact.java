package pkgs;

abstract class Tva {
	String color;
	String name;
	boolean power;
	int channel;

	abstract void power();
	abstract void channelUp();
	abstract void channelDown();
}

class Tva1 extends Tva {
    @Override
    void channelUp() { channel += 1; }

    @Override
    void channelDown() { channel += 1; }

    @Override
    void power() { power = !power; }
}

class Tva2 extends Tva {
    @Override
    void channelUp() { channel += 2; }

    @Override
    void channelDown() { channel += 2; }

    @Override
    void power() { power = !!power; }
}

