---
title: "STM32: LED and button – GPIO input/output in blocking mode"
description: "Configuration of GPIO input and output in STM32 and LED control with a button in blocking (polling) mode using STM32CubeIDE and CubeMX."
date: 2026-04-27 07:00:00 +0100
categories: [Embedded Systems, STM32]
tags: [stm32, gpio]
---

First step in working with an STM32 microcontroller is handling GPIO inputs and outputs (*General-Purpose Input/Output*).

The simplest example is controlling LED using a button. 

First, the onboard LED can be used, followed by custom GPIO connections.

This represents a basic workflow: hardware connections, configuration in STM32CubeMX, and code in STM32CubeIDE.

The first code is typically written in the main loop `while (1)`. In this mode, the input state is read continuously (*polling*), and delay functions (`HAL_Delay`) block CPU execution (*blocking mode*).

This post uses the NUCLEO-G431KB board ([technical documentation and pinout](/assets/posts/stm32-led-button-gpio-blocking-mode/um2397-stm32g4-nucleo32-board-mb1430-stmicroelectronics.pdf)).

Below is a YouTube video showing the full process step by step. The individual steps are described further down.

---

## Video

Below is the full configuration process – step by step, no narration:

<iframe width="100%" height="500" src="https://www.youtube.com/embed/ZItn5qJscc0" 
title="STM32 GPIO LED Button" 
frameborder="0" 
allowfullscreen></iframe>

## System overview

The setup consists of two parts:

- a red LED controlled manually by a button (without a microcontroller),
- onboard LED (green) controlled by the microcontroller, and external LED (yellow) controlled by the microcontroller via a button.

In the first part, the LED is controlled directly by the button, without the MCU.

In the second part, onboard LED (green) on the STM32 board is used first.

Then, control of an external LED from the MCU is shown, including GPIO input and output configuration.

The setup implements two control approaches: hardware (without MCU) and software (with MCU).

---

## Software

Two programs are required:

