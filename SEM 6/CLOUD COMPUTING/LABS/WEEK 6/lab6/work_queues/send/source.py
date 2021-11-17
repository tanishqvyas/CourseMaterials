#!/usr/bin/env python
import pika
import sys

# credentials = pika.PlainCredentials('guest','guest')
connection = pika.BlockingConnection(pika.ConnectionParameters(host='rmq'))
channel = connection.channel()

channel.queue_declare(queue='task_queue', durable=True)

for i in range(15):
    message = "Hello! My SRN is PES2201800125 [" + str(i) + "]"
    channel.basic_publish(
        exchange='',
        routing_key='task_queue',
        body=message,
        properties=pika.BasicProperties(
            delivery_mode=2,  # make message persistent
        ))

    print(" [x] Sent %r" % message)
connection.close()
