EESchema Schematic File Version 2
LIBS:OSBB-v1-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:OSBB-v1-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Modular Open Button Box (MOBB)"
Date "2016-11-02"
Rev "RC4"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74HC4051 U1
U 1 1 57F0E74D
P 650 3750
F 0 "U1" H 1700 4250 60  0000 C CNN
F 1 "74HC4051" H 1850 4350 60  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 1850 4350 60  0001 C CNN
F 3 "" H 1850 4350 60  0001 C CNN
	1    650  3750
	1    0    0    -1  
$EndComp
$Comp
L 74HC4051 U4
U 1 1 57F0E87A
P 7350 3750
F 0 "U4" H 8400 4250 60  0000 C CNN
F 1 "74HC4051" H 8550 4350 60  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 8550 4350 60  0001 C CNN
F 3 "" H 8550 4350 60  0001 C CNN
	1    7350 3750
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_CBE Q1
U 1 1 57F18BC4
P 1200 6000
F 0 "Q1" H 1500 6050 50  0000 R CNN
F 1 "NPN" H 1500 5950 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 1400 6100 50  0001 C CNN
F 3 "" H 1200 6000 50  0000 C CNN
	1    1200 6000
	0    1    1    0   
$EndComp
$Comp
L Q_NPN_CBE Q2
U 1 1 57F18DF7
P 1950 6000
F 0 "Q2" H 2250 6050 50  0000 R CNN
F 1 "NPN" H 2250 5950 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 2150 6100 50  0001 C CNN
F 3 "" H 1950 6000 50  0000 C CNN
	1    1950 6000
	0    1    1    0   
$EndComp
$Comp
L Q_NPN_CBE Q3
U 1 1 57F18FB2
P 2650 6000
F 0 "Q3" H 2950 6050 50  0000 R CNN
F 1 "NPN" H 2950 5950 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 2850 6100 50  0001 C CNN
F 3 "" H 2650 6000 50  0000 C CNN
	1    2650 6000
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 57F190B3
P 1200 5550
F 0 "R2" V 1280 5550 50  0000 C CNN
F 1 "1K" V 1200 5550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 1130 5550 50  0001 C CNN
F 3 "" H 1200 5550 50  0000 C CNN
	1    1200 5550
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 57F19132
P 1950 5550
F 0 "R4" V 2030 5550 50  0000 C CNN
F 1 "1K" V 1950 5550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 1880 5550 50  0001 C CNN
F 3 "" H 1950 5550 50  0000 C CNN
	1    1950 5550
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 57F191AA
P 2650 5550
F 0 "R6" V 2730 5550 50  0000 C CNN
F 1 "1K" V 2650 5550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 2580 5550 50  0001 C CNN
F 3 "" H 2650 5550 50  0000 C CNN
	1    2650 5550
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 57F19227
P 900 5900
F 0 "R1" V 980 5900 50  0000 C CNN
F 1 "10K" V 900 5900 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 830 5900 50  0001 C CNN
F 3 "" H 900 5900 50  0000 C CNN
	1    900  5900
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 57F192A5
P 1700 5900
F 0 "R3" V 1780 5900 50  0000 C CNN
F 1 "10K" V 1700 5900 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 1630 5900 50  0001 C CNN
F 3 "" H 1700 5900 50  0000 C CNN
	1    1700 5900
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 57F1931C
P 2400 5900
F 0 "R5" V 2480 5900 50  0000 C CNN
F 1 "10K" V 2400 5900 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 2330 5900 50  0001 C CNN
F 3 "" H 2400 5900 50  0000 C CNN
	1    2400 5900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 57F19A05
P 1700 6150
F 0 "#PWR01" H 1700 5900 50  0001 C CNN
F 1 "GND" H 1700 6000 50  0000 C CNN
F 2 "" H 1700 6150 50  0000 C CNN
F 3 "" H 1700 6150 50  0000 C CNN
	1    1700 6150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 57F19A4C
