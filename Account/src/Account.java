import java.util.Date;

public class Account implements Comparable<Account> {

	private int id;

	private double balance;

	private double annualIntrestRate;

	private Date dateCreated;

	public Account() {

		id = 0;

		balance = 0;

		annualIntrestRate = 0;

		dateCreated = new Date();

	}

	public int getId() {

		return id;

	}

	public void setId(int id) {

		this.id = id;

	}

	public double getBalance() {

		return balance;

	}

	public void setBalance(double balance) {

		this.balance = balance;

	}

	@Override
	public String toString() {

		return " Account: \n\tID:" + id + ", balance=" + balance

		+ ", annualIntrestRate=" + annualIntrestRate + ", dateCreated="

		+ dateCreated;

	}

	@Override
	public boolean equals(Object obj) {

		if (obj instanceof Account) {

			if (balance == ((Account) obj).getBalance())

				return true;

		}

		return false;

	}

	public double getAnnualIntrestRate() {

		return annualIntrestRate;

	}

	public void setAnnualIntrestRate(double annualIntrestRate) {

		this.annualIntrestRate = annualIntrestRate;

	}

	public Date getDateCreated() {

		return dateCreated;

	}

	public void withdraw(double amount) {

		if (amount > 0 && balance >= amount)

			balance -= amount;

		else

			System.out
					.println("Error: your account has no money enough or the amount is invalid");

	}

	public void deposit(double amount) {

		balance += amount;
		
		

	}

	@Override
	public int compareTo(Account a) {
	
		if (balance >a.getBalance())
			return 1;
		else if (balance < a.getBalance())
			return 0 ;
		else 
			return -1 ;}
	}



