fun main(){
    val numbers = arrayOf(4,26,9,25,6,44,3,1,78,5);
    var max = 0; Int
    var min = 100; Int

    //Цикл для нахождения максимального
    for(i in numbers){
        if(max <= i){
            max = i;
        }
    }
    println("Максимальное число: " + max);

    //Цикл для нахождения минимального
    for(i in numbers){
        if(min >= i){
            min = i;
        }
    }
    println("Минимальное число: " + min);
}