#include <stdio.h>

enum drive {engine, electric, hybrid} drive;
enum vehicleType {ecar, ebus, etruck} vehicleType;

typedef struct Car {
    enum drive whichDrive;
    int sitPlaces;
} Car;

typedef struct Bus {
    int sitPlaces; 
    int standingPlaces;
} Bus;

typedef struct Truck {
    double capacity;
    int numberOfAxles; 
} Truck;

typedef struct Vehicle {
    enum vehicleType type;
    union {
        Car car;
        Bus bus;
        Truck truck;
    };
    
} Vehicle;

Vehicle inputVehicle() {
    Vehicle vehicle; int type = -1;
    printf("Input vehicle type (0 - car, 1 - bus, 2 - truck):\n");
    scanf("%d", &type); vehicle.type = type;
    switch (vehicle.type) {
        case ecar:
            printf("Input car motor type (0 - engine, 1 - electric, 2 - hybrid) and number of sitting places:\n");
            scanf("%d %d", &type, &vehicle.car.sitPlaces); vehicle.car.whichDrive = type; break;
        case ebus:
            printf("Input bus number of sitting and standing places:\n");
            scanf("%d %d", &vehicle.bus.sitPlaces, &vehicle.bus.standingPlaces); break;
        case etruck:
            printf("Input truck capacity (in tones) and number of axles:\n");
            scanf("%lf %d", &vehicle.truck.capacity, &vehicle.truck.numberOfAxles); break;
        default: break;
    }
    return vehicle;
}

void printVehicle(Vehicle vehicle) {
    switch (vehicle.type){
        case ecar: printf("Type = %s\n", "Car"); break;
        case ebus: printf("Type = %s\n", "Bus"); break;
        case etruck: printf("Type = %s\n", "Truck"); break;
        default: break;
    }
    switch (vehicle.type) {
        case ecar:
            switch (vehicle.car.whichDrive) {
                case 0: printf("Type = %s\n", "Engine"); break;
                case 1: printf("Type = %s\n", "Electric"); break;
                case 2: printf("Type = %s\n", "Hybrid"); break;
                default: break;
            }
            printf("SitPlaces = %d\n", vehicle.car.sitPlaces);break;
        case ebus:
            printf("SitPlaces = %d\nStandingPlaces = %d\n", vehicle.bus.sitPlaces, vehicle.bus.standingPlaces); break;
        case etruck:
            printf("Capacity = %.3lf Tones\nNumberOfAxles = %d\n", vehicle.truck.capacity, vehicle.truck.numberOfAxles); break;
        default: break;
    }
}

int main() {
    Vehicle vehicle = inputVehicle();
    printVehicle(vehicle);
    return 0;
}