#!/usr/bin/env python3

import requests
import shutil

class DogPicsDownloader:
    def __init__(self,*,pics_count,https=True):
        self.pics_count = str(pics_count)
        self.https = str(https)
        if int(self.pics_count) > 5:
            raise ValueError('pics_count has to be less then 10')

    def get_urls(self):
        urls = requests.get("http://shibe.online/api/shibes?count="+self.pics_count+"&urls=true&httpsUrls="+self.https)
        return urls.json()

    def download_pics(self):
        urls_list = self.get_urls()
        tag=0
        for url in urls_list:
            with open(str(tag)+"_shiba.jpg",'wb') as content:
                image = requests.get(url,stream=True)
                shutil.copyfileobj(image.raw,content)
            tag+=1
        print(f"Downloaded {tag} images")

if __name__ == "__main__":
    object_downloader = DogPicsDownloader(pics_count=3)
    #Or get urls via get_urls method in class
    #urls = object_downloader.get_urls()
    #print(urls)
    object_downloader.download_pics()
