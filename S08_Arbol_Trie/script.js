const htmlTags = [
    "a", "abbr", "address", "area", "article", "aside", "audio", "b", "base", "bdi", "bdo", "blockquote", 
    "body", "br", "button", "canvas", "caption", "cite", "code", "col", "colgroup", "data", "datalist", 
    "dd", "del", "details", "dfn", "dialog", "div", "dl", "dt", "em", "embed", "fieldset", "figcaption", 
    "figure", "footer", "form", "h1", "h2", "h3", "h4", "h5", "h6", "head", "header", "hr", "html", "i", 
    "iframe", "img", "input", "ins", "kbd", "label", "legend", "li", "link", "main", "map", "mark", "meta", 
    "meter", "nav", "noscript", "object", "ol", "optgroup", "option", "output", "p", "param", "picture", 
    "pre", "progress", "q", "rp", "rt", "ruby", "s", "samp", "script", "section", "select", "small", 
    "source", "span", "strong", "style", "sub", "summary", "sup", "svg", "table", "tbody", "td", "template", 
    "textarea", "tfoot", "th", "thead", "time", "title", "tr", "track", "u", "ul", "var", "video", "wbr"
];

class TrieNode {
    constructor() {
        this.children = {};
        this.isEndOfWord = false;
    }
}

class Trie {
    constructor() {
        this.root = new TrieNode();
    }

    insert(word) {
        let node = this.root;
        for (let i = 0; i < word.length; i++) {
            const char = word[i];
            if (!node.children[char]) {
                node.children[char] = new TrieNode();
            }
            node = node.children[char];
        }
        node.isEndOfWord = true;
    }

    search(word) {
        let node = this.root;
        for (let i = 0; i < word.length; i++) {
            const char = word[i];
            if (!node.children[char]) {
                return false;
            }
            node = node.children[char];
        }
        return node.isEndOfWord;
    }

    startsWith(prefix) {
        let node = this.root;
        for (let i = 0; i < prefix.length; i++) {
            const char = prefix[i];
            if (!node.children[char]) {
                return false;
            }
            node = node.children[char];
        }
        return true;
    }
}

const trie = new Trie();

// Agregar las palabras del diccionario al árbol Trie
htmlTags.forEach((word) => {
    trie.insert(word);
});

const inputTextarea = document.getElementById("input-textarea");
const suggestionsList = document.getElementById("suggestions-list");

// Función para generar sugerencias
function generateSuggestions() {
    const inputValue = inputTextarea.value.toLowerCase().trim();
    const lines = inputValue.split("\n");
    const currentLine = getCurrentLine(inputTextarea);

    if (currentLine >= 0 && currentLine < lines.length) {
        const currentText = lines[currentLine];
        const suggestions = [];

        // Generar sugerencias a partir del árbol Trie
        htmlTags.forEach((tag) => {
            if (trie.startsWith(currentText) && tag.startsWith(currentText)) {
                suggestions.push(tag);
            }
        });

        // Mostrar las sugerencias en la lista
        renderSuggestions(suggestions);
    } else {
        clearSuggestions();
    }
}

// Función para renderizar las sugerencias en la lista
function renderSuggestions(suggestions) {
    suggestionsList.innerHTML = "";
    suggestions.forEach((suggestion) => {
        const li = document.createElement("li");
        li.textContent = suggestion;
        li.addEventListener("click", () => {
            insertSuggestion(suggestion);
        });
        suggestionsList.appendChild(li);
    });
}

// Función para insertar la sugerencia seleccionada en el textarea
function insertSuggestion(suggestion) {
    const lines = inputTextarea.value.split("\n");
    const currentLine = getCurrentLine(inputTextarea);
    const currentText = lines[currentLine];
    const before = lines.slice(0, currentLine).join("\n");
    const after = lines.slice(currentLine + 1).join("\n");

    lines[currentLine] = suggestion;
    inputTextarea.value = before + lines[currentLine] + after;
    suggestionsList.innerHTML = "";
}

// Función para limpiar la lista de sugerencias
function clearSuggestions() {
    suggestionsList.innerHTML = "";
}

// Función para obtener la línea actual del textarea
function getCurrentLine(textarea) {
    const cursorPosition = textarea.selectionStart;
    return textarea.value.substr(0, cursorPosition).split("\n").length - 1;
}

// Evento para detectar cambios en el contenido del textarea
inputTextarea.addEventListener("input", generateSuggestions);

// Evento para manejar las teclas presionadas en el textarea
inputTextarea.addEventListener("keydown", (e) => {
    const suggestions = suggestionsList.getElementsByTagName("li");

    if (e.key === "ArrowDown" || e.key === "ArrowUp") {
        // Flechas hacia abajo o hacia arriba
        e.preventDefault(); // Evitar el scroll del textarea

        let newIndex = currentFocus;
        if (e.key === "ArrowDown") {
            newIndex++;
        } else if (e.key === "ArrowUp") {
            newIndex--;
        }

        highlightSuggestion(suggestions, newIndex);
    } else if (e.key === "Enter") {
        // Enter presionado
        //e.preventDefault();

        if (currentFocus > -1) {
            // Se ha seleccionado una sugerencia
            insertSuggestion(suggestions[currentFocus].textContent);
        } else {
            // No hay sugerencias seleccionadas, insertar el texto actual
            const lines = inputTextarea.value.split("\n");
            const currentLine = getCurrentLine(inputTextarea);
            const currentText = lines[currentLine];
            const before = lines.slice(0, currentLine).join("\n");
            const after = lines.slice(currentLine+1).join("\n");

            lines[currentLine] = currentText + "\n";
            inputTextarea.value = before + lines[currentLine] + after;
        }

        suggestionsList.innerHTML = "";
    }
});

// Función para resaltar la sugerencia actualmente enfocada
let currentFocus = 1;
function highlightSuggestion(suggestions, newIndex) {
    for (let i = 0; i < suggestions.length; i++) {
        suggestions[i].classList.remove("autocomplete-active");
    }
    if (newIndex >= suggestions.length) newIndex = 0;
    if (newIndex < 0) newIndex = (suggestions.length - 1);

    currentFocus = newIndex;
    suggestions[currentFocus].classList.add("autocomplete-active");
}
