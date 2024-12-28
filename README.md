# STM32F401VE Driver Development
Includes drivers for GPIO, SPI and UART

# GPIO Drivers  

Includes custom GPIO drivers providing the following functionalities:
- Configuring GPIO pin mode, type, speed, pull-up/pull-down, and alternate functions.
- Enabling and configuring GPIO interrupts.
- Reading from and writing to GPIO pins.

## Demonstration Project  
To demonstrate the GPIO drivers, a small project has been developed featuring:  
- A **7-segment display** connected to **port D**, capable of displaying digits.  
- **Buttons** connected to **port A**, used to control the display mode..

### Display Modes  
- **Continuous Counting:** The display counts rapidly while a button is pressed.
- **Count Up/Down on Click:** Counts up or down when a button is clicked.
- **Reset:** Resets the display to zero.

## How to Run  
1. **Open in STM32CubeIDE** to explore the code.
2. **Simulate in Proteus** by opening .pdsprj file and running the simulation.

# SPI Drivers  

Includes custom SPI drivers providing the following functionalities:  
- Enabling the clock for a chosen SPI peripheral.  
- Configuring the CR1 and CR2 registers.  
- Reading flag states from the SR register.  
- Transmitting and receiving data.  
- Enabling SPI interrupts.  

## Demonstration Project
To demonstrate the SPI drivers, a project has been developed featuring two STM32 MCUs communicating via SPI to simulate a stoplight:
- **Master MCU:**
  - Controls the data sent to the slave using a timer to regulate the timing of light changes.
  - Includes four buttons for additional functionality:
    1. **Night Mode Button:** Red light duration is shortened.
    2. **Pedestrian Button:** Turns the light red to allow pedestrian crossing.
    3. **Emergency/Train Button:** Turns the light red and activates a special emergency/train passing light.
    4. **Out of Order Button:** Makes the stoplight flash yellow.
- **Slave MCU:**
  - Controls a stoplight based on the data received from the master.
  - Lights up the appropriate light (red, yellow, green, or special light) according to the master’s commands.

## How to Run  
1. **Open in STM32CubeIDE** to explore the code.
2. **Simulate in Proteus** by opening .pdsprj file and running the simulation.

# UART Drivers  

Still in progress

Includes custom UART/USART drivers providing the following functionalities:  
- Configuring the clock for a chosen USART peripheral.  
- Setting up CR1, CR2, CR3, BRR, and GTPR registers.  
- Reading flag states from the SR register.  
- Transmitting and receiving data.  
- Enabling USART interrupts.  

## Demonstration Project  
To demonstrate the UART drivers, a project has been developed featuring:  
- **MCU Side:**  
  - Connected to a PC via a COM port (COM3 in the simulation).
  - Simulates a smart house with **lights**, **switches**, **door locks**, **thermostat**, **alarms**
  - Receives coded data from the PC to:  
    - Send the current status of devices (e.g., light states, thermostat temperature).  
    - Update device states based on received commands.  
- **PC Side:**  
  - Connected to another COM port (COM4 in the simulation) paired with the MCU's COM3 port.  
  - Includes a **C++ application** to visualize the data from the MCU.  
  - Allows the user to:  
    - Monitor device statuses.  
    - Send commands to change device states.

## How to Run  
1. **Open in STM32CubeIDE** to explore the code.
2. **Simulate in Proteus** by opening .pdsprj file and running the simulation.
3. **Run the C++ Application** on the PC.
   - Ensure that the COM ports are properly paired (e.g., COM3 for MCU and COM4 for PC).

