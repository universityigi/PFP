object E11{
	def union[T](a:List[T],b:List[T]):List[T]={
		(a:::b).distinct
	}
}
