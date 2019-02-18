// Scrivere un metodo `def subList(l:List[T]):Boolean` applicabile su un oggetto `List[T]` `s` che restituisce `true` 
// se e solo se tutti gli elementi di `l` appaiono anche in `s` nello stesso ordine, anche non consecutivamente.

import scala.language.implicitConversions

object E1 { 
    implicit def seq2MySeq[T](s:List[T]):MyList[T] = new MyList(s)
}

import E1._

class MyList[T](s:List[T]) {
    def subList(l:List[T]):Boolean = {
		if(l.isEmpty) true
		else if(s.isEmpty) false
		else if(l.head==s.head) s.tail.subList(l.tail)
		else s.tail.subList(l)
	}
}
