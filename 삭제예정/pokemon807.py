import requests

for i in range(1, 10):
    given = requests.get("https://assets.pokemon.com/assets/cms2/img/pokedex/full/00" + str(i) + ".png")
    with open('./포켓몬 807/000' + str(i) + '.png', 'wb') as file:
        file.write(given.content)
    print(i)

for i in range(10, 100):
    given = requests.get("https://assets.pokemon.com/assets/cms2/img/pokedex/full/0" + str(i) + ".png")
    with open('./포켓몬 807/00' + str(i) + '.png', 'wb') as file:
        file.write(given.content)
    print(i)

for i in range(100, 808):
    given = requests.get("https://assets.pokemon.com/assets/cms2/img/pokedex/full/" + str(i) + ".png")
    with open('./포켓몬 807/0' + str(i) + '.png', 'wb') as file:
        file.write(given.content)
    print(i)
