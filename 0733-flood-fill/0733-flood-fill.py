class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if color == image[sr][sc]:
            return image
        m, n = len(image), len(image[0])
        q = deque([(sr, sc)])
        oldColor = image[sr][sc]
        image[sr][sc] = color
        while q:
            cur_x, cur_y = q.popleft()
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                new_x = cur_x + dx
                new_y = cur_y + dy
                if new_x < 0 or new_x >= m or new_y < 0 or new_y >= n:
                    continue
                if image[new_x][new_y] == oldColor:
                    image[new_x][new_y] = color
                    q.append((new_x, new_y))
        return image