// Scrivere un metodo isAnagramOf(a:String, b:String):Boolean che
// verifica se a è un anagramma di b.

// Suggerimento: usare il metodo sorted applicato alle stringhe.

object E4 {
    def isAnagramOf(a:String, b:String) = {
		a.sorted==b.sorted
	}
}
