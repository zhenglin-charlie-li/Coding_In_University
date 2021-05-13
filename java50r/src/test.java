import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        ScoreListMange scoreListMange = new ScoreListMange();
        ScoreList one = new ScoreList("张三", 123, "19级计算机科学三班", 60.0, 90.6);
        ScoreList two = new ScoreList("李四", 456, "19级材料科学十一班", 75.6, 49.6);
        ScoreList three = new ScoreList("阿司匹林", 159, "20级吴院一班", 85.6, 76.2);
        ScoreList four = new ScoreList("哈哈哈", 852, "21级计算机科学二班", 99.0, 86.9);
        scoreListMange.add(one);
        scoreListMange.add(two);
        scoreListMange.add(three);
        scoreListMange.add(four);
        Scanner scanner = new Scanner(System.in);
        int choice = 0;
        while (true) {
            System.out.println();
            System.out.println();
            System.out.println("============================");
            System.out.println("这是成绩单管理系统");
            System.out.println("1--查看全班总平均分");
            System.out.println("2--查看各分数段人数");
            System.out.println("3--找到某个学号");
            System.out.println("4--找到最高分");
            System.out.println("else--Quit");
            System.out.println("============================");
            choice = scanner.nextInt();
            if (choice == 1) {
                System.out.println("班级的平均分是"+scoreListMange.getAverage());
                choice = 0;
            } else if (choice == 2) {
                System.out.println(scoreListMange.numberOfEveryScore());
                choice = 0;
            } else if (choice == 3) {
                System.out.println("请输入学生学号");
                System.out.println(scoreListMange.getStudentById(scanner.nextInt()));
                choice = 0;
            } else if (choice == 4) {
                System.out.println("最高分的学生是"+scoreListMange.getHighest());
                choice = 0;
            } else {
                System.out.println("Quit");
                break;
            }
        }
    }
}
