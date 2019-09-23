object E4 {
	def ugualiIn(f1:Int=>Int,f2:Int=>Int, n:Int):Boolean={
		List.range(0,n+1).forall(x=>(f1(x)==f2(x)))
	}
	def ugualiInRic(f1:Int=>Int,f2:Int=>Int,n:Int):Boolean={
		if(n<0) true
		else if(f1(n)!=f2(n)) false
		else ugualiInRic(f1,f2,n-1)
	}
}
