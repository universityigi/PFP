object E9{
	def consecutivi[T](l:List[T])=l match{
		case Nil => Nil
		case h::Nil => Nil
		case h::t => l.sliding(2,1).map(x=>(x(0),x(1))).toList
	}
}
