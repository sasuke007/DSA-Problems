/**
 * @input A : Integer
 * @input B : Integer array
 *
 * @Output Long.
 */
func solve(A int , B []int )  (int64) {
    var count int64 = 0
    var last int64 = 0
    for index,value:= range B{
        if(value==1){
            last=int64(index+1)
        }
        count+=last
    }
    return count
}
