
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include "hufftree.h"

using namespace std;

HuffTree<char> *rebuildhufuman(char **p1, char **p2) {
    if (**p2 == '0' || (**p1 != '1' && **p1 != '0'))
        return nullptr;
    else {
        HuffTree<char> *root;
        if (**p1 == '0') {
            char wt = (0, **p2);
            (*p2)++;
            root = new HuffTree<char>(wt);
            (*p1)++;
            return root;
        } else if (**p1 == '1')
            (*p1)++;
        root = new HuffTree<char>(rebuildhufuman(p1, p2),
                                  rebuildhufuman(p1, p2));
        return root;

    }
}

HuffTree<char> *rebuild(char *filename) {
    char k;
    fstream fconfig(filename, ios::in);
    if (!fconfig) {
        cout << "error" << endl;
        return nullptr;
    }
    int a[1] = {0};
    fconfig.read(reinterpret_cast<char *>(a), sizeof(a));
    cout << "a: ---------" << a[0] << endl;
    char b[1000000] = {0};

    fconfig.read(reinterpret_cast<char *>(b), sizeof(b));
    for (int count = 0; b[count] != 0; count++)
        cout << b[count] << endl;
    char *p1 = b;
    char **p11 = &p1;
    char *p2;
    for (int count = 0; b[count] == '1' || b[count] == '0'; count++) {
        p2 = &b[count + 1];
    }
    char **p22 = &p2;
    HuffTree<char> *root = rebuildhufuman(p11, p22);
    return root;
}

int UnCompress(HuffTree<char> *tree, char *Only0And1, char *uncompressed) {
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open(Only0And1);
    if (in_stream.fail()) {
        cout << "inserting to Only0And1 file is failing";
        exit(1);
    }
    out_stream.open(uncompressed);
    if (out_stream.fail()) {
        cout << "inserting to afterUncompress file is failing";
        exit(1);
    }
    char contents[102400];
    int i = 0;
    char c;
    while (in_stream.get(c)) {
        contents[i++] = c;
        cout.put(c);
    }
    i = 0;
    cout << endl << "starting uncompress" << endl;
    //问题在这里
    HuffNode<char> *root = (tree->root());
    HuffNode<char> *current = root;

    cout << endl << "root" << typeid(root).name() << endl;
    cout << "current" << typeid(current).name() << endl;
    cout << "*current" << typeid(*current).name() << endl;

//    int rootIndex = numAllNode - 1;
//    cout << endl << "rootIndex" << rootIndex << endl;
//    int index = rootIndex;
    cout << endl << "starting uncompress" << endl;
    char temp;//目前没有 和\n了
    while (contents[i] != '\0') {
        if (contents[i] == '0') {
            current = (current)->left();
            if ((current)->isLeaf()) {
                temp = (current)->val();
                if (temp != 32 && temp != 10) {
                    cout << temp;
                    out_stream.put(temp);
                } else if (temp == 32) {
                    cout << ' ';
                    out_stream.put(' ');
                } else if (temp == 10) {
                    cout << '\n';
                    out_stream.put('\n');
                }
                current = root;
            }
            /*index = tree[index].left;
            if (tree[index].left == -1 && tree[index].right == -1) {
                temp = tree[index].ch;
                if (temp != 32 && temp != 10) {
                    cout << temp;
                    out_stream.put(temp);
                } else if (temp == 32) {
                    cout << ' ';
                    out_stream.put(' ');
                } else if (temp == 10) {
                    cout << '\n';
                    out_stream.put('\n');
                }
                index = rootIndex;
            }*/
        } else if (contents[i] == '1') {
            current = (current)->right();
            if ((current)->isLeaf()) {
                temp = (current)->val();
                if (temp != 32 && temp != 10) {
                    cout << temp;
                    out_stream.put(temp);
                } else if (temp == 32) {
                    cout << ' ';
                    out_stream.put(' ');
                } else if (temp == 10) {
                    cout << '\n';
                    out_stream.put('\n');
                }
                current = root;
            }
            /*index = tree[index].right;
            if (tree[index].left == -1 && tree[index].right == -1) {
                temp = tree[index].ch;
                if (temp != 32 && temp != 10) {
                    cout << temp;
                    out_stream.put(temp);
                } else if (temp == 32) {
                    cout << ' ';
                    out_stream.put(' ');
                } else if (temp == 10) {
                    cout << '\n';
                    out_stream.put('\n');
                }
                index = rootIndex;
            }*/
        }
        i++;
    }
    cout << "UnCompress ended" << endl;
    return 0;
}

