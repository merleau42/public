
#include	"mlx.h"
#include	"mlx_int.h"

void *mlx;
void *win1, *win2, *win3;
void *img1, *img2, *img3, *img4;

int	bpp1, bpp2,	bpp3, bpp4;
int	sl1, sl2, sl3, sl4;
int	endian1, endian2, endian3, endian4;
char *data1, *data2, *data3, *data4;
int	xpm1_x,	xpm1_y;

int	local_endian;

int	color_map_1(void *win,int w,int h);
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

int	expose_win1(void *p){ mlx_put_image_to_window(mlx,win1,img3,0,0); }
int	expose_win2(void *p){ mlx_put_image_to_window(mlx,win2,img4,0,0); mlx_put_image_to_window(mlx,win2,img2,0,0); }

int	key_win1(int key,void *p){ printf("Key in Win1 : %d\n",key); if (key==0xFF1B) exit(0); }
int	key_win2(int key,void *p){ printf("Key in Win2 : %d\n",key); if (key==0xFF1B) exit(0); }
int	key_win3(int key,void *p){ printf("Key in Win3 : %d\n",key); if (key==0xFF1B) mlx_destroy_window(mlx,win3); }

int	mouse_win1(int button,int x,int y, void *p){ printf("Mouse in Win1, button %d at %dx%d.\n",button,x,y); }
int	mouse_win2(int button,int x,int y, void *p){ printf("Mouse in Win2, button %d at %dx%d.\n",button,x,y); }
int	mouse_win3(int x,int y, void *p){ printf("Mouse moving in Win3, at %dx%d.\n",x,y); }

void message(int wait, char *msg){ printf("%s", msg); sleep(wait);  }

int	main()
{
	//:	변동 사항 적용 방법 → 테스트 폴더에서 실행:   make -C ../; clear; ./mlx-test

	message(1, "#### 엔디안 유형 확인");
		int	a = 0x11223344;	
		local_endian = (&a)[0] == 0x11;		//> 4바이트 자료형의 첫번째 바이트를 읽어들였을때, 0x11이냐 0x44이냐를 확인함
		printf("\n     결과: %d\n", local_endian);

	message(1, "\n#### mlx 초기화");
		mlx = mlx_init();
		printf(" ㅡ use_xshm %d, pshm_format %d\n", 
					((t_xvar *)mlx)->use_xshm,
					((t_xvar *)mlx)->pshm_format);

	message(3, "\n#### 첫번째 창 생성");
		win1 = mlx_new_window(mlx, 300, 300, "FIRST");

	message(1, "\n     첫번째 창 칠하기");
		color_map_1(win1, 250, 250);

	message(1, "\n     첫번째 창 비우기");
		mlx_clear_window(mlx, win1);

	message(3, "\n\n#### 이미지 객체1 생성");
		img1 = mlx_new_image(mlx, 42, 42);
		data1 = mlx_get_data_addr(img1,&bpp1,&sl1,&endian1);
		printf(" ㅡ bpp1: %d, sizeline1: %d, endian: %d, type: %d",
						  bpp1,			 sl1,		 endian1,  ((t_img *)img1)->type);

	message(1, "\n     이미지 객체1 채우기");
		color_map_2(data1,bpp1,sl1,42,42,endian1, 1);
		printf("  //  pixmap : %d",
					(int)((t_img *)img1)->pix);

	message(1, "\n     이미지 객체1 화면에 뿌리기");
		mlx_put_image_to_window(mlx,win1,img1,20,20);

	message(1, "\n     이미지 객체1 삭제 (뿌려진 픽셀은 그대로 남고, 가상의 이미지 객체만 삭제됨)");
		mlx_destroy_image(mlx, img1);

	message(3, "\n\n#### 이미지 객체3 생성");
		img3 = mlx_new_image(mlx,242,242);
		data3 = mlx_get_data_addr(img3,&bpp3,&sl3,&endian3);
		printf(" ㅡ bpp3: %d, sizeline3: %d, endian3: %d, type: %d",
						  bpp3,			 sl3,		  endian3,	((t_img *)img3)->type);

	message(1, "\n     이미지 객체3 채우기");
		color_map_2(data3,bpp3,sl3,242,242,endian3, 1);
		printf("  //  pixmap : %d",(int)((t_img *)img3)->pix);

	message(1, "\n     이미지 객체3 화면에 뿌리기");
		mlx_put_image_to_window(mlx,win1,img3,20,20);
	
	message(2, "\n\n#### 화면에 문자열 그리기");
		mlx_string_put(mlx,win1,5,242/2,0xFF99FF,"String output");
		mlx_string_put(mlx,win1,15,242/2+20,0x00FFFF,"MinilibX test");

	message(2, "\n\n#### 이미지 객체2 생성( xpm 파일 사용 )");
		img2 = mlx_xpm_file_to_image(mlx, "open.xpm", &xpm1_x, &xpm1_y);
		data2 = mlx_get_data_addr(img2,&bpp2,&sl2,&endian2);
		printf(" ㅡ xpm %dx%d  //  bpp2: %d, sizeline2: %d, endian2: %d, type: %d",
					xpm1_x, xpm1_y,		 bpp2,			sl2,		 endian2,  ((t_img *)img2)->type);

	message(1, "\n     이미지 객체2 뿌리기");
		mlx_put_image_to_window(mlx,win1,img2,0,0);
		mlx_put_image_to_window(mlx,win1,img2,100,100);

	message(2, "\n\n#### 두번째 창 생성");
		win2 = mlx_new_window(mlx,242,242,"SECOND");
		img4 = mlx_new_image(mlx,242, 242);
		data4 = mlx_get_data_addr(img4,&bpp4,&sl4,&endian4);
		color_map_2(data4,bpp4,sl4,242,242,endian4, 2);

	message(2, "\n\n#### 세번째 창 생성");
		win3 = mlx_new_window(mlx,242,242,"THIRD");

	message(0, "\n\n#### 입력 감지 시작");
		mlx_expose_hook(win1,expose_win1,0);
		mlx_mouse_hook(win1,mouse_win1,0);
		mlx_key_hook(win1,key_win1,0);

		mlx_expose_hook(win2,expose_win2,0);
		mlx_mouse_hook(win2,mouse_win2,0);
		mlx_key_hook(win2,key_win2,0);

		mlx_hook(win3, MotionNotify, PointerMotionMask, mouse_win3, 0);
		mlx_key_hook(win3,key_win3,0);

	message(2, "\n\n#### 루프에 진입. Esc in 3 to destroy, 1&2 to quit.");
		mlx_loop(mlx);
	
	message(1, "\n     감지 내역:");
}

