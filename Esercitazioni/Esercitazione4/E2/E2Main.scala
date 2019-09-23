object E2Main extends App {

    var punti = 0

    val s1 = E2.s(0)
    val c1 = (0,0) #:: Stream.empty
    println("Test 1: "+s1.toList+" (corretto: "+c1.toList+")")
    if (s1==c1) punti += 1

    val s2 = E2.s(1)
    val c2 = (0,1) #:: (1,0) #:: Stream.empty
    println("Test 2: "+s2.toList+" (corretto: "+c2.toList+")")
    if (s2==c2) punti += 1

    val s3 = E2.s(2)
    val c3 = (0,2) #:: (1,1) #:: (2,0) #:: Stream.empty
    println("Test 3: "+s3.toList+" (corretto: "+c3.toList+")")
    if (s3==c3) punti += 1

    val dt = E2.dovetail
    val r4 = dt.take(10).toList
    val c4 = List((0,0), (0,1), (1,0), (0,2), (1,1), (2,0), (0,3), (1,2), (2,1), (3,0))
    println("Test 4: "+r4.toList+" (corretto: "+c4.toList+")")
    if (r4==c4) punti += 1

    val r5 = dt.take(11).toList
    val c5 = List((0,0), (0,1), (1,0), (0,2), (1,1), (2,0), (0,3), (1,2), (2,1), (3,0), (0,4))
    println("Test 5: "+r5.toList+" (corretto: "+c5.toList+")")
    if (r5==c5) punti += 1

    println("Punti: " + punti + " su 5")
}
