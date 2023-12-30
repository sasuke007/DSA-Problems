fun main(args: Array<String>) {
    val matrix: Array<IntArray> = arrayOf(
        intArrayOf(1, 2, 3, 4),
        intArrayOf(5, 0, 7, 8),
        intArrayOf(0, 10, 11, 12),
        intArrayOf(13, 14, 15, 0)
    )

    val main = Main()
    main.setZeroes(matrix)
    main.print(matrix)
}

class Main {

    fun print(matrix: Array<IntArray>) {
        matrix.forEach { it ->
            it.forEach {
                print("$it ")
            }
            println()
        }
        println("------------------------")
    }

    fun setZeroes(matrix: Array<IntArray>): Unit {
        val rows: Int = matrix.size
        val columns: Int = matrix[0].size

        //print(matrix)

        var isZeroRow = false
        var isZeroColumn = false

        for(i in 0..<rows){
            if(matrix[i][0]==0){
                isZeroRow=true
            }
        }
        for(i in 0..<columns){
            if(matrix[0][i]==0){
                isZeroColumn=true
            }
        }

        matrix.forEachIndexed { rowIndex, rowValue ->
            rowValue.forEachIndexed { colIndex, _ ->
                if (matrix[rowIndex][colIndex] == 0) {
                    matrix[rowIndex][0] = 0
                    matrix[0][colIndex] = 0
                }
            }
        }

        print(matrix)

        for (i in 1..<rows) {
            if (matrix[i][0] == 0) {
                for (j in 0..<columns) {
                    matrix[i][j] = 0
                }
            }
        }

        for (i in 1..<columns) {
            if (matrix[0][i] == 0) {
                for (j in 0..<rows) {
                    matrix[j][i] = 0
                }
            }
        }

        if (isZeroRow) {
            for (i in 0..<rows ){
                matrix[i][0]=0
            }
        }
        if (isZeroColumn) {
            for (i in 0..<columns){
                matrix[0][i]=0
            }
        }
    }
}
