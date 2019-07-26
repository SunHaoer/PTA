import java.util.Scanner;

class Num {			// a / b
	long a;
	long b;
	Num(long a, long b) {
		this.a = a;
		this.b = b;
	}
}

public class Main {
	
	public static Num sum = new Num(0, 1);
	
	public static void fun1(Num num) {
		sum.a = sum.a * num.b + num.a * sum.b;
		sum.b = sum.b * num.b;
	}
	
	public static void fun2() {
		for(long i = 2; i <= sum.a && i <= sum.b; i++) {
			if(sum.a % i == 0 && sum.b % i == 0) {
				sum.a /= i;
				sum.b /= i;
				i--;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		Num num[] = new Num[n];
		for(int i = 0; i < n; i++) {
			String temp = sca.next();
			String str[] = temp.split("/");
			num[i] = new Num(Integer.parseInt(str[0]), Integer.parseInt(str[1]));
			fun1(num[i]);
		}
		sca.close();
		sum.b *= n;
		fun2();
		if(sum.a == 0) {
			System.out.println("0");
		} else if(sum.a < 0 && sum.b < 0) {
			System.out.println(Math.abs(sum.a) + "/" + Math.abs(sum.b));
		} else if(sum.a < 0 || sum.b < 0) {
			System.out.println("-" + Math.abs(sum.a) + "/" + Math.abs(sum.b));
		} else if(sum.b != 1) {
			System.out.println(sum.a + "/" + sum.b);
		} else {
			System.out.println(sum.a);
		}
	}

}


