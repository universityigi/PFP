object E19{
	def query(studenti:List[(String,Int)], esami:List[(String,String)]):Int={
		studenti.map(x=>(esami.filter(y=>y._1==x._1).map(h=>h._2).size)).groupBy(studenti.map(x=>x._2)).map(f=>(f._1,f._2.reduce(_+_))).toList.maxBy(x=>x._2)._1

	}
}
