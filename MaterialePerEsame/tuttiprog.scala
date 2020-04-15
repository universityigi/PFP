//i seguenti eserzi sono estratti dal corso di pfp del 2018
//di Federico Mastrogiacomo



        //posso usare la group by per ordinare che tira fuori una map da poter usare
        //adesso alla map applico la condizione che mi fiene chiesta, ma prima la trasforomo in
        //lista per avere i metodi delle liste
object A1 {
    def select(cars:List[Car]) =
        cars.groupBy(c=>c.year)
            .toList.map(
                 p => (p._1, p._2.map(_.owner)
                                 .reduce((a,b)=>if (a.age < b.age) a else b)
                                 .name
                      )
            )
}
// dopo aver messo sotto forma di lista faccio il .map che applica una funzone ad ogni elemento
// in questo caso particolare ho creato una lista che ha come primo elemento l'anno poichè avevo
//precedentemente fatto il tolist del sorted e come secondo elemento una lista dei proprietari
// ricorda che con _.qualcosa puoi accedere ad una sottolista
// pongo la condizione che cercavo con la reduce che ricordiamo essere utile per eliminare nomi
// dalle liste
//quindi il confornto lo faccio ovviamente sul secondo elemento di questa lista che ho creato
// e con . name alla fine prendo solo i nome


object A2 extends App{
    def trim(s:String,control:Char=>Boolean):String={
        val l : List[Char]= s.toList
        l.dropWhile(control).reverse.dropWhile(control).reverse.map(x=>x.toString).reduce(_+_)
        //l'ultimo reverse  porta to string una lista
    }
}

object A3 extends App{
    def aux[T](l1:List[T], l2:List[T],n:Int):Boolean={
        if(n>=0){
            if(l1.contains(l2(n))) false
            else aux(l1,l2,n-1)
        }
        else true
    }
    def test[T](l1:List[T] , l2:List[T]):Boolean={
        if(l1.size>l2.size) aux(l1,l2,l2.size-1)
        else aux(l2,l1,l1.size-1)
    }
}


// Scrivere un metodo generico `countOccIn` applicabile su una lista `a` che, data un'altra lista `b`,
// restituisce una lista di coppie `(x,c)` per ogni elemento distinto `x` di `a`,
// dove `c` è il numero di occorrenze di `x` in `b`.

// La soluzione deve richiedere tempo O(a.size + b.size) e non deve essere né
// iterativa né ricorsiva, ma deve usare i metodi delle liste.

// Suggerimento: usare distinct e groupBy

// Scrivere la soluzione qui...



/*se mi chiede di fare un metodo applicabile definendo una classe
 *prima di tutto creo object con all'interno la redefinizione dell'oggetto sul quale voglio
 * applicare il metodo, dopo di che creo il nuovo oggetto della mia classe e definisco il metodo
 * ricorda che il tipo delle liste lo decidi tu in base al testo
 */
object E1 extends App{
    implicit def listtoMyList[T](l:List[T])= new MyList(l)
}
//metto la a che è l'elemento sul quale vorrò applicare il mio metodo
class MyList[T](a:List[T]){
    def countOccIn(b:List[T]):List[(T,Int)]={
        //identity effettuo group by su se stessa
        val m = b.groupBy(identity)
        // all'interno di map puoi mettere anche if else non articolati credo
        a.distinct.map(x=>(x,if(m contains x) m(x).size else 0))
        // x diventa x , numero di occorrenze tramite if else e contains
        // m(x). size ti restituisce il numero di occorrenze

    }
}



// Scrivere un metodo scalarProd che, date due vettori rappresentati come
// sequenze di Double, ne calcola il prodotto scalare. Se i vettori
// hanno lunghezze diverse, limitare il prodotto scalare al range di
// indici validi comuni. Ad esempio: scalarProd(Seq(3,4), Seq(2,9,1)) ==
// 3*2 + 4*9 == 42

// _Suggerimento:_ usare i metodi delle collezioni

object E1 {
    def scalarProd(a:Seq[Double], b:Seq[Double]):Double =
        (a zip b).foldLeft(0.0)((acc, pair) => acc + pair._1*pair._2)
}

