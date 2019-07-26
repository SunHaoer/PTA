import java.util.Scanner;

public class Main {
	
	public static double a, b, c, d;
	
	public static double fun1(double x) {
		return a * x * x * x + b * x * x + c * x + d;
	}

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		a = sca.nextDouble();
		b = sca.nextDouble();
		c = sca.nextDouble();
		d = sca.nextDouble();
		double m = sca.nextDouble();
		double n = sca.nextDouble();
		double ans = 1;
		sca.close();
		while(n - m >= 0.0009) {
			if(fun1(m) * fun1(n) != 0) {
				ans = (m + n) / 2;
				if(fun1(ans) == 0) {
					break;
				} else if(fun1(ans) * fun1(m) > 0) {
					m = ans;
				} else if(fun1(ans) * fun1(n) > 0) {
					n = ans;
				}
			} else if(fun1(m) == 0) {
				ans = m;
				break;
			} else if(fun1(n) == 0) {
				ans = n;
				break;
			}
		}
		System.out.printf("%.2f", ans);
	}

}

