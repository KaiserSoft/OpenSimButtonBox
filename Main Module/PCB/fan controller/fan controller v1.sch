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
L CONN_01X02 P?
U 1 1 57F24616
P 1850 3400
F 0 "P?" H 1850 3550 50  0000 C CNN
F 1 "AUX1-3" V 1950 3400 50  0000 C CNN
F 2 "" H 1850 3400 50  0000 C CNN
F 3 "" H 1850 3400 50  0000 C CNN
	1    1850 3400
	-1   0    0    1   
$EndComp
$Comp
L OPTO-TRANSISTOR-4 U?
U 1 1 57F2479B
P 3100 3450
F 0 "U?" H 2900 3650 50  0000 L CNN
F 1 "OPTO-TRANSISTOR-4" H 2900 3250 50  0000 L CNN
F 2 "" H 2900 3250 50  0000 L CIN
F 3 "" H 3100 3450 50  0000 L CNN
	1    3100 3450
	1    0    0    -1  
$EndComp
$Comp
L R 1K
U 1 1 57F247E8
P 2500 3350
F 0 "1K" V 2580 3350 50  0000 C CNN
F 1 "R" V 2500 3350 50  0000 C CNN
F 2 "" V 2430 3350 50  0000 C CNN
F 3 "" H 2500 3350 50  0000 C CNN
	1    2500 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 3350 2350 3350
Wire Wire Line
	2650 3350 2800 3350
Wire Wire Line
	2050 3550 2800 3550
$Comp
L R 1.4K
U 1 1 57F248FE
P 3550 2950
F 0 "1.4K" V 3630 2950 50  0000 C CNN
F 1 "R" V 3550 2950 50  0000 C CNN
F 2 "" V 3480 2950 50  0000 C CNN
F 3 "" H 3550 2950 50  0000 C CNN
	1    3550 2950
	1    0    0    -1  
$EndComp
$Comp
L R 1K
U 1 1 57F249B1
P 3800 3100
F 0 "1K" V 3880 3100 50  0000 C CNN
F 1 "R" V 3800 3100 50  0000 C CNN
F 2 "" V 3730 3100 50  0000 C CNN
F 3 "" H 3800 3100 50  0000 C CNN
	1    3800 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	3550 2500 3550 2800
Wire Wire Line
	3400 3100 3650 3100
Wire Wire Line
	3400 3100 3400 3350
$Comp
L Q_NPN_CBE Q?
U 1 1 57F24B04
P 4350 3600
F 0 "Q?" H 4650 3650 50  0000 R CNN
F 1 "Q_NPN_CBE" H 4950 3550 50  0000 R CNN
F 2 "" H 4550 3700 50  0000 C CNN
F 3 "" H 4350 3600 50  0000 C CNN
	1    4350 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2700 4400 2700
Connection ~ 3550 2700
$Comp
L CONN_01X02 P?
U 1 1 57F24BA5
P 4600 2750
F 0 "P?" H 4600 2900 50  0000 C CNN
F 1 "FAN Connector" V 4700 2750 50  0000 C CNN
F 2 "" H 4600 2750 50  0000 C CNN
F 3 "" H 4600 2750 50  0000 C CNN
	1    4600 2750
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P?
U 1 1 57F24C78
P 3600 2300
F 0 "P?" H 3600 2450 50  0000 C CNN
F 1 "+12V Suppply" V 3700 2300 50  0000 C CNN
F 2 "" H 3600 2300 50  0000 C CNN
F 3 "" H 3600 2300 50  0000 C CNN
	1    3600 2300
	0    -1   -1   0   
$EndComp
Text Label 3550 2700 1    60   ~ 0
+12V
Wire Wire Line
	3650 2500 3950 2500
Wire Wire Line
	3950 2500 3950 3900
Text Label 3700 2500 0    60   ~ 0
GND
Text Label 4450 3000 1    60   ~ 0
GND
Text Label 4200 2700 0    60   ~ 0
+12V
Text Label 2100 3550 0    60   ~ 0
GND
Wire Wire Line
	2050 3450 2050 3550
Text Label 2100 3350 0    60   ~ 0
+5V
$Comp
L R 10K
U 1 1 57F24F38
P 4100 3750
F 0 "10K" V 4180 3750 50  0000 C CNN
F 1 "R" V 4100 3750 50  0000 C CNN
F 2 "" V 4030 3750 50  0000 C CNN
F 3 "" H 4100 3750 50  0000 C CNN
	1    4100 3750
	-1   0    0    1   
$EndComp
Wire Wire Line
	3400 3600 4150 3600
Wire Wire Line
	3400 3600 3400 3550
Connection ~ 4100 3600
Wire Wire Line
	3950 3900 4450 3900
Connection ~ 3950 3100
Wire Wire Line
	4450 3900 4450 3800
Connection ~ 4100 3900
Wire Wire Line
	4450 3400 4450 2800
Wire Wire Line
	4450 2800 4400 2800
$EndSCHEMATC
