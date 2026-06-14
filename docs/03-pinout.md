# Pinout

| STM32 Pin | Function | Direction | Peripheral | Notes |
|---|---|---|---|---|
| PA0 | Servo 1 PWM | Output | TIM2 CH1 | 50 Hz servo PWM |
| PA1 | Front light MOSFET | Output | GPIO | HIGH = ON |
| PA2 | GPS UART TX | Output | USART2 TX | To GPS RX |
| PA3 | GPS UART RX | Input | USART2 RX | From GPS TX |
| PA8 | ESC Left PWM | Output | TIM1 CH1 | 50 Hz ESC PWM |
| PA9 | ESC Right PWM | Output | TIM1 CH2 | 50 Hz ESC PWM |
| PA10 | Servo 2 PWM | Output | TIM1 CH3 | 50 Hz servo PWM |
| PB1 | Battery ADC | Input | ADC1 | Battery divider input |
| PB5 | Rear light MOSFET | Output | GPIO | HIGH = ON |
| PB6 | I2C1 SCL | Output | I2C1 | IMU clock |
| PB7 | I2C1 SDA | Bidirectional | I2C1 | IMU data |
| PB10 | Radio UART TX | Output | USART3 TX | To E220 RX |
| PB11 | Radio UART RX | Input | USART3 RX | From E220 TX |
