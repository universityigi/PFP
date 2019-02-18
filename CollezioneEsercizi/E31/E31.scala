object E31{
	def piùFrequente[T](l:Seq[T]):Option[(T,Int)]={
		if(l==Nil) None
		else{
			Some(l.groupBy(identity).map(x=>(x._1,x._2.size)).maxBy(y=>y._2))
		}
	}
}
