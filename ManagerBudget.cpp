#include "ManagerBudget.h"

using namespace std;

void ManagerBudget::addIncome()
{
    BudgetPosition income;
    int lastId;

    lastId = fileWithIncomes.getLastBudgetPositionIdFromFile();

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = enterDataForNewPosition(lastId);

    incomes.push_back(income);

    if(fileWithIncomes.addBudgetPositions(income))
        cout << "Nowy przychod zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");
}

void ManagerBudget::addExpense()
{
    BudgetPosition expense;
    int lastId;

    lastId = fileWithExpenses.getLastBudgetPositionIdFromFile();

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = enterDataForNewPosition(lastId);

    expenses.push_back(expense);

    if(fileWithExpenses.addBudgetPositions(expense))
        cout << "Nowy wydatek zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku." << endl;
    system("pause");
}

BudgetPosition ManagerBudget::enterDataForNewPosition(int lastId)
{
    BudgetPosition budgetPosition;
    int date;
    double amount;

    budgetPosition.setId(lastId+1);
    budgetPosition.setUserId(ID_OF_LOGGED_IN_USER);

    date = dateInputMenu();
    budgetPosition.setDate(date);

    cout << "Podaj czego dotyczy: ";
    budgetPosition.setItem(AuxiliaryMethods::loadLine());

    amount = amountInputMenu();
    budgetPosition.setAmount(amount);

    return budgetPosition;
}

int ManagerBudget::dateInputMenu()
{
    char choice;
    int date = 0;

    do
    {
        cout << "Czy chcesz wprowadzic dzisiejsza date? (t/n) ";
        choice = AuxiliaryMethods::loadCharacter();
    }while(choice!='t' && choice!='n');

    if(choice == 'n')
    {
        date = OperationsOnDates::enterDate();
    }
    else
        date = OperationsOnDates::getSystemDate();

    return date;
}

double ManagerBudget::amountInputMenu()
{
    string amountString;
    double amountDouble;

    cout << "Wprowadz kwote: ";
    amountString = AuxiliaryMethods::loadLine();
    amountString = changeCommaToDot(amountString);
    amountDouble = atof(amountString.c_str());

    return amountDouble;
}

string ManagerBudget::changeCommaToDot(string amount)
{
    string amountWithDot = "";

    for(int characterPosition = 0; characterPosition < amount.size(); characterPosition++)
    {
        if(amount[characterPosition] == ',')
        {
            amountWithDot += ".";
            continue;
        }
            amountWithDot += amount[characterPosition];
    }
    return amountWithDot;
}

void ManagerBudget::viewBalance(int startingDate, int endDate)
{
    double totalIncome=0, totalExpense=0, endResult=0;

    incomes = OperationsOnDates::sortingItemsByDate(incomes);
    expenses = OperationsOnDates::sortingItemsByDate(expenses);

    cout.setf(ios::fixed);
    cout << setprecision(2);

    cout << endl << "----------------PRZYCHODY-----------------" << endl << endl;

    for(vector<BudgetPosition>::iterator itr=incomes.begin(); itr!=incomes.end(); itr++)
    {
        if(startingDate<=itr->getDate() &&  itr->getDate()<=endDate)
        {
            cout << OperationsOnDates::convertDateIntToString(itr->getDate()) << "  Kwota:" <<
            itr->getAmount()<< endl << "            Pozycja:" << itr->getItem() << endl;
            totalIncome += itr->getAmount();
        }
    }

    cout << endl << "-----------------WYDATKI------------------" << endl << endl;

    for(vector<BudgetPosition>::iterator itr=expenses.begin(); itr!=expenses.end(); itr++)
    {
        if(startingDate<=itr->getDate() &&  itr->getDate()<=endDate)
        {
            cout << OperationsOnDates::convertDateIntToString(itr->getDate()) << "  Kwota:" <<
            itr->getAmount()<< endl << "            Pozycja:" << itr->getItem() << endl;
            totalExpense += itr->getAmount();
        }
    }

    endResult = totalIncome - totalExpense;
    cout << endl << "---------------PODSUMOWANIE---------------" << endl;
    cout << endl << "Przychody: " << totalIncome << endl;
    cout << "Wydatki:   " << totalExpense << endl;
    cout << "Bilans:    " << endResult << endl;
}

