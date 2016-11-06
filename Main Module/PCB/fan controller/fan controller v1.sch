EESchema Schematic File Version 2
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
LIBS:fan controller v1-cache
EELAYER 25 0
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
$Comp
L CONN_01X02 P1
U 1 1 57F24616
P 1550 3450
F 0 "P1" H 1550 3600 50  0000 C CNN
F 1 "AUX" V 1650 3450 50  0000 C CNN
F 2 "MOBB-KiCad-Lib:Screw_Terminal_5mm" H 1550 3450 50  0001 C CNN
F 3 "" H 1550 3450 50  0000 C CNN
	1    1550 3450
	-1   0    0    1   
$EndComp
$Comp
L R 1K1
U 1 1 57F247E8
P 2500 3350
F 0 "1K1" V 2580 3350 50  0000 C CNN
F 1 "1K" V 2500 3350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 2430 3350 50  0001 C CNN
F 3 "" H 2500 3350 50  0000 C CNN
	1    2500 3350
	0    1    1    0   
$EndComp
$Comp
L R 1.4K1
U 1 1 57F248FE
P 3550 2950
F 0 "1.4K1" V 3630 2950 50  0000 C CNN
F 1 "R" V 3550 2950 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 3480 2950 50  0001 C CNN
F 3 "" H 3550 2950 50  0000 C CNN
	1    3550 2950
	1    0    0    -1  
$EndComp
$Comp
L R 1K2
U 1 1 57F249B1
P 3800 3100
F 0 "1K2" V 3880 3100 50  0000 C CNN
F 1 "R" V 3800 3100 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 3730 3100 50  0001 C CNN
F 3 "" H 3800 3100 50  0000 C CNN
	1    3800 3100
	0    1    1    0   
$EndComp
$Comp
L Q_NPN_CBE Q1
U 1 1 57F24B04
P 4350 3600
F 0 "Q1" H 4650 3650 50  0000 R CNN
F 1 "NPN" H 4700 3500 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 4550 3700 50  0001 C CNN
F 3 "" H 4350 3600 50  0000 C CNN
	1    4350 3600
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P2
U 1 1 57F24C78
P 3750 1850
F 0 "P2" H 3750 2000 50  0000 C CNN
F 1 "+12V Suppply" V 3850 1850 50  0000 C CNN
F 2 "MOBB-KiCad-Lib:Screw_Terminal_5mm" H 3750 1850 50  0001 C CNN
F 3 "" H 3750 1850 50  0000 C CNN
	1    3750 1850
	0    -1   -1   0   
$EndComp
$Comp
L R 10K1
U 1 1 57F24F38
P 4100 3750
F 0 "10K1" V 4180 3750 50  0000 C CNN
F 1 "R" V 4100 3750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 4030 3750 50  0001 C CNN
F 3 "" H 4100 3750 50  0000 C CNN
	1    4100 3750
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR01
U 1 1 581A5A6C
P 1750 3250
F 0 "#PWR01" H 1750 3100 50  0001 C CNN
F 1 "+5V" H 1750 3390 50  0000 C CNN
F 2 "" H 1750 3250 50  0000 C CNN
F 3 "" H 1750 3250 50  0000 C CNN
	1    1750 3250
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR02
U 1 1 581A5A92
P 1750 3600
F 0 "#PWR02" H 1750 3350 50  0001 C CNN
F 1 "GNDA" H 1750 3450 50  0000 C CNN
F 2 "" H 1750 3600 50  0000 C CNN
F 3 "" H 1750 3600 50  0000 C CNN
	1    1750 3600
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR03
U 1 1 581A5D1A
P 3450 2050
F 0 "#PWR03" H 3450 1900 50  0001 C CNN
F 1 "+12V" H 3450 2190 50  0000 C CNN
F 2 "" H 3450 2050 50  0000 C CNN
F 3 "" H 3450 2050 50  0000 C CNN
	1    3450 2050
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR04
U 1 1 581A5D64
P 4050 2050
F 0 "#PWR04" H 4050 1800 50  0001 C CNN
F 1 "GND" H 4050 1900 50  0000 C CNN
F 2 "" H 4050 2050 50  0000 C CNN
F 3 "" H 4050 2050 50  0000 C CNN
	1    4050 2050
	0    -1   -1   0   
