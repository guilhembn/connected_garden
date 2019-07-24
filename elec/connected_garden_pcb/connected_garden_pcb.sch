EESchema Schematic File Version 4
LIBS:connected_garden_pcb-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	8150 3950 8150 4100
$Comp
L power:GND #PWR04
U 1 1 5D27D6DB
P 2000 1400
F 0 "#PWR04" H 2000 1150 50  0001 C CNN
F 1 "GND" H 2005 1227 50  0000 C CNN
F 2 "" H 2000 1400 50  0001 C CNN
F 3 "" H 2000 1400 50  0001 C CNN
	1    2000 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 2450 8450 2450
$Comp
L power:+3.3V #PWR017
U 1 1 5D27D7A8
P 8450 2450
F 0 "#PWR017" H 8450 2300 50  0001 C CNN
F 1 "+3.3V" H 8465 2623 50  0000 C CNN
F 2 "" H 8450 2450 50  0001 C CNN
F 3 "" H 8450 2450 50  0001 C CNN
	1    8450 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5D27D7E5
P 8150 4100
F 0 "#PWR016" H 8150 3850 50  0001 C CNN
F 1 "GND" H 8155 3927 50  0000 C CNN
F 2 "" H 8150 4100 50  0001 C CNN
F 3 "" H 8150 4100 50  0001 C CNN
	1    8150 4100
	1    0    0    -1  
$EndComp
$Comp
L Sensor:DHT11 U4
U 1 1 5D27D857
P 6150 1400
F 0 "U4" H 5920 1446 50  0000 R CNN
F 1 "DHT11" H 5920 1355 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 6300 1650 50  0001 C CNN
F 3 "http://akizukidenshi.com/download/ds/aosong/DHT11.pdf" H 6300 1650 50  0001 C CNN
	1    6150 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5D27D90E
P 6050 1700
F 0 "#PWR013" H 6050 1450 50  0001 C CNN
F 1 "GND" H 6055 1527 50  0000 C CNN
F 2 "" H 6050 1700 50  0001 C CNN
F 3 "" H 6050 1700 50  0001 C CNN
	1    6050 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR012
U 1 1 5D27D940
P 6050 1100
F 0 "#PWR012" H 6050 950 50  0001 C CNN
F 1 "+3.3V" H 6065 1273 50  0000 C CNN
F 2 "" H 6050 1100 50  0001 C CNN
F 3 "" H 6050 1100 50  0001 C CNN
	1    6050 1100
	1    0    0    -1  
$EndComp
$Comp
L Analog_ADC:MCP3208 U2
U 1 1 5D27D9DB
P 1700 5150
F 0 "U2" H 1700 5828 50  0000 C CNN
F 1 "MCP3208" H 1700 5737 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 1800 5250 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21298c.pdf" H 1800 5250 50  0001 C CNN
	1    1700 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5D27DADA
P 1600 5750
F 0 "#PWR02" H 1600 5500 50  0001 C CNN
F 1 "GND" H 1605 5577 50  0000 C CNN
F 2 "" H 1600 5750 50  0001 C CNN
F 3 "" H 1600 5750 50  0001 C CNN
	1    1600 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5D27DB08
P 1900 5750
F 0 "#PWR03" H 1900 5500 50  0001 C CNN
F 1 "GND" H 1905 5577 50  0000 C CNN
F 2 "" H 1900 5750 50  0001 C CNN
F 3 "" H 1900 5750 50  0001 C CNN
	1    1900 5750
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:SPX3819M5-L-3-3 U3
U 1 1 5D27DBA6
P 2950 1200
F 0 "U3" H 2950 1542 50  0000 C CNN
F 1 "SPX3819M5-L-3-3" H 2950 1451 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 2950 1525 50  0001 C CNN
F 3 "https://www.exar.com/content/document.ashx?id=22106&languageid=1033&type=Datasheet&partnumber=SPX3819&filename=SPX3819.pdf&part=SPX3819" H 2950 1200 50  0001 C CNN
	1    2950 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 900  2350 900 
Wire Wire Line
	2350 900  2350 1100
Wire Wire Line
	2350 1100 2600 1100
Wire Wire Line
	2650 1200 2600 1200
Wire Wire Line
	2600 1200 2600 1100
Connection ~ 2600 1100
Wire Wire Line
	2600 1100 2650 1100
