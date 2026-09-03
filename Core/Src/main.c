#include "main.h"

int main(void)
{
	HAL_Init();
  /* Enable GPIOA clock here */
  RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOAEN);
  /* Enable GPIOC clock here */
  RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOCEN);

  /* Clear PC0, PC1, PC2 mode bits */
  GPIOC->MODER &= ~(
  (3 << 0) |
  (3 << 2) |
  (3 << 4)
  );

  /* Clear PC0, PC1, PC2 ODR bits */
  GPIOC->ODR &= ~(
  (1 << 0) |
  (1 << 1) |
  (1 << 2)
  );

  /* Set PC0, PC1, PC2 to general-purpose output mode: 01 */
  GPIOC->MODER |= (
  (1 << 0) |
  (1 << 2) |
  (1 << 4)
  );

  /* Configure PA4 as input */
  GPIOA->MODER &= ~(3 << 8);

  /* Configure PA4 with pull-up */
  GPIOA->PUPDR &= ~(3 << 8);
  GPIOA->PUPDR |= (1 << 8);

  uint8_t count = 0;
  while(1)
  {
    if(!(GPIOA->IDR & (1<<4)))
    {
      /*
      Clear PC0, PC1, PC2 ODR bits
      GPIOC->ODR &= ~(
      (1 << 0) |
      (1 << 1) |
      (1 << 2)
      );
      GPIOC->ODR |= (count & 0x07)
      */
      switch(count) 
      {
        case 1:
          GPIOC->ODR &= ~(1 << 2);
          GPIOC->ODR &= ~(1 << 1);
          GPIOC->ODR |= (1 << 0);
          break;
        case 2:
          GPIOC->ODR &= ~(1 << 2);
          GPIOC->ODR |= (1 << 1);
          GPIOC->ODR &= ~(1 << 0);
          break;
        case 3:
          GPIOC->ODR &= ~(1 << 2);
          GPIOC->ODR |= (1 << 1);
          GPIOC->ODR |= (1 << 0);
          break;
        case 4:
          GPIOC->ODR |= (1 << 2);
          GPIOC->ODR &= ~(1 << 1);
          GPIOC->ODR &= ~(1 << 0);
          break;
        case 5:
          GPIOC->ODR |= (1 << 2);
          GPIOC->ODR &= ~(1 << 1);
          GPIOC->ODR |= (1 << 0);
          break;
        case 6:
          GPIOC->ODR |= (1 << 2);
          GPIOC->ODR |= (1 << 1);
          GPIOC->ODR &= ~(1 << 0);
          break;
        case 7:
          GPIOC->ODR |= (1 << 2);
          GPIOC->ODR |= (1 << 1);
          GPIOC->ODR |= (1 << 0);
          break;
        default: //0
          GPIOC->ODR &= ~(1 << 2);
          GPIOC->ODR &= ~(1 << 1);
          GPIOC->ODR &= ~(1 << 0);

      }
    }
    else
    {

    }

    count++;

    HAL_Delay(200);

    if(count>7)
    {
      count = 0;
    }
  }
  //WHile forever
    //start variable at 0
    //if button is pressed
      //display the current number in binary -> a bunch of case statements for 0 -> 7
    //else
      //do nothing
    //count to 7
    //if count>7 set count to 0
    //add a 200 ms HAL delay
  //end while loop
}

