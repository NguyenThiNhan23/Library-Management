//Tạo danh mục tra cứu
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
typedef struct quanLyThuVien
{
    int ms;
    string tensach;
    string ho;
    string ten;
    int namXB;
}QL;
typedef struct node
{
    QL data;
    node* next;
} NODE;
typedef struct tagList
{
    NODE* pHead;
    NODE* pTail;
}LIST;
NODE* CreateNode(QL x)
{
    NODE* p;
    p = new NODE;
    if (p == NULL)
    {
        cout << "KHONG DU BO NHO!";
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}
void CreateList(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void addHead(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = NULL;
    }
    else
    {
        p->next = l.pHead;
        l.pHead = p;
    }
}

void addTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->next = p;
        l.pTail = p;
    }
}
//Ham nhap vao 1 quyen sach
QL nhap1QuyenSach(QL x)
{
    cout << "\t\tNhap them mot cuon sach" << endl;
    cout << endl;
    cout << "Nhap ma so sach:";
    cin >> x.ms;
    cout << "Nhap ten sach: ";
    cin.ignore();
    getline(cin, x.tensach);
    cout << "Nhap ho tac gia:";
    fflush(stdout);
    getline(cin, x.ho);
    cout << "Nhap ten tac gia:";
    fflush(stdout);
    getline(cin, x.ten);
    cout << "Nhap nam xuat ban:";
    cin >> x.namXB;
    return x;
}
//Ham nhap vao ds cac quyen sach
void Nhap(LIST& l, int n)
{

    NODE* p;
    for (int i = 0; i < n; i++)
    {
        QL x;
        cout << "-Nhap quyen sach thu " << i + 1 << ":" << endl;
        p = CreateNode(nhap1QuyenSach(x));
        addTail(l, p);
    }
}
//Sắp xếp theo mã số sách, tên tác giả, năm xuất bản
void sapXepTheoMaSo(LIST& l)
{
    for (NODE* k = l.pHead; k->next != NULL; k = k->next)
    {
        for (NODE* h = k->next; h != NULL; h = h->next)
        {
            if (h->data.ms < k->data.ms)
            {
                swap(k->data, h->data);
            }
        }
    }
}
void sapXepTheoTen(LIST& l)
{
    for (NODE* k = l.pHead; k->next != NULL; k = k->next)
    {
        for (NODE* h = k->next; h != NULL; h = h->next)
        {
            if (strcmp(h->data.ten.c_str(), k->data.ten.c_str()) < 0)
            {
                swap(k->data, h->data);
            }
            else if (strcmp(h->data.ten.c_str(), k->data.ten.c_str()) == 0)
            {
                if (strcmp(h->data.ho.c_str(), k->data.ho.c_str()) < 0)
                {
                    swap(k->data, h->data);
                }
            }
        }
    }
}
void sapXepTheoNamXB(LIST& l)
{
    for (NODE* k = l.pHead; k->next != NULL; k = k->next)
    {
        for (NODE* h = k->next; h != NULL; h = h->next)
        {
            if (h->data.namXB < k->data.namXB)
            {
                swap(k->data, h->data);
            }
        }
    }
}
void XuatToanBoSach(LIST l)
{
    cout << "\t\tLiet ke toan bo sach trong thu vien" << endl;
    cout << endl;
    cout << "STT\tMa sach\t\tTen sach\t\tTac gia\t\t\tNam xuat ban\n";
    int stt = 0;
    NODE* p = new NODE;
    for (p = l.pHead; p != NULL; p = p->next)
    {
        cout << stt++ << "\t";
        cout << p->data.ms << "\t\t";
        cout << p->data.tensach << "\t\t";
        cout << p->data.ho << " " << p->data.ten << "\t\t";
        cout << p->data.namXB << endl;
    }
}

void Xuat(LIST& l)
{
    int stt = 0;
    cout << "STT\tMa sach\t\tTen sach\t\tTac gia\t\t\tNam xuat ban\n";
    for (NODE* p = l.pHead; p != NULL; p = p->next)
    {
        cout << stt++ << "\t";
        cout << p->data.ms << "\t\t";
        cout << p->data.tensach << "\t\t";
        cout << p->data.ho << " " << p->data.ten << "\t\t";
        cout << p->data.namXB << endl;
    }
}

