import java.util.Scanner;

public class Main {
	
	public static String [] hashTable = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String str = sca.next();
		sca.close();
		boolean flag = false;
		for(int i = 0; i < str.length(); i++) {
			if(flag == true) {
				System.out.print(" ");
			}
			if(str.charAt(i) == '-') {
				System.out.print("fu");
			} else {
				System.out.print(hashTable[str.charAt(i) - '0']);
			}
			flag = true;
		}
	}

}