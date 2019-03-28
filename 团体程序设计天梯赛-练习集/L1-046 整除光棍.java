import java.math.BigInteger;
import java.util.Scanner;

public class Test {
	
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		sca.close();
		String str = "1";
		BigInteger big1 = new BigInteger(str);
		BigInteger big2 = new BigInteger(n + "");
		while(!big1.remainder(big2).toString().equals("0")) {
			str = str + "1";
			big1 = new BigInteger(str);
		}
		System.out.println(big1.divide(big2) + " " + big1.toString().length());
	}

}
