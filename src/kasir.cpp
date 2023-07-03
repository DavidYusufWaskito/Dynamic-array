#include <iostream>
#include "DArray.h"

struct menu
{
    std::string nama;
    int harga;
    int porsi;
};

void tampilMenu(const dvd::DArray<menu>& _menu)
{
    for (size_t i = 0; i < _menu.Size();i++)
    {
        std::cout << i + 1 << ". " << _menu[i].nama << "\t\t" << _menu[i].harga << std::endl;
    }
}

template<typename T>
void input(T& input, const char* prompt)
{
    do{
        std::cout << prompt;
        if (!(std::cin >> input))
        {
            std::cout << "Input error!\n";
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
        }else break;
    }while(1);
}

int main()
{
    bool isRun = true;
    int pilih_menu;
    int total_bayar = 0;
    int bayar;
    char pilih_ulang;
    dvd::DArray<menu> list_menu = {
        {"Nasi goreng",10000},
        {"Mie goreng",8000},
        {"Mie rebus",8000},
        {"Nasi telor",7000},
        {"Es teh",4000},
        {"Es jeruk",4000}
    };
    dvd::DArray<menu> temp_menu;
    do {
        
        std::cout << "===================================\n";
        std::cout << "         Warmindo David            \n";
        std::cout << "===================================\n";

        tampilMenu(list_menu);
        input(pilih_menu,"Pilih: ");

        // Handle pilihan

        if (pilih_menu >= 1 && pilih_menu <= list_menu.Size())
        {
            menu temp = list_menu[pilih_menu - 1];
            input(temp.porsi,"Mau pesan berapa porsi: ");
            temp_menu.push_back(temp);
        }    
        else std::cout << "Pilihan salah!\n";
        
        do {
            std::cout << "Apakah anda ingin memesan lagi? (y/n): ";
            std::cin >> pilih_ulang;

            if (pilih_ulang == 'y' || pilih_ulang == 'Y')
                break;
            else if (pilih_ulang == 'n' || pilih_ulang == 'N')
            {
                isRun = false;
                break;
            }
            else std::cout << "Pilihan tidak sesuai!\n";    
        }while(1);
    }while(isRun);

    // Hitung total dan suruh bayar
    for (size_t i = 0; i < temp_menu.Size();i++)
    {
        total_bayar += (temp_menu[i].harga * temp_menu[i].porsi);
    }    
 
    
    do{
        std::cout << "Total harga: " << total_bayar << std::endl;
        input(bayar,"Silahkan masukan uang anda: ");

        if (bayar < total_bayar)
            std::cout << "Uang anda kurang!\n\n";
        else break;
    }while(1);
    
    
    std::cout << "\n-----------------------------STRUK PEMBELIAN-------------------------------"<< std::endl;
	std::cout << "NO		MENU		PORSI		HARGA		SUBTOTAL" << std::endl;
	std::cout << "---------------------------------------------------------------------------"<< std::endl;
    for(size_t i = 0; i < temp_menu.Size(); i++)
		std::cout << i+1 << ".		" << temp_menu[i].nama <<"          " << temp_menu[i].porsi << "		"<< temp_menu[i].harga << "		" << temp_menu[i].harga * temp_menu[i].porsi << "		" << std::endl;
	std::cout << "\n---------------------------------------------------------------------------"<< std::endl;
	std::cout << "						Total         = Rp."<< total_bayar << std::endl;
	std::cout << "						Uang anda     = Rp." << bayar << std::endl;
    if (bayar > total_bayar)
	    std::cout << "						Kembalian     = Rp." << bayar - total_bayar << std::endl;
	std::cout << "\n----------------------------SELAMAT MENIKMATI--------------------------------"<< std::endl;

    return 0;
}