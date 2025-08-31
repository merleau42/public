# Cafe24 Mini Repository (Express + MySQL + File Uploads)

간단한 글쓰기 CRUD와 파일 업로드가 가능한 개인 자료실 백엔드 템플릿입니다.
Cafe24 Node.js 호스팅에 맞춰 엔트리 파일은 `web.js`, 기본 포트는 `8001`로 설정되어 있습니다.

## 빠른 시작 (로컬)

```bash
cp .env.example .env
# .env에 DB 정보/JWT_SECRET 설정
npm install
# MySQL에서 schema.sql 실행
npm run dev  # 또는 npm start
```

## 주요 엔드포인트

- `POST /api/auth/register`  (email, password) – 최초 1회 관리자 계정 생성
- `POST /api/auth/login` – JWT 토큰 발급
- `GET /api/posts` – 글 목록
- `GET /api/posts/:id` – 글과 첨부 조회
- `POST /api/posts` – 글 생성 (인증 필요)
- `PUT /api/posts/:id` – 글 수정 (작성자만)
- `DELETE /api/posts/:id` – 글 삭제 (작성자만)
- `POST /api/upload` – 파일 업로드 (multipart `file` 필드, 인증 필요, 선택적으로 `postId` 첨부)

업로드 파일은 `/uploads` 경로로 정적 서빙됩니다.

## Cafe24 배포 팁

- `web.js`를 엔트리로 사용하고, `PORT`는 Cafe24에서 부여한 포트를 사용하세요(보통 `8001`).
- Git 원격 저장소/SSH 키를 설정해 `git push`로 배포합니다.
- 배포 후 패키지 설치 버튼(또는 자동 설치)이 제공되는 경우 `npm install`이 원격에서 수행됩니다.
- 데이터(업로드 파일)는 레포지토리와 별개로 유지되지만, 재배포 정책에 따라 덮어쓰기 위험이 있으니 주기적 백업 또는 S3 같은 외부 스토리지를 고려하세요.
