from qiskit import *
from qiskit.tools.monitor import job_monitor
import serial


#IBMQ.save_account('your token here')

arduino = serial.Serial(port='COM19', baudrate=115200, timeout=.1)

qr=QuantumRegister(5)
cr=ClassicalRegister(5)
circuit=QuantumCircuit(qr,cr)

circuit.h(qr[0])
circuit.h(qr[2])
circuit.h(qr[3])
circuit.h(qr[4])

circuit.cx(qr[0],qr[1])

circuit.measure(qr,cr)

IBMQ.load_account()
provider = IBMQ.get_provider('ibm-q')
qcomp = provider.get_backend('ibmq_lima')

job = execute(circuit,backend=qcomp,shots=1, memory=True)
job_monitor(job)
result=job.result()

bin=result.get_memory()[0]

print(bin)
dec=int(bin, base=2)

decc=str(dec)
arduino.write(bytes(decc, 'utf-8'))