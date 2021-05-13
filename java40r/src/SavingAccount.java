public class SavingAccount extends Accout {

    public SavingAccount(String accout, int balance, double rate) {
        super(accout, balance, rate);
    }

    @Override
    public void addToAccont(int money) {
        super.balance += money;
    }

    @Override
    public boolean quKuan(int money) {
        if (money > balance) {
            return false;
        }
        balance -= money;
        return true;
    }

    @Override
    public String toString() {
        return "Accout{" +
                "SavingAccount='" + accout + '\'' +
                ", balance=" + balance +
                ", rate=" + rate +
                '}';
    }
}
