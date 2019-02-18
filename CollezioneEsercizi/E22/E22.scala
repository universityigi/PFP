object E22{
	def query(studenti:List[(String,Int)],esami:List[(String,String)], e:Int):String={
		var join=for{
			i<-studenti
			j<-esami
			if(i._1==j._1)
		}yield(i,j)
		
		join.map(x=>(x._1._2,x._2._2)).filter(y=>y._1<=e).groupBy(t=>t._2).map(h=>(h._1,h._2.size)).maxBy(r=>r._2)._1
	}
}
