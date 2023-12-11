# Automated-Robot-Arm

The objective of this mini project is to perform a kinematic analysis of a simple 3 DOF  robot arm constructed using servo motors. The analysis was involved creating a Denavit-Hartenberg (DH) table, calculating the forward kinematics, deriving the inverse kinematics, and finding the manipulator Jacobian for a pick and place task.

![arm photo1](https://github.com/Upeksha-Dilhara/Automated-Robot-Arm/assets/128304167/b67cb9c9-8ac8-4699-819a-2c7936bbb9fb)


## 1. Denavit-Hartenberg (DH) Table



### DH Parameters:
- **Link Length (a):** 
- **Link Twist (alpha):** 
- **Link Offset (d):** 
- **Joint Angle (theta):**
  
![DH Table](https://github.com/Upeksha-Dilhara/Automated-Robot-Arm/assets/128304167/b9d1e3ec-dca3-4c33-b4b3-2bf6c23893dd)

## 2. Forward Kinematics

### a) Computation using DH Parameters:
- Compute the forward kinematics of the robot arm and determine its end-effector position and orientation. The process involves finding the transformation matrix from the base frame to the end-effector frame. This matrix encapsulates the combined effects of each joint's motion, allowing precise positioning of the robot's end-effector in its workspace. Understanding forward kinematics is crucial for path planning and control strategies in robotic applications.
  
  ![image](https://github.com/Upeksha-Dilhara/Automated-Robot-Arm/assets/128304167/21f17136-fc8c-48d4-a043-85c7504ff103)
 ![image](https://github.com/Upeksha-Dilhara/Automated-Robot-Arm/assets/128304167/69337d5b-7dc1-4d4e-ab96-2c801f6e942c)



### b) Testing with Sample Joint Angles:
- Here what did was we gave known joint anlges and check whether position and orientation are correct. 
  
![image](https://github.com/Upeksha-Dilhara/Automated-Robot-Arm/assets/128304167/288a346e-8499-41bd-bdf8-394297baa915)


## 3. Inverse Kinematics

### a) Equations Derivation:
In Inverse Kinematics we focuses on figuring out a robotic system's joint configurations that are required to reach a specific end-effector pose.
- Derive the equations for the inverse kinematics of the robot arm.
- Focus on determining joint angles required to position the end-effector at a given location.

  ![image](https://github.com/Upeksha-Dilhara/Automated-Robot-Arm/assets/128304167/7ce25438-789d-4f93-b9ac-4f2326e1e467)


### b) Testing with Various End-Effector Positions:
- Test the inverse kinematics with various end-effector positions.
- Ensure accurate computation of the required joint angles.

## 4. Manipulator Jacobian

### Jacobian Matrix:
- Here we calculated the Jacobian matrix of the manipulator.
  
![image](https://github.com/Upeksha-Dilhara/Automated-Robot-Arm/assets/128304167/8605f25f-58a4-4f22-bb54-5bc64d443c65)


## 5. Pick and Place Task

###  Task Design:
- Design a simple pick and place task for the robot arm to demonstrate its functionality. Specify the initial position of the object to be picked and the final position where it will be placed. This task serves as a practical example of applying the robot's capabilities, showcasing its ability to manipulate objects within its workspace. Providing clear initial and final positions helps users understand the intended motion and functionality of the robot arm in this specific task.

- When we are given position of end effector (x,y,z) , joint angles can be calculated using inverse kinematics equations defined above. 

![image](https://github.com/Upeksha-Dilhara/Automated-Robot-Arm/assets/128304167/4b52eb13-6567-4747-9d5a-7ba3e8240fec)



