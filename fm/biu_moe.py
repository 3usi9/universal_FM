import sys
import getopt
import urllib
import json
from urllib import parse
from urllib import request
# curl -d 'type=1&search=摇曳百合&token=zTwaFuSpNFtpgCvCiqtnChVMZOMpJPiZQWUdFwASztOPxOcvuoNkkQMHqvhzqcAq'  https://biuandroid-ssl.smartgslb.com/Song/search

# [-1- bi ~]$ curl -d 'sid=2015&token=zTwaFuSpNFtpgCvCiqtnChVMZOMpJPiZQWUdFwASztOPxOcvuoNkkQMHqvhzqcAq'  https://biuandroid-ssl.smartgslb.com/Song/download


opt = []

def get_song(song_id):
    post_data = {'sid':song_id, 'token':'zTwaFuSpNFtpgCvCiqtnChVMZOMpJPiZQWUdFwASztOPxOcvuoNkkQMHqvhzqcAq'}
    post_data_xfer = urllib.parse.urlencode(post_data).encode(encoding='UTF8')
    requrl = "https://biuandroid-ssl.smartgslb.com/Song/download"
    req = urllib.request.Request(requrl, post_data_xfer)
    res = json.loads(urllib.request.urlopen(req).read().decode('utf-8'))
    div = '######'
    st = 'Biu_Moe'+div+res['sid']+div+res['url']+div
    requrl = "https://biuandroid-ssl.smartgslb.com/Song/get"
    req = urllib.request.Request(requrl, post_data_xfer)
    res = json.loads(urllib.request.urlopen(req).read().decode('utf-8'))
    res = res['result']
    res = res[0]
    st += res['title'] + div + res['singer'] + div + res['album'] + div
    #     Title                Artist                Album             
    st += '' + div + res['remark'] + div + '' + div + 'Anime' + div
    #     Year       Comment               Track      Genre
    st += 'http://biu.moe/Song/showCover/sid/'+song_id+ div + '' + div
    #     Cover                                                Note
    print(st)


    
def search_song(keywords):
    post_data = {'type':'1', 'token':'zTwaFuSpNFtpgCvCiqtnChVMZOMpJPiZQWUdFwASztOPxOcvuoNkkQMHqvhzqcAq', 'search': keywords}
    post_data_xfer = urllib.parse.urlencode(post_data).encode(encoding='UTF8')
    requrl = "https://biuandroid-ssl.smartgslb.com/Song/search"
    req = urllib.request.Request(requrl, post_data_xfer)
    res = json.loads(urllib.request.urlopen(req).read().decode('utf-8'))
    print(res)




def main(argv):
    SONG = ''
    ALBUM = ''
    RADIO = ''
    KEYWORDS = ''
    try:
        opts, args = getopt.getopt(argv,"hs:a:S:r:",["SONG_ID=","ofile="])
    except getopt.GetoptError:
        print ('biu_moe.py -s <song_id> -a <album_id> -S <keywords> -r <radio_id>')
        sys.exit(2)
        for opt, arg in opts:
        if opt == '-h':
             print ('biu_moe.py -s <song_id> -a <album_id> -S <keywords> -r <radio_id>')
             sys.exit()
        elif opt in ("-s"):
             SONG = arg
        elif opt in ("-a"):
             ALBUM = arg
        elif opt in ("-r"):
             RADIO = arg
        elif opt in ("-S"):
             KEYWORDS = arg
          
    if SONG != '':
        get_song(SONG)

    if KEYWORDS != '':
        search_song(KEYWORDS)
    

if __name__ == "__main__":
   main(sys.argv[1:])
   
