Hola profe, espero esté muy bien.

NAVEGACION

Mi idea es ayudarle a navegar por el menu de mi proyecto aunque siento que no lo complique mucho.

**********************************************************
*                                                        *      El sistema trabaja con un menu que usa un indice
*   Bienvenido al sistema de gestion electronico de la   *      que indica hacia que submenu/funcion
*                                                        *
*               Universidad Alberto Magno                *
*                                                        *
**********************************************************

Ingrese una opcion:
1.Universidad Alberto Magno
2.Estudiantes
3.Profesores
4.Cursos
0.Salir del sistema
1

**********************************************************      Segun lo que se pida se pueden acceder numeros
*          Opciones de gestion de estudiantes            *      o letras
*               Universidad Alberto Magno                *
**********************************************************

Ingrese una opcion:
1.Registrar un nuevo estudiante
2.Expulsar un estudiante
3.Matricular un curso
4.Desmatricular un curso
5.Mostrar la informacion de un estudiante
6.Mostrar el horario de un estudiante
7.Mostrar la nota de un estudiante
0.Salir de la opcion
1
Registrar un nuevo estudiante
Ingrese el nombre
a
Ingrese el numero de identificacion
1
a ha sido ingresdo exitosamente
1;a

**********************************************************      De todos los submenus y del propio sistema se
*         Opciones de gestion de la universidad          *      puede salir con 0
*               Universidad Alberto Magno                *
**********************************************************

Ingrese una opcion:
1.Mostrar todos los estudiantes
2.Mostrar todos los profesores
3.Mostrar todos los cursos
0.Salir de la opcion
0

INDICACIONES

Importe que al cerrar el sistema se haga con la opcion del menu
haciendo pruebas descubrí que si el programa se cierra con el boton
rojo cuadrado los cambios que se hacen en los archivos encargados
de guardar los datos no se actualizan con los nuevos:

SI: Process finished with exit code 0

NO: Process finished with exit code -1073741510 (0xC000013A: interrupted by Ctrl+C)

DECISIONES IMPORTANTES

-La persistencia de datos está implementada de la siguiente forma:
    El programa carga los datos de los archivos
    El programa añade, edita y borra los datos cargados
    El programa lee los datos cargados y reescribe los archivos

    Claramente esta manera de trabajar la memoria no es eficiente
    pero es lo que para esta ocasión me parecio mejor a la hora de
    trabajar la memoria.

-Ya que no se solicitaron metodos complejos no añadí nada muy loco
pero creo haber implementado lo básico.

-Hay codigo que tomé de la IA y adapté al codigo (especialmente
codigo para lo de los archivos).

-Intenté apegarme al principio de la responsabilidad única.

-Aunque el programa no es a prueba de tod o se procuró mantener
toda la proteccion contra errores a la hora de navegar.