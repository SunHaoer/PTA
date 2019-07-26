import java.util.Scanner;

class Person {
	String name;
	String time;
	String sex;
	String tel;
	String phone;
	public Person(String name, String time, String sex, String tel, String phone) {
		super();
		this.name = name;
		this.time = time;
		this.sex = sex;
		this.tel = tel;
		this.phone = phone;
	}
}

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		Person per[] = new Person[n];
		for(int i = 0; i < n; i++) {
			per[i] = new Person(sca.next(), sca.next(), sca.next(), sca.next(), sca.next());
		}
		int m  = sca.nextInt();
		for(int i = 0; i < m; i++) {
			int k = sca.nextInt();
			if(k < n && k >= 0) {
				System.out.println(per[k].name + " " + per[k].tel + " " + per[k].phone + " " + per[k].sex + " " + per[k].time);
			} else {
				System.out.println("Not Found");
			}
		}
		sca.close();
	}

}
