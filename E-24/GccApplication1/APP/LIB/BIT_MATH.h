/*
 * BIT_MATH.h
 *
 * Created: 03/12/2021 03:14:15 م
 *  Author: dell
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)   (reg |= (1<<bit))
#define CLR_BIT(reg,bit)   (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(REG,BIT)   ((REG >> BIT)&1)



#endif /* BIT_MATH_H_ */