object E24 extends App{
	case class Studente(nome:String, età:Int, esami:List[String])
	val q = List(Studente("Marco",   23, List("PFP","SC")),Studente("Laura",   19, List("SC", "FI1", "PFP")),Studente("Stefano", 23, List("SC", "FI1")),Studente("Marco",   25, List("SC", "FI1", "FI2")),Studente("Paola",   22, List("SC", "PFP")))

	val query1 = q.filter(x=>(x.età>=20 || x.età<=24)).filter(t=>t.esami.contains("PFP")).map(r=>r.nome)

	println(query1+"[corretto: List(Marco,Laura,Paola)]")

	val query2 = q.filter(x=>(x.età<24)).map(y=>(y.nome,y.esami.size)).filter(t=>t._2>=2).map(h=>h._1)


	println(query2+"[corretto: List(Marco,Laura,Stefano,Paola)]")
}
