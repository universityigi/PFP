object E1Main extends App {
    
    var punti = 0
    
    val a1:Seq[Double] = Vector(1,2,1,2,1,2)
    val b1:Seq[Double] = Vector(2,1,2,1,2,1)
    val s1:Double = E1.scalarProd(a1,b1)
    val c1 = 12.0
    if (s1 == c1) punti += 1
    println("Test 1: "+s1+" (corretto: "+c1+")")

    val a2:Seq[Double] = Vector(1,2,1,2,1,2)
    val b2:Seq[Double] = Vector(2,1,2,1,2)
    val s2:Double = E1.scalarProd(a2,b2)
    val c2 = 10.0
    if (s2 == c2) punti += 1
    println("Test 2: "+s2+" (corretto: "+c2+")")

    val a3:Seq[Double] = Vector(1)
    val b3:Seq[Double] = Vector()
    val s3:Double = E1.scalarProd(a3,b3)
    val c3 = 0.0
    if (s3 == c3) punti += 1
    println("Test 3: "+s3+" (corretto: "+c3+")")
    
    println("Punti: " + punti + "/3")
}
