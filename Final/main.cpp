#include<iostream>
#include "write_message.h"
#include "uncompress.h"
#include "hufftree.h"
#include "huffmancode.h"
using namespace std;

int printMenu();

bool checkFileName(char *name, int type);

int main() {
    int m;
    //
    int choice;
    char filename[100]; //compress.txt所在位置
    char filename1[100];  //输出的文件夹目录所在位置
    char filename2[100];  //uncompressed.txt
    char filename3[100];  //config.txt所在的目录
    char filename4[100];  //Only0And1.txt
    while ((choice = printMenu()) != 0) {
        if (choice == 1) {
            TreeNode p[10000];
            HuffCode HC;
            cout << "请输入文件路径(.txt结尾)" << endl;
            cin.sync();
            cin.getline(filename, 100);
//            strcpy(filename1,"C:\\Users\\Zhenglin Li\\Desktop\\FileRecv\\compress.txt");
            cout << filename << endl;
            if (checkFileName(filename, 1)) {
                cout << "开始压缩了" << endl;
                LinkNode *head = in_outstream(filename);
                if (head == nullptr) {
                    continue;
                }
                LinkNode *current = head;
                m = Huffumancode(p, HC, current);
                cout << "请输入要压缩到的文件夹路径" << endl;
                cin.sync();
                cin.getline(filename1, 100);
//                strcpy(filename1,"C:\\Users\\Zhenglin Li\\Desktop\\FileRecv");
                write_message(m, p, head, HC, filename, filename1);
            }
            cin.sync();
        } else if (choice == 2) {
            cout << "请输入压缩文件路径(.txt结尾)" << endl;
            cin.sync();
            cin.getline(filename4, 100);
//            strcpy(filename4,"C:\\Users\\Zhenglin Li\\Desktop\\FileRecv\\Only0And1.txt");
            cout << filename4 << endl;
            cout << "请输入配置文件路径(.txt结尾)" << endl;
            cin.sync();
            cin.getline(filename3, 100);
//            strcpy(filename3,"C:\\Users\\Zhenglin Li\\Desktop\\FileRecv\\config.txt");
            cout << filename3 << endl;
            cout << "请输入解压后的文件路径" << endl;
            cin.sync();
            cin.getline(filename2, 100);
//            strcpy(filename2,"C:\\Users\\Zhenglin Li\\Desktop\\FileRecv\\uncompressed.txt");
            cout << filename2 << endl;
            HuffTree<char> *p = rebuild(filename3);
            UnCompress(p, filename4, filename2);    //问题在这里
            cin.sync();
        } else {
            cout << "输入有误, 请重试" << endl;
            cin.sync();
        }
    }
    cout << "退出程序" << endl;
    return 0;
}

int printMenu() {
    int choice;
    cout << "        |-------------------------------------|" << endl;
    cout << "        |           哈夫曼编码程序              |" << endl;
    cout << "        |                                     |" << endl;
    cout << "        |     1: 使用哈夫曼编码压缩文件(.txt)    |" << endl;
    cout << "        |     2: 按照哈夫曼编码解压文件(.txt)    |" << endl;
    cout << "        |     0: 退出程序                      |" << endl;
    cout << "        |                                     |" << endl;
    cout << "        |-------------------------------------|" << endl;
    cout << "        请输入您的选择: " << endl;
    cin >> choice;
    return choice;
}

bool checkFileName(char *name, int type) {
    int length = 0;
    for (int i = 0;; i++) {
        if (name[i] == '\0') {
            length = i;
            break;
        }
    }
    if (length <= 4) {
        return false;
    }
    switch (type) {
        case 1: {
            if (name[length - 1] != 't' || name[length - 2] != 'x' || name[length - 3] != 't' ||
                name[length - 4] != '.') {
                cout << "文件名出错了" << endl;
                return false;
            }
            break;
        }
        case 2: {
            if (name[length - 1] != 'f' || name[length - 2] != 'u' || name[length - 3] != 'h' ||
                name[length - 4] != '.') {
                cout << "文件名出错了" << endl;
                return false;
            }
            break;
        }
    }

    return true;
}