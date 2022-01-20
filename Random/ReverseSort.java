package competetiveQuestions;

import java.util.*;

public class ReverseSort {
	static Scanner sc = new Scanner(System.in);
	
	private static boolean isSorted(int n, String s) {
		
		if(n == 1) return true;
		
		for(int i = 1; i < n; i++) {
			if(s.charAt(i) - '0' < s.charAt(i-1) - '0') return false;
		}
		
		return true;
	}
		
	static public void main(String[] args) {
		int t = sc.nextInt();
		while(t-->0) {
			
			int n = sc.nextInt();
			String s = sc.next();
			
			if(!isSorted(n, s)) {
				System.out.println(1);
				char[] temp = s.toCharArray();
				Arrays.sort(temp);
				
				List<Integer> res = new ArrayList<>();

				for (int i = 0; i < s.length(); i++) {
					if(s.charAt(i) != temp[i])  {
						res.add(i+1);
					}
				}
				
				System.out.println(res.size());
				for(Integer i: res) {
					System.out.print(i + " ");
				}
				System.out.println();
				
			} else System.out.println(0);
		}
	}
}

