![image](https://github.com/user-attachments/assets/0ff65a5d-0aec-4604-b98d-f356cbafb118)

### 주의사항 
- 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하므로, 노드에 연결된 다른 노드의 번호를 오름차순으로 정렬할 필요가 있음
   - vector 정렬 시, sort(v.begin(), v.end()) 로 사용
- DFS 에서, depth 에 주의
- BFS 에서, queue 가 비어있는지 확인하는 조건은 !q.empty() 임
- 예제 입력 3번은 다른 노드와 연결되지 않은 노드가 존재하는 경우인데, DFS 를 모든 정점이 추가됐을 때 result 를 출력하고 종료하도록 구현하면 해당 경우를 놓침

### 풀이
- 기본적인 DFS, BFS 문제이며 시간복잡도를 크게 고려할 사항도 없음
- 예제 입력 3번과 같은 케이스는 주의할 사항임