object E7{
	def findIndices[T](l:List[T],x:T)={
		l.zipWithIndex.filter(y=>y._1==x).map(h=>h._2).toList
	}
}