$EndComp
$Comp
L TLP785 U1
U 1 1 581A6379
P 3100 3450
F 0 "U1" H 2900 3650 50  0000 L CNN
F 1 "Octocoupler" H 2900 3200 50  0000 L CNN
F 2 "Housings_DIP:DIP-4_W7.62mm_LongPads" H 2900 3250 50  0000 L CIN
F 3 "" H 3100 3450 50  0000 L CNN
	1    3100 3450
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P3
U 1 1 581A85A6
P 5000 2700
F 0 "P3" H 5000 2900 50  0000 C CNN
F 1 "Fan" V 5100 2700 50  0000 C CNN
F 2 "MOBB-KiCad-Lib:Molex-KK-1x3P" H 5000 2700 50  0001 C CNN
F 3 "" H 5000 2700 50  0000 C CNN
	1    5000 2700
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P4
U 1 1 581B96A9
P 5550 2700
F 0 "P4" H 5550 2900 50  0000 C CNN
F 1 "Fan" V 5650 2700 50  0000 C CNN
F 2 "MOBB-KiCad-Lib:Molex-KK-1x3P" H 5550 2700 50  0001 C CNN
F 3 "" H 5550 2700 50  0000 C CNN
	1    5550 2700
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 581F2CCC
P 5400 3300
F 0 "R1" V 5480 3300 50  0000 C CNN
F 1 "1.5K" V 5400 3300 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 5330 3300 50  0001 C CNN
F 3 "" H 5400 3300 50  0000 C CNN
	1    5400 3300
	0    1    1    0   
$EndComp
$Comp
L LED D1
U 1 1 581F2E6E
P 5600 3500
F 0 "D1" H 5600 3600 50  0000 C CNN
F 1 "LED" H 5600 3400 50  0000 C CNN
F 2 "LEDs:LED-3MM" H 5600 3500 50  0001 C CNN
F 3 "" H 5600 3500 50  0000 C CNN
	1    5600 3500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2650 3350 2800 3350
Wire Wire Line
	3400 3100 3650 3100
Wire Wire Line
	3400 3100 3400 3350
Wire Wire Line
	3950 2050 3950 3900
Wire Wire Line
	3400 3600 4150 3600
Wire Wire Line
	3400 3600 3400 3550
Connection ~ 4100 3600
Connection ~ 3950 3100
Wire Wire Line
	4450 3900 4450 3800
Connection ~ 4100 3900
Wire Wire Line
	1750 3500 1750 3600
Wire Wire Line
	1750 3250 1750 3400
Wire Wire Line
	3450 2050 3700 2050
Wire Wire Line
	3800 2050 4050 2050
Connection ~ 3550 2050
Connection ~ 3950 2050
Wire Wire Line
	2800 3550 1750 3550
Connection ~ 1750 3550
Wire Wire Line
	2350 3350 1750 3350
Connection ~ 1750 3350
Connection ~ 3550 3100
Connection ~ 3450 2050
Connection ~ 4050 2050
Connection ~ 1750 3250
Connection ~ 1750 3600
Wire Wire Line
	3550 2050 3550 2800
Wire Wire Line
	3550 2700 5350 2700
Connection ~ 3550 2700
Wire Wire Line
	4450 2600 5350 2600
Connection ~ 4800 2600
Connection ~ 4800 2700
Wire Wire Line
	5600 3900 5600 3700
Wire Wire Line
	5600 3300 5550 3300
$Comp
L CONN_01X02 P5
U 1 1 581F3210
P 4950 3100
F 0 "P5" H 4950 3250 50  0000 C CNN
F 1 "Jumper" V 5050 3100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 4950 3100 50  0001 C CNN
F 3 "" H 4950 3100 50  0000 C CNN
	1    4950 3100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5250 3300 5000 3300
Wire Wire Line
	4900 3300 4900 3450
Wire Wire Line
	4900 3450 5000 3450
Wire Wire Line
	5000 3450 5000 3300
Wire Wire Line
	3950 3900 4450 3900
Wire Wire Line
	4900 3300 4650 3300
Wire Wire Line
	4650 3300 4650 2450
Wire Wire Line
	4650 2450 3550 2450
Connection ~ 3550 2450
Wire Wire Line
	4450 3400 4450 2600
Wire Wire Line
	5600 3900 4750 3900
Wire Wire Line
	4750 3900 4750 3350
Wire Wire Line
	4750 3350 4450 3350
Connection ~ 4450 3350
Text Notes 4850 3650 0    60   ~ 0
Cut to \nuse jumper
$EndSCHEMATC