P 900 6150
F 0 "#PWR02" H 900 5900 50  0001 C CNN
F 1 "GND" H 900 6000 50  0000 C CNN
F 2 "" H 900 6150 50  0000 C CNN
F 3 "" H 900 6150 50  0000 C CNN
	1    900  6150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 57F19A93
P 2400 6150
F 0 "#PWR03" H 2400 5900 50  0001 C CNN
F 1 "GND" H 2400 6000 50  0000 C CNN
F 2 "" H 2400 6150 50  0000 C CNN
F 3 "" H 2400 6150 50  0000 C CNN
	1    2400 6150
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 P5
U 1 1 57F1AF96
P 3700 5500
F 0 "P5" H 3700 5850 50  0000 C CNN
F 1 "Rotary Encoders" V 3800 5500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x06" H 3700 5500 50  0001 C CNN
F 3 "" H 3700 5500 50  0000 C CNN
	1    3700 5500
	-1   0    0    1   
$EndComp
Text Label 5950 5150 0    60   ~ 0
reserved_for_4051
$Comp
L CONN_01X05 P14
U 1 1 580F60D7
P 6900 5450
F 0 "P14" H 6900 5750 50  0000 C CNN
F 1 "EXTRA Pins" V 7000 5450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x05" H 6900 5450 50  0001 C CNN
F 3 "" H 6900 5450 50  0000 C CNN
	1    6900 5450
	1    0    0    1   
$EndComp
$Comp
L GND #PWR04
U 1 1 5810375B
P 3600 6500
F 0 "#PWR04" H 3600 6250 50  0001 C CNN
F 1 "GND" H 3600 6350 50  0000 C CNN
F 2 "" H 3600 6500 50  0000 C CNN
F 3 "" H 3600 6500 50  0000 C CNN
	1    3600 6500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR05
U 1 1 581037AF
P 3950 6750
F 0 "#PWR05" H 3950 6600 50  0001 C CNN
F 1 "+5V" H 3950 6890 50  0000 C CNN
F 2 "" H 3950 6750 50  0000 C CNN
F 3 "" H 3950 6750 50  0000 C CNN
	1    3950 6750
	1    0    0    -1  
$EndComp
NoConn ~ 5950 5150
NoConn ~ 5950 4450
NoConn ~ 5950 4550
NoConn ~ 5950 5750
NoConn ~ 4950 6400
NoConn ~ 5100 6400
NoConn ~ 5250 6400
NoConn ~ 5400 6400
NoConn ~ 5550 6400
$Comp
L Teensy3.2 U5
U 1 1 5810D118
P 5250 5050
F 0 "U5" H 4800 5800 60  0000 C CNN
F 1 "Teensy3.2" H 4950 5900 60  0000 C CNN
F 2 "Housings_DIP:DIP-28_W15.24mm_LongPads" H 5250 5650 60  0001 C CNN
F 3 "" H 5250 5650 60  0001 C CNN
	1    5250 5050
	1    0    0    -1  
$EndComp
NoConn ~ 5450 4050
Wire Wire Line
	6200 3800 6200 4750
Wire Wire Line
	3000 3600 3000 4550
Wire Wire Line
	3000 4550 4550 4550
Connection ~ 3000 3600
Wire Wire Line
	3050 3500 3050 4650
Wire Wire Line
	3050 4650 4550 4650
Connection ~ 3050 3500
Wire Wire Line
	3100 3400 3100 4750
Wire Wire Line
	3100 4750 4550 4750
Connection ~ 3100 3400
Wire Wire Line
	1200 5700 1200 5800
Wire Wire Line
	1950 5700 1950 5800
Wire Wire Line
	1700 5750 1950 5750
Connection ~ 1950 5750
Wire Wire Line
	2650 5700 2650 5800
Wire Wire Line
	2400 5750 2650 5750
Connection ~ 2650 5750
Wire Wire Line
	900  5750 1200 5750
Connection ~ 1200 5750
Wire Wire Line
	2450 6100 2400 6100
