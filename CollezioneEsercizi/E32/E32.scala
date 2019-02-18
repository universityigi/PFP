object E32{
	def inter[T](a:List[T], b:List[T]):List[T]={
		a.toSet.intersect(b.toSet).toList
		//oppure a.toSet.exists(b.toSet.contains).toList
		//oppure a.toSet.filter(x=>(b.toSet.contains(x))).toList
	}
}
