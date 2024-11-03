# -*- coding: utf-8 -*-

import hmac
import hashlib
import binascii

#아래는 송신자와 수신자가 사전에 공유해야할 비밀키
key = bytes.fromhex("E49756B4C8FAB4E48222A3E7F3B97CC3")
message = b"WARGREYMON"

#key와 SHA256 해싱 알고리즘을 사용하여 HMAC 메시지 생성
hmac_msg = hmac.new(key, message, hashlib.sha256)

#만들어진 HMAC 메시지 출력
print ("HMAC:", hmac_msg.hexdigest())