Wire Wire Line
	2400 6050 2400 6150
Connection ~ 2400 6100
Wire Wire Line
	1700 6050 1700 6150
Wire Wire Line
	1750 6100 1700 6100
Connection ~ 1700 6100
Wire Wire Line
	900  6050 900  6150
Wire Wire Line
	1000 6100 900  6100
Connection ~ 900  6100
Wire Wire Line
	1400 6100 1400 7150
Wire Wire Line
	2150 6100 2150 6550
Wire Wire Line
	2850 6100 2850 6800
Wire Wire Line
	3900 5750 4550 5750
Wire Wire Line
	3900 5650 4550 5650
Wire Wire Line
	3900 5550 4550 5550
Wire Wire Line
	3900 5450 4550 5450
Wire Wire Line
	3900 5350 4550 5350
Wire Wire Line
	3900 5250 4550 5250
Wire Wire Line
	1200 4850 4550 4850
Wire Wire Line
	1200 4850 1200 5400
Wire Wire Line
	1950 4950 4550 4950
Wire Wire Line
	1950 4950 1950 5400
Wire Wire Line
	2650 5050 4550 5050
Wire Wire Line
	2650 5050 2650 5400
Wire Wire Line
	3100 5150 4550 5150
Wire Wire Line
	3100 5150 3100 5400
Wire Wire Line
	6350 3750 6350 4850
Wire Wire Line
	700  3800 6200 3800
Wire Wire Line
	6200 4750 5950 4750
Wire Wire Line
	6350 4850 5950 4850
Wire Wire Line
	6550 4950 5950 4950
Wire Wire Line
	5950 5050 7850 5050
Wire Wire Line
	5950 5250 6700 5250
Wire Wire Line
	6700 5350 5950 5350
Wire Wire Line
	5950 5450 6700 5450
Wire Wire Line
	6700 5550 5950 5550
Wire Wire Line
	5950 5650 6700 5650
$Comp
L CONN_02X03 P1
U 1 1 581250E2
P 2000 7050
F 0 "P1" H 2000 7250 50  0000 C CNN
F 1 "AUX 1-3" H 2000 6850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x03" H 2000 5850 50  0001 C CNN
F 3 "" H 2000 5850 50  0000 C CNN
	1    2000 7050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 58125247
P 2250 7350
F 0 "#PWR06" H 2250 7200 50  0001 C CNN
F 1 "+5V" H 2250 7490 50  0000 C CNN
F 2 "" H 2250 7350 50  0000 C CNN
F 3 "" H 2250 7350 50  0000 C CNN
	1    2250 7350
	-1   0    0    1   
$EndComp
Wire Wire Line
	2250 6950 2250 7350
Connection ~ 2250 7150
Connection ~ 2250 7050
Wire Wire Line
	1750 6950 1750 6800
Wire Wire Line
	1750 6800 2850 6800
Wire Wire Line
	2150 6550 1700 6550
Wire Wire Line
	1700 6550 1700 7050
Wire Wire Line
	1700 7050 1750 7050
Wire Wire Line
	1400 7150 1750 7150
$Comp
L CONN_01X01 P2
U 1 1 58126797
P 4750 6950
F 0 "P2" H 4750 7050 50  0000 C CNN
F 1 "Wire to Teensy VUSB" V 4850 6950 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01" H 4750 6950 50  0001 C CNN
F 3 "" H 4750 6950 50  0000 C CNN
	1    4750 6950
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR07
U 1 1 581272E3
P 4750 6600
F 0 "#PWR07" H 4750 6450 50  0001 C CNN
F 1 "+5V" H 4750 6740 50  0000 C CNN
F 2 "" H 4750 6600 50  0000 C CNN
F 3 "" H 4750 6600 50  0000 C CNN
	1    4750 6600
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X03 P3
U 1 1 581294B1
P 7050 4400
F 0 "P3" H 7050 4600 50  0000 C CNN
F 1 "+3.3V" H 7050 4200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x03" H 7050 3200 50  0001 C CNN
F 3 "" H 7050 3200 50  0000 C CNN
	1    7050 4400
	0    1    1    0   
