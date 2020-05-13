function getAuthor1() {

    let author1 = document.getElementById("author1");
    console.log(author1.value);
}

function getBookName1() {

    let bookname = document.getElementById("Book name1");
    console.log(bookname.value);
}

function getNbrPages() {

    let pages = document.getElementById("pages");
    console.log(pages.value);
}

function getGenre(){
    let genre = document.getElementById("js");
    console.log(genre.value);
}

function getAuthorOrBookName() {
    let selected_id = $("select option:selected").attr("id");

    if (selected_id == "author"){

        writeFile1('search_form', 'findByAuthor');
        window.location = "list.html";
    }
    else if (selected_id == "Book name"){

        writeFile1('search_form', 'findByName');
        window.location = "list.html";
    }
    else if (selected_id == "genre"){

        writeFile1('search_form', 'findByGenre');
        window.location = "list.html";
    }
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

function free(text){

    var element = document.createElement('a');

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
    element.setAttribute('download', 'request.txt');

    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);
}


function main(){

    let elt = document.getElementById('search_button');
    elt.addEventListener('click', function(){
        getAuthorOrBookName();
    });

    let elt2 = document.getElementById("input");
    elt2.addEventListener('click', function(){
        writeFile('form', 'insert');
    });


    let elt3 = document.getElementById('power');
    elt3.addEventListener('click', function(){
        free('end');
    });
}
main();