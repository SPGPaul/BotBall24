
#include <kipr/botball.h>

// Define motor and sensor ports
#define CLAW_MOTOR_PORT 0
#define DRIVE_MOTOR_LEFT 1
#define DRIVE_MOTOR_RIGHT 2
#define FRONT_BUMPER_LEFT 0
#define FRONT_BUMPER_RIGHT 1
#define BACK_BUMPER_LEFT 2
#define BACK_BUMPER_RIGHT 3

// Define servo positions for the claw
#define CLAW_OPEN_POSITION 1200
#define CLAW_CLOSED_POSITION 800

// Function prototypes
void open_claw();
void close_claw();
void drive_forward(int speed, int duration);
void drive_backward(int speed, int duration);
void turn_left(int speed, int duration);
void turn_right(int speed, int duration);

int main() {
    // Initialize devices
    enable_servos();
    open_claw();

    // Drive to the moon base
    drive_forward(100, 5000); // Speed and duration placeholders
    
    // Close claw to collect the cube
    close_claw();
    msleep(1000); // Wait for the claw to close
    
    // Push orange poms to a designated area
    turn_left(100, 2000); // Adjust as necessary
    drive_forward(100, 6000); // Drive to the poms' area
    
    // Open claw to release the cube
    open_claw();
    
    // Mission complete, disable devices
    disable_servos();
    ao(); // Turn off all motors
    return 0;
}

// Functions implementations
void open_claw() {
    set_servo_position(CLAW_MOTOR_PORT, CLAW_OPEN_POSITION);
    msleep(500); // Give the servo time to move
}

void close_claw() {
    set_servo_position(CLAW_MOTOR_PORT, CLAW_CLOSED_POSITION);
    msleep(500); // Give the servo time to move
}

void drive_forward(int speed, int duration) {
    motor(DRIVE_MOTOR_LEFT, speed);
    motor(DRIVE_MOTOR_RIGHT, speed);
    msleep(duration);
    ao(); // Stop all motors
}

void drive_backward(int speed, int duration) {
    motor(DRIVE_MOTOR_LEFT, -speed);
    motor(DRIVE_MOTOR_RIGHT, -speed);
    msleep(duration);
    ao(); // Stop all motors
}

void turn_left(int speed, int duration) {
    motor(DRIVE_MOTOR_LEFT, -speed);
    motor(DRIVE_MOTOR_RIGHT, speed);
    msleep(duration);
    ao(); // Stop all motors
}

void turn_right(int speed, int duration) {
    motor(DRIVE_MOTOR_LEFT, speed);
    motor(DRIVE_MOTOR_RIGHT, -speed);
    msleep(duration);
    ao(); // Stop all motors
}
