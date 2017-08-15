<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class frm_com_test
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.cmb_ports = New System.Windows.Forms.ComboBox()
        Me.btn_connect = New System.Windows.Forms.Button()
        Me.txt_data = New System.Windows.Forms.TextBox()
        Me.btn_clear = New System.Windows.Forms.Button()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.Label11 = New System.Windows.Forms.Label()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.Label13 = New System.Windows.Forms.Label()
        Me.txt_btn1 = New System.Windows.Forms.TextBox()
        Me.txt_btn2 = New System.Windows.Forms.TextBox()
        Me.txt_btn3 = New System.Windows.Forms.TextBox()
        Me.txt_btn4 = New System.Windows.Forms.TextBox()
        Me.txt_btn5 = New System.Windows.Forms.TextBox()
        Me.txt_btn6 = New System.Windows.Forms.TextBox()
        Me.txt_btn7 = New System.Windows.Forms.TextBox()
        Me.txt_btn8 = New System.Windows.Forms.TextBox()
        Me.txt_btn9 = New System.Windows.Forms.TextBox()
        Me.txt_btn10 = New System.Windows.Forms.TextBox()
        Me.txt_btn11 = New System.Windows.Forms.TextBox()
        Me.txt_joy1 = New System.Windows.Forms.TextBox()
        Me.txt_joy2 = New System.Windows.Forms.TextBox()
        Me.btn_apply = New System.Windows.Forms.Button()
        Me.chkKeyboardEnable = New System.Windows.Forms.CheckBox()
        Me.lblFeedback = New System.Windows.Forms.Label()
        Me.tmrClearFeedback = New System.Windows.Forms.Timer(Me.components)
        Me.btnExit = New System.Windows.Forms.Button()
        Me.Label14 = New System.Windows.Forms.Label()
        Me.Label15 = New System.Windows.Forms.Label()
        Me.txt_btn12 = New System.Windows.Forms.TextBox()
        Me.txt_btn13 = New System.Windows.Forms.TextBox()
        Me.txt_joy1k = New System.Windows.Forms.TextBox()
        Me.txt_joy2k = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'cmb_ports
        '
        Me.cmb_ports.FormattingEnabled = True
        Me.cmb_ports.Location = New System.Drawing.Point(11, 10)
        Me.cmb_ports.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.cmb_ports.Name = "cmb_ports"
        Me.cmb_ports.Size = New System.Drawing.Size(180, 28)
        Me.cmb_ports.TabIndex = 0
        Me.cmb_ports.TabStop = False
        '
        'btn_connect
        '
        Me.btn_connect.Location = New System.Drawing.Point(214, 6)
        Me.btn_connect.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.btn_connect.Name = "btn_connect"
        Me.btn_connect.Size = New System.Drawing.Size(112, 35)
        Me.btn_connect.TabIndex = 1
        Me.btn_connect.TabStop = False
        Me.btn_connect.Text = "Connect"
        Me.btn_connect.UseVisualStyleBackColor = True
        '
        'txt_data
        '
        Me.txt_data.Location = New System.Drawing.Point(380, 10)
        Me.txt_data.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.txt_data.Multiline = True
        Me.txt_data.Name = "txt_data"
        Me.txt_data.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.txt_data.Size = New System.Drawing.Size(125, 343)
        Me.txt_data.TabIndex = 3
        Me.txt_data.TabStop = False
        '
        'btn_clear
        '
        Me.btn_clear.Location = New System.Drawing.Point(379, 389)
        Me.btn_clear.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.btn_clear.Name = "btn_clear"
        Me.btn_clear.Size = New System.Drawing.Size(125, 35)
        Me.btn_clear.TabIndex = 4
        Me.btn_clear.TabStop = False
        Me.btn_clear.Text = "Clear"
        Me.btn_clear.UseVisualStyleBackColor = True
        '
        'SerialPort1
        '
        Me.SerialPort1.BaudRate = 115200
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(11, 90)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(74, 20)
        Me.Label1.TabIndex = 5
        Me.Label1.Text = "Button  1"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(203, 90)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(74, 20)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "Button  2"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(11, 122)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(74, 20)
        Me.Label3.TabIndex = 7
        Me.Label3.Text = "Button  3"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(203, 122)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(74, 20)
        Me.Label4.TabIndex = 8
        Me.Label4.Text = "Button  4"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(11, 154)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(74, 20)
        Me.Label5.TabIndex = 9
        Me.Label5.Text = "Button  5"
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(203, 154)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(74, 20)
        Me.Label6.TabIndex = 10
        Me.Label6.Text = "Button  6"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(11, 186)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(74, 20)
        Me.Label7.TabIndex = 11
        Me.Label7.Text = "Button  7"
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Location = New System.Drawing.Point(203, 186)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(74, 20)
        Me.Label8.TabIndex = 12
        Me.Label8.Text = "Button  8"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Location = New System.Drawing.Point(11, 218)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(74, 20)
        Me.Label9.TabIndex = 13
        Me.Label9.Text = "Button  9"
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Location = New System.Drawing.Point(203, 218)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(79, 20)
        Me.Label10.TabIndex = 14
        Me.Label10.Text = "Button 10"
        '
        'Label11
        '
        Me.Label11.AutoSize = True
        Me.Label11.Location = New System.Drawing.Point(11, 250)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(79, 20)
        Me.Label11.TabIndex = 15
        Me.Label11.Text = "Button 11"
        '
        'Label12
        '
        Me.Label12.AutoSize = True
        Me.Label12.Location = New System.Drawing.Point(11, 314)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(82, 20)
        Me.Label12.TabIndex = 16
        Me.Label12.Text = "Joystick  1"
        '
        'Label13
        '
        Me.Label13.AutoSize = True
        Me.Label13.Location = New System.Drawing.Point(203, 314)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(78, 20)
        Me.Label13.TabIndex = 17
        Me.Label13.Text = "Joystick 2"
        '
        'txt_btn1
        '
        Me.txt_btn1.Location = New System.Drawing.Point(108, 87)
        Me.txt_btn1.MaxLength = 1
        Me.txt_btn1.Name = "txt_btn1"
        Me.txt_btn1.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn1.TabIndex = 1
        Me.txt_btn1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn2
        '
        Me.txt_btn2.Location = New System.Drawing.Point(290, 87)
        Me.txt_btn2.MaxLength = 1
        Me.txt_btn2.Name = "txt_btn2"
        Me.txt_btn2.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn2.TabIndex = 2
        Me.txt_btn2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn3
        '
        Me.txt_btn3.Location = New System.Drawing.Point(108, 119)
        Me.txt_btn3.MaxLength = 1
        Me.txt_btn3.Name = "txt_btn3"
        Me.txt_btn3.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn3.TabIndex = 3
        Me.txt_btn3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn4
        '
        Me.txt_btn4.Location = New System.Drawing.Point(290, 119)
        Me.txt_btn4.MaxLength = 1
        Me.txt_btn4.Name = "txt_btn4"
        Me.txt_btn4.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn4.TabIndex = 4
        Me.txt_btn4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn5
        '
        Me.txt_btn5.Location = New System.Drawing.Point(108, 151)
        Me.txt_btn5.MaxLength = 1
        Me.txt_btn5.Name = "txt_btn5"
        Me.txt_btn5.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn5.TabIndex = 5
        Me.txt_btn5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn6
        '
        Me.txt_btn6.Location = New System.Drawing.Point(290, 151)
        Me.txt_btn6.MaxLength = 1
        Me.txt_btn6.Name = "txt_btn6"
        Me.txt_btn6.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn6.TabIndex = 6
        Me.txt_btn6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn7
        '
        Me.txt_btn7.Location = New System.Drawing.Point(108, 183)
        Me.txt_btn7.MaxLength = 1
        Me.txt_btn7.Name = "txt_btn7"
        Me.txt_btn7.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn7.TabIndex = 7
        Me.txt_btn7.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn8
        '
        Me.txt_btn8.Location = New System.Drawing.Point(290, 183)
        Me.txt_btn8.MaxLength = 1
        Me.txt_btn8.Name = "txt_btn8"
        Me.txt_btn8.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn8.TabIndex = 8
        Me.txt_btn8.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn9
        '
        Me.txt_btn9.Location = New System.Drawing.Point(108, 215)
        Me.txt_btn9.MaxLength = 1
        Me.txt_btn9.Name = "txt_btn9"
        Me.txt_btn9.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn9.TabIndex = 9
        Me.txt_btn9.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn10
        '
        Me.txt_btn10.Location = New System.Drawing.Point(290, 215)
        Me.txt_btn10.MaxLength = 1
        Me.txt_btn10.Name = "txt_btn10"
        Me.txt_btn10.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn10.TabIndex = 10
        Me.txt_btn10.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn11
        '
        Me.txt_btn11.Location = New System.Drawing.Point(108, 247)
        Me.txt_btn11.MaxLength = 1
        Me.txt_btn11.Name = "txt_btn11"
        Me.txt_btn11.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn11.TabIndex = 11
        Me.txt_btn11.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_joy1
        '
        Me.txt_joy1.Location = New System.Drawing.Point(108, 311)
        Me.txt_joy1.MaxLength = 1
        Me.txt_joy1.Name = "txt_joy1"
        Me.txt_joy1.Size = New System.Drawing.Size(36, 26)
        Me.txt_joy1.TabIndex = 15
        Me.txt_joy1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_joy2
        '
        Me.txt_joy2.Location = New System.Drawing.Point(290, 311)
        Me.txt_joy2.MaxLength = 1
        Me.txt_joy2.Name = "txt_joy2"
        Me.txt_joy2.Size = New System.Drawing.Size(36, 26)
        Me.txt_joy2.TabIndex = 16
        Me.txt_joy2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'btn_apply
        '
        Me.btn_apply.Location = New System.Drawing.Point(15, 389)
        Me.btn_apply.Name = "btn_apply"
        Me.btn_apply.Size = New System.Drawing.Size(125, 35)
        Me.btn_apply.TabIndex = 17
        Me.btn_apply.Text = "Apply"
        Me.btn_apply.UseVisualStyleBackColor = True
        '
        'chkKeyboardEnable
        '
        Me.chkKeyboardEnable.AutoSize = True
        Me.chkKeyboardEnable.Location = New System.Drawing.Point(11, 50)
        Me.chkKeyboardEnable.Name = "chkKeyboardEnable"
        Me.chkKeyboardEnable.Size = New System.Drawing.Size(156, 24)
        Me.chkKeyboardEnable.TabIndex = 32
        Me.chkKeyboardEnable.TabStop = False
        Me.chkKeyboardEnable.Text = "Enable Keyboard"
        Me.chkKeyboardEnable.UseVisualStyleBackColor = True
        '
        'lblFeedback
        '
        Me.lblFeedback.AutoSize = True
        Me.lblFeedback.Font = New System.Drawing.Font("Microsoft Sans Serif", 10.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblFeedback.Location = New System.Drawing.Point(10, 351)
        Me.lblFeedback.Name = "lblFeedback"
        Me.lblFeedback.Size = New System.Drawing.Size(100, 25)
        Me.lblFeedback.TabIndex = 33
        Me.lblFeedback.Text = "feedback"
        '
        'tmrClearFeedback
        '
        Me.tmrClearFeedback.Interval = 5000
        '
        'btnExit
        '
        Me.btnExit.Location = New System.Drawing.Point(197, 389)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(125, 35)
        Me.btnExit.TabIndex = 34
        Me.btnExit.TabStop = False
        Me.btnExit.Text = "Exit"
        Me.btnExit.UseVisualStyleBackColor = True
        '
        'Label14
        '
        Me.Label14.AutoSize = True
        Me.Label14.Location = New System.Drawing.Point(203, 250)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(79, 20)
        Me.Label14.TabIndex = 35
        Me.Label14.Text = "Button 12"
        '
        'Label15
        '
        Me.Label15.AutoSize = True
        Me.Label15.Location = New System.Drawing.Point(11, 282)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(79, 20)
        Me.Label15.TabIndex = 36
        Me.Label15.Text = "Button 13"
        '
        'txt_btn12
        '
        Me.txt_btn12.Location = New System.Drawing.Point(290, 247)
        Me.txt_btn12.Name = "txt_btn12"
        Me.txt_btn12.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn12.TabIndex = 12
        Me.txt_btn12.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn13
        '
        Me.txt_btn13.Location = New System.Drawing.Point(108, 279)
        Me.txt_btn13.Name = "txt_btn13"
        Me.txt_btn13.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn13.TabIndex = 13
        Me.txt_btn13.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_joy1k
        '
        Me.txt_joy1k.Location = New System.Drawing.Point(155, 311)
        Me.txt_joy1k.Name = "txt_joy1k"
        Me.txt_joy1k.Size = New System.Drawing.Size(36, 26)
        Me.txt_joy1k.TabIndex = 37
        Me.txt_joy1k.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_joy2k
        '
        Me.txt_joy2k.Location = New System.Drawing.Point(332, 311)
        Me.txt_joy2k.Name = "txt_joy2k"
        Me.txt_joy2k.Size = New System.Drawing.Size(36, 26)
        Me.txt_joy2k.TabIndex = 38
        Me.txt_joy2k.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'frm_com_test
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(9.0!, 20.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(518, 438)
        Me.Controls.Add(Me.txt_joy2k)
        Me.Controls.Add(Me.txt_joy1k)
        Me.Controls.Add(Me.txt_btn13)
        Me.Controls.Add(Me.txt_btn12)
        Me.Controls.Add(Me.Label15)
        Me.Controls.Add(Me.Label14)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.lblFeedback)
        Me.Controls.Add(Me.chkKeyboardEnable)
        Me.Controls.Add(Me.btn_apply)
        Me.Controls.Add(Me.txt_joy2)
        Me.Controls.Add(Me.txt_joy1)
        Me.Controls.Add(Me.txt_btn11)
        Me.Controls.Add(Me.txt_btn10)
        Me.Controls.Add(Me.txt_btn9)
        Me.Controls.Add(Me.txt_btn8)
        Me.Controls.Add(Me.txt_btn7)
        Me.Controls.Add(Me.txt_btn6)
        Me.Controls.Add(Me.txt_btn5)
        Me.Controls.Add(Me.txt_btn4)
        Me.Controls.Add(Me.txt_btn3)
        Me.Controls.Add(Me.txt_btn2)
        Me.Controls.Add(Me.txt_btn1)
        Me.Controls.Add(Me.Label13)
        Me.Controls.Add(Me.Label12)
        Me.Controls.Add(Me.Label11)
        Me.Controls.Add(Me.Label10)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.Label8)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.btn_clear)
        Me.Controls.Add(Me.txt_data)
        Me.Controls.Add(Me.btn_connect)
        Me.Controls.Add(Me.cmb_ports)
        Me.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.MaximizeBox = False
        Me.Name = "frm_com_test"
        Me.Text = "Button Box Receiver"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents cmb_ports As ComboBox
    Friend WithEvents btn_connect As Button
    Friend WithEvents txt_data As TextBox
    Friend WithEvents btn_clear As Button
    Friend WithEvents SerialPort1 As IO.Ports.SerialPort
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents Label5 As Label
    Friend WithEvents Label6 As Label
    Friend WithEvents Label7 As Label
    Friend WithEvents Label8 As Label
    Friend WithEvents Label9 As Label
    Friend WithEvents Label10 As Label
    Friend WithEvents Label11 As Label
    Friend WithEvents Label12 As Label
    Friend WithEvents Label13 As Label
    Friend WithEvents txt_btn1 As TextBox
    Friend WithEvents txt_btn2 As TextBox
    Friend WithEvents txt_btn3 As TextBox
    Friend WithEvents txt_btn4 As TextBox
    Friend WithEvents txt_btn5 As TextBox
    Friend WithEvents txt_btn6 As TextBox
    Friend WithEvents txt_btn7 As TextBox
    Friend WithEvents txt_btn8 As TextBox
    Friend WithEvents txt_btn9 As TextBox
    Friend WithEvents txt_btn10 As TextBox
    Friend WithEvents txt_btn11 As TextBox
    Friend WithEvents txt_joy1 As TextBox
    Friend WithEvents txt_joy2 As TextBox
    Friend WithEvents btn_apply As Button
    Friend WithEvents chkKeyboardEnable As CheckBox
    Friend WithEvents lblFeedback As Label
    Friend WithEvents tmrClearFeedback As Timer
    Friend WithEvents btnExit As Button
    Friend WithEvents Label14 As Label
    Friend WithEvents Label15 As Label
    Friend WithEvents txt_btn12 As TextBox
    Friend WithEvents txt_btn13 As TextBox
    Friend WithEvents txt_joy1k As TextBox
    Friend WithEvents txt_joy2k As TextBox
End Class
