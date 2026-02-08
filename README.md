1	# Line Follower Robot (Arduino)
     2	
     3	This repository contains a simple Arduino sketch for a 3-sensor line follower robot using an L298N motor driver. The sketch header includes the original author note from Mahdi Najafi for the INNO HUB_MODER "HQ" build.
     4	
     5	## Hardware
     6	- Arduino-compatible board
     7	- 3x IR line sensors (left, center, right)
     8	- L298N motor driver
     9	- 2x DC motors
    10	
    11	## Pin Mapping
    12	| Function | Pin |
    13	| --- | --- |
    14	| Left sensor | D2 |
    15	| Center sensor | D3 |
    16	| Right sensor | D4 |
    17	| Motor Left IN1 | D6 |
    18	| Motor Left IN2 | D7 |
    19	| Motor Right IN3 | D8 |
    20	| Motor Right IN4 | D10 |
    21	| ENA (Left PWM) | D5 |
    22	| ENB (Right PWM) | D9 |
    23	
    24	## Speed Settings
    25	- `baseSpeed`: PWM value for normal movement (0-255)
    26	- `Fspeed`: reserved for forward speed tuning (currently defined in the sketch)
    27	
    28	## Usage
    29	1. Open `line_follower.ino` in the Arduino IDE.
    30	2. Adjust `baseSpeed` (and optionally `Fspeed`) to tune speed.
    31	3. Upload to your board.
    32	
    33	## Repository Contents
    34	- `line_follower.ino`: Arduino sketch for the 3-sensor line follower robot.
    35	
    36	## Notes
    37	- Sensors are expected to return `1` on black line and `0` on white background. If your sensors are inverted, change the `== 1` comparisons to `== 0`.
    38	- The sketch uses PWM on `ENA`/`ENB` to control speed.
    39	
    40	## Troubleshooting
    41	- **Robot too fast / overshoots:** Lower `baseSpeed` (0-255). Start around 80-150 and tune up.
    42	- **No movement:** Confirm motor power, `ENA`/`ENB` jumpers removed (so PWM works), and wiring matches the pin table.
    43	- **Wrong direction:** Swap motor leads or swap IN1/IN2 for that motor.