$Comp
L power:GND #PWR07
U 1 1 5D27DE2D
P 2950 1500
F 0 "#PWR07" H 2950 1250 50  0001 C CNN
F 1 "GND" H 2955 1327 50  0000 C CNN
F 2 "" H 2950 1500 50  0001 C CNN
F 3 "" H 2950 1500 50  0001 C CNN
	1    2950 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5D27DEE5
P 3650 1250
F 0 "C1" H 3765 1296 50  0000 L CNN
F 1 "1µF" H 3765 1205 50  0000 L CNN
F 2 "Capacitor_THT:C_Radial_D6.3mm_H7.0mm_P2.50mm" H 3688 1100 50  0001 C CNN
F 3 "~" H 3650 1250 50  0001 C CNN
	1    3650 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 1100 3650 1100
Wire Wire Line
	3650 1100 3800 1100
Wire Wire Line
	3800 1100 3800 1050
Connection ~ 3650 1100
$Comp
L power:GND #PWR010
U 1 1 5D27E011
P 3650 1400
F 0 "#PWR010" H 3650 1150 50  0001 C CNN
F 1 "GND" H 3655 1227 50  0000 C CNN
F 2 "" H 3650 1400 50  0001 C CNN
F 3 "" H 3650 1400 50  0001 C CNN
	1    3650 1400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR011
U 1 1 5D27E04C
P 3800 1050
F 0 "#PWR011" H 3800 900 50  0001 C CNN
F 1 "+3.3V" H 3815 1223 50  0000 C CNN
F 2 "" H 3800 1050 50  0001 C CNN
F 3 "" H 3800 1050 50  0001 C CNN
	1    3800 1050
	1    0    0    -1  
$EndComp
Text Label 7350 3750 0    50   ~ 0
SCLK
Wire Wire Line
	7350 3750 7550 3750
Wire Wire Line
	7550 3650 7350 3650
Wire Wire Line
	7550 3350 7350 3350
Text Label 7350 3650 0    50   ~ 0
MOSI
Text Label 7350 3350 0    50   ~ 0
MISO
Wire Wire Line
	7550 3250 7350 3250
Text Label 7350 3250 0    50   ~ 0
CS
Wire Wire Line
	2300 5350 2500 5350
Wire Wire Line
	2300 5250 2500 5250
Wire Wire Line
	2300 5150 2500 5150
Wire Wire Line
	2300 5050 2500 5050
Wire Wire Line
	1900 4650 2000 4650
$Comp
L power:+3.3V #PWR05
U 1 1 5D2801CC
P 2000 4650
F 0 "#PWR05" H 2000 4500 50  0001 C CNN
F 1 "+3.3V" H 2015 4823 50  0000 C CNN
F 2 "" H 2000 4650 50  0001 C CNN
F 3 "" H 2000 4650 50  0001 C CNN
	1    2000 4650
	1    0    0    -1  
$EndComp
Text Label 2500 5050 0    50   ~ 0
SCLK
Text Label 2500 5150 0    50   ~ 0
MISO
Text Label 2500 5250 0    50   ~ 0
MOSI
Text Label 2500 5350 0    50   ~ 0
CS
$Comp
L Connector:Conn_01x03_Female J1
U 1 1 5D28047E
P 3900 4550
F 0 "J1" H 3927 4576 50  0000 L CNN
F 1 "Moisture1" H 3927 4485 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3900 4550 50  0001 C CNN
F 3 "~" H 3900 4550 50  0001 C CNN
	1    3900 4550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J2
U 1 1 5D280531
P 3900 4900
F 0 "J2" H 3927 4926 50  0000 L CNN
F 1 "Moisture2" H 3927 4835 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3900 4900 50  0001 C CNN
F 3 "~" H 3900 4900 50  0001 C CNN
	1    3900 4900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J3
U 1 1 5D280579
P 3900 5250
F 0 "J3" H 3927 5276 50  0000 L CNN
F 1 "Moisture3" H 3927 5185 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3900 5250 50  0001 C CNN
F 3 "~" H 3900 5250 50  0001 C CNN
	1    3900 5250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J4
U 1 1 5D2805C7
P 3900 5600
F 0 "J4" H 3927 5626 50  0000 L CNN
F 1 "Moisture4" H 3927 5535 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3900 5600 50  0001 C CNN
F 3 "~" H 3900 5600 50  0001 C CNN
	1    3900 5600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J5
