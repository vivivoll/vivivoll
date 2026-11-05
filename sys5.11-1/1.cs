using System;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        //инфа о текущем процессе
        var proc = Process.GetCurrentProcess();
        Console.WriteLine($"имя процесса: {proc.ProcessName}");
        Console.WriteLine($"id процесса: {proc.Id}");
        Console.WriteLine($"старт: {proc.StartTime}");
        Console.WriteLine($"виртуальная память: {proc.VirtualMemorySize64 / 1024 / 1024} MB");

        var line = new string('-', 40);
        Console.WriteLine(line);

        //все процессы в системе
        Console.WriteLine("топ 5 по памяти:");
        var procs = Process.GetProcesses();
        var biggest = procs.OrderByDescending(p => p.WorkingSet64).Take(5); // сортируем и берём пять

        foreach (var p in biggest)
        {
            var mb = p.WorkingSet64 / 1024 / 1024;
            Console.WriteLine($"имя: {p.ProcessName}, id: {p.Id}, память: {mb} мб");
        }

        foreach (var p in procs)
        {
            p.Dispose();
        }
    }
}