import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int a = sca.nextInt();
		char ch = sca.next().charAt(0);
		int b = sca.nextInt();
		sca.close();
		if(ch == '+') {
			System.out.println(a + b);
		} else if(ch == '-') {
			System.out.println(a - b);
		} else if(ch == '*') {
			System.out.println(a * b);
		} else if(ch == '/') {
			System.out.println(a / b);
		} else if(ch == '%') {
			System.out.println(a % b);
		} else {
			System.out.println("ERROR");
		}
	}

}