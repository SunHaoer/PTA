import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int repeat = sca.nextInt();
		String empty = sca.nextLine();
		for(int i = 0; i < repeat; i++) {
			String inputStr = sca.nextLine();
			String[] strs = inputStr.split(",");
			strs[1] = strs[1].substring(0, strs[1].length() - 1);
			if(strs[0].endsWith("ong") && strs[1].endsWith("ong")) {
				String[] outputStrs = strs[1].split(" ");
				int len = outputStrs.length;
				outputStrs[len - 1] = "zhong";
				outputStrs[len - 2] = "ben";
				outputStrs[len - 3] = "qiao";
				System.out.print(strs[0]);
				System.out.print(",");
				for(String str : outputStrs) {
					if(str.isEmpty()) continue;
					System.out.print(" ");
					System.out.print(str);
				}
				System.out.println(".");
			} else {
				System.out.println("Skipped");
			}
		}
		sca.close(); 
	}
	
}
