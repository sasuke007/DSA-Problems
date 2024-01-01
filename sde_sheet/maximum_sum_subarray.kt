import kotlin.math.max

fun main(args: Array<String>) {
    val nums = intArrayOf(5,4,-1,7,8)
    val main = Main()
    println(main.maxSubArray(nums))
}

class Main {
    fun maxSubArray(nums: IntArray): Int {
        var maxTillPreviousElement = if (nums[0] < 0) 0 else nums[0]
        var globalMax = nums[0]
        for (i in 1..<nums.size) {
            maxTillPreviousElement = max(nums[i], maxTillPreviousElement + nums[i])
            globalMax = max(globalMax, maxTillPreviousElement)
        }
        return globalMax
    }

}