bool ktraString(string a, string b)
{
    int dem = 0;
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {

            if (a[i] == b[i])
            {
                dem++;
            }

            else dem;
        }

        if (dem == a.size())
            return true;
        else
            return false;
    }
    else false;
}
//Tìm kiếm theo mã số sách, tên tác giả, năm xuất bản
void TimTheoMS(LIST l, int x)
{
    LIST m;
    CreateList(m);
    NODE* p = l.pHead;
    for (p; p != NULL; p = p->next)
    {
        if (p->data.ms == x)
        {
            NODE* k = CreateNode(p->data);
            addTail(m, k);
        }
    }
    Xuat(m);
}

void TimTheoTen(LIST l)
{
    string x;
    cout << "-Nhap vao ten tac gia can tim: ";
    cin.ignore();
    getline(cin, x);
    NODE* p = l.pHead;
    LIST m;
    CreateList(m);
    for (p; p != NULL; p = p->next)
    {
        if (ktraString(p->data.ten, x) == true)
        {
            NODE* k = CreateNode(p->data);
            addTail(m, k);
        }
    }
    Xuat(m);
}

void TimTheoNamXB(LIST l, int x)
{
    NODE* p = l.pHead;
    LIST m;
    CreateList(m);
    for (p; p != NULL; p = p->next)
    {
        if (p->data.namXB == x)
        {
            NODE* k = CreateNode(p->data);
            addTail(m, k);
        }
    }
    Xuat(m);
}

//Xóa theo mã số sách, tên tác giả, năm xuất bản
void XoaDau(LIST& l)
{
    NODE* p = new NODE;
    p = l.pHead;
    l.pHead = l.pHead->next;
    p->next = NULL;
    delete p;
}
void XoaCuoi(LIST& l)
{
    NODE* p = new NODE;
    for (p = l.pHead; p != NULL; p = p->next)
    {
        if (p->next == l.pTail)
        {
            delete l.pTail;
            p->next = NULL;
            l.pTail = p;
        }
    }
}
bool RemoveSachTheoMaSach(LIST& l, int maSach)
{
    NODE* pDel = l.pHead;
    if (pDel == NULL)
    {
        cout << "Danh sach rong!";
        return false;
    }

    NODE* pPre = NULL;
    while (pDel != NULL)
    {
        NODE* sach = pDel;
        if (sach->data.ms == maSach)
            break;
        pPre = pDel;
        pDel = pDel->next;
    }

    if (pDel == NULL)
    {
        return false;
    }
    else
    {
        if (pDel == l.pHead)
            XoaDau(l);
        else
        {
            pPre->next = pDel->next;
            pDel->next = NULL;
            delete pDel;
            pDel = NULL;
        }
    }
    return true;
}
//xoa tat ca
void RemoveAllSachTheoMaSach(LIST& l, int maSach)
{
    bool tiepTuc = false;
    do {
        tiepTuc = RemoveSachTheoMaSach(l, maSach);
    } while (tiepTuc);
}
//Xoa theo nam xuat ban
bool RemoveNamXB(LIST& l, int namXB)
{
    NODE* pDel = l.pHead;
    if (pDel == NULL)
    {
        cout << "Danh sach rong!";
        return false;
    }

    NODE* pPre = NULL;
    while (pDel != NULL)
    {
        NODE* sach = pDel;
        if (sach->data.namXB == namXB)
            break;
        pPre = pDel;
        pDel = pDel->next;
    }

    if (pDel == NULL)
    {
        return false;
    }
    else
    {
        if (pDel == l.pHead)
            XoaDau(l);
        else
        {
            pPre->next = pDel->next;
            pDel->next = NULL;
            delete pDel;
            pDel = NULL;
        }
    }
    return true;
}
//xoa tat ca
void RemoveAllSachTheoNamXB(LIST& l, int namXB)
{
    bool tiepTuc = false;
    do {
        tiepTuc = RemoveNamXB(l, namXB);
    } while (tiepTuc);
}
//Xoa tac gia
bool RemoveTacgia(LIST& l, string ho, string ten)
{
    NODE* pDel = l.pHead;
    if (pDel == NULL)
    {
        cout << "Danh sach rong!";
        return false;
    }

    NODE* pPre = NULL;
    while (pDel != NULL)
    {
        NODE* sach = pDel;
        if (sach->data.ho.compare(ho) == 0 && sach->data.ten.compare(ten) == 0)
            break;
        pPre = pDel;
        pDel = pDel->next;
    }

    if (pDel == NULL)
    {
        return false;
    }
    else
    {
        if (pDel == l.pHead)
            XoaDau(l);
        else
        {
            pPre->next = pDel->next;
            pDel->next = NULL;
            delete pDel;
            pDel = NULL;
        }
    }
    return true;
}
//xoa tat ca tac gia
void RemoveAllTacgia(LIST& l)
{
    cout << "Ho cua tac gia ma ban muon tim: ";
    string ho, ten;
    fflush(stdin);
    getline(cin, ho);
    cout << "Ten cua tac gia ma ban muon tim: ";
    fflush(stdin);
    getline(cin, ten);
    cin >> ten;
    bool tiepTuc = false;
    do {
        tiepTuc = RemoveTacgia(l, ho, ten);
    } while (tiepTuc);

}
//Cập nhật danh mục
void CapNhatDS(LIST& l, NODE* p, NODE* q)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p->next;
        if (l.pTail == q)
            l.pTail = p;
    }
    else
        addHead(l, p);
}

