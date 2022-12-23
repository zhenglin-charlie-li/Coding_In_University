import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.pow;

public class Q2 {
    public static class Node {
        public int data;
        public Node next;

        public Node(int data) {
            this.data = data;
        }
    }

    public static Node arrayToNode(int[] arr) {
        Node head = new Node(arr[0]); // 把数组的第一个位置定义为头结点
        Node other = head; // 一个指针，此时指向头结点
        for (int i = 1; i < arr.length; i++) { //头结点已经定义，从1开始
            Node temp = new Node(arr[i]);
            other.next = temp;
            other = other.next;

        }//在此处打印结点容易导致head的变化
        return head;
    }

    public static int[] getInput() {
        System.out.println("请输入二进制数的每一位并用逗号隔开：");
        Scanner sc = new Scanner(System.in);
        String str = sc.next().toString();
        String[] arr = str.split(",");
        int[] array = new int[arr.length];
        for (int j = 0; j < array.length; j++) {
            array[j] = Integer.parseInt(arr[j]);
        }
        System.out.println("二进制数如下：" + Arrays.toString(array));
        return array;
    }

    public static void main(String[] args) {
        System.out.println(function2(arrayToNode(getInput())));
    }

    public static int function2(Node head) {
        int res = 0;
        Node temp = head;
        int length = 0;
        while (temp != null) {
            length++;
            temp = temp.next;
        }
        temp = head;
        while (temp != null) {
            if (temp.data == 1) {
                res += pow(2, length - 1);
            }
            length--;
            temp = temp.next;
        }
        return res;
    }
}
