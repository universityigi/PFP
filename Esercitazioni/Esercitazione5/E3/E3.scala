// Se esistesse un premio ignobel per l'informatica, questo si piazzerebbe bene.
// Scrivere un metodo noobSort che, dato un Vector v di n elementi di tipo
// generico, restituisce la versione ordinata di v. Per risolvere il problema,
// generare tutte le permutazioni degli indici da 0 a n-1 e per
// ciascuna vettore permutato verificare se è ordinato e restituirlo.

// _Suggerimento:_ per generare le permutazioni degli indici, usare
// (0 to n-1).permutations.

object E3 {
    def noobSort[T <% Ordered[T]](v:Vector[T]):Vector[T] = {
		if(v.isEmpty) v
		else v.permutations.find(x=>x==x.sorted).get
	}
}
