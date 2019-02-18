import E1._

object E1Main extends App {
    var punti = 0

    val n1 = 10.isPrime
    println(n1+" (corretto: false)")
    if (n1==false) punti += 1 

    val n2 = 11.isPrime
    println(n2+" (corretto: true)")
    if (n2==true) punti += 1 

    val n3 = 96.isPrime
    println(n3+" (corretto: false)")
    if (n3==false) punti += 1 

    val n4 = 97.isPrime
    println(n4+" (corretto: true)")
    if (n4==true) punti += 1 

    val n5 = 1.isPrime
    println(n5+" (corretto: false)")
    if (n5==false) punti += 1 

    val n6 = -3.isPrime
    println(n6+" (corretto: false)")
    if (n6==false) punti += 1 

    println("Punti: " + punti + " su 6")    
}
