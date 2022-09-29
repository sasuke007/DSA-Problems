/**
 * @input A : Integer
 * @input B : Integer
 *
 * @Output Integer
 */
 //import "fmt"
func solve(A int , B int )  (int) {
    answer:=0
    for i:=31;i>=0;i--{
        if (A&(1<<i))!=0 && (B!=0) {
            answer|=(1<<i)
            B--
        }
    }
    //fmt.Println(answer)
    for i:=0;i<32;i++{
        if B!=0 && (answer&(1<<i))==0 {
            answer|=(1<<i)
            B--
        }
    }
    return answer
}
