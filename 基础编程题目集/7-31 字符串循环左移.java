import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String str = sca.nextLine();
		int n = sca.nextInt();
		n = n % str.length();
		sca.close();
		for(int i = n; i < str.length(); i++) {
			System.out.print(str.charAt(i));
		}
		for(int i = 0; i < n; i++) {
			System.out.print(str.charAt(i));
		}
	}

}