$EndComp
Connection ~ 6950 4650
Connection ~ 7050 4650
Wire Wire Line
	4550 4450 4550 3950
Wire Wire Line
	4550 3950 6950 3950
Wire Wire Line
	6950 3950 6950 4150
Wire Wire Line
	6950 4150 7250 4150
Connection ~ 7050 4150
Connection ~ 6950 4150
Wire Wire Line
	5950 4650 7300 4650
Wire Wire Line
	700  3800 700  2500
Wire Wire Line
	700  2500 1400 2500
Wire Wire Line
	3550 2500 3250 2500
Wire Wire Line
	3250 2500 3250 3750
Wire Wire Line
	3250 3750 6350 3750
$Comp
L 74HC4051 U3
U 1 1 57F0E64A
P 4750 3750
F 0 "U3" H 5800 4250 60  0000 C CNN
F 1 "74HC4051" H 5950 4350 60  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 5950 4350 60  0001 C CNN
F 3 "" H 5950 4350 60  0001 C CNN
	1    4750 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2500 5000 2500
Wire Wire Line
	5000 2500 5000 3700
Wire Wire Line
	5000 3700 6550 3700
Wire Wire Line
	6550 3700 6550 4950
Wire Wire Line
	7850 5050 7850 2500
Wire Wire Line
	7850 2500 8100 2500
Wire Wire Line
	8100 2800 8100 3100
Connection ~ 8100 2900
Connection ~ 8100 3000
$Comp
L GND #PWR08
U 1 1 58138476
P 8100 3100
F 0 "#PWR08" H 8100 2850 50  0001 C CNN
F 1 "GND" H 8100 2950 50  0000 C CNN
F 2 "" H 8100 3100 50  0000 C CNN
F 3 "" H 8100 3100 50  0000 C CNN
	1    8100 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 581384B2
P 3550 3100
F 0 "#PWR09" H 3550 2850 50  0001 C CNN
F 1 "GND" H 3550 2950 50  0000 C CNN
F 2 "" H 3550 3100 50  0000 C CNN
F 3 "" H 3550 3100 50  0000 C CNN
	1    3550 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 581384EE
P 5500 3100
F 0 "#PWR010" H 5500 2850 50  0001 C CNN
F 1 "GND" H 5500 2950 50  0000 C CNN
F 2 "" H 5500 3100 50  0000 C CNN
F 3 "" H 5500 3100 50  0000 C CNN
	1    5500 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 58138962
P 1400 3100
F 0 "#PWR011" H 1400 2850 50  0001 C CNN
F 1 "GND" H 1400 2950 50  0000 C CNN
F 2 "" H 1400 3100 50  0000 C CNN
F 3 "" H 1400 3100 50  0000 C CNN
	1    1400 3100
	1    0    0    -1  
$EndComp
Connection ~ 1400 3000
Connection ~ 1400 2900
Connection ~ 3550 2900
Connection ~ 3550 3000
Wire Wire Line
	5500 2800 5500 3100
Connection ~ 5500 2900
Connection ~ 5500 3000
$Comp
L +3.3V #PWR012
U 1 1 58139D77
P 2300 2050
F 0 "#PWR012" H 2300 1900 50  0001 C CNN
F 1 "+3.3V" H 2300 2190 50  0000 C CNN
F 2 "" H 2300 2050 50  0000 C CNN
F 3 "" H 2300 2050 50  0000 C CNN
	1    2300 2050
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR013
U 1 1 5813A24F
P 4250 2050
F 0 "#PWR013" H 4250 1900 50  0001 C CNN
F 1 "+3.3V" H 4250 2190 50  0000 C CNN
F 2 "" H 4250 2050 50  0000 C CNN
F 3 "" H 4250 2050 50  0000 C CNN
	1    4250 2050
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR014
U 1 1 5813A28B
P 6150 2050
F 0 "#PWR014" H 6150 1900 50  0001 C CNN
F 1 "+3.3V" H 6150 2190 50  0000 C CNN
F 2 "" H 6150 2050 50  0000 C CNN
F 3 "" H 6150 2050 50  0000 C CNN
	1    6150 2050
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR015
U 1 1 5813A317
P 8700 2050
F 0 "#PWR015" H 8700 1900 50  0001 C CNN
F 1 "+3.3V" H 8700 2190 50  0000 C CNN
F 2 "" H 8700 2050 50  0000 C CNN
F 3 "" H 8700 2050 50  0000 C CNN
	1    8700 2050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9000 2300 9000 2050
