#!/usr/bin/env python3
import cgi

html = """
<!DOCTYPE html>
<html>
<head><title>CGI TEST</title></head>
<body>
<h5>Hello, CGI!</h5>
<br />
</body>
</html>
"""

print("Content-Type: text/html")
print("")
print(html)