object E3Main extends App {
    var punti = 0
    
    val n1 = E3.maxPrefisso(List(1, 1, 1, 1, 1), 3)
    println(n1 + " (corretto: 3)")
    if (n1==3) punti += 1 
    
    val n2 = E3.maxPrefisso(List(5, 2, 4, 7), 8)
    println(n2 + " (corretto: 2)")
    if (n2==2) punti += 1 
    
    val n3 = E3.maxPrefisso(List(5, 2, 4, 7), 4)
    println(n3 + " (corretto: 0)")
    if (n3==0) punti += 1 
    
    println("Punti: " + punti + " su 3")
}
