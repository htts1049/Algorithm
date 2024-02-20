[[SWEA-18799] 평균의 평균](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&problemLevel=4&contestProbId=AYqmDqj6Uu8DFAQI&categoryId=AYqmDqj6Uu8DFAQI&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=1)


### 어려웠던 점
- float을 사용하면 문제가 요구하는 오차 범위 10^(-9) 이하 조건을 지킬 수 없다.
- 백트래킹 과정에서 부분 집합에 속하는 숫자를 path에 담아두었는데, 공집합을 의미하는 0 크기의 path에서는 평균을 구할 때 devision error가 난다.
- 평균을 구할 때 path.size() 가 아니라 n을 사용하여 오답이 났다.

### 배운 점
- cout.precision(x) 를 사용하면 소수점 x자리까지 출력할 수 있다.
