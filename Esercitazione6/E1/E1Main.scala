object E1Main extends App {
    var punti = 0

    val r1 = E1.buildMatrix(2,2)((i,j) => i + j)
    val c1:Vector[Vector[Double]] = Vector(Vector(0.0,1.0),Vector(1.0,2.0))
    println("Test 1: " + r1 + " (corretto: " + c1 + ")")
    if (c1 == r1) punti += 1

    val r2 = E1.buildMatrix(0,0)((i,j) => 0.0)
    val c2 = Vector()
    println("Test 2: " + r2 + " (corretto: " + c2 + ")")
    if (c2 == r2) punti += 1

    val r3 = E1.buildMatrix(2,4)((i,j) => if (i==0) 1.0 else if (j==0) 1.0 else if (j==3) 1.0 else 0.0)
    val c3 = Vector(Vector(1.0,1.0,1.0,1.0),Vector(1.0,0.0,0.0,1.0))
    println("Test 3: " + r3 + " (corretto: " + c3 + ")")
    if (c3 == r3) punti += 1

    val r4 = E1.buildMatrix(1,1)((i,j) => if (i==j) 1.0 else 0.0)
    val c4 = Vector(Vector(1.0))
    println("Test 4: " + r4 + " (corretto: " + c4 + ")")
    if (c4 == r4) punti += 1

    println("Punti: "+punti+" su 4")
}
