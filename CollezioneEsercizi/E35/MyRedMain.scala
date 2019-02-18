import MyRed._

object MyRedMain extends App {
    val l = List.range(1,1000000)

    val v1 = l.myReduce(_+_)
    println("Test 1: "+v1+" (corretto: " + Some(l.reduce(_+_)) + ")")

    val v2 = List(1).myReduce(_+_)
    println("Test 2: "+v2+" (corretto: " + Some(List(1).reduce(_+_)) + ")")

    val v3 = List[Int]().myReduce(_+_)
    println("Test 3 "+v3+" (corretto: " + None + ")")
}
