#
#    Implement a URL shortener with the following methods:
#
#        shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
#        restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
#    
#   Hint: What if we enter the same URL twice?
#

import hashlib

class  URLShortener:
    map = {}
    def shorten(self,url):
        if url not in self.map:
            shortUrl = hashlib.sha512(url).hexdigest()[:6]
            self.map[shortUrl] = url
        return 'http://newUrl/' + shortUrl

    def restore(self,short):
        return self.map.get(short[14:])

test = URLShortener()
short = test.shorten('https://www.w3schools.com/python/python_classes.asp')
print(test.restore(short))