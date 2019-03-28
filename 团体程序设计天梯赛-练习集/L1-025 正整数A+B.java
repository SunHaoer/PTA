import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String inputStr = sca.nextLine();
		String str1 = inputStr.split(" ")[0];
		String str2 = inputStr.split(" ")[1];
		sca.close();
		while(str1.length() == 0 || str2.length() == 0) {}
		int a = -1, b = -1;
		try {
			a = Integer.parseInt(str1);
			if(a <= 0 || a > 1000) a = -1;
		} catch(Exception e) {
			a = -1;
		}
		try {
			b = Integer.parseInt(str2);
			if(b <= 0 || b > 1000) b = -1;
		} catch (Exception e) {
			b = -1;
		}
		if(a == -1) System.out.print("? + ");
		else System.out.print(a + " + ");
		if(b == -1) System.out.print("? = ");
		else System.out.print(b + " = ");
		if(a != -1 && b != -1) System.out.println(a + b);
		else System.out.println("?");
	}
}

/*
 * 测试点3未通过
 */
