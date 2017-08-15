

Imports System.ComponentModel
Imports System.IO.Ports
Imports System.Threading

Public Class frm_com_test
    Dim comPORT As String
    Dim receivedData As String = ""
    Dim arduinoReady As Boolean = False


    Private Sub frm_com_test_Load(sender As Object, e As EventArgs) Handles Me.Load
        comPORT = ""
        lblFeedback.Text = ""
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
                SerialPort1.Write("wr" + vbLf)
                btn_connect.Text = "Disconnect"
            Else
                MsgBox("Please select a COM port first")
                UpdateLabel(lblFeedback, "Connection established!")
            End If
        Else
            btn_connect.Text = "Connect"
            SerialPort1.Write("ws" + vbLf)
        End If
    End Sub

    Private Sub DataReceivedHandler(
                        sender As Object,
                        e As SerialDataReceivedEventArgs)
        Dim sp As SerialPort = CType(sender, SerialPort)
        Dim indata As String = ""
        Try
            indata = sp.ReadLine()
            'indata = sp.ReadExisting()
        Catch ex As Exception
            Console.WriteLine("Error reading serial:" + ex.ToString)
        End Try



        DataProcess(indata)
        AppendTextBox(txt_data, indata + vbCrLf)
        'Console.WriteLine("Data Received:" + indata)
    End Sub

    Private Sub DataProcess(ByVal data As String)
        ' does something with the serial data from the arduino
        Dim strip = Trim(data.Replace(vbCr, "").Replace(vbLf, ""))

        If strip = "" Then
            Console.WriteLine("Received empty string over serial!")
            Exit Sub
        End If

        Dim btn_press = strip.Substring(1)
        Dim btn_type = strip.Substring(0, 1)

        If arduinoReady = True And btn_type = "B" Then
            'buttons
            Dim btn As Integer = Convert.ToInt32(strip.Substring(1))
            Console.WriteLine("Button pressed:" + btn.ToString)
            If chkKeyboardEnable.Checked = True Then
                SendKeys.SendWait(My.Settings.Item("B" + btn.ToString).ToString)
            End If
            Exit Sub
        ElseIf arduinoReady = True And btn_type = "J" Then
            'joystick
            Dim btn As Integer = Convert.ToInt32(strip.Substring(1))
            Console.WriteLine("Joystick moved:" + btn.ToString)
            If chkKeyboardEnable.Checked = True Then
                SendKeys.SendWait(My.Settings.Item("J" + btn.ToString).ToString)
            End If
            Exit Sub

        ElseIf arduinoReady = True And btn_type = "K" Then
            'joystick - quick hack for other direction
            Dim btn As Integer = Convert.ToInt32(strip.Substring(1))
            Console.WriteLine("Joystick moved:" + btn.ToString)
            If chkKeyboardEnable.Checked = True Then
                SendKeys.SendWait(My.Settings.Item("K" + btn.ToString).ToString)
            End If
            Exit Sub
        End If

        Console.WriteLine(strip)
        If strip = "nr" Then
            arduinoReady = True
            Exit Sub
        ElseIf strip = "ns" Then
            SerialPort1.DiscardOutBuffer()
            SerialPort1.DiscardInBuffer()
            SerialPort1.Close()
            arduinoReady = False
            Exit Sub
        End If
    End Sub



    Private Delegate Sub UpdateLabelDelegate(ByVal LB As Label, ByVal txt As String)
    Private Sub UpdateLabel(ByVal LB As Label, ByVal txt As String)
        Try
            If LB.InvokeRequired Then
                LB.Invoke(New UpdateLabelDelegate(AddressOf UpdateLabel), New Object() {LB, txt})
            Else
                LB.Text = txt
            End If
        Catch ex As Exception
            Console.WriteLine("ERROR during lbl Update" + ex.ToString)
        End Try
    End Sub

    Private Delegate Sub AppendTextBoxDelegate(ByVal TB As TextBox, ByVal txt As String)
    Private Sub AppendTextBox(ByVal TB As TextBox, ByVal txt As String)
        Try
            If TB.InvokeRequired Then
                TB.Invoke(New AppendTextBoxDelegate(AddressOf AppendTextBox), New Object() {TB, txt})
            Else
                TB.AppendText(txt)
            End If
        Catch ex As Exception

        End Try
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
        Try
            KeyboardSettings.store()
            lblFeedback.Text = "Settings Stored"
        Catch ex As Exception
            lblFeedback.Text = "Erro storing new settings"
            MsgBox("Error: " + ex.ToString, vbExclamation)
        End Try

        tmrClearFeedback.Start()
    End Sub

    Private Sub frm_com_test_Closing(sender As Object, e As CancelEventArgs) Handles Me.Closing
        If SerialPort1.IsOpen Then
            RemoveHandler SerialPort1.DataReceived, AddressOf DataReceivedHandler
            SerialPort1.Write("ws" + vbLf)
        End If
    End Sub

    Private Sub tmrClearFeedback_Tick(sender As Object, e As EventArgs) Handles tmrClearFeedback.Tick
        lblFeedback.Text = ""
        tmrClearFeedback.Stop()
    End Sub

    Private Sub btnExit_Click(sender As Object, e As EventArgs) Handles btnExit.Click
        Me.Close()
    End Sub
End Class
