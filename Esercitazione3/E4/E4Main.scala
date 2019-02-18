object E4Main extends App {

    var punti = 0

    val n1 = E4.getModel(0)
    println(n1+" (corretto: List())")
    if (n1==Nil) punti += 1 

    val n2 = E4.getModel(1)
    val r2 = List(Circle(0.5,0.5,0.5))
    println("\n"+n2+" (corretto: "+r2+")")
    if (n2==r2) punti += 1 

    val n3 = E4.getModel(2)
    val r3 = List(Circle(0.25,0.25,0.25), Circle(0.5,0.5,0.5))
    println("\n"+n3+" (corretto: "+r3+")")
    if (n3==r3) punti += 1 

    val n4 = E4.getModel(4)
    val r4 = List(Circle(0.125,0.125,0.125), Circle(0.25,0.25,0.25), Circle(0.375,0.375,0.375), Circle(0.5,0.5,0.5))
    println("\n"+n4+" (corretto: "+r4+")")
    if (n4==r4) punti += 1 

    println("Punti: " + punti + " su 4")
    
    val m = E4.getModel(50)    

    Frame2D.display(n2, 500, 500)
    Frame2D.display(n3, 500, 500)
    Frame2D.display(n4, 500, 500)
    Frame2D.display(m,  500, 500)
}
