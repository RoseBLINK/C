#include <stdio.h>
#include <vector>
#pragma warning(disable: 4996)
// C를 배우는 목적
// 컴퓨터가 어떻게 데이터를 처리하는지 자세히 알 수 있는 언어

// 변수 -> 값에 접근
// &변수 -> 주소에 접근
// *변수 -> 가리키고있는 변수의 값 접근


// 포인터
// 배열
// 문자열
// 메모리 관리


typedef unsigned int UINT;
typedef enum syllable
{
    Do=1, Re=2, Mi=3, Pa=4, So=5
};

typedef struct Info
{
    int id;
    char* Name;
} SERVER;

struct Point
{
    typedef enum aaa
    {
        rrr =1,
        sss,
        yyy,
    };
    int xpos;
    int ypos;
    Info* info; // info.id, info.Name;
};

struct Circle
{
    double radius;
    Point* center; // center 는 xpos, ypos, zpos 값을 가지고 zpos 는 그 안에서 server 변수를 가지는가
    //포인터로 넘기는 이유: 메모리 효율
};

typedef Circle CIRCLE;

void Struct()
{
    int a = 5;
    int* pa = &a;

    *pa = 10;

    Point p = {1,2}; //선언과 동시에 초기화?
    p.xpos = p.rrr; //p의 xpos
    
    Circle c1;
  /*  c1.center->zpos.id.;*/

    Point* pp = &p; // pp는 p의 주소를 갖음 / p 의 자료형이 Point 기때문에 Point*

    const char* pasd = "Asd";

    pp->xpos = 5; // 구조체와 포인터
    pp->ypos = 3; //pp.ypos 치면 자동 변환, (*pp).xpos = 3; 과 같음

    Point cen = { 5,5, nullptr }; //cen 은 xpos 으로 5, ypos으로 5, z는 null?
    Circle cir = { 10, &cen }; // 넘겨줄때 &로 넘겨주는 이유 기억 안남
}

void readFile()
{
    const char* fileName = "userInfo.csv";

    FILE* fd; // 파일 디스크립터
    fd = fopen(fileName, "r"); // 파일 오픈

    if (fd == 0)
    {
        printf("Unable to open file. %s\n", fileName);
        return;
    }

    // 파일 읽기 ( fgetc, fgets, fread, fscanf )

    char buf[1024] = { 0, };
    while (!feof(fd))
    {
        fgets(buf, sizeof(buf), fd);
        printf("buf = %s", buf);
    }

    fclose(fd); // 파일 클로즈
}

void writeFile()
{
    const char* fileName = "userInfo2.csv";

    FILE* fd; // 파일 디스크립터
    fd = fopen(fileName, "w"); // 파일 오픈

    if (fd == 0)
    {
        printf("Unable to open file. %s\n", fileName);
        return;
    }

    // 파일 쓰기 ( fputc, fputs, fwrite, fprintf )

    char buf[1024] = "hello";
    fputs(buf, fd);

    const char* str = "BLACKPINK";
    fprintf(fd, "hello %s\n", str);
    fprintf(fd, "%s\n", buf);

    fclose(fd); // 파일 클로즈
}

void File()
{
    //readFile();
    writeFile();
}

