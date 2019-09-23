object E4{
		def getModel(n:Int)={
			List.range(1,n+1).map(i=> Circle(0.5*i/n,0.5*i/n,0.5*i/n)).toList
		}
}
