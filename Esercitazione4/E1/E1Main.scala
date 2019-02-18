import E1._
import Prof._

object E1Main extends App {
    var punti = 0

    val a1 = List(2,1,3,4,3)
    val b1 = List(0,1,2,1,2,4,9,2,1,1)
    val r1 = a1.countOccIn(b1).sorted
    val c1 = List((1,4), (2,3), (3,0), (4,1))
    if (r1==c1) punti += 1
    println("Test 1: " + r1 + " (corretto: "+c1+")")

    val a2 = List()
    val b2 = List("uno","zero")
    val r2 = a2.countOccIn(b2).sorted
    val c2 = List()
    if (r2==c2) punti += 1
    println("Test 2: " + r2 + " (corretto: "+c2+")")

    val n  = 30000
    val a3 = List.range(0,n)
    val b3 = List.range(1,100).map(i => (1 to i).toList).flatten
    val (vs,ts) = profila {
        E1Slow.countOccIn(a3,b3)
    }
    val (vf,tf) = profila {
        a3.countOccIn(b3)
    }
    if (vs.sorted==vf.sorted) {
        punti += 1
        println("Test 3: (OK)")
    } else
        println("Test 3: (ERR)")

    println("Punti: " + punti + " su 3")
    println("Speedup: " + ts/tf + "x")
}

// versione con ricorsione di coda della soluzione in tempo O(a*b)
// senza l'uso di alcun metodo sulle liste
object E1Slow {
    def countOccIn[T](a:List[T], b:List[T]):List[(T,Int)] = {
        def removeDuplicates(l:List[T], acc:List[T]):List[T] = l match { // O(n^2)
            case Nil  => acc.reverse
            case h::t => if (t contains h) removeDuplicates(t, acc) else removeDuplicates(t, h::acc)
        }
        def countIn(l:List[T], x:T, acc:Int):Int = l match { // O(n)
            case Nil  => acc
            case h::t => if (h == x) countIn(t, x, acc+1) else countIn(t, x, acc)
        }
        def aux(l:List[T], acc:List[(T,Int)]):List[(T,Int)] = l match {
            case Nil  => acc
            case h::t => aux(t, (h, countIn(b, h, 0))::acc)
        }
        aux(removeDuplicates(a, Nil), Nil)
    }
}
