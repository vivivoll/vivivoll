using System;
using System.Collections.Generic;

namespace CardGame
{
    public class Karta
    {
        public string Mast { get; }      
        public string Rank { get; }
        public int Value { get; }  

        //конструктор
        public Karta(string mast, string rank, int value)
        {
            Mast = mast;
            Rank = rank;
            Value = value;
        }
    }

    public class Player
    {
        public string Name { get; }

        public Player(string name)
        {
            Name = name;
        }
    }

    public class Game
    {
        
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Создание игры
            Game game = new Game();
            

            Console.ReadKey();
        }
    }
}