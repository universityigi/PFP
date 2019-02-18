object E3Main extends App {

    var punti = 0

    val v1:Vector[Int] = E3.noobSort(Vector(3,6,9,2,1))
    val c1 = Vector(1,2,3,6,9)
    println("Test 1: "+v1+" (corretto: "+c1+")")
    if (v1 == c1) punti += 1

    val v2 = E3.noobSort(Vector())
    val c2 = Vector()
    println("Test 2: "+v2+" (corretto: "+c2+")")
    if (v2 == c2) punti += 1

    val v3:Vector[String] = E3.noobSort(Vector("uno","due","tre"))
    val c3 = Vector("due","tre","uno")
    println("Test 3: "+v3+" (corretto: "+c3+")")
    if (v3 == c3) punti += 1

    println("Punti: " + punti + "/3")
}
