![image](https://github.com/user-attachments/assets/8da4ef37-2bac-4b78-a9db-35e5f6b3528a)

### 주의사항 
- 표의 크기는 1024 * 1024 = 2^20 이고, 합을 구해야 하는 횟수가 100,000 이므로 1차원 배열과 같은 부분합 방식으로 합을 구하면 100,000 * 1024 = 102,400,000 이 되어 시간 제한에 위험
- 좌표 표시 방법이 (x, y) 으로 되어 있어 주의

### 풀이   

![image](https://github.com/user-attachments/assets/e7ef3394-f73a-4493-94aa-9e33fe9d4f20)   
- (1, 1) 에서 (x, y) 까지의 합을 담은 배열을 미리 구함
- 주어진 (x1, y1), (x2, y2) 사이의 부분합을 계산   
- 빨간색 영역 = 검은색 영역 ( 전체 영역 ) - 파란색 영역 - 초록색 영역 + 갈색 영역 ( 파란색, 초록색 교집합 )

