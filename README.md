# Tmonitor_VacunatePE
Monitor de Temperatura con resolucion de 0.25°C, desde -55°C a 150°C. 
Envia data cada segundo, incluye salida para alarmas de advertencia y alarma de riesgo de perdida total del cargamento en cadena de frio de 2°C a 8°C.

Condiciones de alarma:

    -Advertencia:
    Temperatura medida entre 2°C - 3°C y entre 7°C - 8°C
    Alerta de perdida:
    Temperatura menor a 2°C o mayor a 8°C

    -Salidas de Alerta:
    Actuador luminoso en la cabina del chofer del vehiculo frigorífico
    Actuador sonoro en la cabina del chofer del vehiculo frigorífico

Log de data:
El hardware envia los datos con bluetooth a un app en el celular del conductor.
Combinamos la data con la fecha y hora, las coordenadas GPS para enviarla a la plataforma web.
El hardware puede incluir una memoria SD como respaldo de la data.



