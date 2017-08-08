Public Class KeyboardSettings

    Shared Sub load()
        frm_com_test.txt_btn1.Text = My.Settings.Item("B1").ToString
        frm_com_test.txt_btn2.Text = My.Settings.Item("B2").ToString
        frm_com_test.txt_btn3.Text = My.Settings.Item("B3").ToString
        frm_com_test.txt_btn4.Text = My.Settings.Item("B4").ToString
        frm_com_test.txt_btn5.Text = My.Settings.Item("B5").ToString
        frm_com_test.txt_btn6.Text = My.Settings.Item("B6").ToString
        frm_com_test.txt_btn7.Text = My.Settings.Item("B7").ToString
        frm_com_test.txt_btn8.Text = My.Settings.Item("B8").ToString
        frm_com_test.txt_btn9.Text = My.Settings.Item("B9").ToString
        frm_com_test.txt_btn10.Text = My.Settings.Item("B10").ToString
        frm_com_test.txt_btn11.Text = My.Settings.Item("B11").ToString
        frm_com_test.txt_btn12.Text = My.Settings.Item("B12").ToString
        frm_com_test.txt_btn13.Text = My.Settings.Item("B13").ToString
        frm_com_test.txt_btn14.Text = My.Settings.Item("B14").ToString
        frm_com_test.txt_joy1.Text = My.Settings.Item("J1").ToString
        frm_com_test.txt_joy2.Text = My.Settings.Item("J2").ToString
        frm_com_test.chkKeyboardEnable.Checked = My.Settings.Item("KeyboardEnabled").ToString
    End Sub

    Shared Sub store()
        My.Settings.Item("B1") = frm_com_test.txt_btn1.Text
        My.Settings.Item("B2") = frm_com_test.txt_btn2.Text
        My.Settings.Item("B3") = frm_com_test.txt_btn3.Text
        My.Settings.Item("B4") = frm_com_test.txt_btn4.Text
        My.Settings.Item("B5") = frm_com_test.txt_btn5.Text
        My.Settings.Item("B6") = frm_com_test.txt_btn6.Text
        My.Settings.Item("B7") = frm_com_test.txt_btn7.Text
        My.Settings.Item("B8") = frm_com_test.txt_btn8.Text
        My.Settings.Item("B9") = frm_com_test.txt_btn9.Text
        My.Settings.Item("B10") = frm_com_test.txt_btn10.Text
        My.Settings.Item("B11") = frm_com_test.txt_btn11.Text
        My.Settings.Item("B12") = frm_com_test.txt_btn12.Text
        My.Settings.Item("B13") = frm_com_test.txt_btn13.Text
        My.Settings.Item("B14") = frm_com_test.txt_btn14.Text
        My.Settings.Item("J1") = frm_com_test.txt_joy1.Text
        My.Settings.Item("J2") = frm_com_test.txt_joy2.Text
        My.Settings.Item("KeyboardEnabled") = frm_com_test.chkKeyboardEnable.Checked
        My.Settings.Save()
    End Sub
End Class
