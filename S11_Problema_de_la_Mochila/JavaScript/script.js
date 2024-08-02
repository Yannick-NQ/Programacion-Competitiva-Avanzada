let weightArray = [];
let valueArray = [];
let capacity;
let dp;
let i, w;

document.getElementById('initialize').addEventListener('click', initialize);
document.getElementById('nextStep').addEventListener('click', nextStep);

function initialize() {
    weightArray = document.getElementById('weights').value.split(',').map(Number);
    valueArray = document.getElementById('values').value.split(',').map(Number);
    capacity = Number(document.getElementById('capacity').value);

    const n = weightArray.length;
    dp = Array.from(Array(n + 1), () => Array(capacity + 1).fill(0));

    i = 1;
    w = 0;
    updateMatrixDisplay();
    document.getElementById('nextStep').disabled = false;
}

function nextStep() {
    const n = weightArray.length;

    if (i <= n && w <= capacity) {
        if (weightArray[i - 1] <= w) {
            dp[i][w] = Math.max(dp[i - 1][w], dp[i - 1][w - weightArray[i - 1]] + valueArray[i - 1]);
        } else {
            dp[i][w] = dp[i - 1][w];
        }

        w++;
        if (w > capacity) {
            w = 0;
            i++;
        }
        updateMatrixDisplay();
    } else {
        document.getElementById('nextStep').disabled = true;
        showResult();
    }
}

function updateMatrixDisplay() {
    const matrixContainer = document.getElementById('matrixContainer');
    matrixContainer.innerHTML = '';
    const table = document.createElement('table');

    const headerRow = document.createElement('tr');
    headerRow.appendChild(document.createElement('th'));
    for (let w = 0; w <= capacity; w++) {
        const th = document.createElement('th');
        th.textContent = w;
        headerRow.appendChild(th);
    }
    table.appendChild(headerRow);

    for (let i = 0; i <= weightArray.length; i++) {
        const row = document.createElement('tr');
        const th = document.createElement('th');
        if (i > 0) th.textContent = `Item ${i}`;
        row.appendChild(th);
        for (let w = 0; w <= capacity; w++) {
            const td = document.createElement('td');
            td.textContent = dp[i][w];
            row.appendChild(td);
        }
        table.appendChild(row);
    }

    matrixContainer.appendChild(table);
}

function showResult() {
    const resultContainer = document.getElementById('resultContainer');
    resultContainer.innerHTML = `<p><strong>Valor Máximo:</strong> ${dp[weightArray.length][capacity]}</p>`;
}
