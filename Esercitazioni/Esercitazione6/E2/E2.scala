// Scrivere una versione parallela `fibPar` del metodo `fib` definito nel file `Fib.scala` usando
// fork-join in Scala mediante il costrutto `par`.

// Scrivere la soluzione qui...
object E2{
	def fibPar(a:Int,b:Int)(n:Int):Long={
		def aux(numThreads:Int,n:Int):Long={
			if(n==2) b
			else if(n<2) a
			else if(numThreads<2) fib(a,b)(n)
			else{
				val (ra,rb)= Par.par{aux(numThreads/2,n-1)}{aux(numThreads,n-2)}
				ra+rb
			}
		}
		aux(Runtime.getRuntime().availableProcessors(),n)
	}
	 def fib(a:Int, b:Int)(n:Int):Long = {
        if (n < 2) a
        else if (n == 2) b
        else fib(a,b)(n-1) + fib(a,b)(n-2)
	}
}
