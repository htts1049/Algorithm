![image](https://github.com/user-attachments/assets/d8201af3-1c44-48b7-8604-1212ea1d7d2a)

### 주의사항 
- 수열 출력 순서가 사전 순이므로, for 문에서 시작 index 값에 주의

### 풀이
- 현재 노드에서 다음 노드로 넘어갈 때, for 문의 시작 index 값을 현재 노드 값으로 넣음
- 그러면 for 문이 현재 노드부터 접근하기 때문에, 경로 중 현재 노드보다 값이 작은 노드는 방문하지 않아 사전 순으로 출력
- 현재 노드는 다음 노드로 진행하기 전에 방문처리 되었으니, 다음 노드에서 현재 노드는 미방문 노드 검사 조건에서 걸러짐