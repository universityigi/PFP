import Point._

object C1Main extends App {
    val c = Circle(1,1,5)
    val l1 = List(Point(1,1), Point(5,7), Point(1,2), Point(1,0)) 
    val l2 = List(Point(1,1), Point(1,2)) 

    val n1:Boolean     = c >? l1  // c contiene tutti i punti in l1?
    val n2:Boolean     = c >? l2  // c contiene tutti i punti in l2?
    val p1:List[Point] = c >> l1  // punti di l1 contenuti in c
    val p2:List[Point] = c >> l2  // punti di l2 contenuti in c
    val s:String       = "punto=" + Point(9,4) // converte punto a stringa
    val p:List[Point]  = l2 +++ List(Point(13,13)) // concatena liste di punti

    println(s  + " [corretto: punto=(9.0, 4.0)]")
    println(n1 + " [corretto: false]")
    println(p1 + " [corretto: List((1.0,1.0), (1.0,2.0))]")
    println(n2 + " [corretto: true]")
    println(p2 + " [corretto: List((1.0,1.0), (1.0,2.0))]")
    println(p +  " [corretto: List((1.0,1.0), (1.0,2.0)), ((13.0,13.0))]")
}
