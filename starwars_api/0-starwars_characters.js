#!/usr/bin/node

const request = require("request");

const numFilm = process.argv[2];

request(`https://swapi-api.hbtn.io/api/films/${numFilm}/`, function(err, res, body){
    if(res.statusCode != 200){
        console.log(err);
    }
    movieJson = JSON.parse(body)
    const allCharacters = movieJson.characters
    allCharacters.forEach(character => {
        request(character, function(err, res, body){
            const characterJSON = JSON.parse(body)
            console.log(characterJSON.name);
        })
    });
})