public class CheckingAccount extends Accout {
    private int touzhixiane;

    public int getTouzhixiane() {
        return touzhixiane;
    }

    public void setTouzhixiane(int touzhixiane) {
        this.touzhixiane = touzhixiane;
    }

    public CheckingAccount(String accout, int balance, double rate) {
        super(accout, balance, rate);
    }

    @Override
    public void addToAccont(int money) {
        balance += money;
    }

    @Override
    public boolean quKuan(int money) {
        if (money > balance + touzhixiane) {
            return false;
        }
        balance -= money;
        return true;
    }

    @Override
    public String toString() {
        return "Accout{" +
                "CheckingAccount='" + accout + '\'' +
                ", balance=" + balance +
                ", rate=" + rate +
                '}';
    }
}
