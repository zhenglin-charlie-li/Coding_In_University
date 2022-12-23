let balance = 0;

function init(initial_balance) {
    balance = initial_balance;
}

// Deposit amount
function deposit(amount) {
    balance += amount;
}

// Withdraw amount
function withdraw(amount) {
    balance -= amount;
}

function overdrawn() {
    return balance < 0;
}