void Iostream()
{
    // 표준 입출력
    // 파일 입출력

    /*FILE* fd = fopen("./asdf.csv", "w");
    if ( !fd )
    {
        printf("asdasd");
        exit(0);
    }
    fputs("hello\n", fd);
    fputs("world\n", fd);
    fclose(fd);*/
    
    /// 문자 단위 입출력 함수

    // 문자 출력함수
    putchar('a'); // 표준 출력
    FILE* fp;
    fputc('b', stdout); // fputc의 두번째 인자는 데이터 출력의 방향을 결정한다.

    // 문자 입력함수
    //int a = getchar(); // 표준 입력
    //putchar(a);
    //int a2 = fgetc(stdin);
    //putchar(a2);

    /// 문자열 단위 입출력 함수
    // 문자열 출력함수
    puts("hello");
    fputs("world", stdout); // 알아야 함
    
    char str[7];
    //gets(str);
    //fgets(str, sizeof(str), stdin); // 알아야 함
    //puts(str);

    size_t len = strlen("hello"); // 문자열 길이 반환    
    printf("strlen(hello) = %u\n", len);

    const char* h = "hello";
    const char* w = "world";

    //strcpy(str1, str2); // 문자열 복사
    //printf("str1 = %s, str2 = %s\n", str1, str2);

    //strncpy(str1, str2, sizeof(str1)-1); // 문자열 복사(버퍼의 사이즈)
    //printf("str1 = %s, str2 = %s\n", str1, str2);

    
    char hw[] = "hello";

    //strcat(hw, w); // 문자열 덧붙이기
    //printf("hw = %s\n", hw);

    //strncat(hw, w, 3);
    //printf("hw = %s\n", hw);

    int res = strcmp(h,w);  // 문자열의 내용 비교, h가 w보다 크면 1 작으면 -1 같으면 0
    printf("compare res = %d\n",res);

    int nres = strncmp(h,w,3);
    printf("compare nres = %d\n", nres);

    const char* str45 = "45";
    const char* str55 = "55";
    int num45 = atoi(str45); // 문자열 숫자로 변환
    int num55 = atoi(str55);
    
    int num100 = num45 + num55;
    printf("num45= %d", num100);

}

void VoidPointer()
{
    int num = 20;
    double num2 = 20.1;
    void* ptr;

    ptr = &num; // void 포인터는 무엇이든 될 수 있다.
    ptr = &num2; // 일단 주소 값에만 의미를 두고, 포인터의 형은 나중에 결정한다.
    //*ptr = 50; // 하지만 가리키고 있는 값에 접근할 수 없다.

    int* ptr2 = (int*)ptr; // void 포인터를 int 포인터로 형변환(Unstable)
    ptr2++;
}

void func2(int a, void (*f)(int, double)) // 함수 포인터를 매개변수로 받는 함수
{
    if ( a == 0 )
         f(1, 6.5);
}

void func1(int a, double b)
{
    
}

void func3(int a, double b)
{

}

void FunctionArray()
{
    // 함수 포인터 -> 함수의 주소를 가리킨다
    void (*fptr)(int, double) = func1;
    
    func1(1,7.5); // 일반적인 함수호출
    fptr(1,7.5); // 함수포인터를 통한 함수호출


    void (*fptr3)(int, double) = func3;
    func2(0, fptr);
    func2(0, fptr3); // 인자로 함수포인터 전달


    //overriding 함수 이름은 같은데 반환형 매개변수, 상속관계 부모 클래스의 메소드를 재정의 기능을 다르게 함
    //overloading 함수 이름만 같고, 매개변수 개수 & 타입
}

void PointerArray()
{
    int num1 = 10, num2 = 20, num3 = 30;
    int* ptr1 = &num1;
    int* ptr2 = &num2;
    int* ptr3 = &num3;

    int* ptrArr[] = { ptr1, ptr2, ptr3 }; // 포인터 배열(포인터 변수가 담긴 배열)
    int**dptr = ptrArr;

    char aaa = 'a';

    char a[] = "hello"; // char* == 문자열
    char* a1 = a; // 
    
    const char* aaaa = "hello";

    char b[] = "world";
    char c[] = "foo";

    char* ptrArrChar[] = {a,b,c}; // 문자열이 여러개 담긴 배열


    // 포인터 배열
    // 배열 포인터

    int a123[] = {1,2,3};
    int* b123 = a123;
}

void swap1(int* a, int* b)
{
    int* temp = a;
    a = b;
    b = temp;
}

void swap2(int** a, int** b)
{
    int** temp = a;
    a = b;
    b = temp;
}

void DoublePointer()
{
    // 더블포인터 == 포인터의 주소값

    int num1 = 7;
    int* ptr1 = &num1;
    int** dptr1 = &ptr1; // 포인터의 주소값

    *ptr1 = 10;
    **dptr1 = 12;

    dptr1; // ptr1의 주소(&ptr1)
    *dptr1; // *dptr1은 ptr1과 같다
    &dptr1; // dptr1의 주소


    int num2 = 7;
    int* ptr2 = &num2;

    int num3 = 3;
    int* ptr3 = &num3;

    swap1(ptr2, ptr3);
    swap2(&ptr2, &ptr3);

}

