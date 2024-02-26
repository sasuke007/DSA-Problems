import kotlin.math.max

fun main(args: Array<String>) {
    val nums = intArrayOf(-2,1,-3,4,-1,2,1,-5,4)
    val main = Main()
    println(main.maxSubArray(nums))
}

class Main {
    fun maxSubArray(nums: IntArray): Int {
        var (currStartIndex, currEndIndex) = 0 to 0
        var (startIndex, endIndex) = 0 to 0
        var maxTillPreviousElement = if (nums[0] < 0) 0 else nums[0]
        var globalMax = nums[0]
        for (i in 1..<nums.size) {
            if (nums[i] > maxTillPreviousElement + nums[i]) {
                startIndex = currStartIndex
                endIndex = currEndIndex
                currStartIndex = i
                currEndIndex = i
                maxTillPreviousElement = nums[i]
            } else {
                maxTillPreviousElement += nums[i]
                currEndIndex = i
            }
            if(maxTillPreviousElement>globalMax){
                globalMax=maxTillPreviousElement
                startIndex=currStartIndex
                endIndex=currEndIndex
            }
        }
        for (i in startIndex..endIndex) {
            print("${nums[i]} ")
        }
        println()
        return globalMax
    }

}
