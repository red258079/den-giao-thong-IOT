# den-giao-thong-IOT

Triển Khai trên môi trường Docker
1. Đảm bảo bạn đã cài đặt [Docker Desktop](https://www.docker.com/products/docker-desktop) (phiên bản 18 trở lên).
2. Mở tệp Openremote trong đấy chứa file docker-compose.yml copy vào VS code và đặt tên file là docker-compose.yml và lưa lại
3. Mở CMD và CD vào tệp bạn tạo trên máy vd: cd openremote ==> Enter xuống 
4. Nhập những dòng dưới vào CMD hãy chắc chắn cmd bạn đang cd vào ổ đĩa chứa thư mục mà bạn đang dùng để lưa file docker-compose.yml

   ```bash
   docker compose up -d

---

👉 Nếu nó lỗi thì hãy 
   ```bash
   docker compose down
---
và làm lại từ đầu
```bash
   docker compose up -d
---


   
