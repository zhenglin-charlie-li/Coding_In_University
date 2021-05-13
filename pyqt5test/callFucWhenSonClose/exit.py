from ui_exit import Ui_Dialog
from PyQt5.QtWidgets import QApplication, QMainWindow
import sys
from PyQt5 import QtCore


class My_Exit_Window(QMainWindow, Ui_Dialog):
    '''主程序'''
    def __init__(self):
        super(My_Exit_Window, self).__init__()
        self.setupUi(self)

    # 让多窗口之间传递信号 刷新主窗口信息
    my_Signal = QtCore.pyqtSignal(str)

    def sendEditContent(self):
        content = '1'
        self.my_Signal.emit(content)

    def closeEvent(self, event):
        self.sendEditContent()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_window = My_Exit_Window()
    main_window.show()
    sys.exit(app.exec_())

