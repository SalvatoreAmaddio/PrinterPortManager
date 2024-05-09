#include <Windows.h>
#include <Winspool.h>
//uncomment the following lines for an executable.
//#include <iostream>
//#include<string.h>
//#include <string>

//static DWORD CreateDeletePort(int action, LPWSTR portName, HANDLE printerObject);

//int main(int argc, char** argv)
//{
//    if (argc < 3) //Check if the necessary 3 command line arguments are provided.
//    {
//        std::cerr << "Usage: " << argv[0] << " <port_name> <action>" << std::endl;
//        return -1;
//    }
//
//    size_t size = strlen(argv[1]) + 1; //determining the size of the second command-line Argument:
//    wchar_t* _portName = new wchar_t[size]; //allocate Memory for a Wide Character String:
//    
//    //convert Multibyte string to wide sharacter String:
//    size_t outSize;
//
//    if (mbstowcs_s(&outSize, _portName, size, argv[1], size - 1) != 0) 
//    {
//        delete[] _portName; //free memory allocated for _portName.
//        std::cerr << "Failed to convert string." << std::endl;
//        return -1;
//    }
//
//    LPWSTR portName = _portName; //assign and Convert string to long pointer:
//
//    int action = atoi(argv[2]); //convert the third command-line argument from string to integer
//
//    HANDLE printerObject;
//    PRINTER_DEFAULTS PrinterDefaults; //A structure that contains default settings for a printer
//    memset(&PrinterDefaults, 0, sizeof(PrinterDefaults)); //Initialization of PRINTER_DEFAULTS
//
//    PrinterDefaults.pDatatype = NULL;
//    PrinterDefaults.pDevMode = NULL;
//    PrinterDefaults.DesiredAccess = SERVER_ACCESS_ADMINISTER;
//
//    //Open the printer
//    LPWSTR printer = const_cast<LPTSTR>(TEXT(",XcvMonitor Local Port"));
//
//    if (!OpenPrinter(printer, &printerObject, &PrinterDefaults)) 
//    {
//        delete[] _portName; //free memory allocated for _portName.
//        return -1;
//    }
//
//    DWORD result = CreateDeletePort(action, portName, printerObject); //create or delete port
//    delete[] _portName; //free memory allocated for _portName.
//    return result;
//}

//static DWORD CreateDeletePort(int action, LPWSTR portName, HANDLE printerObject)
//{
//
//    DWORD needed = 0;
//    DWORD xcvresult = 0;
//
//    if (action == 0) 
//    {
//        XcvData(printerObject, L"AddPort", (BYTE*)portName, (lstrlenW(portName) + 1) * 2, NULL, 0, &needed, &xcvresult);
//    } 
//    else 
//    {
//        XcvData(printerObject, L"DeletePort", (BYTE*)portName, (lstrlenW(portName) + 1) * 2, NULL, 0, &needed, &xcvresult);
//    }
//        
//    //Cleanup
//    ClosePrinter(printerObject);
//
//    return xcvresult;
//}

//uncomment the following lines to create a DLL
extern "C" {
    __declspec(dllexport) DWORD CreateDeletePort(int action, LPWSTR portName, HANDLE printerObject);
}

__declspec(dllexport) DWORD CreateDeletePort(int action, LPWSTR portName, HANDLE printerObject) {
    DWORD needed = 0;
    DWORD xcvresult = 0;
    if (action == 0) {
        XcvData(printerObject, L"AddPort", (BYTE*)portName, (wcslen(portName) + 1) * sizeof(wchar_t), NULL, 0, &needed, &xcvresult);
    }
    else {
        XcvData(printerObject, L"DeletePort", (BYTE*)portName, (wcslen(portName) + 1) * sizeof(wchar_t), NULL, 0, &needed, &xcvresult);
    }
    ClosePrinter(printerObject);
    return xcvresult;
}