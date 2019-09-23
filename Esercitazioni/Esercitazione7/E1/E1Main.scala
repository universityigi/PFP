import E1._

object E1Main extends App {

    var punti = 0
    var test  = 0

    def doTest[T](s:List[T], l:List[T], c:Boolean) = {
        test += 1
        val r:Boolean = s.subList(l)
        println("Test " + test + ": " + r + " (corretto: " + c + ")")
        if (c == r) punti += 1
    }
    
    doTest(List(1,2,3,4,5), List(2,3,5), true)
    doTest(List(), List(2,3,5), false)
    doTest(List(1,2), List(), true)
    doTest(List("b", "c", "a"), List("a", "b"), false)
    doTest(List(true, false, false), List(true, true), false)
    doTest(List(true, false, true), List(true, true, false), false)
    doTest(List(Vector(1), Vector(2)), List(Vector(1), Vector(2)), true)

    println("Punti: " + punti + " su " + test)
}
