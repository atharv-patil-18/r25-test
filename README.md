# R-25 Test

<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/rover.jpeg" width="600" height="300"/>

#### Some Instructions
1. You may use any online resources, datasheets, or documentation needed, but be mindful of your time and stay focused on the task.
2. The duration of the test is 90 mins from 5:15pm to 6:45 pm.
3. There will be a MCQ test conducted [here](https://r25.munmap.net)
4. There are 3 tasks in the tests. Complete all of them.
5. In case you are not able to complete all the tasks, do upload the whatever you are able to do.
6. In the `README.md` of your repository include your thought process, places where you got stuck, where you used the help of chatGPT, google or other online resources.
7. Even if you are not able to solve anything. Do fill the readme and what your thought process would have been.
8. Carefully read the instructions to implement the required functionality.
9. Install [mingw(c compiler)](https://www.mingw-w64.org/downloads/#w64devkit) and [git](https://git-scm.com/downloads) if you haven't already done it.
10. After finishing your test, provide the link to your forked repository in the google form provided at the end.
     
### Aim/Objective: You are implementing code to control motors for a rover using data received from an RC transmitter.
## Description
You are implementing code to control a sabrtooth motor driver(we are only trying to control motor 1 using S1 of Sabertooth), connected to drive motors of the rover, using data received from an [RC transmitter](datasheets/transmitter-manual.pdf)(make note that the transmitter is configured to transmit data in extended limits). The data from the transmitter is being recieved by a SBUS reciever module, you can find about the data protocol used [here](https://github.com/bolderflight/sbus/blob/main/README.md). 

### Task 0: Fork the provided repository and ensure it is set to PUBLIC so we can access and assess your work.
### Task 1: Interpolation for Sabertooth.
The motor driver (`Sabertooth 2x60`) in the simplified serial mode (check out the [datasheets](datasheets/sabertooth(2x60).pdf))
Your task is to interpolate a channel value into the format accepted by the motor driver, and make the rover move in forward or backward direction.
### Task 2: Compile and run the code.

#### Code
1. [src/main.c](src/main.c): Code for running the test.
2. [lib/parsing.c](lib/parsing.c): Complete the defined `interpolation` function here.

#### How to Compile & Check your code
(make sure you are in the root directory)   
1. Compile your code by running: `make build`
2. To check if your code is implemented correctly run: `make check`
   
If you are able to compile your code successfully you should see something like this on your screen:

<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/make_check_succesfull.png" width="600" height="300"/>
</p>

4. If your make check was unsuccesfull, you can clean your attempt by running `make clean`, review your implementation and repeat the previous steps.

# Solution
## Understanding
The problem involves controlling a Sabertooth 2x60 motor driver using data from an RC transmitter. The transmitter communicates via the SBUS protocol, which sends data in a serialized format. Our task is to:

1) Extract Data: Read RC channel values from the SBUS data.
2) Convert Data: Map these values into PWM signals that the Sabertooth motor driver understands.
3) Control Motor: Send the converted PWM values to the Sabertooth motor driver to control the rover’s motor.

## Thought Process
1) Data Protocol Insight: First, I examined the SBUS protocol, which sends channel data in a compact, serialized format. Each channel value is 11 bits, so extracting these values correctly is crucial.

2) PWM Value Mapping: The Sabertooth motor driver uses PWM values ranging from 0 to 255. Meanwhile, RC channel values range from 0 to 2047. Thus, I needed to map the channel values into this PWM range.

3) Interpolation Approach: I opted for linear interpolation to scale the RC channel values (0-2047) to PWM values (0-255). This approach ensures a straightforward and accurate conversion from one range to the other.

4) Implementation and Testing: I developed the interpolation function to handle this scaling. To ensure accuracy, I compiled and tested the code using the provided Makefile, verifying that the function correctly maps channel values to PWM signals.

## Implementation
1) Scaling Choice: I used linear interpolation to map RC channel values (0-2047) to PWM values (0-255) for the Sabertooth motor driver. This method ensures a proportional and smooth conversion.

2) Interpolation Formula: The formula scales the input range directly to the output range, making it simple and effective.

3) Testing: After implementing the function, I compiled and tested the code using Makefile to ensure the PWM values correctly controlled the motor based on the RC input.

This approach ensured accurate and responsive motor control.

# Google Form
[Link to Repo Submission](https://docs.google.com/forms/d/e/1FAIpQLSeKVbm2dqWxwA5lbEkRfzY8KF619mI5ibGs0Cm2e5wrb0hoWQ/viewform)


<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/feynman-simple.jpg" width="600" height="600"/>
</p>
