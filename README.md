# Line-following robot (competition)

An ESP32 car that follows a black line using IR reflectance sensors and an H-bridge motor driver (2 DC motors, differential drive).

<!-- Add a photo / video of the car here -->

## Two versions
- **`line_follower_2_sensors.ino`**: the first version. Two IR sensors, four cases: both on the line → forward, one side → turn toward it, none → stop.
- **`line_follower_6_sensors.ino`**: the improved version. Six IR sensors give a finer view of where the line is: center sensors → forward, inner sensors → gentle turn (one wheel stops), outermost sensors → **sharp turn** (wheels spin in opposite directions) for tight curves. All white → stop.

## What I learned
- More sensors let the robot react earlier and handle sharper curves.
- This is **bang-bang (on/off) control**: the motors are either fully on or off, so the car zig-zags along the line.
- Next step: treat the 6 sensors as one position measurement (a weighted average → error from center) and use a **PID controller with PWM motor speed** for smooth, faster tracking.
