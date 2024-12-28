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
