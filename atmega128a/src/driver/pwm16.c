#include "pwm16.h"

void pwm16Init()
{
   DDRE |= (1<<PORTE3);     // oc3a past pwm ouput 
   DDRE |= (1 << PORTE5);  // OC3C 핀(PORTE5)을 PWM 출력으로 설정

   //PORTE의 3번핀
   // 64분주, past pwm, 비반전 모드
   TCCR3A |= (1<<COM3A1) | (1<<WGM31);
   TCCR3A |= (1 << COM3C1);                 // OC3C 비반전 모드
   TCCR3B |= (1<<WGM33) | (1<<WGM32) | (1<<CS31) | (1<<CS30);

   ICR3 = 4999;    // icr은 꼭대기 값
} 
//usart 통신할때 싱크로너스 동기 통신
//uarto 비동기 통신 전이중방식 전화기
//isp 프로그램 업로드
//lsb부터 보냄