Wire Wire Line
	6400 2300 6400 2050
Wire Wire Line
	4450 2300 4450 2050
Wire Wire Line
	2300 2300 2300 2050
$Comp
L CONN_02X32 P6
U 1 1 5813B5E9
P 4400 850
F 0 "P6" H 4400 2500 50  0000 C CNN
F 1 "BTN 1-32" V 4400 850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x32" H 4400 450 50  0001 C CNN
F 3 "" H 4400 450 50  0000 C CNN
	1    4400 850 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2850 1100 1250 1100
Wire Wire Line
	1250 1100 1250 2300
Wire Wire Line
	1250 2300 1400 2300
Wire Wire Line
	1400 2400 1300 2400
Wire Wire Line
	1300 2400 1300 1150
Wire Wire Line
	1300 1150 2950 1150
Wire Wire Line
	2950 1150 2950 1100
Wire Wire Line
	1400 2600 1350 2600
Wire Wire Line
	1350 2600 1350 1200
Wire Wire Line
	1350 1200 3050 1200
Wire Wire Line
	3050 1200 3050 1100
Wire Wire Line
	1400 2700 1400 2700
Wire Wire Line
	1400 2700 1400 1250
Wire Wire Line
	1400 1250 3150 1250
Wire Wire Line
	3150 1250 3150 1100
Wire Wire Line
	2300 2400 2400 2400
Wire Wire Line
	2400 2400 2400 1500
Wire Wire Line
	2400 1500 3250 1500
Wire Wire Line
	3250 1500 3250 1100
Wire Wire Line
	2300 2500 2450 2500
Wire Wire Line
	2450 2500 2450 1550
Wire Wire Line
	2450 1550 3350 1550
Wire Wire Line
	3350 1550 3350 1100
Wire Wire Line
	2300 2600 2500 2600
Wire Wire Line
	2500 2600 2500 1600
Wire Wire Line
	2500 1600 3450 1600
Wire Wire Line
	3450 1600 3450 1100
Wire Wire Line
	2300 2700 2550 2700
Wire Wire Line
	2550 2700 2550 1650
Wire Wire Line
	2550 1650 3550 1650
Wire Wire Line
	3550 1650 3550 1100
Wire Wire Line
	3300 1700 3650 1700
Wire Wire Line
	3650 1700 3650 1100
Wire Wire Line
	3550 2300 3300 2300
Wire Wire Line
	3300 2300 3300 1700
Wire Wire Line
	3550 2400 3350 2400
Wire Wire Line
	3350 2400 3350 1750
Wire Wire Line
	3350 1750 3750 1750
Wire Wire Line
	3750 1750 3750 1100
Wire Wire Line
	3550 2600 3400 2600
Wire Wire Line
	3400 2600 3400 1800
Wire Wire Line
	3400 1800 3850 1800
Wire Wire Line
	3850 1800 3850 1100
Wire Wire Line
	3550 2700 3450 2700
Wire Wire Line
	3450 2700 3450 1850
Wire Wire Line
	3450 1850 3950 1850
Wire Wire Line
	3950 1850 3950 1100
Wire Wire Line
	4450 2400 4500 2400
Wire Wire Line
	4500 2400 4500 1850
