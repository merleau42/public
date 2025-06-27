package pkgs;

class Car {
    String color;
    String gearType;
    int door;

    Car() { this("white", "auto", 4); }

    Car(Car c) {
        color = c.color;
        gearType = c.gearType;
        door = c.door;
    }

    Car(String c, String g, int d) {
        color = c;
        gearType = g;
        door = d;
    }

    void get() {
        System.out.printf("color: %s,  gearType: %s,  door: %d\n", color, gearType, door);
    }
}