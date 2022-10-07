/**
 * @input A : Integer array
 * 
 * @Output Integer
 */
import "math"
func firstMissingPositive(A []int )  (int) {
    n:=len(A)
    answer:=n+1
    for index,value:=range A{
            if value<0{
                A[index]=n+1
            }
    }
    for _,value := range A{
            value:=int(math.Abs(float64(value)))
            if value>=1 && value<=n {
                if A[value-1]>0{
                    A[value-1]=-1*A[value-1]
                }
            }
    }
    for index,value := range A{
            if value >= 0 {
                answer = index+1
                break
            }
    }
    return answer
}
