import java.util.Scanner;

public class Main {
	
	public static String fun1(double open, double close, double low) {
		if(low < open && low < close) {
			return " Lower Shadow";
		}
		return "";
	}
	
	public static String fun2(double open, double close, double high) {
		if(high > open && high > close) {
			return " Upper Shadow";
		}
		return "";
	}

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		double open = sca.nextDouble();
		double high = sca.nextDouble();
		double low = sca.nextDouble();
		double close = sca.nextDouble();
		sca.close();
		if(close < open) {		// bw-solid
			System.out.print("BW-Solid");
		} else if(close > open) {		// r-hollow
			System.out.print("R-Hollow");
		} else if(open == close ) {		// r-cross
			System.out.print("R-Cross");
		}
		String str1 = fun1(open, close, low);
		String str2 = fun2(open, close, high);
		if(str1 != "" || str2 != "") System.out.print(" with");
		System.out.print(str1);
		if(str1 != "" && str2 != "") System.out.print(" and");
		System.out.print(str2);	
	}

}
