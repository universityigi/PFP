object E2Main extends App {
    var punti = 0
    
    val b1:Boolean = E2.corrisp(List("uno", "cinque", "x", "sei"), List(3, 6, 1), (s:String) => s.length)
    println(b1+" (corretto: true)")
    if (b1==true) punti += 1 

    val b2:Boolean = E2.corrisp(List(1, 2, 3, 4), List(2, 4, 5), (_:Int)*2)
    println(b2+" (corretto: false)")
    if (b2==false) punti += 1 

    val b3:Boolean = E2.corrisp(List(-1, 0, 2, -5, 1), List(false, false, true), (_:Int)>0)
    println(b3+" (corretto: true)")
    if (b3==true) punti += 1     
    
    println("Punti: " + punti + " su 3")
}
