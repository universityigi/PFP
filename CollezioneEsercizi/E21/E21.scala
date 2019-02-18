object E21{
	def generateSeq(n:Int,x:Int,f:Int=>Int):List[Int]={
		def aux(i:Int,l:List[Int]):List[Int]={
			if(i==n) l
			else if(i==0) aux(i+1,l:+x)
			else aux(i+1,l:+f(l(i-1)))
		}
		aux(0,List())
	}
}
