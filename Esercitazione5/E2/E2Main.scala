import E2._
import Prof._

object E2Main extends App {

    var punti = 0

    // test correttezza
    val v0 = Vector(1,2,3)
    val m0 = Vector(2,4,6)
    val c0 = v0.isMappedFrom(m0, 2*_)
    val r0 = v0.isMappedFromPar(m0, 2*_)
    if (r0 == c0) punti += 1
    println("Test 0: " + r0 + " (corretto: " + c0 + ")")

    val v1 = Vector(1,2,3)
    val m1 = Vector(2,3)
    val c1 = v1.isMappedFrom(m1, 1+_)
    val r1 = v1.isMappedFromPar(m1, 1+_)
    if (r1 == c1) punti += 1
    println("Test 1: " + r1 + " (corretto: " + c1 + ")")

    val v2 = Vector(1,2,3)
    val m2 = Vector(2,3,3)
    val c2 = v2.isMappedFrom(m2, 1+_)
    val r2 = v2.isMappedFromPar(m2, 1+_)
    if (r2 == c2) punti += 1
    println("Test 2: " + r2 + " (corretto: " + c2 + ")")

    // test prestazionali
    def isPrime(n:Int) = n>1 && (2 to Math.sqrt(n).toInt).forall(n % _ != 0)
    val n = 2000000
    val f:Int=>String = x => if (isPrime(x)) "primo" else "non primo"
    val v:Vector[Int] = (1 to n).toVector
    val m:Vector[String] = v map f
    val (c:Boolean, ts) = profila { v.isMappedFrom(m, f) }
    val (r:Boolean, tp) = profila { v.isMappedFromPar(m, f) }
    if (r == c) punti += 1
    println("Test 3: " + r + " (corretto: " + c + " - t_par: " + tp + " - t_seq: " + ts)

    println("Punti: " + punti + "/4 - Speedup: " + ts/tp)
}