void MultiArray()
{
    int arr[2][3][4] = {{{1,2,3,4}, {1,2,3,4}, {1,2,3,4}}, {{1,2,3,4}, {1,2,3,4}, {1,2,3,4}}};

    int arr2[2][3] = {{1,2,3}, {4,5,6}};

    *(arr2+4);
}

void Dojeon()
{
    int input[10] = {1,2,3,4,5,6,7,8,9,10};
    int newInput[10] = {0, };
    
    int* start = newInput;
    int* end = newInput + 9;
    for ( int i = 0; i < 10; i++ )
    {
        if ( input[i] % 2 != 0 )
        {
            *(start++) = input[i];
        }
        else
        {
            *(end--) = input[i];
        }
    }

    for ( int i = 0; i < 10; i++ )
        printf("%d ", newInput[i]);
}

void func1(int a) // Call by value
{
    a++;
}

void func2(int* a) // Call by reference
{
    *a++;
}

void func3(int arr[]) // Array call
{
    arr[3] = 3;
}

void func4(int* arr) // Array call by pointer
{
    *(arr+3) = 3;
}

void Pointer_Function()
{
    // Call by value
    // Call by Reference
    int num = 1;
    func1(num);
    func1(num);
    func2(&num);

    int arr[10] = {0,};
    func3(arr);
    func4(arr);

    char a = 6;
    char b = 7;
    char c = 7;
    const char* cA = &a;
    cA = &b; // 무엇을 가리키는지를 바꿀 수는 있다 (화살표 바꾸기) - 된다
    //*cA = 10;// 가리키고 있는 값 자체를 바꿀 수는 없다

    char* const cB = &b;
    //cB = &a; // 무엇을 가리킬지를 바꿀수 없다
    *cB = 10; // 가리키고 있는 값 자체를 바꿀 수 있다\`

    const char* const cC = &c;
    //cC = &c;
    //*cC = 11;

    const int const aa = 1;
    //aa = 5;
}

void Pointer_Array()
{
    int arr[5] = { 1,2,3,4,5 };

    printf("arr: %p\n", arr);
    printf("&arr[0]: %p\n", &arr[0]);
    printf("arr[3]: %d\n", arr[3]);
    printf("\n");

    // 배열의 이름 == 포인터(배열을 가리키는 포인터)
    *arr = 7;

    arr; // 배열의 이름이자 첫번째 원소의 주소
    arr+1; // 두번째 원소의 주소
    *(arr+1); // 두번째 원소의 값


    int* abc = arr+1; // 배열을 포인터로 접근
    int* abc2 = &arr[1]; // 배열을 인덱스로 접근(위 아래 같은 방법)

    //*(++abc2) = 20;
    *(abc2+1) = 20;
    printf("%d *abc: %d\n", __LINE__, *abc);
    printf("%d *(abc+1): %d\n", __LINE__, *(abc+1));

    printf("*arr: %d\n", *arr);
    printf("*(arr+3): %d\n", *(arr+3));
    printf("\n");

    for ( int i = 0; i < sizeof(arr) / sizeof(int); i++ )
    {
        printf("%d\n", arr[i]);
    }
    
    printf("\n");

    for ( int i = 0; i < sizeof(arr) / sizeof(int); i++ )
    {
        printf("%d\n", *(arr+i));
    }

    int num = 1;
    int* ptr = &num;
    printf("ptr: %p\n", ptr);
    printf("*ptr: %d\n", *ptr);
    ptr++;
    printf("ptr: %p\n", ptr);
    printf("*ptr: %d\n", *ptr);

    printf("\n");

    // 배열과 문자열

    // 문자열을 만드는 방법 2가지
    char a[] = "hello world"; // 배열을 이용한 방법(1)
    char b =*(a+2);
    printf("%s\n", a); // 문자열 출력
    printf("%c\n", b); // 문자 출력

    const char* a2 = "adfadsf"; // 포인터를 이용한 방법(2)

    char a3 = 'b'; // char는 1바이트 정수표현 및 문자표현
    char* c;
    c = &a3; // 한글자 'b'인 a2의 주소를 가리킴
    c = a;  // 문자열 "hello world"인 a의 첫번째 주소를 가리킴

    printf("%s\n", c); // 문자열 출력
    
}

