#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

function getCharacterName (url) {
  return new Promise((resolve, reject) => {
    request(url, { json: true }, (error, response, body) => {
      if (error) {
        reject(error);
      } else if (response.statusCode !== 200) {
        reject(new Error(`Failed to get character data: ${response.statusCode}`));
      } else {
        resolve(body.name);
      }
    });
  });
}

async function fetchApi (url) {
  try {
    const filmData = await new Promise((resolve, reject) => {
      request(url, { json: true }, (error, response, body) => {
        if (error) {
          reject(error);
        } else if (response.statusCode !== 200) {
          reject(new Error(`Failed to get film data: ${response.statusCode}`));
        } else {
          resolve(body);
        }
      });
    });

    const characterNames = [];
    for (const characterUrl of filmData.characters) {
      const name = await getCharacterName(characterUrl);
      characterNames.push(name);
    }
    characterNames.forEach(name => console.log(name));
  } catch (error) {
    console.log(error);
  }
}

fetchApi(url);