- CubeMX (STM32Cube initialization code generator) – configuration (pins, clocks, peripherals) → [https://www.st.com/en/development-tools/stm32cubemx.html](https://www.st.com/en/development-tools/stm32cubemx.html)
- CubeIDE (Integrated Development Environment for STM32) – code, build, flashing → [https://www.st.com/en/development-tools/stm32cubeide.html](https://www.st.com/en/development-tools/stm32cubeide.html)

CubeMX generates initialization code, which is then extended in CubeIDE.

Build and flashing are performed from CubeIDE.

---

## Wiring (description)

The setup is built on a breadboard.

### 1. Power supply

A 5 V supply from an external USB source is connected to the positive rail (+) of the breadboard, and then to the Vin–GND pins of the microcontroller.

Pin 3V3 is connected to the second positive rail (+) of the breadboard, and GND to the ground rail (−).

The 3V3 voltage powers peripherals and defines the logic high level for GPIO inputs via pull-up resistors.

Powering the MCU via Vin allows simultaneous powering and USB programming.

All parts of the circuit must share a common ground (GND). Lack of a common ground leads to unstable operation.

### 2. LED without microcontroller

Connection: 3V3 → resistor → LED (red) → button → GND.

This allows testing LED operation and button control without the MCU.

The current-limiting resistor can be placed either before or after the LED – the behavior is identical in both cases.

### 3. LED controlled by the microcontroller

The onboard LED (green) is controlled directly by software and used as the first test.

### 4. LED controlled via GPIO_Output

Connection: pin PA0 → 330 Ω resistor → LED (yellow) → GND.

The LED is controlled by the microcontroller based on button input.

### 5. Button input (GPIO_Input)

Connection:
- pin PB6 → button → GND  
- pin PB6 → external pull-up resistor 10 kΩ to 3V3  

The input uses *active low* logic (LOW when the button is pressed).

Pressing the button results in LOW, releasing it results in HIGH.

A too small pull-up resistor increases current consumption.

---

## Configuration in CubeMX

Minimal configuration:

- PA0 → GPIO_Output
- PB6 → GPIO_Input
- input mode: pull-up (external)

Initialization code is generated in CubeMX and used in CubeIDE.

Before code generation, `Toolchain / IDE` must be set to STM32CubeIDE.

Pin names (e.g., LED_GREEN, LED_YELLOW, BTN) can be defined in CubeMX and used directly in CubeIDE code.

Configuration is stored in a `.ioc` file (pins, peripherals, clocks). This file is used by CubeMX to regenerate code. Project files are created from it, including `main.c`, where user code is implemented.

---

## Working in CubeIDE

After generating the project in CubeMX, work continues in CubeIDE.

The project is opened in CubeIDE, the source code is edited, then build and flash are performed.

User code must be placed between `USER CODE BEGIN` and `USER CODE END`. This preserves user code when files are regenerated. Other parts are generated automatically by CubeMX.

Programming is performed via USB using the built-in ST-Link interface.

After build, the code can be uploaded to the MCU (Run – without debugging, Debug – with code tracing) and tested immediately.

---

## Code variants for practice

### Code #1 – setting GPIO output state

The simplest code is placed in the main loop `while (1)`.

Code is written in `C`.

The first example controls the onboard green LED.

In this variant, the microcontroller sets the LED pin HIGH. The LED stays ON.

```c
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    // Set LED pin HIGH (LED ON)
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);


  }
  /* USER CODE END 3 */
```

Line:

```c
HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
```

sets the LED pin HIGH → the LED remains ON. 

---

### Code #2 – LED blinking (blocking)

This example extends the previous one with LED blinking.

The LED is turned ON and OFF using the delay function `HAL_Delay()`.

```c
  while (1)
  {

	// Turn LED ON for 750 ms
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
	HAL_Delay(750);

    // Turn LED OFF for 500 ms,  set LED pin LOW (LED OFF)
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
	HAL_Delay(500);

  }
```

Operation:

- LED ON for 750 ms  
- LED OFF for 500 ms  
- repeated in an infinite loop  

Function:

```c
HAL_Delay(time_ms);
```

blocks execution for a defined time (milliseconds). During this time, the CPU performs no other tasks.

This is an example of *blocking mode*, as the microcontroller does not react to external events (e.g., button) during delay.

---

### Code #3 – LED control with button (polling)

This example extends the previous one with input reading and output control.

Button state is read in the `while (1)` loop (*polling*).

```c
  // Turn external LED ON once before entering the loop
  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);

  while (1)
  {

	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
	  HAL_Delay(750);
	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
	  HAL_Delay(500);

      // Read button state (active LOW)
      if (HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_RESET)
      {
          // Button pressed -> LED ON
          HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
      }
      else
      {
          // Button released -> LED OFF
          HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
      }

  }
```

Operation:

- button released → HIGH → LED OFF  
- button pressed → LOW → LED ON  

This is a direct mapping of the input to the output.

Button state is checked once per loop iteration. Due to `HAL_Delay()`, response is delayed.

---

### Code #4 – LED toggle with button

This example shows control using simple logic implemented in the MCU.

Button press toggles stored LED state.

```c
  /* USER CODE BEGIN WHILE */

  // Turn internal LED ON once before entering the loop
  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

  // Turn external LED ON once before entering the loop
  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);

  // Toggle state variables
  uint8_t ledState = 1;
  uint8_t lastButtonState = GPIO_PIN_SET;  // pull-up -> default HIGH

  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  // Read current button state
	  uint8_t currentButtonState = HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin);

	  // Detect button press (falling edge: HIGH -> LOW)
	  if (lastButtonState == GPIO_PIN_SET && currentButtonState == GPIO_PIN_RESET)
	  {
	    HAL_Delay(20);  // simple debounce

	    if (HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_RESET)
	    {
	      // Toggle LED
	      ledState = !ledState;

	      if (ledState)
	      {
	        HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	      }
	      else
	      {
	        HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
	      }
	    }
	  }

	  // Update previous button state
	  lastButtonState = currentButtonState;

  }
  /* USER CODE END 3 */
```

Operation:

- initial state: LED ON  
- first press → LED OFF  
- next press → LED ON  
- each press toggles state  

Short `HAL_Delay(20)` acts as simple debounce.

Edge detection ensures reaction only to state change.

---

## Summary

LED control with a button is the simplest GPIO example in STM32 (*hello-world* for MCU).

It demonstrates the full workflow: from hardware to code.

Blocking mode (`HAL_Delay`) is simple but limits responsiveness.

It is a starting point for further steps: interrupts, timers, low-power modes, and PWM.

Next step: input handling using interrupts (EXTI).