void Pointer()
{
    int num1 = 1;
    int num2 = 2;

    int* pNum1 = &num1; //pNum1: num1
    int* pNum2 = pNum1; //pNum2: pNum1의 값 할당

    num1 = 5;
    *pNum1 = 10;

    // 접근
    &num1;  // num1의 주소
    &num2;  // num2의 주소
    num1;   // num1의 값
    num2;   // num2의 값
    pNum1;  // pNum1의 값 == num1의 주소
    pNum2;  // pNum2의 값 == pNum1의 값 == num1의 주소
    *pNum1; // pNum1이 가리키고 있는 주소의 값 == num1
    *pNum2; // pNum2이 가리키고 있는 주소의 값 == num1
    &pNum1; // pNum1의 주소
    &pNum2; // pNum2의 주소

    // 변수 -> 값에 접
    // &변수 -> 주소에 접근
    // *변수 -> 가리키고있는 변수의 값 접근

    //////////////////////////////

    int n1 = 10;
    int n2 = 20;

    int* ptr1 = &n1; //ptr1 = n1의 주소
    int* ptr2 = &n2; //ptr2 = n2의 주소

    *ptr1 += 10;
    *ptr2 -= 10;
    printf("ptr1이 가르키고 있는 값: %d \n", *ptr1);
    printf("ptr2가 가르키고 있는 값: %d \n", *ptr2);

    ptr1 = &n2;
    ptr2 = &n1;

    printf("ptr1이 가르키고 있는 값: %d \n", *ptr1);
    printf("ptr2가 가르키고 있는 값: %d \n", *ptr2);

}

void Scanf()
{
    // 정수 입력 받기
    printf("정수를 입력하세요\n");
    int inputNum;
    scanf("%d", &inputNum);

    printf("입력값: %d\n", inputNum);

    // 문자열 입력 받기
    printf("문자열을 입력하세요\n");
    char inputChar[30];
    scanf("%s", &inputChar);

    printf("입력값: %s\n", inputChar);

}

void Array()
{
    int arr[30] = {0,}; // 배열 길이 선언과 동시에 초기화;
    int arr2[30];
    arr2[0] = 0; // 배열 선언 후 초기화 or 값 할당
    
    int arr3[] = {1,2,3,4}; // 배열 길이 선언하지 않고 초기화

    const int num = 10;
    int arr4[num]; // 배열 길이 선언(변수사용)


    char arrChar[3] = {'a', 's', 'd'}; // 기존 배열과 마찬가지로, 길이 선언과 동시에 원소로 초기화
    char arrChar2[4] = "asd"; // 길이 선언과 동시에 문자열로 초기화(길이 = 문자열개수+1)
    char arrChar3[] = "asd"; // 문자열로만 초기화
    arrChar3[0] = 'p';

}

void Type()
{
    // 정수
    char c = 97;
    char c1 = 'a';
    short s = 2;
    const int n = 4;
    unsigned int un = 4;
    long l = 8;
    unsigned long ul = 8;

    int a = 1;
    // lvalue 메모리를 가지고 있음, 참조가능
    // rvalue 메모리를 가지고 있지 않음, literal

    double b = (double)a; // 명시적 형변환

    printf("%d\n", sizeof(int));

    printf("%c\n", c1);
    printf("%d\n", c);
    printf("%d\n", l);

    printf("%p", &c);

    // 실수
    float f = 4.0;
    double d = 8.0;

    printf("%f", d);
}

Point GetCurrentPosition()
{
    Point cen;
    cen.xpos = 1;
    cen.ypos = 2;
    return cen;
}

int main(int argc, char* argv[])
{
    Point curPos = GetCurrentPosition();

    /*for ( int i = 0; i < argc; i++ )
    {
        printf("%s\n", argv[i]);
    }*/

    //Type();
    //Array();
    //Scanf();
    //Pointer();
    //Pointer_Array();
    //Pointer_Function();
    //Dojeon();
    //MultiArray();
    //DoublePointer();
    //PointerArray();
    //FunctionArray();
    //VoidPointer();
    //Iostream();
    //Struct();
    File();
}
