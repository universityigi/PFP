object E3Main extends App {
    val film = List(
        Film(1, "Alien",                1979),
        Film(2, "Kill Bill",            2003),
        Film(3, "Blade Runner",         1982),
        Film(4, "A Clockwork Orange",   1971),
        Film(5, "Natural Born Killers", 1994)
    )
    val registi = List(
        Regista(1, "Ridley Scott"     ),
        Regista(2, "Quentin Tarantino"),
        Regista(3, "Stanley Kubrick"  ),
        Regista(4, "Oliver Stone"     ),
        Regista(5, "Test Director"    )
    )
    val regie = List(
        DirettoDa(1,1), DirettoDa(2,2), DirettoDa(3,1), DirettoDa(4,3), DirettoDa(5,4)
    )
    val db = DB(film, registi, regie)

    var punti = 0

    // trova registi che hanno diretto un film precedente al 1990
    val q1:List[Regista] = db.registiConFilm(_.anno < 1990).sortBy(_.id)
    val r1 = List(registi(0), registi(2))
    println("Test 1: "+q1.map(_.nome)+" (corretto: "+r1.map(_.nome)+")")
    if (q1 == r1) punti += 1

    // trova registi che hanno diretto un film il cui titolo contiene "kill"
    val q2 = db.registiConFilm(_.titolo.toLowerCase contains "kill").sortBy(_.id)
    val r2 = List(registi(1), registi(3))
    println("\nTest 2: "+q2.map(_.nome)+" (corretto: "+r2.map(_.nome)+")")
    if (q2 == r2) punti += 1

    println("Punti: " + punti + " su 2")
}
