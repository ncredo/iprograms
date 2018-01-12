/*
 * operations.h
 *
 *  Created on: Dec 22, 2017
 *      Author: NDUHURA
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_



#endif /* OPERATIONS_H_ */

//fonction qui permet de signaler une alerte en cas de tangage superirieur a 45 degrees
void tangage (int16_t *xAngle, int16_t *xAngleDutyCycle, int16_t *yAngleDutyCycle);

//fonction qui permet de signaler une alerte en cas de roulis superieur a 45 degrees
void roulis (int16_t *yAngle, int16_t *xAngleDutyCycle, int16_t *yAngleDutyCycle);

//fonction qui permet de signaler une inclinaison x degrees (tangage) et y degrees (roulis) par rapport aux deux axes (tangage et roulis) en detectant le tangage en premier
void tangageRoulis1 (int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle, int16_t *yAngleDutyCycle);

//fonction qui permet de signaler le tangage a x degrees par rapport a l'axe de tangage
void tangageRoulis2 (int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle, int16_t *yAngleDutyCycle);

//fonction qui permet de signale une inclinaison x degrees (tangage) et y degrees (roulis) par rapport aux deux axes (roulis et tangage) en detectant le roulis en premier
void roulisTangage1 (int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle, int16_t *yAngleDutyCycle);

//fonction qui permet de signaler le roulis a y degrees par rapport a l'axe de roulis
void roulisTangage2 (int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle, int16_t *yAngleDutyCycle);

//fonction qui permet de signaler si on est bien aligner sur les deux axes (roulis et tangage)
void bienAligner (int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle, int16_t *yAngleDutyCycle);
