public class SavingAccount extends Account {

	public SavingAccount(int id, double balance, double annualIntrestRate) {

		setId(id);

		setBalance(balance);

		setAnnualIntrestRate(annualIntrestRate);

	}

	@Override
	public String toString() {

		return "Saving" + super.toString();

	}

}
