# STM32 Bare-Metal GPIO: Button-Gated Binary Counter

An introductory bare-metal embedded C exercise for the STM32L476RG (Nucleo-64).
It configures GPIO directly through the peripheral registers (no HAL GPIO
abstraction) and drives a 3-bit binary counter on three LEDs, gated by a push
button.

## What it does

- Enables the GPIOA and GPIOC peripheral clocks via `RCC->AHB2ENR`.
- Configures `PC0`, `PC1`, `PC2` as general-purpose outputs (the three counter bits).
- Configures `PA4` as an input with an internal pull-up (the control button).
- In the main loop, while the button is held, it counts 0&ndash;7 and reflects the
  value on the LEDs as a binary pattern, advancing every 200&nbsp;ms via `HAL_Delay`.

The focus is on reading the reference manual and setting `MODER`, `PUPDR`,
`IDR`, and `ODR` bits by hand, rather than relying on generated HAL calls.

## Hardware

- STM32L476RG (Nucleo-64)
- 3 LEDs on `PC0`/`PC1`/`PC2`, push button on `PA4`

## Build

Generated from STM32CubeMX with a CMake build. Open in STM32CubeIDE, or build
with the included CMake presets and an `arm-none-eabi` toolchain, then flash to
the board.

---

## Academic honesty & licensing

This is coursework from an embedded systems course at Cal Poly, San Luis Obispo.
The `main.c` application logic is my own work. The project also bundles
STMicroelectronics' STM32L4xx HAL/CMSIS drivers and CubeMX-generated startup and
configuration files, which are distributed under ST's own license terms and are
**not** mine to relicense.

This repository is shared as a learning reference only. It is intentionally not
released under an open-source license, and you should not submit it as your own
work for a graded assignment.
