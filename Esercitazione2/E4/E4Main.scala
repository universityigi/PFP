object E4Main extends App {
    var punti = 0
    
    val n1 = E4.checkBitonic(List(1,2,5,6,9,4,3,2,0))
    val s1 = (List(1,2,5,6,9),List(4,3,2,0))
    println(n1 + " (corretto: " + s1 + ")")
    if (n1==s1) punti += 1

    val n2 = E4.checkBitonic(List())
    val s2 = (Nil,Nil)
    println(n2 + " (corretto: " + s2 + ")")
    if (n2==s2) punti += 1

    val n3 = E4.checkBitonic(List(1,2,3,2,3,2,1))
    val s3 = (Nil,Nil)
    println(n3 + " (corretto: " + s3 + ")")
    if (n3==s3) punti += 1

    val n4 = E4.checkBitonic(List(1,2,-1))
    val s4 = (List(1,2),List(-1))
    println(n4 + " (corretto: " + s4 + ")")
    if (n4==s4) punti += 1
    
    println("Punti: " + punti + " su 4")
}
