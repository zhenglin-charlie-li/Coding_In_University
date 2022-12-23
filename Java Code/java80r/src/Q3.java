import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Q3 {
    public static class Node {
        public int data;
        public Node next;

        public Node(int data) {
            this.data = data;
        }
    }

    public static Object[] getInput(int i) {
        System.out.println("请输入链表" + i + "的每一个节点的值并用逗号隔开：");
        Scanner sc = new Scanner(System.in);
        String str = sc.next().toString();
        String[] arr = str.split(",");
        int[] array = new int[arr.length];
        for (int j = 0; j < array.length; j++) {
            array[j] = Integer.parseInt(arr[j]);
        }
        System.out.println("链表如下：" + Arrays.toString(array));
        Object[] res = new Object[arr.length];
        for (int j = 0; j < array.length; j++) {
            res[j] = array[j];
        }
        return res;
    }
    public static Node arrayToNode1(Object[] arr) {
        Node head = new Node((Integer) arr[0]); // 把数组的第一个位置定义为头结点
        Node other = head; // 一个指针，此时指向头结点
        for (int i = 1; i < arr.length; i++) { //头结点已经定义，从1开始
            Node temp = new Node( (Integer) arr[i]);
            other.next = temp;
            other = other.next;

        }//在此处打印结点容易导致head的变化
        return head;
    }
    public static void main(String[] args) {
        Node head1=arrayToNode1(getInput(1));
        Node head2=arrayToNode1(getInput(2));

        Node res = function3(head1, head2);
        Node temp = res;
        while (temp != null) {
            System.out.print(temp.data + "  ");
            temp = temp.next;
        }
    }



    public static Node function3(Node head1, Node head2) {
        int i = 1;
        int value1 = 0;
        Node temp = head1;
        while (temp != null) {
            value1 += temp.data * i;
            i *= 10;
            temp = temp.next;
        }
        i = 1;
        temp = head2;
        int value2 = 0;
        while (temp != null) {
            value2 += temp.data * i;
            i *= 10;
            temp = temp.next;
        }
        System.out.println(value1 + " " + value2);
        int value = value1 + value2;
        ArrayList<Integer> arrayList = new ArrayList<>();
        while (value != 0) {
            arrayList.add(value % 10);
            value /= 10;
        }
        System.out.println(arrayList.toString());

        return arrayToNode1(arrayList.toArray());
    }
}
