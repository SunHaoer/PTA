import java.util.Scanner;

public class Main {
	// "a" > "aa" == true
	
	public static boolean fun1(String str1, String str2) {
		for(int i = 0; i < str1.length() && i < str2.length(); i++) {
			if(str1.charAt(i) > str2.charAt(i)) return true;
			else if(str1.charAt(i) < str2.charAt(i)) return false;
		}
		return str1.length() > str2.length();
	}

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		int k = sca.nextInt();
		String[] strs = new String[n];
		for(int i = 0; i < n; i++) {
			strs[i] = sca.next();
		}
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < n - 1 - i; j++) {
				if(fun1(strs[j], strs[j + 1])) {
					String temp = strs[j];
					strs[j] = strs[j + 1];
					strs[j + 1] = temp;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			System.out.println(strs[i]);
		}
		sca.close();
	}

}
