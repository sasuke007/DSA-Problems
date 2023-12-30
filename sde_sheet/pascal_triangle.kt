fun main(args: Array<String>) {
    val (a, b) = readln().split(' ')
    val n = a.toInt()
    val r = b.toInt()
    val main: Main = Main()
    println(main.findNcr(n, r))
}

class Main {
    fun findNcr(n: Int, r: Int): Int {
        val list: MutableList<Int> = mutableListOf(1, 1)
        for (i in 2..n) {
            var temp = 1
            for (j in 1..<list.size) {
                val x = list[j]
                list[j] = temp + list[j]
                temp = x
            }
            list.add(1)
        }
        println(list)
        return list[r - 1]
    }

}