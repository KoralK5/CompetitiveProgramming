import base64

MESSAGE = '''
b'EFIfFAAMAh8GTE9IQUsMBwkAF0hLTFIIAB4NCQoSGQRET11MUg4cBgQJBhAIRk9PQAkTDQAAFR9M\nVVZBRAYJDwcOCxsDAA5SQEFEDgQEHA4ZFwwJBQFLQVlPQBkbBwARCgkPUkBBRB0GDhcCGwFGTFFV\nSxICCQJLWUtIFA4DTFVWQUQYDgJUTBI='
'''

KEY = 'jacopo.notarstefano'

result = []
for i, c in enumerate(base64.b64decode(MESSAGE)):
    result.append(chr(ord(c) ^ ord(KEY[i % len(KEY)])))

print(''.join(result))
