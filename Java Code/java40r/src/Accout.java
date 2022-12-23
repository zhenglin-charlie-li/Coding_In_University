public class Accout {
    protected String accout;
    protected int balance;
    protected double rate;

    public String getAccout() {
        return accout;
    }


    public Accout(String accout, int balance, double rate) {
        this.accout = accout;
        this.balance = balance;
        this.rate = rate;
    }

    public void addToAccont(int money) {
        balance += money;
    }

    public boolean quKuan(int money) {
        balance -= money;
        return true;
    }

    @Override
    public String toString() {
        return "Accout{" +
                "accout='" + accout + '\'' +
                ", balance=" + balance +
                ", rate=" + rate +
                '}';
    }
}
