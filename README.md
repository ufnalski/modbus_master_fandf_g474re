# Modbus master demo (STM32G474RE)
An STM32 HAL example of communicating with an energy meter and a display over the Modbus protocol. Both Modbus devices come from [F&F](https://www.fif.com.pl/en/). For the relevant datasheets visit [LE-01M](https://www.fif.com.pl/en/usage-electric-power-meters/337-energy-meter-le-01m.html) and [MR-LED-T](https://www.fif.com.pl/en/voltage-indicators/1105-panel-display-with-modbus-mr-led-t.html).

![Modbus in action](/Assets/Images/modbus_in_action.jpg)

The main goal for this example is to let you get familiar with the Modbus communication protocol. Here the RTU (Remote Terminal Unit) transmission mode and the RS-485 in the physical layer are used. Reading and writing multiple registers is exercised. The example also encourages you to play with the CRC (Cyclic Redundancy Check) peripheral on STM32 microcontrollers - yes, you don't have to bother the main core to calculate it :slightly_smiling_face:

Modbus was introduced in 1979 and is still popular in industrial environments - you will find plenty of devices that use it and a rich selection of monitoring/debugging tools to help you make the system run. 

# Missing files?
Don't worry :slightly_smiling_face: Just hit Alt-K to generate /Drivers/CMCIS/ and /Drivers/STM32G4xx_HAL_Driver/ based on the .ioc file. After a couple of seconds your project will be ready for building.

# Libraries
* OLED: [stm32-ssd1306](https://github.com/afiskon/stm32-ssd1306) (MIT license)

# Exemplary hardware
* [RS485 Board (3.3V)](https://www.waveshare.com/wiki/RS485_Board_(3.3V)) (Waveshare)
* [OLED display 2.42" (SH1106 or SSD1306)](https://sklep.msalamon.pl/produkt/wyswietlacz-oled-242-128x64px-zolty/)

# Selection of tools for monitoring/debugging
## Hardware
* [KAmod USB RS485 ISO - USB - RS485 converter with galvanic isolation](https://kamami.pl/en/rs485-converters/1187349-kamod-usb-rs485-iso-usb-rs485-converter-with-galvanic-isolation-5906623433391.html) (KAMAMI)
* [USB - RS232/RS485/UART(TTL) converter - FT232RL](https://botland.store/uart-rs232-rs485-converters/24125-usb-rs232rs485uartttl-converter-ft232rl-waveshare-15817-4897068320029.html) (Waveshare)
* [USB TO RS485 Bidirectional Converter](https://www.waveshare.com/product/usb-to-rs485-b.htm) (Waveshare)
* [Serial Server RS232/485 To WiFi and Ethernet, Modbus Gateway](https://www.waveshare.com/rs232-485-to-wifi-eth-b.htm?sku=25223)

## Software I've played with
* [Simply Modbus Master](https://www.simplymodbus.ca/RTUmaster.htm)
* [CAS Modbus Scanner](https://store.chipkin.com/products/tools/cas-modbus-scanner)
* [Serial Port Monitor / Modbus RTU Sniffer / Modbus Protocol Analyzer](https://www.eltima.com/products/modbus-analyzer/)
* [Android Modbus Monitor](https://quantumbitsolutions.com/android-monitor-free/) + USB OTG cable
* [QModMaster](https://sourceforge.net/projects/qmodmaster/)
* [YAT - Yet Another Terminal :: Serial Communication :: Engineer/Test/Debug](https://sourceforge.net/projects/y-a-terminal/) - any serial terminal will do the job as far as you are OK with raw unstructured data.

## Software I haven't played with (yet?)
* [OpenModScan](https://github.com/sanny32/OpenModScan)
* [IO Ninja](https://ioninja.com/)
* [Wireshark](https://www.wireshark.org/)
* [modbus-rs485-wireshark-monitor](https://github.com/ddmesh/modbus-rs485-wireshark-monitor)
* [Modbus Master](https://www.modbus.pl/modbus-master/)

A communication test with the energy meter:

![Communication test with the energy meter](/Assets/Images/energy_meter_read_holding_registers.JPG)

A communication test with the display:

![Communication test with the display](/Assets/Images/display_write_multiple_registers.JPG)

![Displayed value](/Assets/Images/displayed_value.jpg)

# IMHO useful gadgets
* [USB C to USB B adapter](https://allegro.pl/oferta/ugreen-aluminiowy-adapter-przejsciowka-usb-c-na-usb-b-do-skanera-drukarki-13360001183)
* [4-in-1 module for Li-Ion 18650 batteries - USB type C](https://kamami.pl/en/cylindrical-battery-chargers/1178935-4-in-1-module-for-li-ion-18650-batteries-usb-type-c-5906623471157.html)

# Readings and videos
## RS-485
* [RS-485](https://en.wikipedia.org/wiki/RS-485) (Wikipedia)
* [What is RS-485?](https://www.youtube.com/watch?v=bt9Px51eP6s) (Texas Instruments)

## Modbus
* [Modbus](https://en.wikipedia.org/wiki/Modbus) (Wikipedia)
* [Modbus Technical Resources](https://modbus.org/tech.php) (Modbus Organization)
* [How does Modbus Communication Protocol Work?](https://www.youtube.com/watch?v=JBGaInI-TG4)

## Modbus using STM32 (ControllersTech)
* [MODBUS PROTOCOL 101](https://controllerstech.com/understanding-modbus-protocol/)
* [Modbus #1. Read Holding and Input Registers](https://controllerstech.com/stm32-reads-holding-and-input-registers/)
* [STM32 Master Reads Coils and inputs](https://controllerstech.com/modbus-stm32-reads-coils-and-inputs/)
* [Master Writes single Coil and Holding Register](https://controllerstech.com/modbus-3-stm32-master-writes-single-coil-and-holding-register/)
* [Master Writes Multiple Coils and Registers](https://controllerstech.com/modbus-3-1-stm32-master-writes-multiple-coils-and-registers/)
* [Modbus #4. STM32 as Slave || Read Holding and Input Registers](https://controllerstech.com/modbus-4-stm32-as-slave-read-holding-and-input-registers/)
* [Modbus #5. STM32 as Slave || Read Coils and Inputs](https://controllerstech.com/modbus-5-stm32-as-slave-read-coils-and-inputs/)
* [Modbus #6. STM32 as Slave || Write Registers](https://controllerstech.com/modbus-6-stm32-as-slave-write-registers/)
* [Modbus #7. STM32 as Slave || Writing Coils](https://controllerstech.com/modbus-7-stm32-as-slave-writing-coils/)

## CRC
* [Cyclic redundancy check](https://en.wikipedia.org/wiki/Cyclic_redundancy_check) (Wikipedia)
* [Checksums and Hamming distance](https://www.youtube.com/watch?v=ppU41c15Xho) (Ben Eater)
* [How do CRCs work?](https://www.youtube.com/watch?v=izG7qT0EpBw) (Ben Eater)
* [Hardware build: CRC calculation](https://www.youtube.com/watch?v=sNkERQlK8j8) (Ben Eater)
* [AN4187 Application note: Using the CRC peripheral on STM32 microcontrollers](https://www.st.com/resource/en/application_note/an4187-using-the-crc-peripheral-on-stm32-microcontrollers-stmicroelectronics.pdf) (STMicroelectronics)
* [CRC Calculator (Javascript)](http://www.sunshine2k.de/coding/javascript/crc/crc_js.html) and many other [CRC online calculators](https://www.google.com/search?q=crc+online+calculator) - you can use them to verify the configuration of the STM32 CRC peripheral.

Modbus CRC:

![Modbus CRC](/Assets/Images/modbus_crc_online_calculator.JPG)

CubeMX CRC peripheral configuration:

![CubeMX CRC peripheral configuration](/Assets/Images/modbus_crc_stm32.JPG)

# Call for action
Create your own [home laboratory/workshop/garage](http://ufnalski.edu.pl/control_engineering_for_hobbyists/2024_dzien_otwarty_we/Dzien_Otwarty_WE_2024_Control_Engineering_for_Hobbyists.pdf)! Get inspired by [ControllersTech](https://www.youtube.com/@ControllersTech), [DroneBot Workshop](https://www.youtube.com/@Dronebotworkshop), [Andreas Spiess](https://www.youtube.com/@AndreasSpiess), [GreatScott!](https://www.youtube.com/@greatscottlab), [ElectroBOOM](https://www.youtube.com/@ElectroBOOM), [Phil's Lab](https://www.youtube.com/@PhilsLab), [atomic14](https://www.youtube.com/@atomic14), [That Project](https://www.youtube.com/@ThatProject), [Paul McWhorter](https://www.youtube.com/@paulmcwhorter), and many other professional hobbyists sharing their awesome projects and tutorials! Shout-out/kudos to all of them!

> [!WARNING]
> Automation and control engineering - do try this at home :exclamation:

190+ challenges to start from: [Control Engineering for Hobbyists at the Warsaw University of Technology](http://ufnalski.edu.pl/control_engineering_for_hobbyists/Control_Engineering_for_Hobbyists_list_of_challenges.pdf).

Stay tuned!
