// Il metodo `isMappedFrom`, applicabile a un vettore l, verifica se un altro vettore m è 
// ottenibile da l applicando la funzione f a ciascun elemento di l.

// Scrivere una versione parallela `isMappedFromPar` del metodo `isMappedFrom` usando 
// un approccio divide et impera basato sul costrutto `par` fornito. Usare un numero di 
// thread pari al numero di core logici disponibili.

// _Suggerimento:_ ispirarsi alla soluzione dell'esercizio 38 - 
// PIsRot (https://season-lab.github.io/PFP/eserc/soluzScala)

import scala.language.implicitConversions

class MyVec[T](l:Vector[T]) {

    // versione sequenziale
    def isMappedFrom[S](m:Vector[S], f:T=>S) =
        if (l.size != m.size) false
        else isMappedFrom2(0,l.size,m,f)

    // versione parallela, da completare...
    def isMappedFromPar[S](m:Vector[S], f:T=>S)= {
		def aux(min:Int,max:Int,numThreads:Int):Boolean={
			if(numThreads<2) isMappedFrom(m,f)
			else{
				val mid=(min+max)/2
				val (a,b) = Par.par{aux(min,mid,numThreads/2)}{aux(mid,max,numThreads/2)}
				if(a==true && b==true) true
				else false 
			}
		}
		aux(0,m.size,Runtime.getRuntime().availableProcessors())
	}
	def isMappedFrom2[S](min:Int,max:Int,m:Vector[S],f:T=>S)={
		(min until max).forall(i => m(i) == f(l(i)))
	}
	
}

object E2 {
    implicit def vec2MyVec[T](l:Vector[T]) = new MyVec(l)
}
