using System;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        var info = new ProcessStartInfo
        {
            FileName = "ping.exe",
            Arguments = "8.8.8.8 -n 4",
            UseShellExecute = false,
            RedirectStandardOutput = true,
            CreateNoWindow = true
        };

        try
        {
            //стартуем дочерний процесс
            using (var child = Process.Start(info))
            {
                if (child == null)
                {
                    Console.WriteLine("процесс не запустился");
                    return;
                }

                Console.WriteLine("дочерний процесс запущен");

                var outputTask = child.StandardOutput.ReadToEnd();

                //ждем завершения но не дольше 5 секунд
                if (child.WaitForExit(5000))
                {
                    Console.WriteLine("дочерний процесс завершился сам");
                }
                else
                {
                    Console.WriteLine("убиваем принудительно");

                    child.Kill();
                    child.WaitForExit();

                    Console.WriteLine("дочерний процесс был завершён");
                }
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"ошибка при работе с процессом: {ex.Message}");
        }
    }
}