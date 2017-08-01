

Imports System
Imports System.IO.Ports

Public Class frm_com_test
    Dim comPORT As String
    Dim receivedData As String = ""
    Dim arduinoReady As Boolean = False


    Private Sub frm_com_test_Load(sender As Object, e As EventArgs) Handles Me.Load
        comPORT = ""
        For Each sp As String In My.Computer.Ports.SerialPortNames
            cmb_ports.Items.Add(sp)
        Next

        'load stored settings into text boxes
        KeyboardSettings.load()

    End Sub

    Private Sub cmb_ports_SelectedIndexChanged(sender As Object, e As EventArgs) Handles cmb_ports.SelectedIndexChanged
        If (cmb_ports.SelectedItem <> "") Then
            comPORT = cmb_ports.SelectedItem
        End If
    End Sub

    Private Sub btn_connect_Click(sender As Object, e As EventArgs) Handles btn_connect.Click
        If (btn_connect.Text = "Connect") Then
            If (comPORT <> "") Then
                SerialPort1.Close()
                SerialPort1.PortName = comPORT
                SerialPort1.BaudRate = 115200
                SerialPort1.DataBits = 8
                SerialPort1.Parity = Parity.None
                SerialPort1.StopBits = StopBits.One
                SerialPort1.Handshake = Handshake.None
                SerialPort1.Encoding = System.Text.Encoding.Default
                SerialPort1.ReadTimeout = 10000

                AddHandler SerialPort1.DataReceived, AddressOf DataReceivedHandler

                SerialPort1.Open()
                SerialPort1.DiscardInBuffer()
                SerialPort1.Write("wr-rdy" + vbLf)
                btn_connect.Text = "Dis-connect"
            Else
                MsgBox("Select a COM port first")
            End If
        Else
            btn_connect.Text = "Connect"
            SerialPort1.Write("wr-stop" + vbLf)
        End If
    End Sub

    Private Sub DataReceivedHandler(
                        sender As Object,
                        e As SerialDataReceivedEventArgs)
        Dim sp As SerialPort = CType(sender, SerialPort)
        Dim indata As String = ""
        Try
            indata = sp.ReadLine()
        Catch ex As Exception
            Console.WriteLine("Error reading serial:" + ex.ToString)
        End Try

        'Dim indata As String = sp.ReadExisting()

        DataProcess(indata)
        AppendTextBox(txt_data, indata + vbCrLf)
        'Console.WriteLine("Data Received:" + indata)
    End Sub

    Private Sub DataProcess(ByVal data As String)
        ' does something with the serial data from the arduino
        Dim strip = Trim(data.Replace(vbCr, "").Replace(vbLf, ""))

        If strip = "" Then
            Console.WriteLine("empty")
            Exit Sub
        End If

        Dim btn_press = strip.Substring(1)
        Dim btn_type = strip.Substring(0, 1)
        Console.WriteLine("btn:" + btn_press)
        Console.WriteLine("enabled:" + arduinoReady.ToString)
        If btn_type = "B" Then
            'buttons
            Dim btn As Integer = Convert.ToInt32(strip.Substring(1))
            Console.WriteLine("Button pressed:" + btn.ToString)
            SendKeys.SendWait(My.Settings.Item("B" + btn.ToString).ToString)
            Exit Sub
        ElseIf btn_type = "J" Then
            'joystick
            Dim btn As Integer = Convert.ToInt32(strip.Substring(1))
            Console.WriteLine("Joystick moved:" + btn.ToString)
            SendKeys.SendWait(My.Settings.Item("J" + btn.ToString).ToString)
            Exit Sub
        End If

        If strip = "nano rdy" Then
            arduinoReady = True
            Exit Sub
        ElseIf strip = "nano stop" Then
            SerialPort1.DiscardOutBuffer()
            SerialPort1.DiscardInBuffer()
            SerialPort1.Close()
            arduinoReady = False
            Exit Sub
        End If
    End Sub


    Private Delegate Sub AppendTextBoxDelegate(ByVal TB As TextBox, ByVal txt As String)
    Private Sub AppendTextBox(ByVal TB As TextBox, ByVal txt As String)
        If TB.InvokeRequired Then
            TB.Invoke(New AppendTextBoxDelegate(AddressOf AppendTextBox), New Object() {TB, txt})
        Else
            TB.AppendText(txt)
        End If
    End Sub



    Function ReceiveSerialData() As String
        Dim Incoming As String
        Try
            Incoming = SerialPort1.ReadExisting()
            If Incoming Is Nothing Then
                Return Nothing
            Else
                Return Incoming
            End If
        Catch ex As TimeoutException
            Return "Error: Serial Port read timed out."
        End Try

    End Function

    Private Sub btn_clear_Click(sender As Object, e As EventArgs) Handles btn_clear.Click
        txt_data.Text = ""
    End Sub

    Private Sub btn_apply_Click(sender As Object, e As EventArgs) Handles btn_apply.Click
        KeyboardSettings.store()
    End Sub
End Class
