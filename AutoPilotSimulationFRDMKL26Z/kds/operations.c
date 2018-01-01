/*
 * operations.c
 *
 *  Created on: Dec 22, 2017
 *      Author: NDUHURA
 */

#define bool	_Bool
#define true	1
#define false	0

#include "board.h"
#include "fsl_tpm_driver.h"
#include "fsl_debug_console.h"
#include "accel.h"
#include "gpio_pins.h"

//chemin vers le fichier qui contient les declarations des fonctions de l'utilisateurs
#include "C:\Freescale\KSDK_1.3.0\examples\frdmkl26z\demo_apps\bubble_level_tpm\kds\operations.h"

volatile bool isButtonPress = false;

/*variable d'aide a l'initialisation, elle permet d'avoir le comportement voulue au lancement du programme,
 avant de depasser 45 degree*/
bool etatInit = true;

//fonction que detecter si l'angle de tangage depasse 45 degrees
void tangage(int16_t *xAngle, int16_t *xAngleDutyCycle,
		int16_t *yAngleDutyCycle) {

	//on desactive le mode initial pour pouvoir permettre au boutton de prendre le relais
	etatInit = false;

	//on teste si le boutton est appuie pour etteindre la LED verte et sinon on laisse la LED verte allumer
	if (isButtonPress) {
		*xAngleDutyCycle = 0;
		*yAngleDutyCycle = 0;
		LED1_OFF;
		isButtonPress = false;
	} else {
		*xAngleDutyCycle = 0;
		*yAngleDutyCycle = 0;
		LED1_ON;
		if (*xAngle > 0) {
			//on fait l'affichage de message a la console
			PRINTF("Alerte tangage : plus de 45, nez bas a %d degres\r\n",
					*xAngle);
		} else {
			//on fait l'affichage de message a la console
			PRINTF("Alerte tangage : plus de 45, nez haut a %d degres\r\n",
					abs(*xAngle));
		}
	}
}

void roulis(int16_t *yAngle, int16_t *xAngleDutyCycle, int16_t *yAngleDutyCycle) {

	//on desactive le mode initial pour pouvoir permettre au boutton de prendre le relais
	etatInit = false;

	//on teste si le boutton est appuie pour etteindre la LED verte et sinon on laisse la LED verte allumer
	if (isButtonPress) {
		*xAngleDutyCycle = 0;
		*yAngleDutyCycle = 0;
		LED1_OFF;
		isButtonPress = false;
	} else {
		*xAngleDutyCycle = 0;
		*yAngleDutyCycle = 0;
		LED1_ON;
		if (*yAngle > 0) {
			//on fait l'affichage de message a la console
			PRINTF(
					"Alerte roulis : plus de 45, inclinaison a gauche %d degres\r\n",
					*yAngle);
		} else {
			//on fait l'affichage de message a la console
			PRINTF(
					"Alerte roulis : plus de 45, inclinaison a droite %d degres\r\n",
					abs(*yAngle));
		}
	}
}

void tangageRoulis1(int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle,
		int16_t *yAngleDutyCycle) {
	//on teste si le boutton est appuie pour etteindre la LED verte et sinon on laisse la LED verte allumer
	if (isButtonPress || etatInit) {
		//on affecte une valeur de 100 au variable qui gere le rapport cyclique pour allumer les LEDs rouge et bleu
		*xAngleDutyCycle = 100;
		*yAngleDutyCycle = 100;
		LED1_OFF;

		//on fait l'affichage de message a la console
		if (*yAngle >= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre B\r\n", *yAngle,
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre B\r\n", abs(*yAngle),
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre H\r\n", abs(*yAngle),
					abs(*xAngle));
		}
		//on fait l'affiche de message a la console
		else if (*yAngle >= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre H\r\n", *yAngle,
					abs(*xAngle));
		}
	} else {
		//on affecte une valeur de 0 au variable qui gere le rapport cyclique pour eteindre les LEDs rouge et bleu
		*xAngleDutyCycle = 0;
		*yAngleDutyCycle = 0;
		LED1_ON;
		//on fait l'affichage de message a la console
		if (*yAngle >= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre B\r\n", *yAngle,
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre B\r\n", abs(*yAngle),
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre H\r\n", abs(*yAngle),
					abs(*xAngle));
		}
		//on fait l'affichage de message a la console
		else if (*yAngle >= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre H\r\n", *yAngle,
					abs(*xAngle));
		}
	}
}

