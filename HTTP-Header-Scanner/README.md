# HTTP Security Headers Scanner (Asynchronous Triage Prototyping)

A low-level security auditing utility designed in C to analyze HTTP response sequences and flag missing security vectors. 

##  Project Overview
In defensive security operations and application security engineering, validating server-side configuration profiles is critical. This utility processes raw string buffers mimicking server responses to parse, identify, and audit high-priority compliance headers. It validates whether an infrastructure asset has active protection mechanisms deployed against common web-surface attack vectors.

##  Security Vectors Audited
The tool scans for the presence of crucial security shields within the communication layer:
* **X-Frame-Options:** Validates protection configurations against Clickjacking/UI-Redressing vulnerabilities.
* **Content-Security-Policy (CSP):** Audits for active layers mitigating Cross-Site Scripting (XSS) and data injection payloads.

##  Core Skills Demonstrated
* **Security Architecture Literacy:** Deep conceptual knowledge of web server header configurations and browser-enforced security policies.
* **Secure Coding Standards:** Proactive execution of memory-safe operations using `strncpy` limits to securely mitigate potential Buffer Overflow vulnerabilities during buffer handling.
* **String Token Parsing:** Implementation of conditional block routines over structured memory blocks.

##  Deployment & Testing
Compile the source code using standard compilation frameworks (such as GCC or MSVC in Visual Studio):
```bash
gcc header_scanner.c -o header_scanner
./header_scanner
