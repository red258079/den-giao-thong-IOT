# den-giao-thong-IOT

Triển Khai trên môi trường Docker
1. Đảm bảo bạn đã cài đặt [Docker Desktop](https://www.docker.com/products/docker-desktop) (phiên bản 18 trở lên).
2. Mở tệp Openremote trong đấy chứa file docker-compose.yml copy 
3. Mở terminal và chuyển đến thư mục chứa tệp vừa tải bằng lệnh `cd`, sau đó chạy:

   ```bash
   docker compose pull
   docker compose -p openremote up
