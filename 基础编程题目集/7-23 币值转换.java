import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String str = sca.next();
		sca.close();
		for(int i = 0; i < str.length() - 1; i++) {
			if(str.charAt(i) == '0') {
				if(str.length() - 1 - i == 4) {
					System.out.print("W");
					continue;
				}
				if(str.charAt(i + 1) == '0') continue;
			}
			char ch = (char)(str.charAt(i) - '0' + 'a');
			System.out.print(ch);
			if(str.charAt(i) == '0') continue;
			if(str.length() - 1 - i == 8) System.out.print("Y");
			else if(str.length() - 1 - i == 4) System.out.print("W");
			else if((str.length() - 1 - i) % 4 == 3) System.out.print("Q");
			else if((str.length() - 1 - i) % 4 == 2) System.out.print("B");
			else if((str.length() - 1 - i) % 4 == 1) System.out.print("S");
		}
		if(str.charAt(str.length() - 1) != '0' || str.length() == 1) {
			char ch = (char)(str.charAt(str.length() - 1) - '0' + 'a');
			System.out.print(ch);			
		}
	}

}

