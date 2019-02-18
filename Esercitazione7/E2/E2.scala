// Il metodo fornito `def sum3(s:Set[Int]):Set[Set[Int]]` calcola i sottoinsiemi 
// di cardinalità 3 dell'insieme in input `s` tali che la somma del loro elementi 
// sia pari a 0. La soluzione sequenziale proposta ha complessità quadratica 
// (https://en.wikipedia.org/wiki/3SUM). Si richiede di scrivere una versione 
// parallela `def sum3PAR(s:Set[Int]):Set[Set[Int]]` che usa fork-join in Scala 
// mediante il costrutto `par`. La soluzione deve usare un numero di thread pari 
// al numero di core logici disponibili.

object E2 {
    def sum3(s:Set[Int]):Set[Set[Int]]  = {
        val v = s.toVector
        val ris = for {
            i <- 0 until v.size
            j <- i+1 until v.size
            target = -(v(i)+v(j))
            if (target != v(i) && target != v(j))
            if (s.contains(target))
        } yield Set( v(i), v(j), target )
        ris.toSet
    }

    def sum3Par(s:Set[Int]):Set[Set[Int]] = {
        // da completare...
        def aux(min:Int,max:Int,numThreads:Int):Set[Set[Int]] ={
			if(numThreads<2 || min>=max) sum3MinMax(min,max,s)
			else{
				val mid=(min+max)/3
				val (a,b) = Par.par{aux(min,mid,numThreads/2)}{aux(mid,max,numThreads/2)}
				a.union(b)
			}
		}
		aux(0,s.size,Runtime.getRuntime().availableProcessors())
    }
    def sum3MinMax(min:Int,max:Int,s:Set[Int]):Set[Set[Int]]  = {
        val v = s.toVector
        val ris = for {
            i <- min until max
            j <- i+1 until v.size
            target = -(v(i)+v(j))
            if (target != v(i) && target != v(j))
            if (s.contains(target))
        } yield Set( v(i), v(j), target )
        ris.toSet
    }
}
