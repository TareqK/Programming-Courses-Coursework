public class CheckingAccount extends Account {

	private double overDraft;

	public CheckingAccount(int id, double balance, double annualIntrestRate,

	double overDraft) {

		setId(id);

		setBalance(balance);

		setAnnualIntrestRate(annualIntrestRate);

		this.overDraft = overDraft;

	}

	public void withdraw(double amount) {

		if (amount > 0 && (getBalance() + overDraft) >= amount)

			setBalance(getBalance() - amount);

	}

	@Override
	public String toString() {

		return "Checking " + super.toString() + ", overDraft= " + overDraft;

	}

}
