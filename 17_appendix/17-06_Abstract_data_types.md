# 17-06. 추상 자료형(Abstract Data Types)
----

자료구조를 배울 때 아주 중요하게 다뤄지며 반드시 이해해야 하는 개념인 추상 자료형에 대해 알아보자.

<img width="822" alt="image" src="https://user-images.githubusercontent.com/78291267/174012957-a7c97262-abb8-4821-b359-a7b73e68a7cf.png">


자료형에 대한 개념을 지금까지 배운 자료형 개념을 뛰어넘어 좀 더 확장해서 일반적인 개념으로 다시 생각해보자. 

**자료형은 (데이터) 객체의 모음과 그 객체들에 대해 작동하는 연산들이다.**

"int"라는 자료형은 데이터 객체(메모리에 있는 데이터는 전부 객체라고 할 수 있음)들은 INT_MIN ~ INT_MAX 사이 선언된다. 또한 int라는 자료형은 이 데이터들을 가지고 연산을 할 수도 있다. 이 연산들 또한 데이터 타입에 포함돼야 한다.

이 개념들을 가지고, 앞에서 만든 영화 평점관리 프로그램의 평점 목록과 비교해보자. 이 영화 목록에는 문자열, 평점 데이터가 있었다. 이들 객체내에선 출력, 삽입, 삭제 등의 연산으로써 표현 가능하다.

<img width="841" alt="image" src="https://user-images.githubusercontent.com/78291267/174013061-1c9eaa0a-c712-4adb-ade0-db88208e1a3c.png">


두 가지 중요한 개념을 추가로 알아보자. Encapsulation을 통해 복잡하고 자세한 사항들을 사용자가 보지 않게 캡슐로 감싸는 것이다. Abstraction은 TV 리모컨을 예시로 설명한다. 사용설명서에 있는 바와 같이, 리모컨을 사용해 TV를 어떻게 조작하는지는 알지만, 그것이 실제로 어떻게 작동하는지는 사용자가 모르도록 추상화를 할 수 있다. 

아래에서 정확한 정의를 살펴보자.

<img width="818" alt="image" src="https://user-images.githubusercontent.com/78291267/174013107-c464be32-b3cb-4feb-9e22-b95fa0ab6cd2.png">



- 명세(specification) -> 사용설명서
- 구현(implemenataion) -> 실제 작동 원리


<img width="823" alt="image" src="https://user-images.githubusercontent.com/78291267/174013125-1db6bc4b-e3ea-4f57-8514-f96f25b7f02a.png">



이번엔 추상 자료형에 대해 알아보자.

<img width="842" alt="image" src="https://user-images.githubusercontent.com/78291267/174013157-7c549a5c-4aac-485b-89ee-423d2c27bdcb.png">


- 주의: 애매한 것과 추상적인 것은 다르다!
    - 추상화를 명확하게 해야 추상 자료형의 재사용이 용이하다.

인터페이스(inter face)란 무엇인지 살펴보자.

<img width="839" alt="image" src="https://user-images.githubusercontent.com/78291267/174013185-51a453f7-66e5-4f34-965a-31dced919efa.png">

어떤 두 가지 사이에서 중재를 해주는 느낌으로 이해하면 좋다. 인터페이스란 용어는 일반적으로 아주 다양한 의미로 사용된다. 여기서의 인터페이스는 "추상 자료형과 실제 구현의" 인터페이스이다. 

추상 자료형을 구현할 때는 "자료구조"를 이용한다. 어떤 자료구조/자료형을 사용할지 결정하기 위해선 **자료구조들이 가지는 특징들을 명확히 이해**하고 있어야 한다. 