void ManagerBudget::viewBalanceForCurrentMonth()
{
    int beginningOfMonth;

    system("cls");
    if(!incomes.empty() || !expenses.empty())
    {
        beginningOfMonth = OperationsOnDates::getSystemDate()/100*100;

        cout << "$~~~~~~~~BILANS Z AKTUALNEGO MIESIACA~~~~~~~~$" << endl;

        viewBalance(beginningOfMonth, OperationsOnDates::getSystemDate());
    }
    else
        cout << endl << "Nie wprowadzono zadnych pozycji w budzecie osobistym!" << endl << endl;

    system("pause");
}


void ManagerBudget::wyswietlWszystkichAdresatow()
{
    system("cls");
//    if (!adresaci.empty())
//    {
//        cout << "             >>> ADRESACI <<<" << endl;
//        cout << "-----------------------------------------------" << endl;
//        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
//        {
//            wyswietlDaneAdresata(*itr);
//        }
//        cout << endl;
//    }
//    else
//    {
//        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
//    }
    system("pause");
}

//void ManagerBudget::wyswietlDaneAdresata(Adresat adresat)
//{
//    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
//    cout << "Imie:               " << adresat.pobierzImie() << endl;
//    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
//    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
//    cout << "Email:              " << adresat.pobierzEmail() << endl;
//    cout << "Adres:              " << adresat.pobierzAdres() << endl;
//}

//void ManagerBudget::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
//{
//    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
//}

//void ManagerBudget::usunAdresata()
//{
//    idUsuwanegoAdresata = 0;
//
//    system("cls");
//    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
//    idUsuwanegoAdresata = podajIdWybranegoAdresata();
//
//    char znak;
//    bool czyIstniejeAdresat = false;
//
//    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
//    {
//        if (itr -> pobierzId() == idUsuwanegoAdresata)
//        {
//            czyIstniejeAdresat = true;
//            cout << endl << "Potwierdz naciskajac klawisz 't': ";
//            znak = MetodyPomocnicze::wczytajZnak();
//            if (znak == 't')
//            {
//                plikZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
//                adresaci.erase(itr);
//                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
//                system("pause");
//                break;
//            }
//            else
//            {
//                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
//                system("pause");
//            }
//        }
//    }
//    if (czyIstniejeAdresat == false)
//    {
//        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
//        system("pause");
//    }
//    podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata();
//}

int ManagerBudget::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
//    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void ManagerBudget::podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata()
{
//    if (idUsuwanegoAdresata == plikZAdresatami.pobierzIdOstatniegoAdresata())
//        plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata();
}

//void ManagerBudget::edytujAdresata()
//{
//    system("cls");
//    Adresat adresat;
//    int idEdytowanegoAdresata = 0;
//    int numerLiniiEdytowanegoAdresata = 0;
//    string liniaZDanymiAdresata = "";
//
//    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
//    idEdytowanegoAdresata = podajIdWybranegoAdresata();
//
//    char wybor;
//    bool czyIstniejeAdresat = false;
//
//    for (int i = 0; i < adresaci.size(); i++)
//    {
//        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
//        {
//            czyIstniejeAdresat = true;
//            wybor = wybierzOpcjeZMenuEdycja();
//
//            switch (wybor)
//            {
//            case '1':
//                cout << "Podaj nowe imie: ";
//                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
//                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
//                zaktualizujDaneWybranegoAdresata(adresaci[i]);
//                break;
//            case '2':
//                cout << "Podaj nowe nazwisko: ";
//                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
//                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
//                zaktualizujDaneWybranegoAdresata(adresaci[i]);
//                break;
//            case '3':
//                cout << "Podaj nowy numer telefonu: ";
//                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
//                zaktualizujDaneWybranegoAdresata(adresaci[i]);
//                break;
//            case '4':
//                cout << "Podaj nowy email: ";
//                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
//                zaktualizujDaneWybranegoAdresata(adresaci[i]);
//                break;
//            case '5':
//                cout << "Podaj nowy adres zamieszkania: ";
//                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
//                zaktualizujDaneWybranegoAdresata(adresaci[i]);
//                break;
//            case '6':
//                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
//                break;
//            default:
//                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
//                break;
//            }
//        }
//    }
//    if (czyIstniejeAdresat == false)
//    {
//        cout << endl << "Nie ma takiego adresata." << endl << endl;
//    }
//    system("pause");
//}

char ManagerBudget::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = AuxiliaryMethods::loadCharacter();

    return wybor;
}

//void ManagerBudget::zaktualizujDaneWybranegoAdresata(Adresat adresat)
//{
//    plikZAdresatami.edytujAdresataWPliku(adresat);
//
//    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
//}
