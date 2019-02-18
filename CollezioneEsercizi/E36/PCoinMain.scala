object PCoinMain extends App {
    val coins = List(10,100,1,2,5,20,10,50,1,200,100,5,20,10,10,5,1,20,50,1,5,200,2,50,20,1,1,2,5,200,100)
    val a1 = 899
    println("Versione sequenziale...")
    val (v1, t1)   = Prof.profila { PCoin.countChange    (a1, coins) }
    println("Versione parallela...")
    val (vp1, tp1) = Prof.profila { PCoin.countChangePar (a1, coins) }
    println("Test: " + vp1 + " (corretto: " + v1 + " - tempo seq: "+t1*1E-9+" sec - tempo par: "+tp1*1E-9+" sec)")
}