void tangageRoulis2(int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle,
		int16_t *yAngleDutyCycle) {
	//on teste si le boutton est appuie pour etteindre la LED verte et sinon on laisse la LED verte allumer
	if (isButtonPress || etatInit) {
		*xAngleDutyCycle = 100;
		*yAngleDutyCycle = 0;
		LED1_OFF;
		//on fait l'affichage de message a la console
		if (*yAngle >= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre B\r\n", *yAngle,
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre B\r\n", abs(*yAngle),
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre H\r\n", abs(*yAngle),
					abs(*xAngle));
		}
		//on fait l'affichage de message a la console
		else if (*yAngle >= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre H\r\n", *yAngle,
					abs(*xAngle));
		}
	} else {
		*xAngleDutyCycle = 0;
		*yAngleDutyCycle = 0;
		LED1_ON;
		//on fait l'affichage de message a la console
		if (*yAngle >= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre B\r\n", *yAngle,
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre B\r\n", abs(*yAngle),
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre H\r\n", abs(*yAngle),
					abs(*xAngle));
		}
		//on fait l'affichage de message a la console
		else if (*yAngle >= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre H\r\n", *yAngle,
					abs(*xAngle));
		}
	}
}

void roulisTangage1(int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle,
		int16_t *yAngleDutyCycle) {
	if (isButtonPress || etatInit) {
		*yAngleDutyCycle = 100;
		*xAngleDutyCycle = 100;
		LED1_OFF;
		//on fait l'affichage de message a la console
		if (*yAngle >= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre B\r\n", *yAngle,
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre B\r\n", abs(*yAngle),
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre H\r\n", abs(*yAngle),
					abs(*xAngle));
		}
		//on fait l'affichage de message a la console
		else if (*yAngle >= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre H\r\n", *yAngle,
					abs(*xAngle));
		}
	} else {
		//on affecte une valeur de 0 au variable qui gere le rapport cyclique pour eteindre les LEDs rouge et bleu
		*xAngleDutyCycle = 0;
		*yAngleDutyCycle = 0;
		LED1_ON;
		//on fait l'affichage de message a la console
		if (*yAngle >= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre B\r\n", *yAngle,
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre B\r\n", abs(*yAngle),
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre H\r\n", abs(*yAngle),
					abs(*xAngle));
		}
		//on fait l'affichage de message a la console
		else if (*yAngle >= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre H\r\n", *yAngle,
					abs(*xAngle));
		}
	}
}

void roulisTangage2(int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle,
		int16_t *yAngleDutyCycle) {
	if (isButtonPress || etatInit) {
		*yAngleDutyCycle = 100;
		*xAngleDutyCycle = 0;
		LED1_OFF;
		//on fait l'affichage de message a la console
		if (*yAngle >= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre B\r\n", *yAngle,
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre B\r\n", abs(*yAngle),
					*xAngle);
		}
		//on fait l'affiche de message a la console
		else if (*yAngle <= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre H\r\n", abs(*yAngle),
					abs(*xAngle));
		}
		//on fait l'affichage de message a la console
		else if (*yAngle >= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre H\r\n", *yAngle,
					abs(*xAngle));
		}
	} else {
		*xAngleDutyCycle = 0;
		*yAngleDutyCycle = 0;
		LED1_ON;
		//on fait l'affichage de message a la console
		if (*yAngle >= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre B\r\n", *yAngle,
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle >= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre B\r\n", abs(*yAngle),
					*xAngle);
		}
		//on fait l'affichage de message a la console
		else if (*yAngle <= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre D Tangage %d degre H\r\n", abs(*yAngle),
					abs(*xAngle));
		}
		//on fait l'affichage de message a la console
		else if (*yAngle >= 0 && *xAngle <= 0) {
			PRINTF("Roulis %d degre G Tangage %d degre H\r\n", *yAngle,
					abs(*xAngle));
		}
	}
}

void bienAligner(int16_t *yAngle, int16_t *xAngle, int16_t *xAngleDutyCycle,
		int16_t *yAngleDutyCycle) {

	//on teste si l'angle de roulis et l'angle de tangage est inferieur a 5 degree et on allume la lumiere blanche
	if (isButtonPress || etatInit) {
		*xAngleDutyCycle = 100;
		*yAngleDutyCycle = 100;
		LED1_ON;
		//on fait l'affiche de message a la console
		PRINTF("Avion parfaitement aligne sur les deux axes\r\n");
	} else {
		*xAngleDutyCycle = 0;
		*yAngleDutyCycle = 0;
		LED1_ON;
		//on fait l'affiche de message a la console
		PRINTF("Avion parfaitement aligne sur les deux axes\r\n");
	}
}

