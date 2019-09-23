object E3 {
	def sommaQuadrati(x:Int,y:Int):Int={
		if(x==y) x*y
		else x*x+sommaQuadrati(x+1,y)
	}
	def sommaQuadratiList(x:Int,y:Int)={
		List.range(x,y+1).map(x=>(x*x)).reduce(_+_)
	}
}
