import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String str = sca.nextLine();
		String temp = sca.nextLine();
		sca.close();
		for(int i = 0; i < 10; i++) {
			str = str.replaceAll(temp, "");
		}
		System.out.println(str);
	}

}