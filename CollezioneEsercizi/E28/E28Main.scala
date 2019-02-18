import E28._

object E28Main extends App {
    def p(s:String, r:String, k:Int) = 
        println("\"" + s + "\" -> \"" + s.rot(k)  + "\" (corretto: \""+ r + "\")")
    val (s1, r1, k1) = ("Zorro", "Apssp", 1)
    val (s2, r2, k2) = ("Apssp", "Zorro", 26-1)
    val (s3, r3, k3) = ("Hello World!", "Uryyb Jbeyq!", 13)
    val (s4, r4, k4) = ("Uryyb Jbeyq!", "Hello World!", 26-13)
    p(s1, r1, k1)
    p(s2, r2, k2)
    p(s3, r3, k3)
    p(s4, r4, k4)
}