Wire Wire Line
	4500 1850 4050 1850
Wire Wire Line
	4050 1850 4050 1100
Wire Wire Line
	4450 2500 4550 2500
Wire Wire Line
	4550 2500 4550 1800
Wire Wire Line
	4550 1800 4150 1800
Wire Wire Line
	4150 1800 4150 1100
Wire Wire Line
	4450 2600 4600 2600
Wire Wire Line
	4600 2600 4600 1750
Wire Wire Line
	4600 1750 4250 1750
Wire Wire Line
	4250 1750 4250 1100
Wire Wire Line
	4450 2700 4650 2700
Wire Wire Line
	4650 2700 4650 1700
Wire Wire Line
	4650 1700 4350 1700
Wire Wire Line
	4350 1700 4350 1100
Wire Wire Line
	4450 1650 4450 1100
Wire Wire Line
	5500 2300 4700 2300
Wire Wire Line
	4700 2300 4700 1650
Wire Wire Line
	4700 1650 4450 1650
Wire Wire Line
	5500 2400 4750 2400
Wire Wire Line
	4750 2400 4750 1600
Wire Wire Line
	4750 1600 4550 1600
Wire Wire Line
	4550 1600 4550 1100
Wire Wire Line
	5500 2600 4800 2600
Wire Wire Line
	4800 2600 4800 1550
Wire Wire Line
	4800 1550 4650 1550
Wire Wire Line
	4650 1550 4650 1100
Wire Wire Line
	5500 2700 4850 2700
Wire Wire Line
	4850 2700 4850 1500
Wire Wire Line
	4850 1500 4750 1500
Wire Wire Line
	4750 1500 4750 1100
Wire Wire Line
	6400 2400 6450 2400
Wire Wire Line
	6450 2400 6450 1850
Wire Wire Line
	6450 1850 4900 1850
Wire Wire Line
	4900 1850 4900 1450
Wire Wire Line
	4900 1450 4850 1450
Wire Wire Line
	4850 1450 4850 1100
Wire Wire Line
	6400 2500 6500 2500
Wire Wire Line
	6500 2500 6500 1800
Wire Wire Line
	6500 1800 4950 1800
Wire Wire Line
	4950 1800 4950 1100
Wire Wire Line
	6400 2600 6550 2600
Wire Wire Line
	6550 2600 6550 1750
Wire Wire Line
	6550 1750 5050 1750
Wire Wire Line
	5050 1750 5050 1100
Wire Wire Line
	2300 3000 2300 3600
Wire Wire Line
	2300 3600 9000 3600
Wire Wire Line
	9000 3600 9000 3000
Wire Wire Line
	2400 2900 2400 3500
Wire Wire Line
	2400 3500 9100 3500
Wire Wire Line
	9100 3500 9100 2900
Wire Wire Line
	2500 2800 2500 3400
Wire Wire Line
	2500 3400 9200 3400
Wire Wire Line
	9200 3400 9200 2800
Wire Wire Line
	4550 3400 4550 2800
Connection ~ 4550 3400
Wire Wire Line
	4550 2800 4450 2800
$Comp
L 74HC4051 U2
U 1 1 57F0E4CD
P 2800 3750
F 0 "U2" H 3850 4250 60  0000 C CNN
F 1 "74HC4051" H 4000 4350 60  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 4000 4350 60  0001 C CNN
F 3 "" H 4000 4350 60  0001 C CNN
	1    2800 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 3000 4450 3600
Connection ~ 4450 3600
Wire Wire Line
	4500 2900 4450 2900
Wire Wire Line
	4500 3500 4500 2900
Connection ~ 4500 3500
Wire Wire Line
	6400 3000 6400 3600
Connection ~ 6400 3600
Wire Wire Line
	6450 2900 6400 2900
Wire Wire Line
	6400 2800 6500 2800
Wire Wire Line
	6500 2800 6500 3400
Connection ~ 6500 3400
Wire Wire Line
	6450 3500 6450 2900
