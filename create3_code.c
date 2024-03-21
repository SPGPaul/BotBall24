
#include <kipr/botball.h>

// Define the Create robot's port constants
#define CREATE_DRIVE_MOTOR 0

// Define sensor ports for bumpers
#define BUMPER_SENSOR_LEFT 4
#define BUMPER_SENSOR_RIGHT 5

// Function prototypes for the Create robot
void drive_create_straight(int speed, int duration);
void turn_create(int speed_left, int speed_right, int duration);
void escort_astronauts();

int main() {
    // Start the create robot
    create_connect();
    
    // Escort astronauts to the airlock
    escort_astronauts();
    
    // Disconnect the create robot
    create_disconnect();
    return 0;
}

// Function to drive the Create robot straight
void drive_create_straight(int speed, int duration) {
    create_drive_direct(speed, speed);
    msleep(duration);
    create_stop();
}

// Function to turn the Create robot
void turn_create(int speed_left, int speed_right, int duration) {
    create_drive_direct(speed_left, speed_right);
    msleep(duration);
    create_stop();
}

// Function to escort astronauts
void escort_astronauts() {
    // Drive to astronauts' location
    drive_create_straight(200, 4000); // Speed and duration are placeholders
    
    // Turn towards the airlock
    turn_create(200, -200, 2000); // Adjust values accordingly
    
    // Drive towards the airlock
    drive_create_straight(200, 5000); // Drive to the airlock
    
    // Check if astronauts are collected using bumpers
    if(digital(BUMPER_SENSOR_LEFT) == 1 && digital(BUMPER_SENSOR_RIGHT) == 1) {
        // Astronauts are collected, continue to the airlock
        drive_create_straight(200, 4000); // Proceed to airlock
    } else {
        // Handle the case if astronauts are not detected by bumpers
        // Could involve additional searching or returning to start
    }
}
