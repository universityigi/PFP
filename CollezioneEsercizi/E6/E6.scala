object E6{
	def equalInRange(f1:Int=>Int,f2:Int=>Int,a:Int,b:Int):Boolean={
		if(f1(a)!=f2(a)) false
		else if(a==b) true
		else equalInRange(f1,f2,a+1,b)
	}
}
