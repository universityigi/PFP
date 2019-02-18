object E16{
	def mediaVeicoli(l:List[Int]):Double={
		(l.span(_>0)._1.reduce(_+_)/l.span(_>0)._1.size)
	}
}
