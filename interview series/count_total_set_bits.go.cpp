/**
 * @input A : Integer
 *
 * @Output Integer
 */
import (math "math"
//"fmt"
)
func max(A int,B int) int {
if(A>=B){
return A
}
return B
}
func solve(A int )  (int) {
    A+=1
    answer:=0
    mod:=int(math.Pow(10,9))+7
    for i:=0;i<32;i++{
        periodicity:= int(math.Pow(2,float64(i+1)))
        //fmt.Println(periodicity)
        bitsInCurrentColumn:=((A/periodicity)*(periodicity/2))+int(max(0,A%periodicity-periodicity/2))
        //fmt.Println(bitsInCurrentColumn)
        answer= (answer + bitsInCurrentColumn)%mod
    }
    return answer
}
