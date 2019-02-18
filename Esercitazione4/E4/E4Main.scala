object E4Main extends App {
    var punti = 0

    val s1:Boolean = E4.isAnagramOf("anna", "nana")
    val c1 = true
    println("Test 1: "+s1+" (corretto: "+c1+")")
    if (s1 == c1) punti += 1

    val s2 = E4.isAnagramOf("Anna", "nana")
    val c2 = false
    println("Test 2: "+s2+" (corretto: "+c2+")")
    if (s2 == c2) punti += 1

    val s3 = E4.isAnagramOf("grano", "rogna")
    val c3 = true
    println("Test 3: "+s3+" (corretto: "+c3+")")
    if (s3 == c3) punti += 1

    println("Punti: " + punti + " su 3")
}
