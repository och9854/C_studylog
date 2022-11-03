# 17-07. 인터페이스 적용 사례
---

앞 강의에서는 추상자료형의 기본적인 개념과 이론적인 측면에서 살펴보았다. 이번 강의에서는 예제를 통해 인터페이스를 적용하는 과정을 살펴보면서 앞에서 배운 개념들이 어떻게 활용되는지 이해해보자.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/174013655-c796da74-dfbc-4bac-99bd-846a031634f6.png">

비슷한 코드를 짜다보면 어떻게 하면 이전에 짜둔 코드들을 대부분을 이용해 짤 수 있을까란 생각을 하게 될 것이다. 

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/174014214-1fc0ae6d-c108-4633-b2a2-bbf83ff3dd49.png">

몇줄만 바꿔도 새로운 프로그램을 작성하게 해주는 것이 자료구조를 공부하는 중요한 이유이다. 그러면, 가장 먼저 데이터(자료)와 자료 구조를 분리하는 것이다. 

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/174018215-d194059a-9154-424b-a320-9d51ade38d77.png">

C언어에서는 주로 struct를 통해 정의한다. 왼쪽 박스에서 볼 수 있듯이, 영화에 대한 정보를 담는 구조체를 하나 생성하고, typedef를 통해 movie Item으로 정의한다. 추후에 이들만 바꿔주면 쉽게 코드를 재사용할 수 있다. 또한, 함수들도 일반화할 수 있다. 이들은 포인터 연산을 통해 구현된다. 

또한, node 연산에 대해서도 따로 정의를 해줄 수 있다. 여기서 체크할 점은 **Item이 무엇이 들어오든지 상관없는 형태로 코드가 짜여있다**라는 것이다. 

코드 재사용 측면에서도 이를 살펴보자.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/174090883-322d103b-cd37-41fb-a553-a6a8e01ea1ca.png">

다음과 같이 노드들을 삭제하는 일반화된 코드를 따로 쩍어두면 오른쪽과 같이 간단히 한줄로 이를 구현할 수 있게 된다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/174091249-244b49b0-b966-4b0c-b52a-bd654581067f.png">

## 실습

앞서 만들어둔 영화 리스트 저장 코드를 추상화해보자.

"SimpleList.h"에 인터페이스가 들어가고, "SimpleList.c"에 실제 구현된 함수가 들어간다. "main.c"에서는 가져다 쓸 것이다.

