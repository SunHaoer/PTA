import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String str = sca.next();
		int a = 0, b = 0;
		sca.close();
		int i = 0;
		for(i = 0; i < str.length(); i++) {
			if(str.charAt(i) == '/') {
				break;
			}
			a = a * 10 + (str.charAt(i) - '0');
		}
		for(i = i + 1; i < str.length(); i++) {
			b = b * 10 + (str.charAt(i) - '0');
		}
		for(i = 2; i <= a && i <= b; i++) {
			while(a % i == 0 && b % i == 0) {
				a /= i;
				b /= i;
			}
		}
		System.out.println(a + "/" + b);
	}

}