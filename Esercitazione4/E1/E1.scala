// Scrivere un metodo generico `countOccIn` applicabile su una lista `a` che, data un'altra lista `b`,
// restituisce una lista di coppie `(x,c)` per ogni elemento distinto `x` di `a`,
// dove `c` è il numero di occorrenze di `x` in `b`.

// La soluzione deve richiedere tempo O(a.size + b.size) e non deve essere né
// iterativa né ricorsiva, ma deve usare i metodi delle liste.

// Suggerimento: usare distinct e groupBy

// Scrivere la soluzione qui...
import scala.language.implicitConversions
object E1{
	implicit def convList[T](l:List[T])=new MiaCount(l)
}
class MiaCount[T](a:List[T]){
	def countOccIn(b:List[T])={
		a.distinct.map(x=>(x, if(b.groupBy(identity).contains(x)) b.groupBy(identity)(x).size else 0))
	}
}
