import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String input = sca.nextLine();
		if(input.length() == 1) {System.out.println(""); return;}
		input = input.substring(0, input.length() - 1);
			String[] output = input.split(" ");
			for(int i = 0;i < output.length - 1;i++) {
				if(output[i].length() != 0) {
					System.out.print(output[i].length() + " ");
				}
			}
			System.out.print(output[output.length - 1].length());
	}
}