object E1 extends App{
    def sommaFun(f1:Double=>Double, f2:Double=>Double)=(x:Double)=>f1(x)+f2(x)

}


object E1 extends App{
    implicit def inToMyInt(x:Int) = new MyInt(x)
}
class MyInt(x:Int){
    def isPrime(x:Int):Boolean={
        val l =List.range(1,x+1)
        l.forall(l(x+1)%_==0)
    }
}


object E2 extends App{
   /* def auxIterator[A,B](a:List[A],b:List[B],f:A=>B,n:Int,bool : Boolean):Boolean={
        if(n>=0 && bool==true){
            if(b(n)==f(a(n))){
                auxIterator(a,b,f,n-1,true)
            }
        }
        if(bool == false) false
        else true
    }
    def corrisp[A,B](a:List[A],b:List[B],f:A=>B):Boolean={
        if(a.size<b.size){
            auxIterator(a,b,f,a.size,true)
        }
        else{
            auxIterator(a,b,f,b.size,true)
        }
    }
    * dio è porco e la ricorsione fa schifo  */
    def corrisp[A,B](a:List[A],b:List[B],f:A=>B):Boolean= (a zip b).forall(x=>x._2==f(x._1))
}



sealed abstract class BinTree {
    def isSearchTree:Boolean=this match{
        case E() => true
        case T(l,e,r) => (l,r)match{
            case(E(),E())     => true
            case(T(_,le,_),E()) => le <= e && l.isSearchTree
            case(E(),T(_,re,_)) => re >= e && r.isSearchTree
            case(T(_,le,_),T(_,re,_)) => le <= e && re >= e && l.isSearchTree && r.isSearchTree
        }
    }
}

// albero non vuoto
case class T(l:BinTree, e:Int, r:BinTree) extends BinTree

// albero vuoto
case class E() extends BinTree


object E4 extends App{
    def auxBit(l:List[Int],size:Int,n:Int):Int={
        if(n<size-1){
            if(l(n)<l(n+1)){
                if(l(n)>l(n+1)) n
                auxBit(l,size,n+1)
            }
            else if(l(n)==l(n+1)) 0
        }
        n
    }
    def checkBitonic(l:List[Int]):(List[Int],List[Int])={
        List(List(0),List(l.slice(0,auxBit(l,l.size,0))+1))
    }
}


// Scrivere una versione parallela `fibPar` del metodo `fib` definito nel file `Fib.scala` usando
// fork-join in Scala mediante il costrutto `par`.

// Scrivere la soluzione qui...
object E2 extends App{
    //con questa val vedo il num di core disponibili
    lazy val NUM_CORES = Runtime.getRuntime().availableProcessors()
    //funzione sequenziale per i casi in cui non hai core disponibili o passi base
    def fib(a:Int, b:Int)(n:Int):Long ={
        if (n < 2) a
        else if (n == 2) b
        else fib(a,b)(n-1) + fib(a,b)(n-2)
    }
    //funzione parallela per altri casi con ncores > 2
    def fibPar(a:Int, b:Int)(n:Int,t:Int=NUM_CORES):Long ={
        if (n < 3 || t < 2) Fib.fib(a,b)(n)
        else{
            val (l,r) = Par.par(fibPar(a,b)(n-1,t/2))(fibPar(a,b)(n-2,t/2))
            l+r
        }
    }
}



// Scrivere un metodo currificato `def buildMatrix(rows:Int, cols:Int)(f:(Int,Int) => Double):Vector[Vector[Double]]` che,
// dato un numero di righe `rows` e un numero di colonne `cols` e una funzione `f` da coppie di indici `(i,j)`
// a `Double`, restituisce un `Vector[Vector[Double]]` `v` tale che per ogni `i` in `[0,rows-1]` e per ogni `j` in
// `[0,cols-1]` si ha `v(i)(j) == f(i,j)`.

// Scrivere la soluzione qui...
object E1 {
    def buildMatrix(rows:Int, cols:Int)(f:(Int,Int) => Double):Vector[Vector[Double]] =
        (for (i <- 0 until rows)
                yield (for (j <- 0 until cols) yield f(i,j)).toVector
        ).toVector
}

// doppio for e il .toVector matrice rappresentata classicamente
