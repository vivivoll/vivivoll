fun main(){
    //Ввод начального числа
    print("Введите начальное число: ");
    val number_1 = readLine()!!.toInt();
    println();
    //Ввод конечного числа
    print("Введите конечное число: ");
    val number_2 = readLine()!!.toInt();
    println();

    //Вывод чисел, которые подходят по критериям
    for(i in number_1..number_2 step 2){
        if(i % 3 == 0){
            println(i);
        }
    }
}