object E18{
	def filterByIndex[T](l:List[T],f:Int=>Boolean):List[T]={
		l.zipWithIndex.filter(x=>f(x._2)).map(y=>y._1)
	}
}
