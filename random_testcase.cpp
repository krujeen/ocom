#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream> // ไลบรารีสำหรับจัดการไฟล์

using namespace std;

int main()
{
    // ตั้งค่า seed สำหรับการสุ่ม
    srand(time(0));

    // กำหนดจำนวนชุดทดสอบ
    int numTestCases = 10; // จำนวนไฟล์ชุดทดสอบที่ต้องการสร้าง
    int maxN = 0;          // ค่า N สูงสุดในแต่ละชุดทดสอบ
    int N = 1;             // ค่า N ที่ต้องการสุ่ม
    int start_n = 1;
    int stop_n = 100;   // ถ้าต้องการทศนิยม ให้เพิ่ม 0 อีก 2 ตัว
    double R00 = 100.0; // จำนวนทศนิยม 100.0 คือ 2 ตำแหน่ง

    int I1orR0 = 1; // กำหนดว่าจะ random จำนวนเต็มหรือจำนวนจริง

    // สร้างโฟลเดอร์ testcase ถ้าไม่มี
    string folderName = "testcase";
    filesystem::create_directory(folderName);

    // สำหรับสร้างไฟล์ 1.in, 2.in, ... , numTestCases.in
    for (int t = 1; t <= numTestCases; t++)
    {
        // สร้างชื่อไฟล์ เช่น "1.in", "2.in", ...
        string fileName = folderName + "/" + to_string(t) + ".in";

        // เปิดไฟล์เพื่อเขียนข้อมูล
        ofstream outFile(fileName);

        if (!outFile)
        {
            cerr << "ไม่สามารถเปิดไฟล์ " << fileName << " ได้" << endl;
            return 1;
        }

        // สุ่มค่า N (จำนวนตัวเลขในแต่ละชุด)
        if (maxN != 0)
        {
            N = rand() % maxN + 1; // สุ่มค่า N ตั้งแต่ 1 ถึง maxN
            outFile << N << endl;
        }

        // เลือกตัวเลชว่าจะสุ่ม I หรือ R
        if (I1orR0 == 1)
        {
            // สุ่มตัวเลขในชุดข้อมูล
            for (int i = 0; i < N; i++)
            {
                int value = rand() % stop_n + start_n; // สุ่มค่าตัวเลขตั้งแต่ 1 ถึง 1000
                outFile << value << " ";               // เขียนตัวเลขลงในไฟล์
            }
        }
        else
        {
            // สุ่มตัวเลขในชุดข้อมูล
            for (int i = 0; i < N; i++)
            {
                double value = (rand() % stop_n + start_n) / R00; // สุ่มค่าตัวเลขตั้งแต่ 1 ถึง 1000
                outFile << value << " ";                          // เขียนตัวเลขลงในไฟล์
            }
        }

        outFile << endl;

        // ปิดไฟล์เมื่อเขียนเสร็จ
        outFile.close();

        cout << "สร้างไฟล์ " << fileName << " เรียบร้อยแล้ว" << endl;
    }

    return 0;
}
