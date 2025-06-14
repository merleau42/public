// sw.js - 기본 캐싱용 (옵션)
self.addEventListener('install', event => {
  console.log('✅ Service Worker: Installed');
});

self.addEventListener('activate', event => {
  console.log('✅ Service Worker: Activated');
});

self.addEventListener('fetch', event => {
  // 현재는 기본 fetch 처리만
});
