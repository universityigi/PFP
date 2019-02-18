// Scrivere un metodo `def s(k:Int):Stream[(Int,Int)]` che genera ricorsivamente 
// lo stream finito che contiene tutte le coppie `(x,y)` con `x+y=k` per `x` 
// crescente e `x`, `y` interi non negativi.
// Ad esempio: `s(3)=(0,3) #:: (1,2) #:: (2,1) #:: (3,0) #:: Stream.empty`.

// Scrivere poi un metodo `def dovetail:Stream[(Int,Int)]` che genera lo
// stream infinito delle coppie `(x,y)` con `x`, `y` interi non negativi che 
// copre tutti i punti a coordinate intere del primo quadrante del piano
// cartesiano. Lo stream deve generare prima tutte le coppie `(x,y)` con
// `x+y=0`, poi quelle con `x+y=1` per `x` crescente, poi quelle con `x+y=2`
// sempre per `x` crescente, ecc.

// _Suggerimento:_ generare lo stream `dovetail` ricorsivamente come
// concatenazione degli stream `s(0) #::: s(1) #::: s(2) #::: ...`,
// dove `#:::` è l'operatore Scala di concatenazione di stream.

object E2 {
    def s(k:Int):Stream[(Int,Int)] = {
		def aux(x:Int):Stream[(Int,Int)]={
			if(x>k) Stream.empty
			else (x,k-x) #:: aux(x+1)
		}
		aux(0)
	}

    def dovetail:Stream[(Int,Int)] = {
		def aux(n:Int):Stream[(Int,Int)]={
			s(n) #::: aux(n+1)
		}
		aux(0)
	}
}
