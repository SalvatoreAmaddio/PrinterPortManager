# PrinterPortManager

This is a small C++ project in the context of Windows programming. It adds or removes Printer's Ports.
The 'PrinterPortManager.cpp' file comes with the code to either:
- Build and run the project as an executable.
- Build the project as DLL.

The code is organised in two #pragma region blocks. The first block is the code for the executable. The second block is the code for DLL. Both blocks are commented. Uncomment the block of code you want to use.

Also;
## Arguments:
- A String: this is the Port's Name to add or remove. 
- An Integer: this is the action to take. Give 0 to add a Port; Give 1 to remove the Port.  

## Using the DLL in C#:
Upload the dll in your project, ensure it is in your bin folder. Then in your class add the following:

```csharp
[DllImport("PrinterPortManager.dll", CharSet = CharSet.Unicode, SetLastError = true)]
public static extern uint CreateDeletePort(int action, string portName);
```

Now you can call the function from the DLL, for example:

```csharp
	...
	CreateDeletePort(0, "MyNewPort"); //Add a new port.
	...
	CreateDeletePort(1, "MyNewPort"); //delete the new port.
```