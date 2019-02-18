import E23._

object E23Main extends App {
    val (v,t) = profila {
        println("Valutazione espressione...")
        (1 to 1000000).map(_.toLong).sum
    }

    println("Valore prodotto: "+v+" (corretto: 500000500000)")
    println("Tempo richiesto: "+t+"*"+1E-9+" secondi")
}