Connection ~ 6450 3500
Wire Wire Line
	9100 2900 9000 2900
Wire Wire Line
	9200 2800 9000 2800
Wire Wire Line
	2300 2900 2400 2900
Wire Wire Line
	2300 2800 2500 2800
Wire Wire Line
	4450 2050 4250 2050
Wire Wire Line
	6400 2050 6150 2050
Wire Wire Line
	6400 2700 6600 2700
Wire Wire Line
	6600 2700 6600 1700
Wire Wire Line
	6600 1700 5150 1700
Wire Wire Line
	5150 1700 5150 1100
Wire Wire Line
	8100 2300 6700 2300
Wire Wire Line
	6700 2300 6700 1600
Wire Wire Line
	8100 2400 6750 2400
Wire Wire Line
	6750 2400 6750 1550
Wire Wire Line
	6750 1550 5450 1550
Wire Wire Line
	8100 2600 6800 2600
Wire Wire Line
	6800 2600 6800 1500
Wire Wire Line
	6800 1500 5350 1500
Wire Wire Line
	8100 2700 6850 2700
Wire Wire Line
	6850 2700 6850 1450
Wire Wire Line
	9000 2050 8700 2050
Wire Wire Line
	9000 2400 9050 2400
Wire Wire Line
	9050 2400 9050 1400
Wire Wire Line
	9000 2500 9100 2500
Wire Wire Line
	9100 2500 9100 1350
Wire Wire Line
	9000 2600 9150 2600
Wire Wire Line
	9150 2600 9150 1300
Wire Wire Line
	9000 2700 9200 2700
Wire Wire Line
	9200 2700 9200 1250
Wire Wire Line
	3550 2800 3550 3100
$Comp
L GND #PWR016
U 1 1 581440C2
P 2450 600
F 0 "#PWR016" H 2450 350 50  0001 C CNN
F 1 "GND" H 2450 450 50  0000 C CNN
F 2 "" H 2450 600 50  0000 C CNN
F 3 "" H 2450 600 50  0000 C CNN
	1    2450 600 
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 600  5950 600 
Connection ~ 5850 600 
Connection ~ 5750 600 
Connection ~ 5650 600 
Connection ~ 5550 600 
Connection ~ 5450 600 
Connection ~ 5350 600 
Connection ~ 5250 600 
Connection ~ 5150 600 
Connection ~ 5050 600 
Connection ~ 4950 600 
Connection ~ 4850 600 
Connection ~ 4750 600 
Connection ~ 2850 600 
Connection ~ 2950 600 
Connection ~ 3050 600 
Connection ~ 3150 600 
Connection ~ 3250 600 
Connection ~ 3350 600 
Connection ~ 3450 600 
Connection ~ 3550 600 
Connection ~ 3650 600 
Connection ~ 3750 600 
Connection ~ 3850 600 
Connection ~ 3950 600 
Connection ~ 4050 600 
Connection ~ 4150 600 
Connection ~ 4250 600 
Connection ~ 4350 600 
Connection ~ 4450 600 
Connection ~ 4550 600 
Connection ~ 4650 600 
Wire Wire Line
	1400 2800 1400 3100
$Comp
L GND #PWR017
U 1 1 581472AD
P 7250 4150
F 0 "#PWR017" H 7250 3900 50  0001 C CNN
F 1 "GND" H 7250 4000 50  0000 C CNN
F 2 "" H 7250 4150 50  0000 C CNN
F 3 "" H 7250 4150 50  0000 C CNN
	1    7250 4150
	0    -1   -1   0   
$EndComp
Connection ~ 7150 4150
$Comp
L +3.3V #PWR018
U 1 1 58147458
P 7300 4650
F 0 "#PWR018" H 7300 4500 50  0001 C CNN
F 1 "+3.3V" H 7300 4790 50  0000 C CNN
F 2 "" H 7300 4650 50  0000 C CNN
F 3 "" H 7300 4650 50  0000 C CNN
	1    7300 4650
	0    1    1    0   
