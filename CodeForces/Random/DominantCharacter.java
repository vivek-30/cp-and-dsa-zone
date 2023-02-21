package competetiveQuestions;

import java.io.*;

public class DominantCharacter {
	
	private static int solve(int n, String str) {
		
		int ans = Integer.MAX_VALUE;
		
		for(int i = 0; i < str.length(); i++) {
			byte track[] = {0, 0, 0};

			track[str.charAt(i) - 'a']++;
			for(int j = i+1; j < Math.min(n, i+7); j++) {
				track[str.charAt(j) - 'a']++;
				
				if(track[0] > track[1] && track[0] > track[2]) {
					ans = Math.min(ans, (j - i + 1));
				}
			}
		}
		
		return ans == Integer.MAX_VALUE ? -1 : ans;
	}
	
	public static void main(String... args) throws IOException {
		
		InputStreamReader obj = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(obj);
		
		int t = Integer.parseInt(br.readLine());
		
		while(t-->0)  {
			int n = Integer.parseInt(br.readLine());
			String str = br.readLine();
			
			System.out.println(solve(n, str));
		}
		
	}
}

