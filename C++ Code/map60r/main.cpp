#include <iostream>
#include<fstream>
#include <map>

using namespace std;
typedef struct LNode {
    char key{};//字符
    int number{};//权值
    LNode *next = nullptr;
} LinkNode;

//创建一个新结点
LinkNode *CreateNode() {
    auto *newNode = (LNode *) malloc(sizeof(LNode));
    if (newNode != nullptr) {
        newNode->key = '0';
        newNode->number = 0;
        newNode->next = nullptr;
    }
    return newNode;
}

//读取文件的信息，返回链表头指针
LinkNode *in_outstream(char *fileName) {
    char c;
    bool flag;
    LinkNode *head = nullptr;//头指针
    LinkNode *current = head;//当前结点
    ifstream in_stream;//源文件
    in_stream.open(fileName);
    //打开源文件错误
    if (in_stream.fail()) {
        cout << endl << "未找到文件!!!" << endl << endl;
        return nullptr;
    }

    //遍历文件，依次读取每个字符
    while (in_stream.get(c)) {
//        cout << c;
        flag = true;//标志c不存在于链表中
        //遍历链表，判断c是否已经存在于链表中
        for (current = head; current != nullptr; current = current->next) {
            //c已经存在，c对应的频数加1
            if (current->key == c) {
                current->number++;
                flag = false;//flag置为false
                break;//跳出for循环
            }
        }
        //遍历完链表，c不存在，则创建新节点
        if (flag) {
            LinkNode *newnode = CreateNode();
            newnode->key = c;
            newnode->number++;
            newnode->next = head;
            head = newnode;//这里头指针在往前移动，所以最后还需要一个头指针
        }
    }
    LinkNode *head1 = CreateNode();//最后加一个头指针在前面
    head1->next = head;
//    cout << endl<< "The result:" << endl;//控制台输出

    //遍历链表，分别输出至控制台和文件中
//    for (current = head; current != nullptr; current = current->next) {
//        cout << current->key << ' ' << current->number << '\n';
//    }

    //关闭流
    in_stream.close();

    return head1;//返回存放了权值和字符的链表头指针
}

LinkNode *read() {
    char filename[100];
    cout << "请输入文件路径(.txt结尾)" << endl;
    cin.getline(filename, 100);
    LinkNode *head = in_outstream(filename);
    if (head == nullptr) {
        return nullptr;
    }
    return head;
}

int main() {
    LinkNode *head = read();
    map<char, int> myMap;
    cout << "LinkNode " << endl;
    for (LinkNode *current = head->next; current != nullptr; current = current->next) {
        cout << current->key << ' ' << current->number << '\n';
        myMap.insert(pair<char, int>(current->key, current->number));
    }
    cout << "myMap " << endl;
    for (auto &x: myMap) {
        cout << x.first << ": " << x.second << endl;
    }
    cout<<"请输入字符串:"<<endl;
    string s1;
    cin >> s1;
    cout<<s1<<"的编码是:";
    for (char temp='a';temp<='z';temp++) {
        if(myMap.count(temp)>0){
            cout<<myMap[temp];
        }else{
            cout<<0;
        }
    }
    return 0;
}