void Thoat()
{
    cout << endl;
    cout << "\t\t\t\tCam on da su dung. Xin chao va hen gap lai!" << endl;
    cout << endl;
}

void MENU() {
    cout << "\t\t*******************************************" << endl;
    cout << "\t\t\tChuong trinh quan ly thu vien" << endl;
    cout << "\t\t\t\t(Nhom 1 - De 3)" << endl;
    cout << "\t\t*******************************************" << endl;
    cout << endl;
    cout << "\t\t1. Nhap vao mot cuon sach" << endl;
    cout << "\t\t2. Sua thong tin sach" << endl;
    cout << "\t\t3. Xoa mot cuon sach theo ma so sach" << endl;
    cout << "\t\t4. Xoa mot cuon sach theo ten tac gia" << endl;
    cout << "\t\t5. Xoa mot cuon sach theo nam xuat ban" << endl;
    cout << "\t\t6. Sap xep sach theo ma so sach" << endl;
    cout << "\t\t7. Sap xep sach theo ten tac gia" << endl;
    cout << "\t\t8. Sap xep sach theo nam xuat ban" << endl;
    cout << "\t\t9. Tim kiem sach theo ma so sach" << endl;
    cout << "\t\t10. Tim kiem sach theo ten tac gia" << endl;
    cout << "\t\t11. Tim kiem sach theo nam xuat ban" << endl;
    cout << "\t\t12. Liet ke toan bo sach trong thu vien" << endl;
    cout << "\t\t13. Thoat khoi he thong" << endl;
    cout << endl;
    cout << "\t\t*******************************************" << endl;
    cout << "=> Moi chon chuc nang: ";
}

int Choose(LIST& l)
{
    int chon;
    do {
        MENU();
        cin >> chon;
        cout << "======================================" << endl;
        switch (chon) {
        case 1:
            int n;
            cout << "-Nhap vao so luong sach can them: ";
            cin >> n;
            Nhap(l, n);
            break;
        case 2:
            break;
        case 3:
            int m;
            cout << "Nhap vao MaSo can xoa: ";
            cin >> m;
            RemoveAllSachTheoMaSach(l, m);
            XuatToanBoSach(l);
            break;
        case 4:
            RemoveAllTacgia(l);
            XuatToanBoSach(l);
            break;
        case 5:
            int k;
            cout << "Nhap vao so nam can xoa: ";
            cin >> k;
            RemoveAllSachTheoNamXB(l, k);
            XuatToanBoSach(l);
            break;
        case 6:
            sapXepTheoMaSo(l);
            XuatToanBoSach(l);
            break;
        case 7:
            sapXepTheoTen(l);
            XuatToanBoSach(l);
            break;
        case 8:
            sapXepTheoNamXB(l);
            XuatToanBoSach(l);
            break;
        case 9:
            int x;
            cout << "-Nhap ma so sach can tim: ";
            cin >> x;
            TimTheoMS(l, x);
            break;
        case 10:
            TimTheoTen(l);
            break;
        case 11:
            int a;
            cout << "-Nhap nam xuat ban can tim: ";
            cin >> a;
            TimTheoNamXB(l, a);
            break;
        case 12:
            XuatToanBoSach(l);
            break;
        case 13:
            Thoat();
            break;
        }
        if (chon != 13) {
            cout << endl;
            cout << "=========================" << endl;
            cout << "=> Nhan enter de tro ve !";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (chon != 13);
    return 0;
}



int main()
{
    LIST l;
    CreateList(l);
    Choose(l);
    return 0;
}
