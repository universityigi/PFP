object E33Main extends App {
    val s:Stream[Int] = E33.primes
    println("Primi 5 numeri primi: "  + s.take(5) .toList)
    println("Primi 10 numeri primi: " + s.take(10).toList)
    println("Primi 20 numeri primi: " + s.take(20).toList)
}
