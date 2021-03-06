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
L CONN_01X03 P4
U 1 1 5835809A
P 10300 5550
F 0 "P4" H 10300 5750 50  0000 C CNN
F 1 "AUX3" V 10400 5550 50  0000 C CNN
F 2 "MOBB-KiCad-Lib:Molex-KK-1x3P" H 10300 5550 50  0001 C CNN
F 3 "" H 10300 5550 50  0000 C CNN
	1    10300 5550
	0    1    1    0   
$EndComp
$Comp
L CONN_01X03 P3
U 1 1 583580FD
P 9650 5550
F 0 "P3" H 9650 5750 50  0000 C CNN
F 1 "AUX2" V 9750 5550 50  0000 C CNN
F 2 "MOBB-KiCad-Lib:Molex-KK-1x3P" H 9650 5550 50  0001 C CNN
F 3 "" H 9650 5550 50  0000 C CNN
	1    9650 5550
	0    1    1    0   
$EndComp
$Comp
L CONN_01X03 P1
U 1 1 5835813A
P 9000 5550
F 0 "P1" H 9000 5750 50  0000 C CNN
F 1 "AUX1" V 9100 5550 50  0000 C CNN
F 2 "MOBB-KiCad-Lib:Molex-KK-1x3P" H 9000 5550 50  0001 C CNN
F 3 "" H 9000 5550 50  0000 C CNN
	1    9000 5550
	0    1    1    0   
$EndComp
$Comp
L CONN_02X03 P2
U 1 1 583581DC
P 9650 4700
F 0 "P2" H 9650 4900 50  0000 C CNN
F 1 "Aux1-3" H 9650 4500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x03" H 9650 3500 50  0001 C CNN
F 3 "" H 9650 3500 50  0000 C CNN
	1    9650 4700
	0    1    1    0   
$EndComp
Wire Wire Line
	9000 5350 9000 5100
Wire Wire Line
	9000 5100 9550 5100
Wire Wire Line
	9550 5100 9550 4950
Wire Wire Line
	9650 5350 9650 4950
Wire Wire Line
	10300 5350 10300 5100
Wire Wire Line
	10300 5100 9750 5100
Wire Wire Line
	9750 5100 9750 4950
Text Label 9650 5000 3    60   ~ 0
+5V
Wire Wire Line
	10400 5350 10400 4250
Wire Wire Line
	10400 4250 9750 4250
Wire Wire Line
	9750 4250 9750 4450
Wire Wire Line
	9750 5350 9750 5300
Wire Wire Line
	9750 5300 9950 5300
Wire Wire Line
	9950 5300 9950 4350
Wire Wire Line
	9950 4350 9650 4350
Wire Wire Line
	9650 4350 9650 4450
Wire Wire Line
	9100 5350 9100 4250
Wire Wire Line
	9100 4250 9550 4250
Wire Wire Line
	9550 4250 9550 4450
$EndSCHEMATC
