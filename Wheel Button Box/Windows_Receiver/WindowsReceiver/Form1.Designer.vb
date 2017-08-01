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
        Me.lblStatus = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'cmb_ports
        '
        Me.cmb_ports.FormattingEnabled = True
        Me.cmb_ports.Location = New System.Drawing.Point(13, 14)
        Me.cmb_ports.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.cmb_ports.Name = "cmb_ports"
        Me.cmb_ports.Size = New System.Drawing.Size(180, 28)
        Me.cmb_ports.TabIndex = 0
        '
        'btn_connect
        '
        Me.btn_connect.Location = New System.Drawing.Point(201, 10)
        Me.btn_connect.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.btn_connect.Name = "btn_connect"
        Me.btn_connect.Size = New System.Drawing.Size(112, 35)
        Me.btn_connect.TabIndex = 1
        Me.btn_connect.Text = "Connect"
        Me.btn_connect.UseVisualStyleBackColor = True
        '
        'txt_data
        '
        Me.txt_data.Location = New System.Drawing.Point(331, 14)
        Me.txt_data.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.txt_data.Multiline = True
        Me.txt_data.Name = "txt_data"
        Me.txt_data.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.txt_data.Size = New System.Drawing.Size(112, 436)
        Me.txt_data.TabIndex = 3
        '
        'btn_clear
        '
        Me.btn_clear.Location = New System.Drawing.Point(331, 460)
        Me.btn_clear.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.btn_clear.Name = "btn_clear"
        Me.btn_clear.Size = New System.Drawing.Size(112, 35)
        Me.btn_clear.TabIndex = 4
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
        Me.Label1.Location = New System.Drawing.Point(12, 63)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(74, 20)
        Me.Label1.TabIndex = 5
        Me.Label1.Text = "Button  1"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(12, 96)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(74, 20)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "Button  2"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(12, 129)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(74, 20)
        Me.Label3.TabIndex = 7
        Me.Label3.Text = "Button  3"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(12, 162)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(74, 20)
        Me.Label4.TabIndex = 8
        Me.Label4.Text = "Button  4"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(12, 195)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(74, 20)
        Me.Label5.TabIndex = 9
        Me.Label5.Text = "Button  5"
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(12, 228)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(74, 20)
        Me.Label6.TabIndex = 10
        Me.Label6.Text = "Button  6"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(12, 261)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(74, 20)
        Me.Label7.TabIndex = 11
        Me.Label7.Text = "Button  7"
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Location = New System.Drawing.Point(12, 294)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(74, 20)
        Me.Label8.TabIndex = 12
        Me.Label8.Text = "Button  8"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Location = New System.Drawing.Point(12, 327)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(74, 20)
        Me.Label9.TabIndex = 13
        Me.Label9.Text = "Button  9"
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Location = New System.Drawing.Point(12, 360)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(79, 20)
        Me.Label10.TabIndex = 14
        Me.Label10.Text = "Button 10"
        '
        'Label11
        '
        Me.Label11.AutoSize = True
        Me.Label11.Location = New System.Drawing.Point(12, 393)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(79, 20)
        Me.Label11.TabIndex = 15
        Me.Label11.Text = "Button 11"
        '
        'Label12
        '
        Me.Label12.AutoSize = True
        Me.Label12.Location = New System.Drawing.Point(12, 424)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(63, 20)
        Me.Label12.TabIndex = 16
        Me.Label12.Text = "Joyst  1"
        '
        'Label13
        '
        Me.Label13.AutoSize = True
        Me.Label13.Location = New System.Drawing.Point(12, 459)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(59, 20)
        Me.Label13.TabIndex = 17
        Me.Label13.Text = "Joyst 2"
        '
        'txt_btn1
        '
        Me.txt_btn1.Location = New System.Drawing.Point(109, 60)
        Me.txt_btn1.MaxLength = 1
        Me.txt_btn1.Name = "txt_btn1"
        Me.txt_btn1.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn1.TabIndex = 18
        Me.txt_btn1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn2
        '
        Me.txt_btn2.Location = New System.Drawing.Point(109, 93)
        Me.txt_btn2.MaxLength = 1
        Me.txt_btn2.Name = "txt_btn2"
        Me.txt_btn2.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn2.TabIndex = 19
        Me.txt_btn2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn3
        '
        Me.txt_btn3.Location = New System.Drawing.Point(109, 126)
        Me.txt_btn3.MaxLength = 1
        Me.txt_btn3.Name = "txt_btn3"
        Me.txt_btn3.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn3.TabIndex = 20
        Me.txt_btn3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn4
        '
        Me.txt_btn4.Location = New System.Drawing.Point(109, 159)
        Me.txt_btn4.MaxLength = 1
        Me.txt_btn4.Name = "txt_btn4"
        Me.txt_btn4.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn4.TabIndex = 21
        Me.txt_btn4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn5
        '
        Me.txt_btn5.Location = New System.Drawing.Point(109, 192)
        Me.txt_btn5.MaxLength = 1
        Me.txt_btn5.Name = "txt_btn5"
        Me.txt_btn5.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn5.TabIndex = 22
        Me.txt_btn5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn6
        '
        Me.txt_btn6.Location = New System.Drawing.Point(109, 225)
        Me.txt_btn6.MaxLength = 1
        Me.txt_btn6.Name = "txt_btn6"
        Me.txt_btn6.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn6.TabIndex = 23
        Me.txt_btn6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn7
        '
        Me.txt_btn7.Location = New System.Drawing.Point(109, 258)
        Me.txt_btn7.MaxLength = 1
        Me.txt_btn7.Name = "txt_btn7"
        Me.txt_btn7.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn7.TabIndex = 24
        Me.txt_btn7.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn8
        '
        Me.txt_btn8.Location = New System.Drawing.Point(109, 291)
        Me.txt_btn8.MaxLength = 1
        Me.txt_btn8.Name = "txt_btn8"
        Me.txt_btn8.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn8.TabIndex = 25
        Me.txt_btn8.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn9
        '
        Me.txt_btn9.Location = New System.Drawing.Point(109, 324)
        Me.txt_btn9.MaxLength = 1
        Me.txt_btn9.Name = "txt_btn9"
        Me.txt_btn9.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn9.TabIndex = 26
        Me.txt_btn9.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn10
        '
        Me.txt_btn10.Location = New System.Drawing.Point(109, 358)
        Me.txt_btn10.MaxLength = 1
        Me.txt_btn10.Name = "txt_btn10"
        Me.txt_btn10.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn10.TabIndex = 27
        Me.txt_btn10.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_btn11
        '
        Me.txt_btn11.Location = New System.Drawing.Point(109, 390)
        Me.txt_btn11.MaxLength = 1
        Me.txt_btn11.Name = "txt_btn11"
        Me.txt_btn11.Size = New System.Drawing.Size(36, 26)
        Me.txt_btn11.TabIndex = 28
        Me.txt_btn11.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_joy1
        '
        Me.txt_joy1.Location = New System.Drawing.Point(109, 421)
        Me.txt_joy1.MaxLength = 1
        Me.txt_joy1.Name = "txt_joy1"
        Me.txt_joy1.Size = New System.Drawing.Size(36, 26)
        Me.txt_joy1.TabIndex = 29
        Me.txt_joy1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txt_joy2
        '
        Me.txt_joy2.Location = New System.Drawing.Point(109, 456)
        Me.txt_joy2.MaxLength = 1
        Me.txt_joy2.Name = "txt_joy2"
        Me.txt_joy2.Size = New System.Drawing.Size(36, 26)
        Me.txt_joy2.TabIndex = 30
        Me.txt_joy2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'btn_apply
        '
        Me.btn_apply.Location = New System.Drawing.Point(230, 460)
        Me.btn_apply.Name = "btn_apply"
        Me.btn_apply.Size = New System.Drawing.Size(84, 30)
        Me.btn_apply.TabIndex = 31
        Me.btn_apply.Text = "Apply"
        Me.btn_apply.UseVisualStyleBackColor = True
        '
        'lblStatus
        '
        Me.lblStatus.AutoSize = True
        Me.lblStatus.Location = New System.Drawing.Point(226, 430)
        Me.lblStatus.Name = "lblStatus"
        Me.lblStatus.Size = New System.Drawing.Size(66, 20)
        Me.lblStatus.TabIndex = 32
        Me.lblStatus.Text = "Label14"
        '
        'frm_com_test
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(9.0!, 20.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(456, 509)
        Me.Controls.Add(Me.lblStatus)
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
        Me.Name = "frm_com_test"
        Me.Text = "Arduino COM Test"
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
    Friend WithEvents lblStatus As Label
End Class
