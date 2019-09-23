import scala.language.implicitConversions

object E1{
	implicit def numPrime(x:Int)= new MioPrime(x:Int)
	
	class MioPrime(x:Int){
		def isPrime={
			if(x==1) false
			else if(x==2) true
			else if(x<0) false
			else{
				List.range(2,x).forall(y=>x%y!=0)
			}
		}
	}
}
