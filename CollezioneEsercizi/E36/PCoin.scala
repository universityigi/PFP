object PCoin {
    // versione sequenziale (inefficiente, nel caso peggiore richiede 2^n chiamate ricorsive, con n=coins.size) 
    def countChange(amount:Int, coins:List[Int]):Int =
        if (amount == 0) 1
        else if (coins.isEmpty || amount < 0) 0
        else countChange(amount - coins.head, coins.tail) + countChange(amount, coins.tail)

    // versione parallela, da completare
    def countChangePar(amount:Int, coins:List[Int], maxThreads:Int = Runtime.getRuntime().availableProcessors()):Int = {
		if(amount==0) 1
		else if(coins.isEmpty || amount<0) 0
		else if(maxThreads <2) countChange(amount,coins)
		else{
			val (a,b) =Par.par{countChangePar(amount-coins.head,coins.tail, maxThreads/2)}{countChangePar(amount,coins.tail, maxThreads/2)}
			a+b
		}
	}
}