U 1 1 5D28060D
P 3900 5950
F 0 "J5" H 3927 5976 50  0000 L CNN
F 1 "Moisture5" H 3927 5885 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3900 5950 50  0001 C CNN
F 3 "~" H 3900 5950 50  0001 C CNN
	1    3900 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4450 3600 4450
Wire Wire Line
	3600 4450 3600 4800
Wire Wire Line
	3700 4800 3600 4800
Connection ~ 3600 4800
Wire Wire Line
	3600 4800 3600 5150
Wire Wire Line
	3700 5150 3600 5150
Connection ~ 3600 5150
Wire Wire Line
	3600 5150 3600 5500
Wire Wire Line
	3700 5500 3600 5500
Connection ~ 3600 5500
Wire Wire Line
	3600 5500 3600 5850
Wire Wire Line
	3700 5850 3600 5850
Connection ~ 3600 5850
Wire Wire Line
	3600 5850 3600 6250
Wire Wire Line
	3700 4550 3500 4550
Wire Wire Line
	3500 4550 3500 4350
Wire Wire Line
	3500 4550 3500 4900
Wire Wire Line
	3500 5950 3700 5950
Connection ~ 3500 4550
Wire Wire Line
	3700 5600 3500 5600
Connection ~ 3500 5600
Wire Wire Line
	3500 5600 3500 5950
Wire Wire Line
	3700 5250 3500 5250
Connection ~ 3500 5250
Wire Wire Line
	3500 5250 3500 5600
Wire Wire Line
	3700 4900 3500 4900
Connection ~ 3500 4900
Wire Wire Line
	3500 4900 3500 5250
Wire Wire Line
	3700 4650 3350 4650
Wire Wire Line
	3700 5000 3350 5000
Wire Wire Line
	3700 5350 3350 5350
Wire Wire Line
	3700 5700 3350 5700
Wire Wire Line
	3700 6050 3350 6050
$Comp
L power:+3.3V #PWR08
U 1 1 5D2869C9
P 3500 4350
F 0 "#PWR08" H 3500 4200 50  0001 C CNN
F 1 "+3.3V" H 3515 4523 50  0000 C CNN
F 2 "" H 3500 4350 50  0001 C CNN
F 3 "" H 3500 4350 50  0001 C CNN
	1    3500 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5D286A13
P 3600 6250
F 0 "#PWR09" H 3600 6000 50  0001 C CNN
F 1 "GND" H 3605 6077 50  0000 C CNN
F 2 "" H 3600 6250 50  0001 C CNN
F 3 "" H 3600 6250 50  0001 C CNN
	1    3600 6250
	1    0    0    -1  
$EndComp
Text Label 3350 4650 0    50   ~ 0
A0
Text Label 3350 5000 0    50   ~ 0
A1
Text Label 3350 5350 0    50   ~ 0
A2
Text Label 3350 5700 0    50   ~ 0
A3
Text Label 3350 6050 0    50   ~ 0
A4
Wire Wire Line
	1100 4850 950  4850
Wire Wire Line
	1100 4950 950  4950
Wire Wire Line
	1100 5050 950  5050
Wire Wire Line
	1100 5150 950  5150
Wire Wire Line
	1100 5250 950  5250
Text Label 950  4850 0    50   ~ 0
A0
Text Label 950  4950 0    50   ~ 0
A1
Text Label 950  5050 0    50   ~ 0
A2
Text Label 950  5150 0    50   ~ 0
A3
Text Label 950  5250 0    50   ~ 0
A4
$Comp
L Switch:SW_Push_Dual SW1
U 1 1 5D28C0F8
P 7200 2650
F 0 "SW1" H 7200 2935 50  0000 C CNN
F 1 "Reset" H 7200 2844 50  0000 C CNN
F 2 "Button_Switch_THT:SW_TH_Tactile_Omron_B3F-10xx" H 7200 2850 50  0001 C CNN
F 3 "" H 7200 2850 50  0001 C CNN
	1    7200 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 2650 7500 2650
Wire Wire Line
	7000 2650 6900 2650
Wire Wire Line
	6900 2650 6900 2800
Wire Wire Line
	7500 2650 7500 2550
Connection ~ 7500 2650
Wire Wire Line
	7500 2650 7400 2650
$Comp
L Device:R R1
U 1 1 5D294407
P 7500 2400
F 0 "R1" H 7570 2446 50  0000 L CNN
F 1 "10k" H 7570 2355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7430 2400 50  0001 C CNN
F 3 "~" H 7500 2400 50  0001 C CNN
	1    7500 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR015
