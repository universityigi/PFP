import E2.myFor

object E2Main extends App {
    var x     = -1
    var n     = -1
    var punti =  0

    n = 0
    myFor(x=0)(x<10)(x+=1) {
        n += 1
    }
    println(n+" (corretto: 10)")
    if (n==10) punti += 1 

    n = 0
    myFor(x=5)(x>0)(x-=1) {
        n += 1
    }
    println(n+" (corretto: 5)")
    if (n==5) punti += 1 

    n = 0
    myFor(x=0)(x<0)(x+=1) {
        n += 1
    }
    println(n+" (corretto: 0)")
    if (n==0) punti += 1 

    println("Punti: " + punti + " su 3")    
}
