object E12{
	def max(s:List[String])={
		s.map(x=>(x.size)).reduce((x,y)=> if(x>y) x else y)
	}
}
