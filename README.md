# CMAKE_TUTORIAL
## Environment
- Windows 11
- Visial Studio 2022
- CMake 3.30.3 

## Tutorials
<details>
<summary>Step1 - Basic Structure of CMake </summary>

### Step1 - Basic Structure of CMake
우선, 다음을 찾아 이해하자.

**Commands**
- add_executable() : 실행파일 생성 
- cmake_minimum_required() : 최소 요구 CMake 버전을 명시
- project() : 프로젝트 명 설정
    - \<PROJECT_NAME\> 변수에 프로젝트명을 저장
    - 이외에도 다른 변수들을 set하게 됨 (공식문서 참고)
    - \<PROJECT_NAME\>_VERSION_MAJOR, \<PROJECT_NAME\>_VERSION_MINOR도 설정 가능
- set() : 변수 값 설정
- configure_file() : 템플릿 파일을 이용해 CMake 변수들로 치환하여 파일 생성
- target_include_directories() : 타겟을 컴파일할 때, include directory를 명시

**Variables**
- CMAKE_CXX_STANDARD : 11은 c++ 2011 표준을 의미 (공식문서 참고)
- CAMKE_CXX_STANDART_REQUIRED : TRUE / FALSE
- \<PROJECT_NAME\>_VERSION_MAJOR : 프로젝트의 First Version Number
- \<PROJECT_NAME\>_VERSION_MINOR : 프로젝트의 Second Version Number
- PROJECT_BINARY_DIR : 현재 프로젝트의 빌드 디렉토리의 경로

**Understanding**
1. cmake_minimum_required로 최소 CMake 버전 3.10을 명시
2. 프로젝트 명을 step1으로 설정하고, 프로젝트 버전 1.0 명시
3. c++ 표준 설정
4. main.cpp 파일을 이용해 main 실행파일을 생성
5. config.h.in 파일의 CMake 변수들을 치환하여 config.h 파일을 생성. 생성된 헤더파일은 $PROJECT_BINARY_DIR에 생김
6. main을 컴파일할 때, $PROJECT_BINARY_DIR를 include 경로에 추가함.

**Questions**

Q1: 3.30.3 버전의 CMake를 설치했는데, 왜 cmake_minimum_required의 버전은 이보다 낮게 설정해야하는가?

A: cmake_minimum_required의 공식문서를 보면 최대 지정가능한 버전이 명시되어 있음.

Q2: 왜 표준 라이브러리는 CMake에서 따로 링크해줄 필요가 없는가?

A: iostream과 같은 표준 라이브러리는 컴파일러가 이를 자동으로 찾고 링크해준다.

Q3: configure_file()이 무슨 역할인가?

A: config.h.in 템플릿 파일에서 정의된 플레이스홀더(예: @PROJECT_NAME@, @VERSION@)를 CMake 변수를 사용해 실제 값으로 치환한다. 이를 통해 프로젝트 버전이나 옵션 등을 소스 코드에서 쉽게 참조할 수 있다.
</details>

<details>
<summary> Step2 - Adding a Library </summary>

### Step2 - Adding a Library
**Commands**
- add_library() : 라이브러리를 프로젝트에 추가함
- add_subdirectory() : 여기에 들어가는 디렉토리에는 CMakeLists.txt가 포함되어야 함. 해당 디렉토리를 로드하고, 그 디렉토리의 CMakeLists.txt를 실행해줌.
- target_link_libraries() : 라이브러리를 실행파일에 링크해줌

**Variables**
- PROJECT_SOURCE_DIR : CMakeLists.txt 파일이 위치한 디렉토리를 기준으로 하여, 해당 프로젝트의 최상위 디렉토리

**Understanding**
1. step1과 동일하게 CMake 버전, 프로젝트 이름 및 버전, C++ 표준을 명시함
2. add_subdirectory를 통해 MyMath 디렉토리를 로드함. 이때, MyMath의 CMakeLists.txt가 실행됨. 
3. add_library를 통해 MyMath.cpp를 통해 mymath 라이브러리가 만들어짐.
4. 다시 돌아와서 main.cpp를 통해 main 실행파일을 생성.
5. 3에서 만들어진 mymath 라이브러리를 main에 링크
6. main에서 MyMath 헤더를 쓸 수 있도록 include 경로에 추가해줌.

**Questions** 

Q1: 5,6번 과정에서 라이브러리를 링크하는 것과 include해서 쓰는 것은 어떤 차이인가?

A:

라이브러리 링크: 링크 단계에서 실행파일이 라이브러리의 코드에 접근할 수 있도록 결합하는 작업.

include 경로 추가: 컴파일 단계에서 헤더 파일의 선언을 찾을 수 있도록 경로를 지정하는 작업.

</details>

<details>
<summary> Step3 - Adding an Option </summary>

### Step2 - Adding a Library
**Commands**
- if() - 명령어의 조건부 실행
- option() - 사용자가 설정할 수 있는 불린 옵션을 제공
- target_compile_definitions() - 지정된 타깃을 컴파일 할때, compile definition을 지정 (즉, #ifdef에 사용될 수 있음)

**Variables**
None

**Understanding**
1. 우선 step2의 과정은 생략한다.
2. option을 통해서 USE_MYMATH를 ON으로 정의한다. 
3. if문에서 USE_MYMATH가 ON이므로 참이다.
4. if문 안에서 target_compile_definition이 실행되고, "USE_MYMATH"가 mymath 컴파일 시에 정의된다.

**Questions** 
None
</details>

## References
[1] https://cmake.org/cmake/help/v3.30/guide/tutorial/index.html

