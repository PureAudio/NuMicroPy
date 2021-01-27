
#define MICROPY_HW_BOARD_NAME "NHS-N3292x-1-CF"

#define MICROPY_HW_BOARD_NHS_N3292x_1_CF

//RTC
#define MICROPY_HW_ENABLE_RTC       (1)

//VPOST
#define MICROPY_HW_ENABLE_VPOST     (1)

//Touch ADC
#define MICROPY_HW_ENABLE_TOUCHADC	(1)

// I2C busses
#define MICROPY_HW_I2C0_SCL (pin_B13)
#define MICROPY_HW_I2C0_SDA (pin_B14)

//UART
#define MICROPY_HW_UART0_RXD  (pin_D2) //JTAG TDI
#define MICROPY_HW_UART0_TXD  (pin_D1) //JTAG TMS
#define MICROPY_HW_UART0_CTS  (pin_D3) //JTAG TDO
#define MICROPY_HW_UART0_RTS  (pin_D4) //JTAG TRST

//Sensor
#define MICROPY_HW_SENSOR_SCL 	(pin_B13)
#define MICROPY_HW_SENSOR_SDA 	(pin_B14)
#define MICROPY_HW_SENSOR_POWERDOWN (pin_E8)
#define MICROPY_HW_SENSOR_RESET	 (pin_B4)

//SPU PA pin
#define MICROPY_HW_SPU_PA	 	(pin_A0)
