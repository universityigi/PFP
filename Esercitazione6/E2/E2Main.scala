object E2Main extends App {

    var punti = 0

    val r1 = E2.fibPar(1,1)(1)
    val c1 = Fib.fib(1,1)(1)
    println("Test 1: " + r1 + " (corretto: " + c1 + ")")
    if (c1 == r1) punti += 1

    val r2 = E2.fibPar(1,1)(2)
    val c2 = Fib.fib(1,1)(2)
    println("Test 2: " + r2 + " (corretto: " + c2 + ")")
    if (c2 == r2) punti += 1

    val r3 = E2.fibPar(1,1)(3)
    val c3 = Fib.fib(1,1)(3)
    println("Test 3: " + r3 + " (corretto: " + c3 + ")")
    if (c3 == r3) punti += 1

    val r4 = E2.fibPar(1,1)(10)
    val c4 = Fib.fib(1,1)(10)
    println("Test 4: " + r4 + " (corretto: " + c4 + ")")
    if (c4 == r4) punti += 1

    val n5 = 41
    print("Versione sequenziale...")
    val (c5,t5_seq) = Prof.profila(Fib.fib(1,1)(n5))
    println(" -> " + t5_seq + "sec")

    print("Versione parallela...")
    val (r5,t5_par) = Prof.profila(E2.fibPar(1,1)(n5))
    println(" -> " + t5_par + "sec")

    println("Test 5: " + r5 + " (corretto: " + c5 + ")")
    if (c5 == r5) punti += 1

    println("Punti: "+punti+" su 5 - Speedup: " + t5_seq/t5_par)
}
