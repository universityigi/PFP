object C2Main extends App {
    val l1:List[Int] = List(1,0,1,1)
    val l2:List[Int] = List(1,0,0,1)
    val l3:List[Int] = List(1,1,1,1,4)
    val l4:List[Int] = Nil

    val r1:Int = C2.ps(l1,l2)
    println(r1  + " [corretto: 2]")

    val r2:Int = C2.ps(l1,l3)
    println(r2  + " [corretto: 3]")

    val r3:Int = C2.ps(l1,l4)
    println(r3  + " [corretto: 0]")
}
