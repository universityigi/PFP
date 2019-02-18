import scala.language.implicitConversions
object PIsRot{
	implicit def convRort[T](l:Seq[T])= new MioPIsRot(l)
}

class MioPIsRot[T](l:Seq[T]){
	def isRotPar(m:Seq[T]) :Option[Int]={
		def aux(min:Int,max:Int,numThreads:Int):Option[Int]={
			if(numThreads<2) isRot(m,min,max)
			else if(min>=max) None
			else{
				val mid=(min+max)/2
				val (a,b)= Par.par{aux(min,mid,numThreads/2)}{aux(mid,max,numThreads/2)}
				if(a==None) b else a
			}
		}
		aux(0,m.size,Runtime.getRuntime().availableProcessors())
	}
		def isRot(m:Seq[T],min:Int,max:Int) :Option[Int]={
		if(l.filter(x=>m.contains(x))==l){
			val join=for{
				i<- min until max
				(a,b) = m splitAt(i)
				if(l==b++a)
			}yield i
			if(join.isEmpty) None
			else Some(join.head)
		}
		else{
			None
		}
	}

}
