import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String str = sca.nextLine() + '\n';
		int cnt = 0;
		for(char ch : str.toCharArray()) {
			if(ch == '6') {
				cnt++;
			} else {
				if(cnt <= 3) {
					while(cnt-- > 0) {
						System.out.print("6");
					}
				} else if(cnt <= 9) {
					System.out.print("9");
				} else {
					System.out.print("27");
				}
				cnt = 0;
				System.out.print(ch);
			}
		}
		sca.close();
	}
	
}
