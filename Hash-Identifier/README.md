# Cryptographic Hash Identifier (CLI Triage Utility)

A high-performance, lightweight Command Line Interface (CLI) utility written in C to analyze unknown strings and identify cryptographic hashing algorithms based on length characteristics.

##  Project Overview
In security operations and forensics, determining an unknown hash type is a vital first triage step before executing decryption workflows or integrity checks. This project demonstrates foundational low-level string manipulation principles to mimic automated signature-triage utilities found in professional Linux toolkits.

##  Logic & Specifications
The tool utilizes memory-safe character arrays and efficient logical execution branches to identify structures matching specific industry standards:
* **32 Characters** ➔ Flagged as **MD5** (Message Digest 5)
* **40 Characters** ➔ Flagged as **SHA-1** (Secure Hash Algorithm 1)
* **64 Characters** ➔ Flagged as **SHA-256** (Secure Hash Algorithm 2)

##  Core Skills Demonstrated
* **Low-Level Software Engineering:** Manual string analysis using standard C memory buffers.
* **Algorithmic Logic:** Constructing clean conditional blocks.
* **Defensive Foundations:** Practical comprehension of cryptographic data signatures.

##  Deployment
Compile and run the source file using any standard C compiler (such as GCC):
```bash
gcc hash_id.c -o hash_id
./hash_id
