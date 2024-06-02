#include "system.h"
// School* LoadData();
// void SaveData(School* school)
// {
//     ofstream file("data.bin", ios::binary);
//     if(file.is_open() == 0)
//     {
//         cout << "Khong the load data" << endl;
//         return;
//     }
//     ghi so khoa hoc
//     file.write((char*)&school->num_school, sizeof(int));
//     SchoolYear* school_year = school->school_year_head;
//     for(int i = 0; i < school->num_school; i++)
//     {
//         int temp;
//         ghi ngay bat dau va ket thuc cua khoa hoc
//         file.write((char*)&school_year->start, sizeof(int));
//         file.write((char*)&school_year->end, sizeof(int));
//         ghi so lop trong khoa hoc
//         file.write((char*)&school_year->num_class, sizeof(int));
//         Class* classs = school_year->class_head;
//         for(int j = 0; j < school_year->num_class; j++)
//         {
//             ghi so ki tu  ten cua class
//             temp = classs->ClassName.length();
//             file.write((char*)&temp, sizeof(int));
//             ghi ten lop
//             file.write((char*)&classs->ClassName, sizeof(classs->ClassName));
//             /ghi so hoc sinh trong lop
//             file.write((char*)&classs->num_student, sizeof(int));
//             Student* student = classs->student_head;
//             for(int t = 0; t < classs->num_student; t++)
//             {
//                 ghi so thu tu cua hoc sinh
//                 file.write((char*)&student->No, sizeof(int));
//                 ghi so ki tu cua firstname
//                 temp = student->FirstName.size();
//                 file.write((char*)&temp, sizeof(int));
//                 /ghi firstname
//                 file.write((char*)&student->FirstName, sizeof(student->FirstName));
//                 ghi so ki tu cua lastname
//                 temp = student->LastName.size();
//                 file.write((char*)&temp, sizeof(int));
//                 /ghi firstname
//                 file.write((char*)&student->LastName, sizeof(student->LastName));
//                 /ghi gender
//                 file.write((char*)&student->Gender, sizeof(bool));
//                 /ghi ngay
//                 file.write((char*)&student->DateofBirth.Day, sizeof(int));
//                 ghi thang
//                 file.write((char*)&student->DateofBirth.Month, sizeof(int));
//                 /ghi nam
//                 file.write((char*)&student->DateofBirth.Year, sizeof(int));
//                 temp = student->SocialID.size();
//                 ghi size sosialid
//                 file.write((char*)&temp, sizeof(int));
//                 ghi socialid
//                 file.write((char*)&student->SocialID, sizeof(student->SocialID));
                

//             }

//         }




//         school_year = school_year->next;
//     }
// }