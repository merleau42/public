#!/usr/bin/env python3
# 파일명: day3-cv2-camera-photo-button-led.py (폴링 감지용 안정화 버전)
# 설명: 인터럽트(엣지 감지)를 사용하지 않고, 10~20ms 주기의 폴링으로 버튼 눌림을 감지합니다.
# 엣지 감지 실패(RuntimeError) 환경에서도 안정적으로 동작합니다.
# 권장 배선(BCM 번호):
# - LED: GPIO17 -> 저항 -> LED -> GND
# - 버튼: GPIO23 -> GND (내부 풀업 사용, 눌렀을 때 LOW)
# 필요 패키지:
# sudo apt-get install python3-opencv
# pip install opencv-python
# (RPi.GPIO는 라즈베리파이 OS에 기본 포함)

import cv2
import time
import RPi.GPIO as GPIO

# ==============================================================================
# 설정
# ==============================================================================
LED_PIN = 17
BUTTON_PIN = 23
POLL_INTERVAL = 0.02 # 20ms 주기

# 카메라 해상도
CAM_WIDTH = 640
CAM_HEIGHT = 480

# 플래시(LED) 빠르게 깜빡이는 횟수/간격
FLASH_TIMES = 3
FLASH_ON_SEC = 0.05
FLASH_OFF_SEC = 0.05

# 촬영 시 프레임을 추가로 한 번 더 읽을지 여부(타이밍 안정화용)
READ_EXTRA_FRAME = True

# ==============================================================================
# 함수 정의
# ==============================================================================
def now_filename(prefix="photo"):
	return time.strftime(f"{prefix}_%Y%m%d_%H%M%S.jpg")

def flash_led(times):
	for _ in range(times):
		GPIO.output(LED_PIN, GPIO.HIGH)
		time.sleep(FLASH_ON_SEC)
		GPIO.output(LED_PIN, GPIO.LOW)
		time.sleep(FLASH_OFF_SEC)

def main():
	# GPIO 초기화
	GPIO.setwarnings(False)
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(LED_PIN, GPIO.OUT, initial=GPIO.LOW)
	GPIO.setup(BUTTON_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP) # 내부 풀업: 눌림 시 LOW

	# 카메라 초기화
	cap = cv2.VideoCapture(0)
	if not cap.isOpened():
		print("카메라를 열 수 없습니다. (VideoCapture(0) 실패)")
		GPIO.cleanup()
		return
	cap.set(cv2.CAP_PROP_FRAME_WIDTH, CAM_WIDTH)
	cap.set(cv2.CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT)

	last_saved = ""
	last_state = GPIO.input(BUTTON_PIN) # HIGH(기본)로 시작

	try:
		while True:
			ret, frame = cap.read()
			if not ret:
				print("프레임을 읽을 수 없습니다.")
				break

			# 프레임이 정상적으로 읽혔으면, 버튼 상태를 폴링하여 눌림 감지
			# 버튼 눌림: HIGH -> LOW 전이(눌림) 감지
			current = GPIO.input(BUTTON_PIN)
			if last_state == GPIO.HIGH and current == GPIO.LOW:
				# 플래시 -> 촬영 -> 저장
				flash_led(FLASH_TIMES)
				if READ_EXTRA_FRAME: # 타이밍 이슈로 인해 한 프레임을 더 읽음
					ok, shot = cap.read()
					if not ok:
						shot = frame.copy()
				filename = now_filename("photo")
				cv2.imwrite(filename, shot)
				print(f"[{filename}] 저장됨")
				last_saved = filename
				# 간단 디바운스(누르고 있는 동안 중복 트리거 방지)
				time.sleep(0.1)
			last_state = current

			# 화면 안내
			info1 = "Press BUTTON to shoot (Polling mode)"
			info2 = f"Saved: {last_saved}" if last_saved else "Ready..."
			cv2.putText(frame, info1, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
			cv2.putText(frame, info2, (10, CAM_HEIGHT - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
			cv2.imshow("Camera", frame)

			# ESC 종료
			key = cv2.waitKey(1) & 0xFF
			if key == 27:
				break

			time.sleep(POLL_INTERVAL)

	except KeyboardInterrupt:
		print("KeyboardInterrupt: 사용자에 의해 종료")
	finally:
		cap.release()
		cv2.destroyAllWindows()
		GPIO.cleanup()

if __name__ == "__main__":
	main()
