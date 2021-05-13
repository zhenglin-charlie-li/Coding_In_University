public class test {
    public static void main(String[] args) {
        Accout accout = new Accout("aaa",123,100.0);
        System.out.println(accout.toString());
        Accout accout1 = new CheckingAccount("bbb",456,200.0);
        System.out.println(accout1.toString());

        Accout accout2 = new SavingAccount("ccc",456,300.0);
        System.out.println(accout2.toString());
    }
}
