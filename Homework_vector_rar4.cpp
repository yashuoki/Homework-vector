#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

int main() {
    // ����������� ��� �����������
    // �������� �����
    HANDLE rarfile = CreateFile("work_with_vector.rar",
	GENERIC_READ, // ����� ������� - ������
	0, // ����� ������������ �� ������������
	NULL, // ������� ������������ - �� ���������
	OPEN_EXISTING, // ����, �����������, ��� ���� ���������, ������ ���� ����������
	FILE_ATTRIBUTE_NORMAL, // ������� �������� �����
	NULL); // ������ ����� �� ������������

    // �������� ��������� �������� �����
	if (rarfile == INVALID_HANDLE_VALUE) {
        cout << "������ �������� �����" << endl;
        return 1;
    }

    // ��������� ������� �����
    DWORD rarSize = GetFileSize(rarfile, NULL);
    if (rarSize == INVALID_FILE_SIZE) {
        cout << "������ ��������� ������� �����" << endl;
        CloseHandle(rarfile);
        return 1;
    }

    // ��������� ������ ��� ���������� ������
    vector<char> bufrar(rarSize);

    // ������ ������ �� ����� � �����
    DWORD bytesRead;
    if (!ReadFile(rarfile, bufrar.data(), rarSize, &bytesRead, NULL)) {
    	//��������� �� ������ ������ buffrar, ���������� ���� ��� ��������� �� ����� = rarsize, bytesRead �������� ���������� ����������� ���� ����� ���������
        cout << "������ ������ �����" << endl;
        CloseHandle(rarfile);
        return 1;
    }
	
	
    // �������� �����
    CloseHandle(rarfile);


    return 0;
}
