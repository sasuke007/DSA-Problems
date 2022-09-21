func climbStairs(n int) int {
    first := 1
    second := 1
    for i:=2;i<=n;i++ {
        temp:=second+first
        first=second
        second=temp
    }
    return second
}