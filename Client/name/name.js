function buildTab() {

    let tabAuthor = "";
    let tabBookname = "";
    let tabPages = "";
    let tabGenre = "";
    let infos = "";
    let tmp2 = "";
    let str = "";
    let i = 1;

    let tmp = readFile();
    infos = tmp.split('\n');
    infos.sort();

    for (let m = 1; m < infos.length - 1; m++) {
        tmp2 = infos[m];
        str = tmp2.split(';');
        tabAuthor = str[0];
        tabBookname = str[1];
        tabPages = str[2];
        tabGenre = str[3];
        console.log(tabAuthor +' '+ tabBookname +' '+ tabPages +' ' +tabGenre);
        let saisies = document.getElementById("table");
        saisies.insertAdjacentHTML('BeforeEnd','<tr><td>'+i+'</td><td>'+tabAuthor+'</td><td>'+tabBookname+'</td><td>'+tabPages+'</td><td>'+tabGenre+'</td></tr>');
        i++;
    }
}

function insertSearchTime(){
    let tmp = "";
    tmp = readFile().split('\n');
    tmp.sort();
    let time = document.getElementById("footer");
    time.insertAdjacentHTML('BeforeEnd','<tr><td>Execution time</td><td>'+tmp[0]+'</td><td>seconds</td></tr>');

}

function readFileByName(fileName){

    let xhr = new XMLHttpRequest();
    do {
        xhr.open("GET", fileName, false);
        xhr.send(null);

    }while(xhr.status === 404);

    // assumes status 200
    return xhr.responseText;
}

function readFile(){
    readFileByName("ready.txt");
    return readFileByName("results.txt");
}

function writeFile(id_form,func) {

    var element = document.createElement('a');

    let text1 = document.getElementById(id_form);
    let count = text1.elements.length;
    let textToSave = func;
    for(let i = 0;i<count-1;i++){
        textToSave += ";" + text1[i].value;
    }

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(textToSave));
    element.setAttribute('download', 'request.txt');

    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);
}


function main(){
    buildTab();
    insertSearchTime();
}

main();