/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_stm32f0discovery
 * @{
 *
 * @file
 * @brief       Peripheral MCU configuration for the STM32F0discovery board
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef PERIPH_CONF_H_
#define PERIPH_CONF_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Clock system configuration
 * @{
 */
#define CLOCK_HSE           (8000000U)          /* external oscillator */
#define CLOCK_CORECLOCK     (48000000U)         /* desired core clock frequency */

/* the actual PLL values are automatically generated */
#define CLOCK_PLL_MUL       (CLOCK_CORECLOCK / CLOCK_HSE)
/** @} */

/**
 * @name Timer configuration
 * @{
 */
#define TIMER_NUMOF         (1U)
#define TIMER_0_EN          1
#define TIMER_IRQ_PRIO      1

/* Timer 0 configuration */
#define TIMER_0_DEV         TIM2
#define TIMER_0_CHANNELS    4
#define TIMER_0_FREQ        (CLOCK_CORECLOCK)
#define TIMER_0_MAX_VALUE   (0xffffffff)
#define TIMER_0_CLKEN()     (RCC->APB1ENR |= RCC_APB1ENR_TIM2EN)
#define TIMER_0_ISR         isr_tim2
#define TIMER_0_IRQ_CHAN    TIM2_IRQn
/** @} */

/**
 * @name UART configuration
 * @{
 */
#define UART_NUMOF          (2U)
#define UART_0_EN           1
#define UART_1_EN           1
#define UART_IRQ_PRIO       1

/* UART 0 device configuration */
#define UART_0_DEV          USART1
#define UART_0_CLKEN()      (RCC->APB2ENR |= RCC_APB2ENR_USART1EN)
#define UART_0_CLKDIS()     (RCC->APB2ENR &= (~RCC_APB2ENR_USART1EN))
#define UART_0_IRQ          USART1_IRQn
#define UART_0_ISR          isr_usart1
/* UART 0 pin configuration */
#define UART_0_PORT         GPIOB
#define UART_0_PORT_CLKEN() (RCC->AHBENR |= RCC_AHBENR_GPIOBEN)
#define UART_0_RX_PIN       7
#define UART_0_TX_PIN       6
#define UART_0_AF           0

/* UART 1 device configuration */
#define UART_1_DEV          USART2
#define UART_1_CLKEN()      (RCC->APB1ENR |= RCC_APB1ENR_USART2EN)
#define UART_1_CLKDIS()     (RCC->APB1ENR &= (~RCC_APB1ENR_USART2EN))
#define UART_1_IRQ          USART2_IRQn
#define UART_1_ISR          isr_usart2
/* UART 1 pin configuration */
#define UART_1_PORT         GPIOA
#define UART_1_PORT_CLKEN() (RCC->AHBENR |= RCC_AHBENR_GPIOAEN)
#define UART_1_RX_PIN       3
#define UART_1_TX_PIN       2
#define UART_1_AF           1
/** @} */

/**
 * @name ADC configuration
 * @{
 */
#define ADC_NUMOF           (1U)
#define ADC_0_EN            1
#define ADC_MAX_CHANNELS    6

/* ADC 0 configuration */
#define ADC_0_DEV           ADC1
#define ADC_0_CHANNELS      6
#define ADC_0_CLKEN()       (RCC->APB2ENR |= RCC_APB2ENR_ADCEN)
#define ADC_0_CLKDIS()      (RCC->APB2ENR &= ~(RCC_APB2ENR_ADCEN))
#define ADC_0_PORT          GPIOC
#define ADC_0_PORT_CLKEN()  (RCC->AHBENR |= RCC_AHBENR_GPIOCEN)
/* ADC 0 channel 0 pin config */
#define ADC_0_CH0           10
#define ADC_0_CH0_PIN       0
/* ADC 0 channel 1 pin config */
#define ADC_0_CH1           11
#define ADC_0_CH1_PIN       1
/* ADC 0 channel 2 pin config */
#define ADC_0_CH2           12
#define ADC_0_CH2_PIN       2
/* ADC 0 channel 3 pin config */
#define ADC_0_CH3           13
#define ADC_0_CH3_PIN       3
/* ADC 0 channel 4 pin config */
#define ADC_0_CH4           14
#define ADC_0_CH4_PIN       4
/* ADC 0 channel 5 pin config */
#define ADC_0_CH5           15
#define ADC_0_CH5_PIN       5
/** @} */

/**
 * @name SPI configuration
 * @{
 */
#define SPI_NUMOF           (2U)
#define SPI_0_EN            1
#define SPI_1_EN            1
#define SPI_IRQ_PRIO        1

/* SPI 0 device config */
#define SPI_0_DEV           SPI1
#define SPI_0_CLKEN()       (RCC->APB2ENR |= RCC_APB2ENR_SPI1EN)
#define SPI_0_CLKDIS()      (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN))
#define SPI_0_IRQ           SPI1_IRQn
#define SPI_0_ISR           isr_spi1
/* SPI 1 pin configuration */
#define SPI_0_PORT          GPIOA
#define SPI_0_PORT_CLKEN()  (RCC->AHBENR |= RCC_AHBENR_GPIOAEN)
#define SPI_0_PIN_SCK       5
#define SPI_0_PIN_MISO      6
#define SPI_0_PIN_MOSI      7
#define SPI_0_PIN_AF        0

/* SPI 1 device config */
#define SPI_1_DEV           SPI2
#define SPI_1_CLKEN()       (RCC->APB1ENR |= RCC_APB1ENR_SPI2EN)
#define SPI_1_CLKDIS()      (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
#define SPI_1_IRQ           SPI2_IRQn
#define SPI_1_ISR           isr_spi2
/* SPI 1 pin configuration */
#define SPI_1_PORT          GPIOB
#define SPI_1_PORT_CLKEN()  (RCC->AHBENR |= RCC_AHBENR_GPIOBEN)
#define SPI_1_PIN_SCK       13
#define SPI_1_PIN_MISO      14
#define SPI_1_PIN_MOSI      15
#define SPI_1_PIN_AF        0
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H_ */
