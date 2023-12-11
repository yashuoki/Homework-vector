#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

int main() {
    // комментарий для репозитория
    // Открытие файла
    HANDLE rarfile = CreateFile("work_with_vector.rar",
	GENERIC_READ, // Права доступа - чтение
	0, // Флаги безопасности не используются
	NULL, // Атрибут безопасности - по умолчанию
	OPEN_EXISTING, // Флаг, указывающий, что файл откроется, только если существует
	FILE_ATTRIBUTE_NORMAL, // Атрибут обычного файла
	NULL); // Шаблон файла не используется

    // Проверка успешного открытия файла
	if (rarfile == INVALID_HANDLE_VALUE) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    // Получение размера файла
    DWORD rarSize = GetFileSize(rarfile, NULL);
    if (rarSize == INVALID_FILE_SIZE) {
        cout << "Ошибка получения размера файла" << endl;
        CloseHandle(rarfile);
        return 1;
    }

    // Выделение буфера для считывания данных
    vector<char> bufrar(rarSize);

    // Чтение данных из файла в буфер
    DWORD bytesRead;
    if (!ReadFile(rarfile, bufrar.data(), rarSize, &bytesRead, NULL)) {
    	//Указатель на начало буфера buffrar, количество байт для прочтения из файла = rarsize, bytesRead содержит фактически прочитанных байт после окончания
        cout << "Ошибка чтения файла" << endl;
        CloseHandle(rarfile);
        return 1;
    }
	
	
    // Закрытие файла
    CloseHandle(rarfile);


    return 0;
}
