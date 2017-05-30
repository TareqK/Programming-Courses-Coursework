public class Person {

	protected String name;
	protected String address;
	protected String email;
	protected String phoneNumber;

	public Person() {
		name = "jeff";
		address = "zanarkand";
		email = "raj@microsoftsupport.com";
		phoneNumber = "5550100";
	}

	public Person(String name, String address, String email, String phoneNumber) {

		this.name = name;
		this.address = address;
		this.email = email;
		this.phoneNumber = phoneNumber;
	}

	public String getName() {
		return name;
	}

	public String getAddress() {
		return address;
	}

	public String getEmail() {
		return email;
	}

	public String getPhoneNumber() {
		return phoneNumber;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}

	public String toString() {
		return ("name: " + name + "\nAddress: " + address + "\nEmail: " + email
				+ "\nNumber: " + phoneNumber);
	}
}
