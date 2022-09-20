func Min(x, y int) int {
 if x < y {
   return x
 }
 return y
}

func Max(x, y int) int {
 if x > y {
   return x
 }
 return y
}

func rob(nums []int) int {
    n:= len(nums)
    if n==1{
        return nums[0];
    }
    dp:= make([]int,n)
    dp[n-1]=nums[n-1];
    dp[n-2]=Max(dp[n-1],nums[n-2])
    for i:=len(nums)-3;i>=0;i--{
        dp[i]=Max(nums[i]+dp[i+2],dp[i+1])
    }
    return dp[0]
}