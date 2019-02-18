import scala.language.implicitConversions
object E28{
	implicit def cifCesare(s:String)=new MioCif(s:String)
}

class MioCif(s:String){
	def rot(k:Int):String={
	}
}
