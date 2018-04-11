# PID Controller Project

### Overview
In this project, I have implemented a PID controller in C++ to maneuver the vehicle around the track in a simulator. PID stands for Proportional Integral Derivative. The main aim was to calculate steering angle using this controller but I have also implemented this for calculating the throttle. 

### Results: 
Here is the record of the video of the car driving around the track in simulator :


### Reflection:

1. Components of PID controller:
As discussed, there are three components namely Proportional,Integral,Derivative.

- Proportional : This components specifies that the car will move in proportion to the cross track error(CTE).CTE gives the distance of the car from the center of the lane. If the car is much to the left, it will try to move right to come to the center and vice versa. Considering only this term or keeping this term too high in PID controller will probably overshoot the car and make frequent oscillations.

- Integral : It specifies that the car will also move in proportional to the Sum of all the CTEs because it is necessary to consider previous CTEs to check whether the car is constantly driving away from the center or not. Manufacturing faults like steering not aligned properly can cause the car to constantly drive away from center. Hence this component tends to move the car towards the center.

- Derivative : Here the derivative specifies the change in CTE as the car moves from time to time. In this project we are considering change in time as constant i.e. 1sec and hence we need to consider only the difference between the previous and current CTE. This term is necessary when the car started steering from left/right towards the center, steering will be less as the change in CTE becomes lesser and lesser and the car will not overshoot leading to a smoother steering. Too high value leads to more time to converge to the center . Too small value for the coefficient will lead the car to overshoot.


2. Tuning the coefficients :
I have used manual tuning. I am trying to implement twiddle. But yielded good results with this too. In the first trial, I just tried with all the coefficients set in the range of 0 to 1 and the throttle was constant i.e. 0.3. I found out that it yeilds large angles and eventually car went off the track. Then I tried keeping ki and kd as 0 and set kp as 0.1 or 0.2. It gives frequent oscillations indicating that the differential value is too small. So then I kept increasing kd by 0.5 trial and eventually started getting good results in range 3 to 4.5. Also I tried increasing Ki but the car was veering off track. So I finally settled with values as 0.1, 0, 3.5 for kp, ki , kd respectively and the throttle was 0.3. I wanted to increase the speed to increased the throttle to 0.5 but found out that the car was turning little bit out of edges in sharp turns. So I tried implementing pid for throttle but it also didn't yeilded good results. So later I implemented the code to control the throttle which increases the throttle when the road is straight and slows down during turns.



### Instructions : 
src directory contains the core implementation in which main.cpp and PID.cpp have been modified.

1. Clone this repo.
2. Make a build directory: mkdir build && cd build
3. Compile: cmake .. && make
4. Run it: ./pid.

If you want to try PID on throttle as well please uncomment wherever pid_th obj is used in main.cpp.


