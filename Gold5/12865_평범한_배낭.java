import java.util.Scanner;

public class Main {

	public static int[][] dp;
	static int[] W;
	static int[] V;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt(), K = sc.nextInt();
		int maxValue = 0;
		
		W = new int[N+1];
		V = new int[N+1];
		dp = new int[N+1][K+1];
		
		for(int i=1;i<=N;i++) {
			W[i] = sc.nextInt();
			V[i] = sc.nextInt();
		}
		
		System.out.println(bag(N, K));
		

	}
	
	public static int bag(int i, int k) {
		
		if(i < 0) return 0;
		
		if(dp[i][k] == 0)//탐색 X
			if(W[i] > k) 
				dp[i][k] = bag(i-1, k);
			else
				dp[i][k] = Math.max(bag(i-1, k), bag(i-1, k - W[i]) + V[i]);
		
		return dp[i][k];

	}

}
