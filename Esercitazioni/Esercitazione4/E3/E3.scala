// Aggiungi alla classe DB un metodo registiConFilm(p:Film=>Boolean) che
// estrae tutti i registi che hanno diretto almeno un film con la proprietà p.

case class Film(id:Int, titolo:String, anno:Int)
case class Regista(id:Int, nome:String)
case class DirettoDa(idFilm:Int, idRegista:Int)

case class DB(film:List[Film], registi:List[Regista], regie:List[DirettoDa]) {
    def registiConFilm(p:Film=>Boolean):List[Regista] = {
		val join = for{
			i <- film
			j <- registi
			k <- regie
			if(j.id==k.idRegista &&i.id==k.idFilm && p(i))
		}yield(i,j,k)
		join.map(x=>x._2).distinct
	}
}
