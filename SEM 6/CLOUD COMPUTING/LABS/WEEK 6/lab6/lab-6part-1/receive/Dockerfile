FROM python:3.7-slim-stretch
ENV PYTHONUNBUFFERED 1
ENV PYTHONDONTWRITEBYTECODE 1

RUN pip install pika
COPY . /code
WORKDIR /code
# CMD ["python", "source.py"]