U 1 1 5D294465
P 7500 2250
F 0 "#PWR015" H 7500 2100 50  0001 C CNN
F 1 "+3.3V" H 7515 2423 50  0000 C CNN
F 2 "" H 7500 2250 50  0001 C CNN
F 3 "" H 7500 2250 50  0001 C CNN
	1    7500 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5D2944FE
P 6900 2800
F 0 "#PWR014" H 6900 2550 50  0001 C CNN
F 1 "GND" H 6905 2627 50  0000 C CNN
F 2 "" H 6900 2800 50  0001 C CNN
F 3 "" H 6900 2800 50  0001 C CNN
	1    6900 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2650 7400 2850
Connection ~ 7400 2650
Wire Wire Line
	7000 2650 7000 2850
Connection ~ 7000 2650
Wire Wire Line
	8750 3550 9050 3550
Wire Wire Line
	8150 3950 9050 3950
Wire Wire Line
	9050 3950 9050 3850
$Comp
L Device:R R2
U 1 1 5D2990DC
P 9050 3700
F 0 "R2" H 9120 3746 50  0000 L CNN
F 1 "10k" H 9120 3655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8980 3700 50  0001 C CNN
F 3 "~" H 9050 3700 50  0001 C CNN
	1    9050 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 2850 7500 2850
Wire Wire Line
	7500 2850 7500 2650
$Comp
L Device:R R3
U 1 1 5D2A576A
P 9400 2200
F 0 "R3" H 9470 2246 50  0000 L CNN
F 1 "10k" H 9470 2155 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9330 2200 50  0001 C CNN
F 3 "~" H 9400 2200 50  0001 C CNN
	1    9400 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 2350 9400 2400
$Comp
L Switch:SW_Push_Dual SW2
U 1 1 5D2A6CB1
P 9600 2600
F 0 "SW2" V 9554 2748 50  0000 L CNN
F 1 "Flash" V 9645 2748 50  0000 L CNN
F 2 "Button_Switch_THT:SW_TH_Tactile_Omron_B3F-10xx" H 9600 2800 50  0001 C CNN
F 3 "" H 9600 2800 50  0001 C CNN
	1    9600 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	9600 2400 9400 2400
Connection ~ 9400 2400
Wire Wire Line
	9600 2800 9400 2800
$Comp
L power:+3.3V #PWR019
U 1 1 5D2A97F6
P 9400 2050
F 0 "#PWR019" H 9400 1900 50  0001 C CNN
F 1 "+3.3V" H 9415 2223 50  0000 C CNN
F 2 "" H 9400 2050 50  0001 C CNN
F 3 "" H 9400 2050 50  0001 C CNN
	1    9400 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 5D2A984F
P 9400 2800
F 0 "#PWR020" H 9400 2550 50  0001 C CNN
F 1 "GND" H 9405 2627 50  0000 C CNN
F 2 "" H 9400 2800 50  0001 C CNN
F 3 "" H 9400 2800 50  0001 C CNN
	1    9400 2800
	1    0    0    -1  
$EndComp
Connection ~ 9400 2800
$Comp
L power:+3.3V #PWR018
U 1 1 5D2AAF82
P 9150 2850
F 0 "#PWR018" H 9150 2700 50  0001 C CNN
F 1 "+3.3V" H 9165 3023 50  0000 C CNN
F 2 "" H 9150 2850 50  0001 C CNN
F 3 "" H 9150 2850 50  0001 C CNN
	1    9150 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 2650 8750 2400
Connection ~ 8150 3950
$Comp
L RF_Module:ESP-12F U5
U 1 1 5D27D4EE
P 8150 3250
F 0 "U5" H 8150 4228 50  0000 C CNN
F 1 "ESP-12F" H 8150 4137 50  0000 C CNN
F 2 "RF_Module:ESP-12E" H 8150 3250 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 7800 3350 50  0001 C CNN
	1    8150 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 2400 9400 2400
Wire Wire Line
	8750 2850 9150 2850
Wire Wire Line
	8750 2750 8850 2750
Wire Wire Line
	8750 2950 8850 2950
Text Label 8850 2750 0    50   ~ 0
TX
Text Label 8850 2950 0    50   ~ 0
RX
$Comp
L Device:R R4
U 1 1 5D2E2005
P 2350 1900
F 0 "R4" H 2420 1946 50  0000 L CNN
F 1 "1.8K" H 2420 1855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2280 1900 50  0001 C CNN
F 3 "~" H 2350 1900 50  0001 C CNN
	1    2350 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5D2E20C8