int	color_map_1(void *win,int w,int h)
{
	int	x, y;
	int	color, red, green, blue;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)		//:	(w,h) ~~ (0,0) 구간에서, 현재 좌표 (x,y)를 확보. 
		{				//:	└─> 손에 들고있는, 확보된 상태를 이용해서 원하는 행동을 할 수 있다

///			현재 좌표의 정보가, 현재 좌표에 찍어줄 점의 색상을 결정함
			red		=	0xFF * (w-x)/w;			//>  전체 가로 너비에서 x의 위치가 해당하는 비율 반전			x 255
			green	=	0xFF * y/h;				//>  전체 세로 높이에서 y의 위치가 해당하는 비율 (0% ~ 100%)	x 255
			blue	=	0xFF * x/w;				//>  전체 가로 너비에서 x의 위치가 해당하는 비율 (0% ~ 100%)	x 255
												//<  곱셈보다 나눗셈이 먼저 행해진다면 0이 되어버림 (괄호 주의)
//!					FF0000
			color = (red << 16) + (green << 8) + blue; /// 0000FF
//>									00FF00

			mlx_pixel_put(mlx, win, x, y, color);
		}
	}
}

int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type)
{
	int	x, y;
	int	opp;
	int	dec;
	int	color;
	int	color2;
	unsigned char *ptr;

	opp = bpp/8;
	printf(" ㅡ opp : %d ",opp);
	y = h;
	while (y--)
	{
		ptr = data+y*sl;
		x = w;
		while (x--)
		{
			if (type==2)
				color = (y*255)/w + ((((w-x)*255)/w)<<16) + (((y*255)/h)<<8);
			else
				color = (x*255)/w + ((((w-x)*255)/w)<<16) + (((y*255)/h)<<8);
			color2 = mlx_get_color_value(mlx,color);
			dec = opp;
			while (dec--)
				if (endian==local_endian)
				{
					if (endian)
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[4-opp+dec];
					else
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[dec];
				}
				else
				{
					if (endian)
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[opp-1-dec];
					else
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[3-dec];
				}
		}
	}
}