$EndComp
Connection ~ 7150 4650
Wire Wire Line
	9050 1400 5950 1400
Wire Wire Line
	5950 1400 5950 1100
Wire Wire Line
	9100 1350 5850 1350
Wire Wire Line
	5850 1350 5850 1100
Wire Wire Line
	9150 1300 5750 1300
Wire Wire Line
	5750 1300 5750 1100
Wire Wire Line
	9200 1250 5650 1250
Wire Wire Line
	5650 1250 5650 1100
Wire Wire Line
	6700 1600 5550 1600
Wire Wire Line
	5550 1600 5550 1100
Wire Wire Line
	5450 1550 5450 1100
Wire Wire Line
	5350 1500 5350 1100
Wire Wire Line
	6850 1450 5250 1450
Wire Wire Line
	5250 1450 5250 1100
$Comp
L Q_NPN_CBE Q4
U 1 1 5817D9AB
P 3500 6200
F 0 "Q4" H 3800 6250 50  0000 R CNN
F 1 "NPN" H 3850 6150 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 3700 6300 50  0001 C CNN
F 3 "" H 3500 6200 50  0000 C CNN
	1    3500 6200
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 5817DD3B
P 4100 5950
F 0 "R10" V 4180 5950 50  0000 C CNN
F 1 "100K" V 4100 5950 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 4030 5950 50  0001 C CNN
F 3 "" H 4100 5950 50  0000 C CNN
	1    4100 5950
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 5817DE4E
P 3100 5550
F 0 "R7" V 3180 5550 50  0000 C CNN
F 1 "1K" V 3100 5550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 3030 5550 50  0001 C CNN
F 3 "" H 3100 5550 50  0000 C CNN
	1    3100 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 5950 3950 5950
Wire Wire Line
	3600 5950 3600 6000
Connection ~ 3600 5950
Wire Wire Line
	3100 5950 3100 5700
Wire Wire Line
	3100 6750 3850 6750
$Comp
L R R8
U 1 1 58188FA9
P 3100 6350
F 0 "R8" V 3180 6350 50  0000 C CNN
F 1 "1K" V 3100 6350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 3030 6350 50  0001 C CNN
F 3 "" H 3100 6350 50  0000 C CNN
	1    3100 6350
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P4
U 1 1 58189415
P 3900 7100
F 0 "P4" H 3900 7250 50  0000 C CNN
F 1 "Pit Limiter" V 4000 7100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x02" H 3900 7100 50  0001 C CNN
F 3 "" H 3900 7100 50  0000 C CNN
	1    3900 7100
	0    1    1    0   
$EndComp
Wire Wire Line
	3850 6750 3850 6900
$Comp
L +3.3V #PWR019
U 1 1 5818997F
P 4350 5950
F 0 "#PWR019" H 4350 5800 50  0001 C CNN
F 1 "+3.3V" H 4350 6090 50  0000 C CNN
F 2 "" H 4350 5950 50  0000 C CNN
F 3 "" H 4350 5950 50  0000 C CNN
	1    4350 5950
	0    1    1    0   
$EndComp
Wire Wire Line
	4750 6750 4750 6600
$Comp
L R R9
U 1 1 58189FAC
P 3450 6450
F 0 "R9" V 3530 6450 50  0000 C CNN
F 1 "10K" V 3450 6450 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 3380 6450 50  0001 C CNN
F 3 "" H 3450 6450 50  0000 C CNN
	1    3450 6450
	0    1    1    0   
$EndComp
Wire Wire Line
	3300 6200 3300 6450
Wire Wire Line
	3300 6200 3100 6200
Wire Wire Line
	3100 6500 3100 6750
Connection ~ 3300 6200
Wire Wire Line
	3600 6400 3600 6500
Connection ~ 3600 6450
Wire Wire Line
	3950 6750 3950 6900
Wire Wire Line
	4250 5950 4350 5950
$EndSCHEMATC
