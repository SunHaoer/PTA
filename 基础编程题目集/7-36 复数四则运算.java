import java.util.Scanner;

/*
 *  (a+bi)+(c+di)=(a+c)+(b+d)i
 *  (a+bi)-(c+di)=(a-c)+(b-d)i
 *  (a+bi)(c+di)=(ac-bd)+(bc+ad)i
 *  (a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +((bc-ad)/(c^2+d^2))i
 */

public class Main {
	
	public static double a, b, c, d, ans1 = 0, ans2 = 0; 
	
	public static void print(char ch) {
		System.out.printf("(%.1f", a);
		if(b >= -0.05) System.out.printf("+");
		System.out.printf("%.1fi) %c (%.1f", b, ch, c);
		if(d >= -0.05) System.out.printf("+");
		System.out.printf("%.1fi) = ", d);
		if(ans1 <= -0.05 || ans1 >= 0.05) System.out.printf("%.1f", ans1);
		if( (ans2 >= 0.05) && (ans1 <= -0.05 || ans1 >= 0.05) ) System.out.printf("+");
		if(ans2 <= -0.05 || ans2 >= 0.05) System.out.printf("%.1fi", ans2);
		if( (ans1 > -0.05 && ans1 < 0.05) && (ans2 > -0.05 && ans2 < 0.05) ) System.out.printf("0.0");
		System.out.printf("\n");
	}
	
	public static void fun1() {
		ans1 = a + c;
		ans2 = b + d;
		print('+');
	}
	
	public static void fun2() {
		ans1 = a - c;
		ans2 = b - d;
		print('-');
	}
	
	public static void fun3() {
		ans1 = a * c - b * d;
		ans2 = b * c + a * d;
		print('*');
	}
	
	public static void fun4() {
		ans1 = (a * c + b * d) / (c * c + d * d);
		ans2 = ( (b * c - a * d) / (c * c + d * d) );
		print('/');
	}

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		a = sca.nextDouble();
		b = sca.nextDouble();
		c = sca.nextDouble();
		d = sca.nextDouble();
		ans1 = 0;
		ans2 = 0;
		sca.close();
		fun1();		
		fun2();
		fun3();
		fun4();
	}

}

