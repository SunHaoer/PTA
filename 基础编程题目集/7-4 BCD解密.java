import java.util.Scanner;

public class Main {

	public static String fun1(int num) {
		String str = "";
		while(num != 0) {
			str += num % 16;
			num /= 16;
		}
		return new StringBuffer(str).reverse().toString();
	}
	
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int num = sca.nextInt();
		sca.close();
		if(num != 0) {
			System.out.println(fun1(num));
		} else {
			System.out.println("0");
		}
	}

}


/*
 *  10进制转16进制
 */