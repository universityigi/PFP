object E33{
	def primes:Stream[Int]={
		def numPrimo(x:Int):Stream[Int]={
			if(List.range(2,x).forall(y=>x%y!=0)){
				
				x#::numPrimo(x+1)
			}
			else{
				numPrimo(x+1)
			}
				
		}
		2 #:: numPrimo(3)
	}
}
