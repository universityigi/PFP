object E1{
	def sommaFun(f1:Double=>Double, f2:Double=>Double):Double=>Double ={
		def aux(i:Double)={
			f1(i)+f2(i)
		}
		aux _
	}
}
