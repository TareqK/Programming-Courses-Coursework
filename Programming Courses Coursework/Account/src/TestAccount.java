public class TestAccount {
	public static void main(String[] args) {
		Object[] a = new Object[2];
		a[0] = new CheckingAccount(10, 250, .5, 1000);
		a[1] = new SavingAccount(45, 2, .5);
		for(int i =0;i<a.length;i++)
		System.out.println(a[i].toString());
		System.out.println("the more valuable count is \n"+max(a).toString());
	}

	public static Object max(Object[] a){
		Object max=a[0];
		for(int i=1;i<a.length;i++)
			if(((Comparable)max).compareTo(a[i])==-1)
				max=a[i];
		return max;
	}
}


