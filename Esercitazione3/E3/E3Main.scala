object E3Main extends App {
    var punti = 0

    val e  = E()
    val t1 = T(e,  10, e)
    val t2 = T(e,  30, e)
    val t3 = T(e,  25, t2)
    val t4 = T(t3, 40, e)
    val t5 = T(t1, 20, t4)
    val t6 = T(e, 40, t3)
    val t7 = T(t1, 20, t6)

    val n1 = e.isSearchTree
    println(n1+" (corretto: true)")
    if (n1==true) punti += 1 

    val n2 = t1.isSearchTree
    println(n2+" (corretto: true)")
    if (n2==true) punti += 1 

    val n3 = t5.isSearchTree
    println(n3+" (corretto: true)")
    if (n3==true) punti += 1 

    val n4 = t6.isSearchTree
    println(n4+" (corretto: false)")
    if (n4==false) punti += 1 

    val n5 = t7.isSearchTree
    println(n5+" (corretto: false)")
    if (n5==false) punti += 1 

    println("Punti: " + punti + " su 5")
}
