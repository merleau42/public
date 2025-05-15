import requests

import os, time



def 다운(파일명, url):

    

    with open(파일명, "wb") as file:

        file.write(requests.get(url).content)



try:

    os.makedirs('포켓몬 898 마리')

except:

    pass



for i in range(1,899):

    time.sleep(1.5)

    num=("00"+str(i))[-3:]

    try:

        print(f'now: {num}')

        url=f'https://assets.pokemon.com/assets/cms2/img/pokedex/full/{num}.png'

        다운(f'./포켓몬 898 마리/{num}.png', url)

    except:

        pass



print('완료')
