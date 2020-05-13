function getAuthorOrBookName() {
    let selected_id = $("select option:selected").attr("id");

    if (selected_id == "author"){

        writeFile1('search_form', 'findByAuthor');
    }
    else if (selected_id == "Book name"){

        writeFile1('search_form', 'findByName');
    }
    else if (selected_id == "genre"){

        writeFile1('search_form', 'findByGenre');
    }

    window.location.reload();

}

function buildTab(m) {

    let tabAuthor = "";
    let tabBookname = "";
    let tabPages = "";
    let tabGenre = "";
    let infos = "";
    let tmp2 = "";
    let str = "";

    infos = readFile().split('\n');
    console.log(infos[1]);

    if (infos[1] == undefined) {
        let saisies = document.getElementById("table");
        saisies.insertAdjacentHTML('BeforeEnd', '<tr><td>/</td><td>No results</td><td>No results</td><td>No results</td><td>No results</td></tr>');

    } else {

        infos = readFile().split('\n');
        infos.sort();
        let b=m;

        for (m; m < b + 100; m++) {

            if (infos[m] == undefined) {
                for (let j= (100-m); j<100; j++){}
                let tmp = document.getElementById("table");
                tmp.insertAdjacentHTML('BeforeEnd', '<tr></tr>');
            }else {
                tmp2 = infos[m];
                str = tmp2.split(';');
                tabAuthor = str[0];
                tabBookname = str[1];
                tabPages = str[2];
                tabGenre = str[3];
                console.log(tabAuthor + ' ' + tabBookname + ' ' + tabPages + ' ' + tabGenre);
                let saisies = document.getElementById("table");
                saisies.insertAdjacentHTML('BeforeEnd', '<tr><td>' + m + '</td><td>' + tabAuthor + '</td><td>' + tabBookname + '</td><td>' + tabPages + '</td><td>' + tabGenre + '</td></tr>');
            }
        }
    }
}

function pagination(){

    let infos = "";
    let x = 1;
    let a = 1;

    infos = readFile().split('\n');
    infos.sort();
    console.log(infos);

    for (let i=1; i<=((infos.length/100)+1); i++){
        let pages = document.getElementById("pagination");
        pages.insertAdjacentHTML('BeforeEnd', ' <a onclick ="changetab('+x+')">page '+a+' ('+x+' à '+(x+99)+')</a> ');
        x+=100;
        a++;
    }

}

function changetab(k){

    document.getElementById("table").innerHTML = "";
    buildTab(k);
}

function insertSearchTime(){

    let tmp = "";
    tmp = readFile().split('\n');
    tmp.sort();
    let time = document.getElementById("footer");
    time.insertAdjacentHTML('BeforeEnd','<td>Execution time</td><td>'+tmp[0]+'</td><td>seconds</td><td><!--<button id="reload">Actualiser la liste</button>--></td>');
    /*let elt4 = document.getElementById('reload');
    elt4.addEventListener('click', function(){
        reload();
    });*/
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

function free(text){

    var element = document.createElement('a');

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
    element.setAttribute('download', 'request.txt');

    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);
}

function reload(){

    location.reload();
}

function writeFile1(id_form,func) {

    var element = document.createElement('a');

    let text1 = document.getElementById(id_form);
    let count = text1.elements.length;
    let textToSave = func;
    for(let i = 1;i<count-1;i++){
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

    insertSearchTime();

    pagination();

    buildTab(1);


    let elt = document.getElementById('search_button');
    elt.addEventListener('click', function(){
        getAuthorOrBookName();
    });

    let elt3 = document.getElementById('power');
    elt3.addEventListener('click', function(){
        free('end');
    });

}
main();