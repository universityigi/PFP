import E2._
import Prof._

object E2Main extends App {

    var punti = 0

    // test correttezza
    val s0 = Set(-1,-2,3,4,7,-30)
    val c0 = sum3(s0)
    val r0 = sum3Par(s0)
    if (r0 == c0) punti += 1
    println("Test 0: " + r0 + " (corretto: " + c0 + ")")

    val s1 = Set(1,-2)
    val c1 = sum3(s1)
    val r1 = sum3Par(s1)
    if (r1 == c1) punti += 1
    println("Test 1: " + r1 + " (corretto: " + c1 + ")")

    val s2 = Set(4,2,-6,1,5)
    val c2 = sum3(s2)
    val r2 = sum3Par(s2)
    if (r2 == c2) punti += 1
    println("Test 2: " + r2 + " (corretto: " + c2 + ")")

    val s3:Set[Int] = Set()
    val c3 = sum3(s3)
    val r3 = sum3Par(s3)
    if (r3 == c3) punti += 1
    println("Test 3: " + r3 + " (corretto: " + c3 + ")")

    // test prestazionali
    val r = scala.util.Random
    r.setSeed(4815162342L)
    val s4 = (for (i <- 0 until 3000) yield r.nextInt(6000)-2000).toSet

    val (c4, ts) = profila { sum3(s4) }
    val (r4, tp) = profila { sum3Par(s4) }

    if (r4 == c4) punti += 1
    println("Test 4: " + r4.size + " (corretto: " + c4.size + ")")

    println("Punti: " + punti + "/5 - Speedup: " + ts.toDouble/tp)
}