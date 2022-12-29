using Serilog;


public class Program
{
    public static void Main()
    {
        Log.Logger = new LoggerConfiguration()
            .MinimumLevel.Information()
            .WriteTo.Console()
            .WriteTo.File("log.txt",
                rollingInterval: RollingInterval.Day,
                rollOnFileSizeLimit: true)
            .CreateLogger();
            
        Log.Information("Hello, Serilog! {}", "test if can seen");
        Log.Information("Hello, Serilog! {0}", "test if can seen");
        
        Log.CloseAndFlush();
    }
}