import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String str = sca.next();
		String str1[] = str.split("/");
		str = sca.next();
		String str2[] = str.split("/");
		sca.close();
		int a1 = Integer.parseInt(str1[0]);
		int b1 = Integer.parseInt(str1[1]);
		int a2 = Integer.parseInt(str2[0]);
		int b2 = Integer.parseInt(str2[1]);
		int a3 = a1 * b2 + a2 * b1;
		int b3 = b1 * b2;
		for(int i = 2; i <= a3 && i <= b3; i++) {
			if(a3 % i == 0 && b3 % i == 0) {
				a3 /= i;
				b3 /= i;
				i--;
			}
		}
		if(b3 != 1) {
			System.out.println(a3 + "/" + b3);
		} else {
			System.out.println(a3);
		}
	}

}
