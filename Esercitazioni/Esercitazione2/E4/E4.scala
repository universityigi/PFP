object E4{
	def checkBitonic(l:List[Int]):(List[Int],List[Int])={
		val (inc,dec)=(l.splitAt(l.length/2+1)._1,l.splitAt(l.length/2+1)._2)
		if(inc.sorted==inc ) (inc,dec)
		else (Nil,Nil)
	}
	def checkBitonicProf(l:List[Int]):(List[Int],List[Int]) = {
        val max = l.zipWithIndex.sliding(3,1).filter(t => t(0)._1 < t(1)._1 && t(1)._1 > t(2)._1).toList
        if (max.length != 1) (Nil,Nil)
        else (l.take(max.head(2)._2), l.drop(max.head(2)._2))
    }
}
}