P 2350 2300
F 0 "R5" H 2420 2346 50  0000 L CNN
F 1 "5K" H 2420 2255 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2280 2300 50  0001 C CNN
F 3 "~" H 2350 2300 50  0001 C CNN
	1    2350 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 1100 2350 1750
Connection ~ 2350 1100
Wire Wire Line
	2350 2050 2350 2100
Wire Wire Line
	2350 2450 2350 2650
$Comp
L power:GND #PWR06
U 1 1 5D2E6BF7
P 2350 2650
F 0 "#PWR06" H 2350 2400 50  0001 C CNN
F 1 "GND" H 2355 2477 50  0000 C CNN
F 2 "" H 2350 2650 50  0001 C CNN
F 3 "" H 2350 2650 50  0001 C CNN
	1    2350 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 4650 1500 4650
$Comp
L power:+3.3V #PWR01
U 1 1 5D2EB9B9
P 1500 4650
F 0 "#PWR01" H 1500 4500 50  0001 C CNN
F 1 "+3.3V" H 1515 4823 50  0000 C CNN
F 2 "" H 1500 4650 50  0001 C CNN
F 3 "" H 1500 4650 50  0001 C CNN
	1    1500 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2100 2350 2100
Connection ~ 2350 2100
Wire Wire Line
	2350 2100 2350 2150
Text Label 2200 2100 0    50   ~ 0
A5
Wire Wire Line
	1100 5350 950  5350
Text Label 950  5350 0    50   ~ 0
A5
$Comp
L Connector:Screw_Terminal_01x02 J6
U 1 1 5D2F0189
P 650 1200
F 0 "J6" H 570 875 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 570 966 50  0000 C CNN
F 2 "TerminalBlock_RND:TerminalBlock_RND_205-00001_1x02_P5.00mm_Horizontal" H 650 1200 50  0001 C CNN
F 3 "~" H 650 1200 50  0001 C CNN
	1    650  1200
	-1   0    0    1   
$EndComp
Wire Wire Line
	850  1100 950  1100
Wire Wire Line
	950  1100 950  900 
Wire Wire Line
	950  1400 950  1200
Wire Wire Line
	950  1200 850  1200
Wire Wire Line
	8150 5000 8000 5000
Wire Wire Line
	8150 5100 8000 5100
Wire Wire Line
	8150 5200 8000 5200
Text Label 8000 5000 0    50   ~ 0
RX
Text Label 8000 5100 0    50   ~ 0
TX
$Comp
L power:GND #PWR0101
U 1 1 5D2FA87B
P 8000 5200
F 0 "#PWR0101" H 8000 4950 50  0001 C CNN
F 1 "GND" H 8005 5027 50  0000 C CNN
F 2 "" H 8000 5200 50  0001 C CNN
F 3 "" H 8000 5200 50  0001 C CNN
	1    8000 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5D2FAB4C
P 6550 1250
F 0 "R6" H 6620 1296 50  0000 L CNN
F 1 "R" H 6620 1205 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6480 1250 50  0001 C CNN
F 3 "~" H 6550 1250 50  0001 C CNN
	1    6550 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 1100 6050 1100
Connection ~ 6050 1100
Wire Wire Line
	6550 1400 6450 1400
Wire Wire Line
	6550 1400 6850 1400
Connection ~ 6550 1400
Text Label 6850 1400 0    50   ~ 0
DHT11Data
Wire Wire Line
	8750 3050 8850 3050
Text Label 8850 3050 0    50   ~ 0
DHT11Data
$Comp
L Connector:Conn_01x03_Female J7
U 1 1 5D2F4476
P 8350 5100
F 0 "J7" H 8377 5126 50  0000 L CNN
F 1 "UART out" H 8377 5035 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8350 5100 50  0001 C CNN
F 3 "~" H 8350 5100 50  0001 C CNN
	1    8350 5100
	1    0    0    -1  
$EndComp
$Comp
L connected_garden_lib:TP4056-18650 U1
U 1 1 5D383666
P 1500 1150
F 0 "U1" H 1475 1625 50  0000 C CNN
F 1 "TP4056-18650" H 1475 1534 50  0000 C CNN
F 2 "connected_garden_footprints:TP4056-18650" H 1450 1150 50  0001 C CNN
F 3 "" H 1450 1150 50  0001 C CNN
	1    1500 1150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
