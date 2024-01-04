#pragma once
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace Microsoft::VisualBasic;
namespace Global {
    public ref class GlobalData
    {
    public:
        static String^ CurrentUser;
    };
}