from ui_user import Ui_Dialog
from PyQt5.QtWidgets import QApplication, QMainWindow
from exit import My_Exit_Window
import sys


class My_Main_Window(QMainWindow, Ui_Dialog):
    '''主程序'''
    def __init__(self):
        super(My_Main_Window, self).__init__()
        self.setupUi(self)

    def btn(self):
        self.exit_window = My_Exit_Window()
        # 接受子窗口传回来的信号  然后调用主界面的函数
        self.exit_window.my_Signal.connect(self.active_exit)
        self.exit_window.show()

    def active_exit(self):
        self.label.setText('子窗口被关闭')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_window = My_Main_Window()
    main_window.show()
    sys.exit(app.exec_())

